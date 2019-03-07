# Bring in/build our library components...
ADD_SUBDIRECTORY(lib)

# Now declare runit's executables proper...
ADD_EXECUTABLE(runit runit.c)
TARGET_LINK_LIBRARIES(runit runit_runtime)

ADD_EXECUTABLE(runit-init runit-init.c)
TARGET_LINK_LIBRARIES(runit-init runit_runtime)

ADD_EXECUTABLE(runsv runsv.c)
TARGET_LINK_LIBRARIES(runsv runit_runtime)

ADD_EXECUTABLE(runsvdir runsvdir.c)
TARGET_LINK_LIBRARIES(runsvdir runit_runtime)

ADD_EXECUTABLE(runsvstat runsvstat.c)
TARGET_LINK_LIBRARIES(runsvstat runit_runtime)

ADD_EXECUTABLE(runsvcrtl runsvctrl.c)
TARGET_LINK_LIBRARIES(runsvcrtl runit_runtime)

ADD_EXECUTABLE(sv sv.c)
TARGET_LINK_LIBRARIES(sv runit_runtime)

ADD_EXECUTABLE(svwaitup svwaitup.c)
TARGET_LINK_LIBRARIES(svwaitup runit_runtime)

ADD_EXECUTABLE(svwaitdown svwaitdown.c)
TARGET_LINK_LIBRARIES(svwaitdown runit_runtime)

ADD_EXECUTABLE(utmpset utmpset.c)
TARGET_LINK_LIBRARIES(utmpset runit_runtime)

ADD_EXECUTABLE(runsvchdir runsvchdir.c)
TARGET_LINK_LIBRARIES(runsvchdir runit_runtime)

ADD_EXECUTABLE(chpst chpst.c)
TARGET_LINK_LIBRARIES(chpst runit_runtime)

ADD_EXECUTABLE(svlogd svlogd.c)
TARGET_LINK_LIBRARIES(svlogd runit_runtime)
   

# Set destinations for things...binaries go in /usr/sbin or /usr/local/sbin...
INSTALL(TARGETS
    runit
    runit-init
    runsv
    runsvdir
    runsvstat
    runsvcrtl
    sv
    svwaitup
    svwaitdown
    utmpset
    runsvchdir
    chpst
    svlogd
    DESTINATION ${CMAKE_INSTALL_SBINDIR})
