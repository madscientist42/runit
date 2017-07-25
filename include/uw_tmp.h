#include <sys/types.h>

/* NOTE: FreeBSD migrated to utmpx...
   This has some different interfaces.  I have more work to do on this...   
*/

#ifdef HASUTMPX
#include <utmpx.h>
typedef struct utmpx uw_tmp;
#ifdef _PATH_UTMPX
#define UW_TMP_UFILE _PATH_UTMPX    /* utmpx does not separate utmp and wtmp, woe later! */
#define UW_TMP_WFILE _PATH_UTMPX
#endif

#else
#include <utmp.h>

#ifdef _PATH_UTMP
  #define UW_TMP_UFILE _PATH_UTMP
  #define UW_TMP_WFILE _PATH_WTMP
#else
  /* AIX only has UTMP_FILE */
  #ifdef UTMP_FILE
    #define UW_TMP_UFILE UTMP_FILE
    #define UW_TMP_WFILE WTMP_FILE
  #else
    #error neither _PATH_UTMP nor UTMP_FILE defined.
  #endif
#endif
typedef struct utmp uw_tmp;
#endif

