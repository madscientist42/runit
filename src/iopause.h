/* Public domain. */

#ifndef IOPAUSE_H
#define IOPAUSE_H

#include "config.h"

#if defined(HASPOLL)
	typedef struct 
	{
		int fd;
		short events;
		short revents;
	} iopause_fd;

	#define IOPAUSE_READ 1
	#define IOPAUSE_WRITE 4
#else
	#define IOPAUSE_POLL

	#include <sys/types.h>
	#include <poll.h>

	typedef struct pollfd iopause_fd;
	#define IOPAUSE_READ POLLIN
	#define IOPAUSE_WRITE POLLOUT
#endif 

#include "taia.h"
extern void iopause(iopause_fd *,unsigned int,struct taia *,struct taia *);

#endif
