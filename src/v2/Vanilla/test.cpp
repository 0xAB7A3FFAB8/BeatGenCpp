#include "BeatGenOBJ.h"
#include "BeatGenToks.h"
#include "BeatGen.h"
#include <iostream>


int main()
{
    BeatGen::BeatGenContainer BGC; // Create a BeatGenContainer
    BGC.beatGenNotes.push_back(BGOBJ::note(1,1,BGToks::Bomb,BGToks::Left,5)); // Add a note to the BeatGenContainer
    BGC.beatGenWalls.push_back(BGOBJ::wall(0,2,BGToks::CrouchHight,5,12)); // Add a wall to the BeatGenContainer
    std::cout << BeatGen::genJson(BGC); // Generate a json code from the BeatGenContainer
    std::cin.ignore();
}