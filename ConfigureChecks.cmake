include(CheckIncludeFile) 
include(CheckSymbolExists) 


# Do our checks.  This takes the "odd" out of the build process..
check_include_file(dirent.h     HASDIRENT)
check_include_file(poll.h	HASPOLL)

check_symbol_exists(mkfifo	"sys/stat.h"  		HASMKFIFO)
check_symbol_exists(flock	"sys/file.h"        	HASFLOCK)
check_symbol_exists(sigprocmask	"signal.h"		HASSIGPROCMASK)
check_symbol_exists(sigaction	"signal.h"		HASSIGACTION)


# Jam out a config.h in the sources directory...
CONFIGURE_FILE(src/config.h.in src/config.h)
