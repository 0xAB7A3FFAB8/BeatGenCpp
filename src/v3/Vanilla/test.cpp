#include "BeatGenOBJ.h"
#include "BeatGenToks.h"
#include "BeatGen.h"
#include <iostream>

int main() {
    BeatGen::BeatGenContainer BGC(true); // Create a BeatGenContainer
    BGC.beatGenNotes.push_back(BGOBJ::note(1,2,1,BGToks::Up,0,69)); // Add a note to the BeatGenContainer
    std::cout << BeatGen::genJson(BGC, "3.0.0", true);
}

