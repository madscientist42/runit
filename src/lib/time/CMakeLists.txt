# Declare the runit libraries...
#
# (All runit core lib functions are static linkages based on original build system...)
ADD_LIBRARY(time OBJECT
	iopause.c
	tai_now.c
	tai_pack.c
	tai_sub.c
	tai_unpack.c
	taia_add.c
	taia_approx.c
	taia_frac.c
	taia_less.c
	taia_now.c
	taia_pack.c
	taia_sub.c
	taia_uint.c)


