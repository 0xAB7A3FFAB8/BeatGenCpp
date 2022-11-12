GCCFLAGS=

output: test.o BeatGen.o BeatGenReader.o jsoncpp.o
	g++ -o out jsoncpp.o BeatGen.o BeatGenReader.o test.o 

test.o: test.cpp BeatGen.hpp BeatGenReader.hpp BeatGenOBJ.hpp BeatGenToks.hpp
	g++ -c test.cpp $(GCCFLAGS)

BeatGen.o: BeatGen.cpp BeatGen.hpp
	g++ -c BeatGen.cpp $(GCCFLAGS)

BeatGenReader.o: BeatGenReader.cpp BeatGenReader.hpp
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
	g++ -shared -o libV2BeatGen.so BeatGen.o BeatGenReader.o jsoncpp.o -fPIC $(GCCFLAGS)
	rm *.o

mvso:
	sudo mv libV2BeatGen.so /usr/lib

testso:
	g++ -o out test.cpp -lV2BeatGen -L. -fPIC $(GCCFLAGS)

getlines:
	cat test.cpp BeatGen.cpp BeatGenReader.cpp BeatGenOBJ.hpp BeatGenToks.hpp BeatGen.hpp BeatGenReader.hpp | wc -l