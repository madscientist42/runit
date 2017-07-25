# Declare the runit libraries...
#
# (All runit core lib functions are static linkages based on original build system...)
ADD_LIBRARY(byte OBJECT
	byte_chr.c
	byte_copy.c
	byte_cr.c
	byte_diff.c
	byte_rchr.c
	fmt_uint.c
	fmt_uint0.c
	fmt_ulong.c
	scan_ulong.c
	str_chr.c
	str_diff.c
	str_len.c
	str_start.c)


