#include "BeatGenOBJ.h"
#include "BeatGenToks.h"
#include "BeatGen.h"
#include <iostream>


int main()
{
    BeatGen::BeatGenContainer BGC;
    BGC.beatGenNotes.push_back(BGOBJ::note(1,1,BGToks::Bomb,BGToks::Left,5));
    BGC.beatGenWalls.push_back(BGOBJ::wall(0,2,BGToks::CrouchHight,5,12));
    BeatGen::genJson(BGC);
    std::cin.ignore();
}