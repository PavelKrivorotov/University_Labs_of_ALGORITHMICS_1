TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        processor.cpp \
        stack.cpp \
        stackitem.cpp \
        task.cpp \
        turn.cpp \
        turnitem.cpp

HEADERS += \
    processor.h \
    stack.h \
    stackitem.h \
    task.h \
    turn.h \
    turnitem.h
