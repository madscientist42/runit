
# Declare our project's additional include path entries...
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -I${CMAKE_SOURCE_DIR}/include")

# Bring in/build our library components...
ADD_SUBDIRECTORY(lib)

# Now declare runit's executables proper...
ADD_EXECUTABLE(runit runit.c)
TARGET_LINK_LIBRARIES(runit runit_unix runit_byte)

ADD_EXECUTABLE(runit-init runit-init.c)
TARGET_LINK_LIBRARIES(runit-init runit_unix runit_byte)

ADD_EXECUTABLE(runsv runsv.c)
TARGET_LINK_LIBRARIES(runsv runit_unix runit_byte runit_time)

ADD_EXECUTABLE(runsvdir runsvdir.c)
TARGET_LINK_LIBRARIES(runsvdir runit_unix runit_byte runit_time)

ADD_EXECUTABLE(runsvstat runsvstat.c)
TARGET_LINK_LIBRARIES(runsvstat runit_unix runit_byte runit_time)

ADD_EXECUTABLE(runsvcrtl runsvctrl.c)
TARGET_LINK_LIBRARIES(runsvcrtl runit_unix runit_byte runit_time)

ADD_EXECUTABLE(sv sv.c)
TARGET_LINK_LIBRARIES(sv runit_unix runit_byte runit_time)

ADD_EXECUTABLE(svwaitup svwaitup.c)
TARGET_LINK_LIBRARIES(svwaitup runit_unix runit_byte runit_time)

ADD_EXECUTABLE(svwaitdown svwaitdown.c)
TARGET_LINK_LIBRARIES(svwaitdown runit_unix runit_byte runit_time)

ADD_EXECUTABLE(utmpset utmpset.c)
TARGET_LINK_LIBRARIES(utmpset runit_unix runit_byte)

ADD_EXECUTABLE(runsvchdir runsvchdir.c)
TARGET_LINK_LIBRARIES(runsvchdir runit_unix runit_byte)

ADD_EXECUTABLE(chpst chpst.c)
TARGET_LINK_LIBRARIES(chpst runit_unix runit_byte runit_time)


INSTALL(TARGETS runit runit-init runsv runsvdir runsvstat runsvcrtl sv DESTINATION ${CMAKE_INSTALL_SBINDIR})
