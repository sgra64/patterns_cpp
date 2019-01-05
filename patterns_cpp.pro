
INCLUDEPATH += \
    includes

HEADERS += \
    includes/Singleton.h \
    includes/Factory.h \
    includes/Observer.h \
    includes/Pubsub.h \
    includes/PublisherIntf.h

SOURCES += \
    main.cpp \
    src/Singleton.cpp \
    src/Factory.cpp \
    src/Observer.cpp \
    src/Pubsub.cpp

test {
    message(Test build)

    QT += testlib
    TARGET = testmain

    HEADERS -=

    HEADERS += \
        test/testQString.h \
        test/testMyFirstTest.h \
        test/testFactory.h

    SOURCES -= \
        main.cpp

    SOURCES += \
        test/testmain.cpp \
        test/testMyFirstTest.cpp \
        test/testFactory.cpp

} else {
    message(Normal build)
}
