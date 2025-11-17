cmake_minimum_required (VERSION 3.18) 
cmake_policy(SET CMP0079 NEW)

set(CMAKE_TOOLCHAIN_FILE "D:/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")

#project
project(ct_recon) 
set(CMAKE_CXX_FLAGS_RELEASE "/O2 /MD /D_ITERATOR_DEBUG_LEVEL=0")
set(CMAKE_C_FLAGS_RELEASE "/O2 /MD /D_ITERATOR_DEBUG_LEVEL=0")
set(CUDA_NVCC_FLAGS_RELEASE "-O3 -Xcompiler=\"/MD\"")

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /Zi")
set(CMAKE_SHARED_LINKER_FLAGS_DEBUG "${CMAKE_SHARED_LINKER_FLAGS_DEBUG} /DEBUG")

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Zi")
set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "${CMAKE_SHARED_LINKER_FLAGS_RELEASE} /DEBUG")

# For executable debug info
set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} /DEBUG")
set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} /DEBUG")

# For RelWithDebInfo builds
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "/MD /Zi /O2")
set(CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO "/DEBUG")

#set project output directory
SET(PROJECT_OUTPUT_DIR "${PROJECT_BINARY_DIR}/../output")
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_OUTPUT_DIR}")
set(LIBRARY_OUTPUT_PATH "${PROJECT_OUTPUT_DIR}")
set(RUNTIME_OUTPUT_DIRECTORY "${PROJECT_OUTPUT_DIR}")
message(STATUS "PROJECT_OUTPUT_DIR: " ${PROJECT_OUTPUT_DIR})

#build setting: just unicode version
add_definitions(-D_BIND_TO_CURRENT_VCLIBS_VERSION=1)
add_definitions(-D_UNICODE -DUNICODE)
SET(CMAKE_DEBUG_POSTFIX d)
if("${CMAKE_SIZEOF_VOID_P}" EQUAL "8")	
	if (WIN32)
        set(WINXXBITS Win64)
        set(util_postfix _64)
        message(STATUS "Target is 64 bits")
    endif(WIN32)
else("${CMAKE_SIZEOF_VOID_P}" EQUAL "8")
	if (WIN32)
        set(WINXXBITS Win32)
        set(util_postfix _32)
        message(STATUS "Target is 32 bits")
    endif(WIN32)
endif("${CMAKE_SIZEOF_VOID_P}" EQUAL "8")

#openmp
include (FindOpenMP)
if (OPENMP_FOUND)
      message("build with openmp")
      set (HAVE_OPENMP TRUE)
      set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
      set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
endif()

#cmake folder
set_property(GLOBAL PROPERTY USE_FOLDERS ON) 

#cuda
if(NOT DEFINED CMAKE_CUDA_ARCHITECTURES)
  set(CMAKE_CUDA_ARCHITECTURES 52 61 70 75 80 86 89 90)
endif()

add_definitions(-D_ALLOW_COMPILER_AND_STL_VERSION_MISMATCH)

#qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets)
FILE(COPY ${_qt5Widgets_install_prefix}/bin/Qt5Cored.dll DESTINATION ${PROJECT_OUTPUT_DIR}/debug/)
# FILE(COPY ${_qt5Widgets_install_prefix}/bin/Qt5Widgetsd.dll DESTINATION ${PROJECT_OUTPUT_DIR}/debug/)
# FILE(COPY ${_qt5Widgets_install_prefix}/bin/Qt5Guid.dll DESTINATION ${PROJECT_OUTPUT_DIR}/debug/)
# FILE(COPY ${_qt5Widgets_install_prefix}/bin/Qt5Chartsd.dll DESTINATION ${PROJECT_OUTPUT_DIR}/debug/)
FILE(COPY ${_qt5Widgets_install_prefix}/bin/Qt5Core.dll DESTINATION ${PROJECT_OUTPUT_DIR}/release/)
# FILE(COPY ${_qt5Widgets_install_prefix}/bin/Qt5Widgets.dll DESTINATION ${PROJECT_OUTPUT_DIR}/release/)
# FILE(COPY ${_qt5Widgets_install_prefix}/bin/Qt5Gui.dll DESTINATION ${PROJECT_OUTPUT_DIR}/release/)
# FILE(COPY ${_qt5Widgets_install_prefix}/bin/Qt5Charts.dll DESTINATION ${PROJECT_OUTPUT_DIR}/release/)
# FILE(COPY ${_qt5Widgets_install_prefix}/bin/Qt5Quickd.dll DESTINATION ${PROJECT_OUTPUT_DIR}/debug/)
# FILE(COPY ${_qt5Widgets_install_prefix}/bin/Qt5Quick.dll DESTINATION ${PROJECT_OUTPUT_DIR}/release/)
# FILE(COPY ${_qt5Widgets_install_prefix}/bin/Qt5QuickWidgetsd.dll DESTINATION ${PROJECT_OUTPUT_DIR}/debug/)
# FILE(COPY ${_qt5Widgets_install_prefix}/bin/Qt5QuickWidgets.dll DESTINATION ${PROJECT_OUTPUT_DIR}/release/)
# FILE(COPY ${_qt5Widgets_install_prefix}/bin/Qt5WebEngineCored.dll DESTINATION ${PROJECT_OUTPUT_DIR}/debug/)
# FILE(COPY ${_qt5Widgets_install_prefix}/bin/Qt5WebEngineCore.dll DESTINATION ${PROJECT_OUTPUT_DIR}/release/)
# FILE(COPY ${_qt5Widgets_install_prefix}/bin/Qt5PrintSupportd.dll DESTINATION ${PROJECT_OUTPUT_DIR}/debug/)
# FILE(COPY ${_qt5Widgets_install_prefix}/bin/Qt5PrintSupport.dll DESTINATION ${PROJECT_OUTPUT_DIR}/release/)
# FILE(COPY ${_qt5Widgets_install_prefix}/bin/Qt5Networkd.dll DESTINATION ${PROJECT_OUTPUT_DIR}/debug/)
# FILE(COPY ${_qt5Widgets_install_prefix}/bin/Qt5Network.dll DESTINATION ${PROJECT_OUTPUT_DIR}/release/)
# FILE(COPY ${_qt5Widgets_install_prefix}/bin/Qt5Qmld.dll DESTINATION ${PROJECT_OUTPUT_DIR}/debug/)
# FILE(COPY ${_qt5Widgets_install_prefix}/bin/Qt5Qml.dll DESTINATION ${PROJECT_OUTPUT_DIR}/release/)

