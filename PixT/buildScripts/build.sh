mkdir build 
cd build
cmake.exe ../Game 
cmake --build . 
cp PixGame.exe "../$1.exe"