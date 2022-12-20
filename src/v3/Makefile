COMPFLAGS=-lstdc++ -std=c++17 -O3
COMPILER=clang++

output: test.o BeatGen.o BeatGenReader.o jsoncpp.o
	$(COMPILER) $(COMPFLAGS) jsoncpp.o BeatGen.o BeatGenReader.o test.o  

test.o: test.cpp BeatGen.h BeatGenReader.h BeatGenOBJ.h BeatGenToks.h
	$(COMPILER) -c $(COMPFLAGS)  test.cpp 

BeatGen.o: BeatGen.cpp BeatGen.h
	$(COMPILER) -c $(COMPFLAGS) BeatGen.cpp  

BeatGenReader.o: BeatGenReader.cpp BeatGenReader.h
	$(COMPILER) -c $(COMPFLAGS) BeatGenReader.cpp  

jsoncpp.o: ./dist/jsoncpp.cpp
	$(COMPILER) -c $(COMPFLAGS) ./dist/jsoncpp.cpp  

clean:
	rm *.o

clear:
	rm *.o a.out

genso:
	$(COMPILER) -c BeatGenReader.cpp -fPIC $(COMPFLAGS) 
	$(COMPILER) -c BeatGen.cpp -fPIC $(COMPFLAGS) 
	$(COMPILER) -c ./dist/jsoncpp.cpp -fPIC $(COMPFLAGS) 
	$(COMPILER) -shared -o libV3BeatGen.so BeatGen.o BeatGenReader.o jsoncpp.o -fPIC $(COMPFLAGS) 
	rm *.o

mvso:
	sudo mv libV3BeatGen.so /../../

testso:
	$(COMPILER) -o out test.cpp -lV3BeatGen -L. -fPIC $(COMPFLAGS) 

getlines:
	cat test.cpp BeatGen.cpp BeatGenReader.cpp BeatGenOBJ.h BeatGenToks.h BeatGen.h BeatGenReader.h | wc -l