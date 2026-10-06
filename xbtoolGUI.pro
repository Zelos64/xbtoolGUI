QT     += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    findarchive.cpp \
    jsonmanager.cpp \
    main.cpp \
    mainwindow.cpp \

HEADERS += \
    findarchive.h \
    jsonmanager.h \
    mainwindow.h \

FORMS +=

# CONFIG += lrelease
# CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    XbTool/CsvHelper.dll \
    XbTool/Data/xb1_arrays.csv \
    XbTool/Data/xb1_fieldInfo.csv \
    XbTool/Data/xb1_tableDisplay.csv \
    XbTool/Data/xb1_tableInfo.csv \
    XbTool/Data/xb2_arrays.csv \
    XbTool/Data/xb2_fieldInfo.csv \
    XbTool/Data/xb2_tableDisplay.csv \
    XbTool/Data/xb2_tableInfo.csv \
    XbTool/Data/xbx_arrays.csv \
    XbTool/Data/xbx_fieldInfo.csv \
    XbTool/Data/xbx_tableDisplay.csv \
    XbTool/Data/xbx_tableInfo.csv \
    XbTool/DotNet.Glob.dll \
    XbTool/DotNetZip.dll \
    XbTool/LibHac.dll \
    XbTool/Newtonsoft.Json.dll \
    XbTool/Npgsql.dll \
    XbTool/System.Buffers.dll \
    XbTool/System.Memory.dll \
    XbTool/System.Numerics.Vectors.dll \
    XbTool/System.Runtime.CompilerServices.Unsafe.dll \
    XbTool/System.Threading.Tasks.Extensions.dll \
    XbTool/System.ValueTuple.dll \
    XbTool/XbTool.exe
