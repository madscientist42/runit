#include <sys/types.h>

#if defined(HASUTMPX) && !defined(HASUTMP)

/* FreeBSD migrated to utmpx- thing is that this doesn't play nice with
   all "Unices" because some distributions have the header.  If both are
   present, for now, pick the utmp.h path... */

#include <utmpx.h>

#ifdef _PATH_UTMPX
#define UW_TMP_UFILE _PATH_UTMPX    /* utmpx does not separate utmp and wtmp, woe later! */
#define UW_TMP_WFILE _PATH_UTMPX
#endif

#ifndef ut_time
#define ut_time ut_tv.tv_sec
#endif
typedef struct utmpx uw_tmp;

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
