/* Public domain. */

#include <errno.h>
#include <unistd.h>
#include "stralloc.h"
#include "str.h"
#include "env.h"
#include "pathexec.h"

static stralloc tmp;

void pathexec_run(const char *file,const char * const *argv,const char * const *envp)
{
  const char *path;
  unsigned int split;
  int savederrno;

  if (file[str_chr(file,'/')]) {
    execve(file,(char *const*)argv,(char *const*)envp);
    return;
  }

  path = env_get("PATH");
  if (!path) path = "/bin:/usr/bin";

  savederrno = 0;
  for (;;) {
    split = str_chr(path,':');
    if (!stralloc_copyb(&tmp,path,split)) return;
    if (!split)
      if (!stralloc_cats(&tmp,".")) return;
    if (!stralloc_cats(&tmp,"/"))  return;
    if (!stralloc_cats(&tmp,file)) return;
    if (!stralloc_0(&tmp)) return;

    execve(tmp.s,(char *const*)argv,(char*const*)envp);
    if (errno != ENOENT) {
      savederrno = errno;
      if ((errno != EACCES) && (errno != EPERM) && (errno != EISDIR)) return;
    }

    if (!path[split]) {
      if (savederrno) errno = savederrno;
      return;
    }
    path += split;
    path += 1;
  }
}
