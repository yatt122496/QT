cmake_minimum_required(VERSION 3.5)

STRING( REGEX REPLACE ".*/(.*)" "\\1" CURRENT_FOLDER ${CMAKE_CURRENT_SOURCE_DIR} )
set(CMAKE_TARGET ${CURRENT_FOLDER})

project(${CMAKE_TARGET} LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


if(UNIX)
	SET(CMAKE_SYSTEM_NAME Linux)
	SET(CMAKE_C_COMPILER "arm-linux-gnueabihf-gcc")
	SET(CMAKE_CXX_COMPILER "arm-linux-gnueabihf-g++")
endif()

SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

# 支持打印机需要添加 PrintSupport
# 支持网络需要添加 Network
set(QT_MODULES
	Widgets
	Network
)
find_package(Qt5 COMPONENTS ${QT_MODULES} REQUIRED)

set(SRC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/source/src)
set(INC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/source/inc)
set(QRC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/source/qrc)

qt5_add_resources(QRC_FILES
	${QRC_PATH}/application.qrc
)

FILE(GLOB QT_SOURCE_FILES "${SRC_PATH}/*.cpp")
# AUX_SOURCE_DIRECTORY(${SRC_PATH} QT_SOURCE_FILES)
# set(QT_SOURCE_FILES
# 	${SRC_PATH}/main.cpp
# 	${SRC_PATH}/mainwindow.cpp
# 	${SRC_PATH}/dialog.cpp
# 	${SRC_PATH}/stackdlg.cpp
# 	${SRC_PATH}/workspace.cpp
# )

FILE(GLOB QT_HEADER_FILES "${INC_PATH}/*.h")
# set(QT_HEADER_FILES
# 	# ${INC_PATH}/paintarea.h
# 	# ${INC_PATH}/mainwindow.h
# 	# ${INC_PATH}/image.h
# 	# ${INC_PATH}/showwidget.h
# 	# ${INC_PATH}/painter.h
# )

if(ANDROID)
  add_library(${CMAKE_TARGET} SHARED
	${QT_SOURCE_FILES}
	${QT_HEADER_FILES}
	${QRC_FILES}
  )
else()
  add_executable(${CMAKE_TARGET}
	${QT_SOURCE_FILES}
	${QT_HEADER_FILES}
	${QRC_FILES}
  )
endif()

# 支持打印机需要添加 Qt5::PrintSupport
# 支持网络需要添加 Qt5::Network
# set(Qt5_MODULES1 ${QT_MODULES})
# FOREACH(src ${Qt5_MODULES1})
# 	STRING(CONCAT Qt5_MODULES ${Qt5_MODULES} "Qt5::${src}")
# ENDFOREACH()
# STRING(STRIP ${Qt5_MODULES} Qt5_MODULES)

set(Qt5_MODULES Qt5::Widgets Qt5::Network)
message(${Qt5_MODULES})

target_link_libraries(${CMAKE_TARGET} PRIVATE ${Qt5_MODULES})
