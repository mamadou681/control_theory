QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

greaterThan(QT_MAJOR_VERSION, 4): CONFIG += c++11
lessThan(QT_MAJOR_VERSION, 5): QMAKE_CXXFLAGS += -std=c++11

#TARGET = sharedlib-usage
#TEMPLATE = app

# Tell the qcustomplot header that it will be used as library:
DEFINES += QCUSTOMPLOT_USE_LIBRARY

# Platform-specific configurations
QCPLIB = $$PWD/qcustomplot
win32 {
    # Define paths for Windows
    DESTDIR_build = $$OUT_PWD
    DESTDIR_WIN = $$replace(DESTDIR_build, "/", "\\")
    QCPLIB_WIN = $$replace(QCPLIB, "/", "\\")



    INCLUDEPATH +=$$QCPLIB/include
    CONFIG(debug, release|debug) {
        LIBS += -L$$QCPLIB/libs/windows/ -lqcustomplotd2
        # Add post-build commands to copy the appropriate DLL
        QMAKE_POST_LINK += $$escape_expand(\\n) xcopy \"$$QCPLIB_WIN\\libs\\windows\\*.dll\" \"$$DESTDIR_WIN\\debug\" /Y $$escape_expand(\\n)
    } else {
        LIBS += -L$$QCPLIB/libs/windows/ -lqcustomplot2
        message("DESTDIR_WIN  is: $$DESTDIR_WIN")
        message("QCPLIB_WIN: $$QCPLIB_WIN")
        # Add post-build commands to copy the appropriate DLL
        QMAKE_POST_LINK += $$escape_expand(\\n) xcopy \"$$QCPLIB_WIN\\libs\\windows\\*.dll\" \"$$DESTDIR_WIN\\release\" /Y $$escape_expand(\\n)
    }
} else:unix {
   INCLUDEPATH +=$$QCPLIB/include
    CONFIG(debug, release|debug) {
        LIBS += -L$$QCPLIB/libs/linux -lqcustomplotd
    } else {
        LIBS += -L$$QCPLIB/libs/linux -lqcustomplot
    }
} else:android {
    ANDROID_EXTRA_LIBS += $$PWD/libs/android/armeabi-v7a/libqcustomplot.so \
                          $$PWD/libs/android/arm64-v8a/libqcustomplot.so
}

SOURCES += \
    qcustomplot/QCustomplotWrapper.cpp


HEADERS += \
    qcustomplot/QCustomplotWrapper.h
