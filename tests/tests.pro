QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  tst_tests.cpp

win64:CONFIG(release, debug|release): LIBS += -L$$PWD/../../paterns/lab2_Patterns/SubstringSearchAlgorithms/ -lSubstringSearchAlgorithms
else:win64:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../paterns/lab2_Patterns/SubstringSearchAlgorithms/ -lSubstringSearchAlgorithmsd
else:unix: LIBS += -L$$PWD/../../paterns/lab2_Patterns/SubstringSearchAlgorithms/ -lSubstringSearchAlgorithms

INCLUDEPATH += $$PWD/../../paterns/lab2_Patterns/SubstringSearchAlgorithms
DEPENDPATH += $$PWD/../../paterns/lab2_Patterns/SubstringSearchAlgorithms
