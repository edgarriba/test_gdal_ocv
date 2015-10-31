cmake_minimum_required(VERSION 2.8)

PROJECT(gdal_ocv)

FIND_PACKAGE(OpenCV REQUIRED)
INCLUDE(${OpenCV_INCLUDE_DIRS})

ADD_EXECUTABLE(gdal-image-io gdal-image-io.cpp )
TARGET_LINK_LIBRARIES(gdal-image-io ${OpenCV_LIBS})
