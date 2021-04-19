QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Command.cpp \
    main.cpp \
    mainwindow.cpp \


HEADERS += \
    Command.h \
    mainwindow.h \


FORMS += \
    mainwindow.ui



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target






win64:CONFIG(release, debug|release): LIBS += -L$$PWD/../../source/repos/SubstringSearchAlgorithms/release/ -lSubstringSearchAlgorithms
else:win64:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../source/repos/SubstringSearchAlgorithms/debug/ -lSubstringSearchAlgorithms
else:unix: LIBS += -L$$PWD/../../source/repos/SubstringSearchAlgorithms/ -lSubstringSearchAlgorithms

INCLUDEPATH += $$PWD/../../source/repos/SubstringSearchAlgorithms
DEPENDPATH += $$PWD/../../source/repos/SubstringSearchAlgorithms
