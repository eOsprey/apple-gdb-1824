
/**
 * \file autoopts.c
 *
 *  Time-stamp:      "2012-01-29 09:58:30 bkorb"
 *
 *  This file contains all of the routines that must be linked into
 *  an executable to use the generated option processing.  The optional
 *  routines are in separately compiled modules so that they will not
 *  necessarily be linked in.
 *
 *  This file is part of AutoOpts, a companion to AutoGen.
 *  AutoOpts is free software.
 *  AutoOpts is Copyright (c) 1992-2012 by Bruce Korb - all rights reserved
 *
 *  AutoOpts is available under any one of two licenses.  The license
 *  in use must be one of these two and the choice is under the control
 *  of the user of the license.
 *
 *   The GNU Lesser General Public License, version 3 or later
 *      See the files "COPYING.lgplv3" and "COPYING.gplv3"
 *
 *   The Modified Berkeley Software Distribution License
 *      See the file "COPYING.mbsd"
 *
 *  These files have the following md5sums:
 *
 *  43b91e8ca915626ed3818ffb1b71248b pkg/libopts/COPYING.gplv3
 *  06a1a2e4760c90ea5e1dad8dfaac4d39 pkg/libopts/COPYING.lgplv3
 *  66a5cedaf62c4b2637025f049f9b826f pkg/libopts/COPYING.mbsd
 */

#ifndef PKGDATADIR
#  define PKGDATADIR ""
#endif

static char const   zNil[] = "";
static arg_types_t  argTypes             = { NULL };
static char         line_fmt_buf[32];
static ag_bool      displayEnum          = AG_FALSE;
static char const   pkgdatadir_default[] = PKGDATADIR;
static char const * program_pkgdatadir   = pkgdatadir_default;
static tOptionLoadMode option_load_mode  = OPTION_LOAD_UNCOOKED;
static tePagerState pagerState           = PAGER_STATE_INITIAL;

       FILE *       option_usage_fp      = NULL;

/* = = = START-STATIC-FORWARD = = = */
static tSuccess
next_opt_arg_must(tOptions * pOpts, tOptState* pOptState);

static tSuccess
next_opt_arg_may(tOptions * pOpts, tOptState* pOptState);

static tSuccess
next_opt_arg_none(tOptions * pOpts, tOptState* pOptState);

static tSuccess
next_opt(tOptions * pOpts, tOptState * pOptState);

static tSuccess
doPresets(tOptions * pOpts);
/* = = = END-STATIC-FORWARD = = = */

LOCAL void *
ao_malloc(size_t sz)
{
    void * res = malloc(sz);
    if (res == NULL) {
        fprintf(stderr, zAO_Alloc, (int)sz);
        exit(EXIT_FAILURE);
    }
    return res;
}
#undef  malloc
#define malloc(_s) ao_malloc(_s)

LOCAL void *
ao_realloc(void *p, size_t sz)
{
    void * res = (p == NULL) ? malloc(sz) : realloc(p, sz);
    if (res == NULL) {
        fprintf(stderr, zAO_Realloc, (int)sz, p);
        exit(EXIT_FAILURE);
    }
    return res;
}
#undef  realloc
#define realloc(_p,_s) ao_realloc(_p,_s)

LOCAL char *
ao_strdup(char const *str)
{
    char * res = strdup(str);
    if (res == NULL) {
        fprintf(stderr, zAO_Strdup, (int)strlen(str));
        exit(EXIT_FAILURE);
    }
    return res;
}
#undef  strdup
#define strdup(_p) ao_strdup(_p)

#ifndef HAVE_PATHFIND
#  include "compat/pathfind.c"
#endif

#ifndef HAVE_SNPRINTF
#  include "compat/snprintf.c"
#endif

#ifndef HAVE_STRDUP
#  include "compat/strdup.c"
#endif

#ifndef HAVE_STRCHR
#  include "compat/strchr.c"
#endif

