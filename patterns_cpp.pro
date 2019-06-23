
INCLUDEPATH += \
    includes

HEADERS += \
    includes/Singleton.h \
    includes/Factory.h \
    includes/Observer.h \
    includes/Pubsub.h \
    includes/PublisherIntf.h \
    includes/SensorDataProviderIntf_2.h \
    includes/SensorDataProvider_2.h \
    includes/SensorDataPublisher_1.h

SOURCES += \
    main.cpp \
    src/Singleton.cpp \
    src/Factory.cpp \
    src/Observer.cpp \
    src/Pubsub.cpp \
    src/SensorDataProvider_2.cpp \
    src/SensorDataPublisher_1.cpp

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
