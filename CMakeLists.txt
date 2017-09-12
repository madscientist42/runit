# a version for testing with later cmake, EXPERIMENTAL....

CMAKE_MINIMUM_REQUIRED (VERSION 2.8.8)
PROJECT (runit C)
set(VERSION "2.1.3")

# Specify where we're dropping things- the end-user of this system
# can specify elsewhere, but we're going to pour it here to make
# it easier on us...
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
    SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)
endif()

# Do our up-front config checks...
INCLUDE(GNUInstallDirs)
INCLUDE(ConfigureChecks.cmake)

# Declare our project's additional include path entries...
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_BINARY_DIR}/include)

# Add the various subdirectories for sourcecode, etc...
ADD_SUBDIRECTORY(src)

add_custom_target(dist
    WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
    COMMAND "${CMAKE_COMMAND}" -E remove -F "${CMAKE_CURRENT_BINARY_DIR}/runit-*.tar.gz"
    COMMAND git archive -o "${CMAKE_CURRENT_BINARY_DIR}/runit-${VERSION}.tar.gz" --format tar.gz --prefix="runit-${VERSION}/" HEAD
)

