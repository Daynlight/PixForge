mkdir build 
cd build
cmake.exe ../../PixT/PixGame/ 
cmake --build . 
cp PixGame.exe ../$1.exe