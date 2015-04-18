TEMPLATE = app

QT += qml quick widgets sql

SOURCES += main.cpp \
    recipe.cpp \
    RecipeReader.cpp \
    mashstep.cpp \
    recipemanager.cpp \
    GPIO.cpp \
    Temp_Probe.cpp \
    Timer.cpp \
    qthermocouple.cpp \
    qtimer.cpp \
    qthermocouplemanager.cpp \
    levelsensor.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML2_IMPORT_PATH += $$PWD/../qml-extras/modules
QML2_IMPORT_PATH += $$PWD/../qml-material/modules
# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    RecipeReader.h \
    recipe.h \
    mashstep.h \
    recipemanager.h \
    GPIO.h \
    Timer.h \
    Temp_Probe.h \
    qthermocouple.h \
    qtimer.h \
    qthermocouplemanager.h \
    levelsensor.h

INCLUDEPATH += $$PWD/../qdjango/src/db

unix:!macx: LIBS += -L$$PWD/../qdjango/build/src/http/ -lqdjango-http

INCLUDEPATH += $$PWD/../qdjango/build/src/http
DEPENDPATH += $$PWD/../qdjango/build/src/http

unix:!macx: LIBS += -L$$PWD/../qdjango/build/src/script/ -lqdjango-script

INCLUDEPATH += $$PWD/../qdjango/build/src/script
DEPENDPATH += $$PWD/../qdjango/build/src/script

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../qdjango/build/src/db/release/ -lqdjango-db
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../qdjango/build/src/db/debug/ -lqdjango-db
else:unix: LIBS += -L$$PWD/../qdjango/build/src/db/ -lqdjango-db

INCLUDEPATH += $$PWD/../qdjango/build/src/db
DEPENDPATH += $$PWD/../qdjango/build/src/db
