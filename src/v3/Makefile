GCCFLAGS=

output: test.o BeatGen.o BeatGenReader.o jsoncpp.o
	g++ -o out jsoncpp.o BeatGen.o BeatGenReader.o test.o 

test.o: test.cpp BeatGen.h BeatGenReader.h BeatGenOBJ.h BeatGenToks.h
	g++ -c test.cpp $(GCCFLAGS)

BeatGen.o: BeatGen.cpp BeatGen.h
	g++ -c BeatGen.cpp $(GCCFLAGS)

BeatGenReader.o: BeatGenReader.cpp BeatGenReader.h
	g++ -c BeatGenReader.cpp $(GCCFLAGS)

jsoncpp.o: ./dist/jsoncpp.cpp
	g++ -c ./dist/jsoncpp.cpp $(GCCFLAGS)

clean:
	rm *.o

clear:
	rm *.o out

genso:
	g++ -c BeatGenReader.cpp -fPIC $(GCCFLAGS)
	g++ -c BeatGen.cpp -fPIC $(GCCFLAGS)
	g++ -c ./dist/jsoncpp.cpp -fPIC $(GCCFLAGS) 
	g++ -shared -o libV3BeatGen.so BeatGen.o BeatGenReader.o jsoncpp.o -fPIC $(GCCFLAGS)
	rm *.o

mvso:
	sudo mv libV3BeatGen.so /usr/lib

testso:
	g++ -o out test.cpp -lV3BeatGen -L. -fPIC $(GCCFLAGS)

getlines:
	cat test.cpp BeatGen.cpp BeatGenReader.cpp BeatGenOBJ.h BeatGenToks.h BeatGen.h BeatGenReader.h | wc -l