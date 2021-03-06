# SED script for preprocessing embedded headers from source 
# (S. Chamberlain markup)
# middle pass; most of the work is done here.
#
# First, get rid of /*proto* markers; they have done their job in the first pass.
# (They remain comment-introducers)
/^\/\*proto\*/s/^\/\*proto\*/\/*/
/^\/\*proto-internal\*/s/^\/\*proto-internal\*/\/*/
#
# *-*/ is an alternative (older) comment-block end.  Remap for uniformity:
s/^\*-\*\//\*\//
#
# {* and *} are standins for comment markers (originally embedded in .c 
# comments)---turn into real comment markers:
s/{\*/\/\*/
s/\*}/\*\//
#
# '*+++' and '*---' span a block of text that includes both header lines 
# (marked by leading '$') and explanatory text (to be comments).
# No need to start comment at "*+++", or end it at "*---", since we're 
# already in a *proto* comment block.  Just delete.
/\*\+\+\+/d
/\*---/d
#
# Any line beginning with '$' is made a line of code in the header; 
#  stuff in between is comments, so *precede* each '$' line with 
#  END-comment, *follow* each '$' line with START-comment; third pass later 
#  eliminates empty comment blocks.
/^\$/i\
*/
/^\$/a\
/*
#
# Now delete the '$' markers themselves:
/^\$/s/\$//
#
# *+ and *- delimit larger blocks of code, treated the same as '$' lines
/^\*\+$/c\
*/
/^\*-$/c\
/*
#
# '*;' introduces code which may have a single line or multiple lines;
# it extends until the next semicolon (which is also printed).
#
# One-line case: (do this first; else second line address for multi-line case
# will include random text til we happen to end a line in a proto comment with
# a semicolon)
/^\*;.*;$/{
s/^\*;/*\/\
/
s/;$/;\
\/*\
/
}
# Multi-line case:
/^\*;/,/.*;$/{
s/^\*;/*\/\
/
s/;$/;\
\/*\
/
}