/*
 *  handle_opt
 *
 *  This routine handles equivalencing, sets the option state flags and
 *  invokes the handler procedure, if any.
 */
LOCAL tSuccess
handle_opt(tOptions * pOpts, tOptState* pOptState)
{
    /*
     *  Save a copy of the option procedure pointer.
     *  If this is an equivalence class option, we still want this proc.
     */
    tOptDesc* pOD = pOptState->pOD;
    tOptProc* pOP = pOD->pOptProc;
    if (pOD->fOptState & OPTST_ALLOC_ARG)
        AGFREE(pOD->optArg.argString);

    pOD->optArg.argString = pOptState->pzOptArg;

    /*
     *  IF we are presetting options, then we will ignore any un-presettable
     *  options.  They are the ones either marked as such.
     */
    if (  ((pOpts->fOptSet & OPTPROC_PRESETTING) != 0)
       && ((pOD->fOptState & OPTST_NO_INIT) != 0)
       )
        return PROBLEM;

    /*
     *  IF this is an equivalence class option,
     *  THEN
     *      Save the option value that got us to this option
     *      entry.  (It may not be pOD->optChar[0], if this is an
     *      equivalence entry.)
     *      set the pointer to the equivalence class base
     */
    if (pOD->optEquivIndex != NO_EQUIVALENT) {
        tOptDesc* p = pOpts->pOptDesc + pOD->optEquivIndex;

        /*
         * IF the current option state has not been defined (set on the
         *    command line), THEN we will allow continued resetting of
         *    the value.  Once "defined", then it must not change.
         */
        if ((pOD->fOptState & OPTST_DEFINED) != 0) {
            /*
             *  The equivalenced-to option has been found on the command
             *  line before.  Make sure new occurrences are the same type.
             *
             *  IF this option has been previously equivalenced and
             *     it was not the same equivalenced-to option,
             *  THEN we have a usage problem.
             */
            if (p->optActualIndex != pOD->optIndex) {
                fprintf(stderr, (char*)zMultiEquiv, p->pz_Name, pOD->pz_Name,
                        (pOpts->pOptDesc + p->optActualIndex)->pz_Name);
                return FAILURE;
            }
        } else {
            /*
             *  Set the equivalenced-to actual option index to no-equivalent
             *  so that we set all the entries below.  This option may either
             *  never have been selected before, or else it was selected by
             *  some sort of "presetting" mechanism.
             */
            p->optActualIndex = NO_EQUIVALENT;
        }

        if (p->optActualIndex != pOD->optIndex) {
            /*
             *  First time through, copy over the state
             *  and add in the equivalence flag
             */
            p->optActualValue = pOD->optValue;
            p->optActualIndex = pOD->optIndex;
            pOptState->flags |= OPTST_EQUIVALENCE;
        }

        /*
         *  Copy the most recent option argument.  set membership state
         *  is kept in ``p->optCookie''.  Do not overwrite.
         */
        p->optArg.argString = pOD->optArg.argString;
        pOD = p;

    } else {
        pOD->optActualValue = pOD->optValue;
        pOD->optActualIndex = pOD->optIndex;
    }

    pOD->fOptState &= OPTST_PERSISTENT_MASK;
    pOD->fOptState |= (pOptState->flags & ~OPTST_PERSISTENT_MASK);

    /*
     *  Keep track of count only for DEFINED (command line) options.
     *  IF we have too many, build up an error message and bail.
     */
    if (  (pOD->fOptState & OPTST_DEFINED)
       && (++pOD->optOccCt > pOD->optMaxCt)  )  {

        if ((pOpts->fOptSet & OPTPROC_ERRSTOP) != 0) {
            char const * pzEqv =
                (pOD->optEquivIndex != NO_EQUIVALENT) ? zEquiv : zNil;

            fputs(zErrOnly, stderr);

            if (pOD->optMaxCt > 1)
                fprintf(stderr, zAtMost, pOD->optMaxCt, pOD->pz_Name, pzEqv);
            else
                fprintf(stderr, zOnlyOne, pOD->pz_Name, pzEqv);
        }

        return FAILURE;
    }

    /*
     *  If provided a procedure to call, call it
     */
    if (pOP != NULL)
        (*pOP)(pOpts, pOD);

    return SUCCESS;
}

