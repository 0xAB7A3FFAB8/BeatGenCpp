g++ -c -o BeatGen.o BeatGen.cpp

ar rcs libBeatGen.a BeatGen.o

g++ -c -o BeatGenReader.o BeatGenReader.cpp

ar rcs libBeatGenReader.a BeatGenReader.o

g++ test.cpp libBeatGen.a libBeatGenReader.a -o test.exe 

