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
    inline std::string genJson(BeatGenContainer BGC,std::string version ,bool Styled)
    {
        Json::Value root;

        root["version"] = version;
        root["bpmEvents"] = Json::arrayValue;
        root["rotationEvents"] = Json::arrayValue;
        root["colorNotes"] = Json::arrayValue;
        root["bombNotes"] = Json::arrayValue;
        root["obstacles"] = Json::arrayValue;
        root["sliders"] = Json::arrayValue;
        root["burstSliders"] = Json::arrayValue;
        root["waypoints"] = Json::arrayValue;
        root["basicBeatmapEvents"] = Json::arrayValue;
        root["colorBoostBeatmapEvents"] = Json::arrayValue;
        root["lightColorEventsBoxGroup"] = Json::arrayValue;
        root["lightRotationEventsBoxGroup"] = Json::arrayValue;
        root["basicEventTypesWithKeywords"] = Json::objectValue;
        root["useNormalEventsAsCompatibleEvents"] = BGC.nomalCompatible;

        for (int i = 0; i < BGC.beatGenBpmEvents.size(); i++) {
            Json::Value bpmEvent;
            bpmEvent["b"] = BGC.beatGenBpmEvents[i].beat;
            bpmEvent["m"] = BGC.beatGenBpmEvents[i].bpm;
        }

        if(!Styled){
            Json::FastWriter writer;
            return writer.write(root);
        }else {
            Json::StyledWriter writer;
            return writer.write(root);
        }
        return "Something went wrong while generating the json";
    }
}

#endif