# Target: Sun 2, running SunOS 3
# The system-supplied assembler re-orders the symbols so that gdb
# cannot find "gcc_compiled.".
#msg If you compile your program with GCC, use the GNU assembler.
#msg
TDEPFILES= m68k-tdep.o
TM_FILE= tm-sun2.h
