# Declare the runit libraries...
#
# (All runit core lib functions are static linkages based on original build system...)
ADD_LIBRARY(unix OBJECT
	alloc.c
	alloc_re.c
	buffer.c
	buffer_0.c
	buffer_1.c
	buffer_2.c
	buffer_get.c
	buffer_put.c
	buffer_read.c
	buffer_write.c
	coe.c
	env.c
	error.c
	error_str.c
	fd_copy.c
	fd_move.c
	fifo.c
	lock_ex.c
	lock_exnb.c
	ndelay_off.c
	ndelay_on.c
	open_append.c
	open_read.c
	open_trunc.c
	open_write.c
	openreadclose.c
	pathexec_env.c
	pathexec_run.c
	prot.c
    pmatch.c
	readclose.c
	seek_set.c
	sgetopt.c
	sig.c
	sig_block.c
	sig_catch.c
	sig_pause.c
	stralloc_cat.c
	stralloc_catb.c
	stralloc_cats.c
	stralloc_eady.c
	stralloc_opyb.c
	stralloc_opys.c
	stralloc_pend.c
	strerr_die.c
	strerr_sys.c
	subgetopt.c
	uidgid.c
	wait_nohang.c
	wait_pid.c)



