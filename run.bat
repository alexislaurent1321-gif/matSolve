@echo off
echo Compilation


cmake -B build 
cmake --build build --config Release   
.\build\Release\MatrixProject.exe   