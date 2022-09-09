#include "BeatGenOBJ.h"
#include "BeatGenToks.h"
#include "BeatGen.h"

int main() {
    BeatGen::BeatGenContainer BGC(true); // Create a BeatGenContainer
    BGC.beatGenNotes.push_back(BGOBJ::note(1,2,1,BGToks::Up,0,69)); // Add a note to the BeatGenContainer
}

