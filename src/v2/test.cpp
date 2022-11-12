#include "BeatGenOBJ.h"
#include "BeatGen.h"
#include "BeatGenReader.h"
#include <iostream>
#include <vector>
#include <fstream>
#include "BeatGenToks.h"

std::string readFile(std::string path)
{
    std::ifstream file(path);
    std::string str;
    std::string content;
    while (std::getline(file, str))
    {
        content += str;
        content.push_back('\n');
    }
    return content;
}

void writeFile(std::string path, std::string content)
{
    std::ofstream file(path);
    file << content;
    file.close();
}

int main()
{
    BeatGen::BeatGenContainer BGC; // Create a BeatGenContainer
    BGC = BGR::readJson(readFile("test.dat")); // Read a Json File
    BGC.version = "2.6.0"; // Set the version
    BGC.beatGenNotes.push_back(std::make_shared<BGOBJ::note>(1,1,BGToks::Bomb,BGToks::Left,5)); // Add a note to the BeatGenContainer
    BGC.beatGenWalls.push_back(std::make_shared<BGOBJ::wall>(0,2,BGToks::CrouchHight,5,12)); // Add a wall to the BeatGenContainer
    BGC.beatGenSliders.push_back(std::make_shared<BGOBJ::slider>(BGToks::Type::Red, BGToks::Slider::Clockwise,BGOBJ::sliderpart(1,1,BGToks::Up,1,15),BGOBJ::sliderpart(1,1,BGToks::Down,1,25))); // Add an Slider to the BeatGenContainer
    BGC.beatGenAutoSliders.push_back(std::make_shared<BGOBJ::slider>(BGToks::Type::Red, BGToks::Slider::Clockwise,BGOBJ::sliderpart(1,1,BGToks::Up,1,35),BGOBJ::sliderpart(1,1,BGToks::Down,1,45))); // Add an Slider with Blocks to the BeatGenContainer
    writeFile("testcomp.dat" ,BeatGen::genJson(BGC,false)); // Generate a json code from the BeatGenContainer
    std::cout << "Done" << std::endl;
    std::cin.ignore();
}