# FILE(COPY ${_qt5Widgets_install_prefix}/bin/Qt5Positioningd.dll DESTINATION ${PROJECT_OUTPUT_DIR}/debug/)
# FILE(COPY ${_qt5Widgets_install_prefix}/bin/Qt5Positioning.dll DESTINATION ${PROJECT_OUTPUT_DIR}/release/)
# FILE(COPY ${_qt5Widgets_install_prefix}/bin/Qt5WebEngineWidgetsd.dll DESTINATION ${PROJECT_OUTPUT_DIR}/debug/)
# FILE(COPY ${_qt5Widgets_install_prefix}/bin/Qt5WebEngineWidgets.dll DESTINATION ${PROJECT_OUTPUT_DIR}/release/)
# FILE(COPY ${_qt5Widgets_install_prefix}/bin/Qt5WinExtrasd.dll DESTINATION ${PROJECT_OUTPUT_DIR}/debug/)
# FILE(COPY ${_qt5Widgets_install_prefix}/bin/Qt5WinExtras.dll DESTINATION ${PROJECT_OUTPUT_DIR}/release/)
# FILE(COPY ${_qt5Widgets_install_prefix}/bin/Qt5WebChanneld.dll DESTINATION ${PROJECT_OUTPUT_DIR}/debug/)
# FILE(COPY ${_qt5Widgets_install_prefix}/bin/Qt5WebChannel.dll DESTINATION ${PROJECT_OUTPUT_DIR}/release/)
# FILE(COPY ${_qt5Widgets_install_prefix}/bin/Qt5OpenGLd.dll DESTINATION ${PROJECT_OUTPUT_DIR}/debug/)
# FILE(COPY ${_qt5Widgets_install_prefix}/bin/Qt5OpenGL.dll DESTINATION ${PROJECT_OUTPUT_DIR}/release/)
# FILE(COPY ${_qt5Widgets_install_prefix}/bin/Qt5Sqld.dll DESTINATION ${PROJECT_OUTPUT_DIR}/debug/)
# FILE(COPY ${_qt5Widgets_install_prefix}/bin/Qt5Sql.dll DESTINATION ${PROJECT_OUTPUT_DIR}/release/)
# FILE(COPY ${_qt5Widgets_install_prefix}/bin/Qt5Xmld.dll DESTINATION ${PROJECT_OUTPUT_DIR}/debug/)
# FILE(COPY ${_qt5Widgets_install_prefix}/bin/Qt5Xml.dll DESTINATION ${PROJECT_OUTPUT_DIR}/release/)
# FILE(COPY ${_qt5Widgets_install_prefix}/bin/Qt5Svgd.dll DESTINATION ${PROJECT_OUTPUT_DIR}/debug/)
# FILE(COPY ${_qt5Widgets_install_prefix}/bin/Qt5Svg.dll DESTINATION ${PROJECT_OUTPUT_DIR}/release/)

option(build_test "Build test" ON)
if(build_test)
    subdirs(test)
endif(build_test)

subdirs(BackprojectionFDK)
