# Target: SPARC running VxWorks

TDEPFILES= sparc-tdep.o remote-vx.o remote-vxsparc.o xdr_ld.o xdr_ptrace.o xdr_rdb.o
TM_FILE= tm-vxsparc.h
VPATH += vx-share
