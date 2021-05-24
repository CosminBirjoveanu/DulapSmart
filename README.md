# SmartDrobe
 
## Prerequisites
 
This ReadMe assumes that you have CLion, g++, Git, CMake and Curl installed 
 
 
## Running the application
 
1. Install Pistache.io
 
Open a terminal window and paste this code:
 
```bash
sudo apt-get install libcurl4-openssl-dev -y
git clone --recurse-submodules https://github.com/pistacheio/pistache.git
cd pistache
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
sudo make install
```
 
2. Clone the github repository into CLion: 
[https://github.com/CosminBirjoveanu/SmartDrobe.git](https://github.com/CosminBirjoveanu/SmartDrobe.git)
