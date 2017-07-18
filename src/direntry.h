/* Public domain. */

#ifndef DIRENTRY_H
#define DIRENTRY_H


#include <sys/types.h>
#include "config.h"
#if defined(HASDIRENT)
	#include <dirent.h>
	#define direntry struct dirent
#else
	#include <dir.h>
	#define direntry struct direct
#endif

#endif