static tSuccess
next_opt_arg_must(tOptions * pOpts, tOptState* pOptState)
{
    /*
     *  An option argument is required.  Long options can either have
     *  a separate command line argument, or an argument attached by
     *  the '=' character.  Figure out which.
     */
    switch (pOptState->optType) {
    case TOPT_SHORT:
        /*
         *  See if an arg string follows the flag character
         */
        if (*++(pOpts->pzCurOpt) == NUL)
            pOpts->pzCurOpt = pOpts->origArgVect[ pOpts->curOptIdx++ ];
        pOptState->pzOptArg = pOpts->pzCurOpt;
        break;

    case TOPT_LONG:
        /*
         *  See if an arg string has already been assigned (glued on
         *  with an `=' character)
         */
        if (pOptState->pzOptArg == NULL)
            pOptState->pzOptArg = pOpts->origArgVect[ pOpts->curOptIdx++ ];
        break;

    default:
#ifdef DEBUG
        fputs("AutoOpts lib error: option type not selected\n", stderr);
        exit(EXIT_FAILURE);
#endif

    case TOPT_DEFAULT:
        /*
         *  The option was selected by default.  The current token is
         *  the option argument.
         */
        break;
    }

    /*
     *  Make sure we did not overflow the argument list.
     */
    if (pOpts->curOptIdx > pOpts->origArgCt) {
        fprintf(stderr, zMisArg, pOpts->pzProgPath, pOptState->pOD->pz_Name);
        return FAILURE;
    }

    pOpts->pzCurOpt = NULL;  /* next time advance to next arg */
    return SUCCESS;
}


static tSuccess
next_opt_arg_may(tOptions * pOpts, tOptState* pOptState)
{
    /*
     *  An option argument is optional.
     */
    switch (pOptState->optType) {
    case TOPT_SHORT:
        if (*++pOpts->pzCurOpt != NUL)
            pOptState->pzOptArg = pOpts->pzCurOpt;
        else {
            char* pzLA = pOpts->origArgVect[ pOpts->curOptIdx ];

            /*
             *  BECAUSE it is optional, we must make sure
             *  we did not find another flag and that there
             *  is such an argument.
             */
            if ((pzLA == NULL) || (*pzLA == '-'))
                pOptState->pzOptArg = NULL;
            else {
                pOpts->curOptIdx++; /* argument found */
                pOptState->pzOptArg = pzLA;
            }
        }
        break;

    case TOPT_LONG:
        /*
         *  Look for an argument if we don't already have one (glued on
         *  with a `=' character) *AND* we are not in named argument mode
         */
        if (  (pOptState->pzOptArg == NULL)
           && (! NAMED_OPTS(pOpts))) {
            char* pzLA = pOpts->origArgVect[ pOpts->curOptIdx ];

            /*
             *  BECAUSE it is optional, we must make sure
             *  we did not find another flag and that there
             *  is such an argument.
             */
            if ((pzLA == NULL) || (*pzLA == '-'))
                pOptState->pzOptArg = NULL;
            else {
                pOpts->curOptIdx++; /* argument found */
                pOptState->pzOptArg = pzLA;
            }
        }
        break;

    default:
    case TOPT_DEFAULT:
        fputs(zAO_Woops, stderr );
        exit(EX_SOFTWARE);
    }

    /*
     *  After an option with an optional argument, we will
     *  *always* start with the next option because if there
     *  were any characters following the option name/flag,
     *  they would be interpreted as the argument.
     */
    pOpts->pzCurOpt = NULL;
    return SUCCESS;
}


