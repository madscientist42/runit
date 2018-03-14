/* Public domain. */

#ifndef ERROR_H
#define ERROR_H

/* 20030124: include <errno.h> -upcoming glibc changes */
#include <errno.h>
#include <string.h>
 

/* Handle Gerrit's remappings for now.  Need to be revisited properly- they're not usefully defined
 * here and in error.c when they're properly, for POSIX systems, handled by errno.h and strerror.h
 * instead of this odd configuration that is clearly to compensate for "broken" Unices      			FCE (03/13/18)
 */
extern int error_intr;
extern int error_nomem;
extern int error_noent;
extern int error_txtbsy;
extern int error_io;
extern int error_exist;
extern int error_timeout;
extern int error_inprogress;
extern int error_wouldblock;
extern int error_again;
extern int error_pipe;
extern int error_perm;
extern int error_acces;
extern int error_nodevice;
extern int error_proto;
extern int error_isdir;
extern int error_connrefused;
extern int error_notdir;


extern const char *error_str(int err);

#endif
