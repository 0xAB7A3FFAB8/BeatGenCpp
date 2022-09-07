#include "BeatGenOBJ.h" //object classes
#include "BeatGenToks.h" //token classes (for Readeble Code)
#include "BeatGen.h" //container class and Json Generator
#include <iostream>


int main()
{
    BeatGen::BeatGenContainer BGC; // Create a BeatGenContainer
    BGC.beatGenNotes.push_back(BGOBJ::note(1,1,BGToks::Bomb,BGToks::Left,5)); // Add a note to the BeatGenContainer
    BGC.beatGenWalls.push_back(BGOBJ::wall(0,2,BGToks::CrouchHight,5,12)); // Add a wall to the BeatGenContainer
    BGC.beatGenSliders.push_back(BGOBJ::slider(BGToks::Type::Red, BGToks::Slider::Clockwise,BGOBJ::sliderpart(1,1,BGToks::Up,1,15),BGOBJ::sliderpart(1,1,BGToks::Down,1,25))); // Add an Slider to the BeatGenContainer
    BGC.beatGenAutoSliders.push_back(BGOBJ::slider(BGToks::Type::Red, BGToks::Slider::Clockwise,BGOBJ::sliderpart(1,1,BGToks::Up,1,35),BGOBJ::sliderpart(1,1,BGToks::Down,1,45))); // Add an Slider with Blocks to the BeatGenContainer
    std::cout << BeatGen::genJson(BGC,false); // Generate a json code from the BeatGenContainer
    std::cin.ignore();
}