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
    movingobj.cpp \
    brickwall.cpp


HEADERS += \
    object.h \
    movingobj.h \
    stationaryobj.h \
    brickwall.h
