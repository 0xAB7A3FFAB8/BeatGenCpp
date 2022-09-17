#include "BeatGen.h"
#include <iostream>
#include <vector>
#include <fstream>


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



int main()
{
    BeatGen::BeatGenContainer BGC(true);
    BGOBJ::note n1(0,0,0,0,0,0);
    BGOBJ::note n2(0,0,0,0,0,20);
    BGOBJ::slider s1(0,0,BGOBJ::sliderpart(1,1,1,1,1),BGOBJ::sliderpart(1,1,1,1,5));
    BGOBJ::autoSlider as1(0,0,BGOBJ::sliderpart(1,1,1,1,10),BGOBJ::sliderpart(1,1,1,1,15));


    BGC.beatGenNotes.push_back(n1);
    BGC.beatGenNotes.push_back(n2);
    BGC.beatGenSliders.push_back(s1);
    BGC.beatGenAutoSliders.push_back(as1);
    std::cout << BeatGen::genJson(BGC, "3.0.0", true);
}
