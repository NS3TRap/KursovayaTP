TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -L"SFML-2.5.1\bin"
LIBS += -L"SFML-2.5.1\lib"

CONFIG(release, debug|release): LIBS += -lflac -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window -lfreetype -lopenal32 -logg -lvorbis -lvorbisenc -lvorbisfile
CONFIG(debug, debug|release):   LIBS += -lflac -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window -lfreetype -lopenal32 -logg -lvorbis -lvorbisenc -lvorbisfile

INCLUDEPATH += "SFML-2.5.1\include"
DEPENDPATH += "SFML-2.5.1\include"

SOURCES += main.cpp \
    screens.cpp \
    userinterfacescreen.cpp \
    record.cpp \
    listofrecords.cpp \
    map.cpp \
    movingobj.cpp \
    player.cpp \
    bullet.cpp \
    enemy.cpp \
    brickwall.cpp \
    base.cpp \
    metalwall.cpp \
    outputrecordsscreen.cpp

HEADERS += \
    screens.h \
    userinterfacescreen.h \
    record.h \
    listofrecords.h \
    map.h \
    object.h \
    movingobj.h \
    stationaryobj.h \
    player.h \
    bullet.h \
    enemy.h \
    brickwall.h \
    base.h \
    metalwall.h \
    outputrecordsscreen.h
