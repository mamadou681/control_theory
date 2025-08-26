QT += quick

greaterThan(QT_MAJOR_VERSION, 4): QT += printsupport
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/AverageFilter.cpp \
    src/EKF.cpp \
    src/FilterInfo.cpp \
    src/FilterManager.cpp \
    src/IMUReader.cpp \
    src/KalmanFilter.cpp \
    src/LowPassFilter.cpp \
    src/MovingAverageFilter.cpp \
    src/QmlObjectListModel.cpp \
    src/SensorData.cpp \
    src/main.cpp \
#    qcustomplot/QCustomplotWrapper.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#HEADERS += \
#    qcustomplot/QCustomplotWrapper.h

include(qcustomplot.pri)

EIGENLIB = $$PWD/eigen
INCLUDEPATH +=$$EIGENLIB


HEADERS += \
    src/AverageFilter.h \
    src/EKF.h \
    src/FilterInfo.h \
    src/FilterManager.h \
    src/IMUReader.h \
    src/KalmanFilter.h \
    src/LowPassFilter.h \
    src/MovingAverageFilter.h \
    src/QmlObjectListModel.h \
    src/SensorData.h

DISTFILES +=

