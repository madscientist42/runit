include(CheckIncludeFile)
include(CheckSymbolExists)
include(CheckTypeSize)


# Do our checks.  This takes the "odd" out of the build process..

# Some things work by knowing that we have a header...
check_include_file(dirent.h     HASDIRENT)
check_include_file(poll.h		HASPOLL)
check_include_file(sys/select.h HASSYSSELECT)
check_include_file(utmp.h      HASUTMP)
check_include_file(utmpx.h      HASUTMPX)

# Some things work by checking for it in the right header...
check_symbol_exists(mkfifo	"sys/stat.h"  		HASMKFIFO)
check_symbol_exists(flock	"sys/file.h"        	HASFLOCK)
check_symbol_exists(sigprocmask	"signal.h"		HASSIGPROCMASK)
check_symbol_exists(sigaction	"signal.h"		HASSIGACTION)
check_symbol_exists(waitpid	"sys/wait.h"		HASWAITPID)

# Some things work by checking size of types...
check_type_size("long" SIZEOF_LONG)
MESSAGE(STATUS "Size of 'long' is ${SIZEOF_LONG} bytes")
# So, what is the size of "long"?   32 or 64...?
if(SIZEOF_LONG EQUAL 4)
	SET(UINT64_TYPEDEF "long long")
else (SIZEOF_LONG EQUAL 4)
	if (SIZEOF_LONG EQUAL 8)
		SET(UINT64_TYPEDEF "long")
	else (SIZEOF_LONG EQUAL 8)
		message (FATAL_ERROR "Could not find a 64-bit integer type")
	endif (SIZEOF_LONG EQUAL 8)
endif (SIZEOF_LONG EQUAL 4)

# Jam out a config.h
CONFIGURE_FILE(include/config.h.in ${CMAKE_BINARY_DIR}/include/config.h)
