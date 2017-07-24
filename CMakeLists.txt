# a version for testing with later cmake, EXPERIMENTAL....

CMAKE_MINIMUM_REQUIRED (VERSION 2.8)
PROJECT (runit)
set(VERSION "2.2.0")

# Specify where we're dropping things- the end-user of this system
# can specify elsewhere, but we're going to pour it here to make
# it easier on us...
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)

# Do our up-front config checks...
INCLUDE(ConfigureChecks.cmake)
INCLUDE(GNUInstallDirs)

ADD_DEFINITIONS(-DETC_PREFIX="${CMAKE_INSTALL_FULL_SYSCONFDIR}")
ADD_DEFINITIONS(-DPROJECT_VERSION="${PROJECT}") 

# Add the various subdirectories for sourcecode, etc...
ADD_SUBDIRECTORY(src)

