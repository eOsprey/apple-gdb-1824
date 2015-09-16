/* sun3-xdep.c
   Sun-3 Machine-dependent code which would otherwise be in inflow.c and core.c,
   for GDB, the GNU debugger.
   Copyright (C) 1986, 1987, 1989 Free Software Foundation, Inc.

This file is part of GDB.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

#include <stdio.h>
#include "defs.h"
#include "param.h"
#include "inferior.h"

#include <sys/ptrace.h>
#define KERNEL		/* To get floating point reg definitions */
#include <machine/reg.h>

#include "gdbcore.h"

extern int errno;

#if defined (GDB_TARGET_IS_SUN3)
/* All of this stuff is only relevant if both host and target are sun3.  */
void
fetch_inferior_registers ()
{
  struct regs inferior_registers;
#ifdef FP0_REGNUM
  struct fp_status inferior_fp_registers;
#endif /* FP0_REGNUM */
  extern char registers[];

  registers_fetched ();

  ptrace (PTRACE_GETREGS, inferior_pid, &inferior_registers);
#ifdef FP0_REGNUM
  ptrace (PTRACE_GETFPREGS, inferior_pid, &inferior_fp_registers);
#endif  /* FP0_REGNUM */

  bcopy (&inferior_registers, registers, 16 * 4);
#ifdef FP0_REGNUM
  bcopy (&inferior_fp_registers, &registers[REGISTER_BYTE (FP0_REGNUM)],
	 sizeof inferior_fp_registers.fps_regs);
#endif  /* FP0_REGNUM */
  *(int *)&registers[REGISTER_BYTE (PS_REGNUM)] = inferior_registers.r_ps;
  *(int *)&registers[REGISTER_BYTE (PC_REGNUM)] = inferior_registers.r_pc;
#ifdef FP0_REGNUM
  bcopy (&inferior_fp_registers.fps_control,
	 &registers[REGISTER_BYTE (FPC_REGNUM)],
	 sizeof inferior_fp_registers - sizeof inferior_fp_registers.fps_regs);
#endif  /* FP0_REGNUM */
}

/* Store our register values back into the inferior.
   If REGNO is -1, do this for all registers.
   Otherwise, REGNO specifies which register (so we can save time).  */

store_inferior_registers (regno)
     int regno;
{
  struct regs inferior_registers;
#ifdef FP0_REGNUM
  struct fp_status inferior_fp_registers;
#endif /* FP0_REGNUM */
  extern char registers[];

  bcopy (registers, &inferior_registers, 16 * 4);
#ifdef FP0_REGNUM
  bcopy (&registers[REGISTER_BYTE (FP0_REGNUM)], &inferior_fp_registers,
	 sizeof inferior_fp_registers.fps_regs);
#endif /* FP0_REGNUM */
  inferior_registers.r_ps = *(int *)&registers[REGISTER_BYTE (PS_REGNUM)];
  inferior_registers.r_pc = *(int *)&registers[REGISTER_BYTE (PC_REGNUM)];

#ifdef FP0_REGNUM
  bcopy (&registers[REGISTER_BYTE (FPC_REGNUM)],
	 &inferior_fp_registers.fps_control,
	 sizeof inferior_fp_registers - sizeof inferior_fp_registers.fps_regs);
#endif /* FP0_REGNUM */

  ptrace (PTRACE_SETREGS, inferior_pid, &inferior_registers);
#if FP0_REGNUM
  ptrace (PTRACE_SETFPREGS, inferior_pid, &inferior_fp_registers);
#endif /* FP0_REGNUM */
}

/* Machine-dependent code for pulling registers out of a Sun-3 core file. */

void
fetch_core_registers (core_reg_sect, core_reg_size, which)
     char *core_reg_sect;
     unsigned core_reg_size;
     int which;
{
  extern char registers[];
  struct regs *regs = (struct regs *) core_reg_sect;

  if (which == 0) {
	  if (core_reg_size < sizeof (struct regs)) {
		  error ("Cannot find registers in core file");
	  }

    bcopy ((char *)regs, registers, 16 * 4);
    supply_register (PS_REGNUM, &regs->r_ps);
    supply_register (PC_REGNUM, &regs->r_pc);

  } else if (which == 2) {

#define fpustruct  ((struct fpu *) core_reg_sect)

    if (core_reg_size >= sizeof (struct fpu))
      {
#ifdef FP0_REGNUM
	bcopy (fpustruct->f_fpstatus.fps_regs,
	      &registers[REGISTER_BYTE (FP0_REGNUM)],
	      sizeof fpustruct->f_fpstatus.fps_regs);
	bcopy (&fpustruct->f_fpstatus.fps_control,
	      &registers[REGISTER_BYTE (FPC_REGNUM)],
	      sizeof fpustruct->f_fpstatus -
		sizeof fpustruct->f_fpstatus.fps_regs);
#endif /* FP0_REGNUM */
      }
    else
      fprintf (stderr, "Could NOT read float regs from core file\n");
  }
}
#else /* Not sun3 target.  */
/* These functions should NOT be called when we are cross-debugging.  */

void
fetch_inferior_registers ()
{
}

/* ARGSUSED */
store_inferior_registers (regno)
     int regno;
{
}

/* ARGSUSED */
void
fetch_core_registers (core_reg_sect, core_reg_size, which)
     char *core_reg_sect;
     unsigned core_reg_size;
     int which;
{
}
#endif /* Not sun3 target.  */

/* EOF */
