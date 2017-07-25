# Declare the runit libraries...
ADD_SUBDIRECTORY(byte)
ADD_SUBDIRECTORY(time)
ADD_SUBDIRECTORY(unix)

ADD_LIBRARY(runit_runtime $<TARGET_OBJECTS:byte> $<TARGET_OBJECTS:time> $<TARGET_OBJECTS:unix>)
