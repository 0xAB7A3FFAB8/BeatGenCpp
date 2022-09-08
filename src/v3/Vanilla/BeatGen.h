#ifndef BEATGEN_H_
#define BEATGEN_H_

#include "BeatGenOBJ.h"
#include "dist/jsoncpp.cpp"
#include <vector>
#include <string>

namespace BeatGen {
    class BeatGenContainer { //Container class for BeatGen Objects
        public:
            std::vector<BGOBJ::basicEvent> beatGenBasicEvents;
            std::vector<BGOBJ::note> beatGenNotes;	
            std::vector<BGOBJ::wall> beatGenWalls;
            std::vector<BGOBJ::slider> beatGenSliders;
            std::vector<BGOBJ::burstSlider> beatGenBurstSliders;
            std::vector<BGOBJ::bomb> beatGenBombs;
            std::vector<BGOBJ::bpmEvent> beatGenBpmEvents;
            std::vector<BGOBJ::rotationEvent> beatGenRotationEvents;
            std::vector<BGOBJ::colorBoostEvent> beatGenColorBoostEvents;
            std::vector<BGOBJ::lightColorEvent> beatGenLightColorEvents;
            std::vector<BGOBJ::lightRotationEvent> beatGenLightRotationEvents;
            bool nomalCompatible;
            BeatGenContainer(bool normalCompatible) : nomalCompatible(normalCompatible) {}
    };
    inline std::string genJson(BeatGenContainer BGC,std::string version,bool FastWrite)
    {
        return "";
    }
}

#endif