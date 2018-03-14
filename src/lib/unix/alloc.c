/* Public domain. */

// FIXME -- Review for refactor/replace.  This is goofy and doesn't QUITE do what Gerrit thought it did.

#include <stdlib.h>
#include <errno.h>
#include "alloc.h"
#include "error.h"

#define ALIGNMENT 16 /* XXX: assuming that this alignment is enough */
#define SPACE 2048 /* must be multiple of ALIGNMENT */

typedef union { char irrelevant[ALIGNMENT]; double d; } aligned;
static aligned realspace[SPACE / ALIGNMENT];
#define space ((char *) realspace)
static unsigned int avail = SPACE; /* multiple of ALIGNMENT; 0<=avail<=SPACE */

/*@null@*//*@out@*/char *alloc(n)
unsigned int n;
{
  char *x;
  n = ALIGNMENT + n - (n & (ALIGNMENT - 1)); /* XXX: could overflow */
  if (n <= avail) { avail -= n; return space + avail; }
  x = malloc(n);
  if (!x) errno = ENOMEM;
  return x;
}

void alloc_free(x)
char *x;
{
  if (x >= space)
    if (x < space + SPACE)
      return; /* XXX: assuming that pointers are flat */
  free(x);
}
