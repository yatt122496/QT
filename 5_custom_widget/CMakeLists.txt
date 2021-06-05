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

if(!win32)
	SET(CMAKE_SYSTEM_NAME Linux)
	SET(CMAKE_C_COMPILER "arm-linux-gnueabihf-gcc")
	SET(CMAKE_CXX_COMPILER "arm-linux-gnueabihf-g++")
endif(!win32)

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

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(SRC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/source/src)
set(INC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/source/inc)
set(QRC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/source/qrc)

qt5_add_resources(QRC_FILES
	${QRC_PATH}/application.qrc
)

AUX_SOURCE_DIRECTORY(${SRC_PATH} QT_SOURCE_FILES)
# set(QT_SOURCE_FILES
# 	${SRC_PATH}/main.cpp
# 	${SRC_PATH}/mainwindow.cpp
# 	${SRC_PATH}/tabwidget.cpp
# 	${SRC_PATH}/mainwindow.ui
# 	${SRC_PATH}/analogclock.cpp
# 	${SRC_PATH}/Dockwidget.cpp
# 	${SRC_PATH}/drawwidget.cpp
# )

set(QT_HEADER_FILES
	${INC_PATH}/tabwidget.h
	${INC_PATH}/mainwindow.h
	${INC_PATH}/analogclock.h
	${INC_PATH}/Dockwidget.h
	${INC_PATH}/drawwidget.h
)

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

target_link_libraries(${CMAKE_TARGET} PRIVATE Qt5::Widgets)