static tSuccess
next_opt_arg_none(tOptions * pOpts, tOptState* pOptState)
{
    /*
     *  No option argument.  Make sure next time around we find
     *  the correct option flag character for short options
     */
    if (pOptState->optType == TOPT_SHORT)
        (pOpts->pzCurOpt)++;

    /*
     *  It is a long option.  Make sure there was no ``=xxx'' argument
     */
    else if (pOptState->pzOptArg != NULL) {
        fprintf(stderr, zNoArg, pOpts->pzProgPath, pOptState->pOD->pz_Name);
        return FAILURE;
    }

    /*
     *  It is a long option.  Advance to next command line argument.
     */
    else
        pOpts->pzCurOpt = NULL;
    return SUCCESS;
}

/**
 *  Find the option descriptor and option argument (if any) for the
 *  next command line argument.  DO NOT modify the descriptor.  Put
 *  all the state in the state argument so that the option can be skipped
 *  without consequence (side effect).
 *
 * @param pOpts     the program option descriptor
 * @param pOptState the state of the next found option
 */
static tSuccess
next_opt(tOptions * pOpts, tOptState * pOptState)
{
    {
        tSuccess res = find_opt(pOpts, pOptState);
        if (! SUCCESSFUL(res))
            return res;
    }

    if (  ((pOptState->flags & OPTST_DEFINED) != 0)
       && ((pOptState->pOD->fOptState & OPTST_NO_COMMAND) != 0)) {
        fprintf(stderr, zNotCmdOpt, pOptState->pOD->pz_Name);
        return FAILURE;
    }

    return get_opt_arg(pOpts, pOptState);
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *  DO PRESETS
 *
 *  The next several routines do the immediate action pass on the command
 *  line options, then the environment variables, then the config files in
 *  reverse order.  Once done with that, the order is reversed and all
 *  the config files and environment variables are processed again, this
 *  time only processing the non-immediate action options.  doPresets()
 *  will then return for optionProcess() to do the final pass on the command
 *  line arguments.
 */

/**
 *  scan the command line for immediate action options.
 *  This is only called the first time through.
 *  While this procedure is active, the OPTPROC_IMMEDIATE is true.
 *
 *  @param pOpts   program options descriptor
 *  @returns SUCCESS or FAILURE
 */
LOCAL tSuccess
immediate_opts(tOptions * pOpts)
{
    tSuccess  res;

    pOpts->fOptSet  |= OPTPROC_IMMEDIATE;
    pOpts->curOptIdx = 1;     /* start by skipping program name */
    pOpts->pzCurOpt  = NULL;

    /*
     *  Examine all the options from the start.  We process any options that
     *  are marked for immediate processing.
     */
    for (;;) {
        tOptState opt_st = OPTSTATE_INITIALIZER(PRESET);

        res = next_opt(pOpts, &opt_st);
        switch (res) {
        case FAILURE: goto   failed_option;
        case PROBLEM: res = SUCCESS; goto leave;
        case SUCCESS: break;
        }

        /*
         *  IF this is an immediate-attribute option, then do it.
         */
        if (! DO_IMMEDIATELY(opt_st.flags))
            continue;

        if (! SUCCESSFUL(handle_opt(pOpts, &opt_st)))
            break;
    } failed_option:;

    if ((pOpts->fOptSet & OPTPROC_ERRSTOP) != 0)
        (*pOpts->pUsageProc)(pOpts, EXIT_FAILURE);

leave:

    pOpts->fOptSet &= ~OPTPROC_IMMEDIATE;
    return res;
}

/**
 * Process all the options from our current position onward.  (This allows
 * interspersed options and arguments for the few non-standard programs that
 * require it.)  Thus, do not rewind option indexes because some programs
 * choose to re-invoke after a non-option.
 *
 *  @param pOpts   program options descriptor
 *  @returns SUCCESS or FAILURE
 */
LOCAL tSuccess
regular_opts(tOptions * pOpts)
{
    /* assert:  pOpts->fOptSet & OPTPROC_IMMEDIATE == 0 */
    for (;;) {
        tOptState opt_st = OPTSTATE_INITIALIZER(DEFINED);

        switch (next_opt(pOpts, &opt_st)) {
        case FAILURE: goto   failed_option;
        case PROBLEM: return SUCCESS; /* no more args */
        case SUCCESS: break;
        }

        /*
         *  IF this is an immediate action option,
         *  THEN skip it (unless we are supposed to do it a second time).
         */
        if (! DO_NORMALLY(opt_st.flags)) {
            if (! DO_SECOND_TIME(opt_st.flags))
                continue;
            opt_st.pOD->optOccCt--; /* don't count this repetition */
        }

        if (! SUCCESSFUL(handle_opt(pOpts, &opt_st)))
            break;
    } failed_option:;

    if ((pOpts->fOptSet & OPTPROC_ERRSTOP) != 0)
        (*pOpts->pUsageProc)(pOpts, EXIT_FAILURE);

    return FAILURE;
}


/**
 *  check for preset values from a config files or envrionment variables
 */
static tSuccess
doPresets(tOptions * pOpts)
{
    tOptDesc * pOD = NULL;

    if (! SUCCESSFUL(immediate_opts(pOpts)))
        return FAILURE;

    /*
     *  IF this option set has a --save-opts option, then it also
     *  has a --load-opts option.  See if a command line option has disabled
     *  option presetting.
     */
    if (  (pOpts->specOptIdx.save_opts != NO_EQUIVALENT)
       && (pOpts->specOptIdx.save_opts != 0)) {
        pOD = pOpts->pOptDesc + pOpts->specOptIdx.save_opts + 1;
        if (DISABLED_OPT(pOD))
            return SUCCESS;
    }

    /*
     *  Until we return from this procedure, disable non-presettable opts
     */
    pOpts->fOptSet |= OPTPROC_PRESETTING;
    /*
     *  IF there are no config files,
     *  THEN do any environment presets and leave.
     */
    if (pOpts->papzHomeList == NULL) {
        env_presets(pOpts, ENV_ALL);
    }
    else {
        env_presets(pOpts, ENV_IMM);

        /*
         *  Check to see if environment variables have disabled presetting.
         */
        if ((pOD != NULL) && ! DISABLED_OPT(pOD))
            intern_file_load(pOpts);

        /*
         *  ${PROGRAM_LOAD_OPTS} value of "no" cannot disable other environment
         *  variable options.  Only the loading of .rc files.
         */
        env_presets(pOpts, ENV_NON_IMM);
    }
    pOpts->fOptSet &= ~OPTPROC_PRESETTING;

    return SUCCESS;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *  THESE ROUTINES ARE CALLABLE FROM THE GENERATED OPTION PROCESSING CODE
 */
/*=--subblock=arg=arg_type,arg_name,arg_desc =*/
/*=*
 * library:  opts
 * header:   your-opts.h
 *
 * lib_description:
 *
 *  These are the routines that libopts users may call directly from their
 *  code.  There are several other routines that can be called by code
 *  generated by the libopts option templates, but they are not to be
 *  called from any other user code.  The @file{options.h} header is
 *  fairly clear about this, too.
=*/

/*=export_func optionProcess
 *
 * what: this is the main option processing routine
 *
 * arg:  + tOptions* + pOpts + program options descriptor +
 * arg:  + int       + argc  + program arg count  +
 * arg:  + char**    + argv  + program arg vector +
 *
 * ret_type:  int
 * ret_desc:  the count of the arguments processed
 *
 * doc:
 *
 * This is the main entry point for processing options.  It is intended
 * that this procedure be called once at the beginning of the execution of
 * a program.  Depending on options selected earlier, it is sometimes
 * necessary to stop and restart option processing, or to select completely
 * different sets of options.  This can be done easily, but you generally
 * do not want to do this.
 *
 * The number of arguments processed always includes the program name.
 * If one of the arguments is "--", then it is counted and the processing
 * stops.  If an error was encountered and errors are to be tolerated, then
 * the returned value is the index of the argument causing the error.
 * A hyphen by itself ("-") will also cause processing to stop and will
 * @emph{not} be counted among the processed arguments.  A hyphen by itself
 * is treated as an operand.  Encountering an operand stops option
 * processing.
 *
 * err:  Errors will cause diagnostics to be printed.  @code{exit(3)} may
 *       or may not be called.  It depends upon whether or not the options
 *       were generated with the "allow-errors" attribute, or if the
 *       ERRSKIP_OPTERR or ERRSTOP_OPTERR macros were invoked.
=*/
int
optionProcess(tOptions * pOpts, int argCt, char ** argVect)
{
    if (! SUCCESSFUL(validate_struct(pOpts, argVect[0])))
        exit(EX_SOFTWARE);

    /*
     *  Establish the real program name, the program full path,
     *  and do all the presetting the first time thru only.
     */
    if ((pOpts->fOptSet & OPTPROC_INITDONE) == 0) {
        pOpts->origArgCt   = (unsigned int)argCt;
        pOpts->origArgVect = argVect;
        pOpts->fOptSet    |= OPTPROC_INITDONE;
        if (HAS_pzPkgDataDir(pOpts))
            program_pkgdatadir = pOpts->pzPkgDataDir;

        if (! SUCCESSFUL(doPresets(pOpts)))
            return 0;

        /*
         *  IF option name conversion was suppressed but it is not suppressed
         *  for the command line, then it's time to translate option names.
         *  Usage text will not get retranslated.
         */
        if (  ((pOpts->fOptSet & OPTPROC_TRANSLATE) != 0)
           && (pOpts->pTransProc != NULL)
           && ((pOpts->fOptSet & OPTPROC_NO_XLAT_MASK)
              == OPTPROC_NXLAT_OPT_CFG)  )  {

            pOpts->fOptSet &= ~OPTPROC_NXLAT_OPT_CFG;
            (*pOpts->pTransProc)();
        }

        if ((pOpts->fOptSet & OPTPROC_REORDER) != 0)
            optionSort(pOpts);

        pOpts->curOptIdx   = 1;
        pOpts->pzCurOpt    = NULL;
    }

    /*
     *  IF we are (re)starting,
     *  THEN reset option location
     */
    else if (pOpts->curOptIdx <= 0) {
        pOpts->curOptIdx = 1;
        pOpts->pzCurOpt  = NULL;
    }

    if (! SUCCESSFUL(regular_opts(pOpts)))
        return pOpts->origArgCt;

    /*
     *  IF    there were no errors
     *    AND we have RC/INI files
     *    AND there is a request to save the files
     *  THEN do that now before testing for conflicts.
     *       (conflicts are ignored in preset options)
     */
    if (  (pOpts->specOptIdx.save_opts != NO_EQUIVALENT)
       && (pOpts->specOptIdx.save_opts != 0)) {
        tOptDesc*  pOD = pOpts->pOptDesc + pOpts->specOptIdx.save_opts;

        if (SELECTED_OPT(pOD)) {
            optionSaveFile(pOpts);
            exit(EXIT_SUCCESS);
        }
    }

    /*
     *  IF we are checking for errors,
     *  THEN look for too few occurrences of required options
     */
    if ((pOpts->fOptSet & OPTPROC_ERRSTOP) != 0) {
        if (! is_consistent(pOpts))
            (*pOpts->pUsageProc)(pOpts, EXIT_FAILURE);
    }

    return pOpts->curOptIdx;
}

/*
 * Local Variables:
 * mode: C
 * c-file-style: "stroustrup"
 * indent-tabs-mode: nil
 * End:
 * end of autoopts/autoopts.c */
