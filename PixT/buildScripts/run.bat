mkdir build 
cd build
cmake.exe ../Game
cmake --build . 
move PixGame.exe ../%1.exe
cd ../
%1.exe