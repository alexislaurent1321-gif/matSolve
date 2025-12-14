@echo off
echo Compilation

@REM g++ -g -o test.exe main.cpp diag.cpp Thomas.cpp climb.cpp descent.cpp Gauss.cpp LU.cpp Cholesky.cpp CG.cpp solve.cpp Complex.cpp Rational.cpp Vec.cpp Mat.cpp utils.cpp
@REM ./test.exe
@REM rm test.exe

cmake -B build 
cmake --build build --config Release   
.\build\Release\MatrixProject.exe   