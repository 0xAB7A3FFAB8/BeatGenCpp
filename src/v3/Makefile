GCCFLAGS=

output: test.o BeatGen.o BeatGenReader.o jsoncpp.o
	gcc -o out jsoncpp.o BeatGen.o BeatGenReader.o test.o -fPIC $(GCCFLAGS) -lstdc++

test.o: test.cpp BeatGen.h BeatGenReader.h BeatGenOBJ.h BeatGenToks.h
	gcc -c test.cpp $(GCCFLAGS) -fPIC -lstdc++

BeatGen.o: BeatGen.cpp BeatGen.h
	gcc -c BeatGen.cpp $(GCCFLAGS) -fPIC -lstdc++

BeatGenReader.o: BeatGenReader.cpp BeatGenReader.h
	gcc -c BeatGenReader.cpp $(GCCFLAGS) -fPIC -lstdc++

jsoncpp.o: ./dist/jsoncpp.cpp
	gcc -c ./dist/jsoncpp.cpp $(GCCFLAGS) -fPIC -lstdc++

clean:
	rm *.o

clear:
	rm *.o out

genso:
	gcc -c BeatGenReader.cpp -fPIC $(GCCFLAGS) -lstdc++
	gcc -c BeatGen.cpp -fPIC $(GCCFLAGS) -lstdc++
	gcc -c ./dist/jsoncpp.cpp -fPIC $(GCCFLAGS) -lstdc++
	gcc -shared -o libV3BeatGen.so BeatGen.o BeatGenReader.o jsoncpp.o -fPIC $(GCCFLAGS) -lstdc++
	rm *.o

mvso:
	sudo mv libV3BeatGen.so /usr/lib

testso:
	gcc -o out test.cpp -lV3BeatGen -L. -fPIC $(GCCFLAGS) -lstdc++

getlines:
	cat test.cpp BeatGen.cpp BeatGenReader.cpp BeatGenOBJ.h BeatGenToks.h BeatGen.h BeatGenReader.h | wc -l