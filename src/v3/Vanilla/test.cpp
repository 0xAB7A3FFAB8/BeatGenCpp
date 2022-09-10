#include "BeatGen.h"
#include <iostream>

int main()
{
    BeatGen::BeatGenContainer BGC(true);
    BGOBJ::note n1(0,0,0,0,0,0);
    BGOBJ::note n2(0,0,0,0,0,20);
    BGC.beatGenNotes.push_back(n1);
    BGC.beatGenNotes.push_back(n2);
    std::cout << BeatGen::genJson(BGC, "3.0.0", true);
}
