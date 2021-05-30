QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        CPlusFactory.cpp \
        CPlusUnits.cpp \
        CSharpFactory.cpp \
        CSharpUnits.cpp \
        Compiler.cpp \
        JavaFactory.cpp \
        JavaUnits.cpp \
        Units.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    AbsFactory.h \
    CPlusFactory.h \
    CPlusUnits.h \
    CSharpFactory.h \
    CSharpUnits.h \
    Compiler.h \
    JavaFactory.h \
    JavaUnits.h \
    Units.h
