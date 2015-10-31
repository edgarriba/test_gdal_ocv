#!/bin/bash

ROOT_PATH=`pwd`


echo "1. Install GDAL driver"

sudo apt-get -y install libgdal-dev


echo "2. Install custom OpenCV"

sudo apt-get -y install build-essential
sudo apt-get -y install cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev

cd && git clone https://github.com/edgarriba/opencv.git
git checkout gdal_lan && mkdir build && cd build
cmake -DWITH_GDAL=ON ..
sudo make -j8 install


echo "3. Build visualizer"

cd $ROOT_PATH && mkdir build && cd build && cmake .. && make
