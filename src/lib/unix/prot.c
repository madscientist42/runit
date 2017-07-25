/* Public domain. */

#include <sys/types.h>
#include <unistd.h>

#include "prot.h"

// FIXME -- This is quite redundant as this is in all BSD/SYSV systems in the large...and 
// 			doesn't need to stay once we get to first functioning cut of this with the 
//			new framework (FCE 07-17-17)

int prot_gid(gid_t gid)
{
  return setgid(gid); /* _should_ be redundant, but on some systems it isn't */
}

int prot_uid(uid_t uid)
{
  return setuid(uid);
}
