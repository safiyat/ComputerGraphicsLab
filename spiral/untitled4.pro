TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

LIBS += -lglut -lGL -lGLU

include(deployment.pri)
qtcAddDeployment()

