sudo apt update 
sudo apt install g++-10
export CXX=g++-10
git clone https://github.com/google/googletest.git
mkdir build
cd build
cmake ..
make
./practiceUT
