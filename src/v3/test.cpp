#include "BeatGen.h"
#include "BeatGenReader.h"
#include <iostream>
#include <vector>
#include <fstream>
#include "BeatGenToks.h"
#include <chrono>


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

//function that writes a string to a file
void writeFile(std::string path, std::string content)
{
    std::ofstream file(path);
    file << content;
    file.close();
}

int main()
{
    //get current time in milliseconds
    auto start = std::chrono::high_resolution_clock::now();

    BeatGen::ids.push_back("NE");
    BeatGen::BeatGenContainer BGC(true, "3.0.0");
    BGC = BGR::readJson(readFile("test.dat"));
    BGOBJ::note n1(0,0,0,0,0,0);
    BGOBJ::note n2(0,0,0,0,0,20);
    BGOBJ::slider s1(0,0,BGOBJ::sliderpart(1,1,1,1,1),BGOBJ::sliderpart(1,1,1,1,5));
    BGOBJ::autoSlider as1(0,0,BGOBJ::sliderpart(1,1,1,1,10),BGOBJ::sliderpart(1,1,1,1,15));

    n1.customData["NE"].push_back(BGOBJ::CustomData(BGCToks::INT, "x"));
    n1.customData["NE"].back().value = 3;

    BGC.beatGenNotes.push_back(std::make_shared<BGOBJ::note>(n1));
    BGC.beatGenNotes.push_back(std::make_shared<BGOBJ::note>(n2));
    BGC.beatGenSliders.push_back(std::make_shared<BGOBJ::slider>(s1));
    BGC.beatGenAutoSliders.push_back(std::make_shared<BGOBJ::autoSlider>(as1));
    writeFile("testcomp.dat" ,BeatGen::genJson(BGC, true));
    std::cout << "Done! in:" << std::endl;
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start).count() << "ms" << std::endl;
}
