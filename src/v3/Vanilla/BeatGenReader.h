#ifndef BEAT_GEN_READER_H_
#define BEAT_GEN_READER_H_

#include <functional>
#include <vector>
#include <string>
#include <memory>
#ifndef LIB_JSONCPP_JSON_TOOL_H_INCLUDED
#include "dist/jsoncpp.cpp"
#endif
#include "BeatGenOBJ.h"

namespace BGR {
    inline BeatGen::BeatGenContainer readJson(std::string json){
        Json::Value root;
        Json::Reader reader;
        bool parsingSuccessful = reader.parse(json, root);
        if (!parsingSuccessful)
        {
            // report to the user the failure and their locations in the document.
            std::cout << "Failed to parse configuration"
                << reader.getFormattedErrorMessages();
        }
        BeatGen::BeatGenContainer BGC(true, root["version"].asString());
        for (int i = 0; i < root["colorNotes"].size(); i++) {
            BGC.beatGenNotes.push_back(std::make_shared<BGOBJ::note>(root["colorNotes"][i]["x"].asInt(), root["colorNotes"][i]["y"].asInt(), root["colorNotes"][i]["c"].asInt(), root["colorNotes"][i]["d"].asInt(),root["colorNotes"][i]["a"].asInt(), root["colorNotes"][i]["b"].asFloat()));
        }
        for (int i = 0; i < root["obstacles"].size(); i++) {
            BGC.beatGenWalls.push_back(std::make_shared<BGOBJ::wall>(root["obstacles"][i]["x"].asInt(), root["obstacles"][i]["y"].asInt(), root["obstacles"][i]["w"].asInt(), root["obstacles"][i]["h"].asInt(), root["obstacles"][i]["d"].asFloat(), root["obstacles"][i]["b"].asFloat()));
        }
        for (int i = 0; i < root["bombNotes"].size(); i++) {
            BGC.beatGenBombs.push_back(std::make_shared<BGOBJ::bomb>(root["bombNotes"][i]["x"].asInt(), root["bombNotes"][i]["y"].asInt() , root["bombNotes"][i]["b"].asFloat()));
        }
        for (int i = 0; i < root["bpmEvents"].size(); i++) {
            BGC.beatGenBpmEvents.push_back(std::make_shared<BGOBJ::bpmEvent>(root["bpmEvents"][i]["b"].asFloat(), root["bpmEvents"][i]["m"].asFloat()));
        }
        for (int i = 0; i < root["rotationEvents"].size(); i++) {
            BGC.beatGenRotationEvents.push_back(std::make_shared<BGOBJ::rotationEvent>(root["rotationEvents"][i]["b"].asFloat(), root["rotationEvents"][i]["r"].asFloat(), root["rotationEvents"][i]["e"].asInt()));
        }
        for (int i = 0; i < root["sliders"].size(); i++) {
            BGC.beatGenSliders.push_back(std::make_shared<BGOBJ::slider>(root["sliders"][i]["c"].asInt(),root["sliders"][i]["m"].asInt(),BGOBJ::sliderpart(root["sliders"][i]["x"].asInt(), root["sliders"][i]["y"].asInt(), root["sliders"][i]["d"].asInt(), root["sliders"][i]["mu"].asFloat(), root["sliders"][i]["b"].asFloat()),BGOBJ::sliderpart(root["sliders"][i]["tx"].asInt(), root["sliders"][i]["ty"].asInt(), root["sliders"][i]["td"].asInt(), root["sliders"][i]["tmu"].asFloat(), root["sliders"][i]["tb"].asFloat())));
        }
        for (int i = 0; i < root["burstSliders"].size(); i++) {
            BGC.beatGenBurstSliders.push_back(std::make_shared<BGOBJ::burstSlider>(root["burstSliders"][i]["c"].asInt(), root["burstSliders"][i]["sc"].asInt(), root["burstSliders"][i]["s"].asFloat(),BGOBJ::burstSliderpart(root["burstSliders"][i]["x"].asInt(), root["burstSliders"][i]["y"].asInt(), root["burstSliders"][i]["d"].asInt(), root["burstSliders"][i]["b"].asFloat()), BGOBJ::burstSliderpart(root["burstSliders"][i]["tx"].asInt(), root["burstSliders"][i]["ty"].asInt(), root["burstSliders"][i]["td"].asInt(), root["burstSliders"][i]["tb"].asFloat())));
        }
        for (int i = 0; i < root["basicBeatmapEvents"].size(); i++) {
            BGC.beatGenBasicEvents.push_back(std::make_shared<BGOBJ::basicEvent>(root["basicBeatmapEvents"][i]["et"].asFloat(), root["basicBeatmapEvents"][i]["i"].asInt(), root["basicBeatmapEvents"][i]["f"].asFloat(), root["basicBeatmapEvents"][i]["b"].asFloat()));
        }
        for (int i = 0; i < root["colorBoostBeatmapEvents"].size(); i++) {
            BGC.beatGenColorBoostEvents.push_back(std::make_shared<BGOBJ::colorBoostEvent>(root["colorBoostBeatmapEvents"][i]["b"].asFloat(),root["colorBoostBeatmapEvents"][i]["o"].asBool()));
        }
        for (int i = 0; i < root["lightColorEventBoxGroups"].size(); i++) {
            std::vector<BGOBJ::lightEventData> LEDV;
            std::vector<BGOBJ::lightEventBoxContainer> LEBCV;
            for (int e = 0; e < root["lightColorEventBoxGroups"][i]["e"].size(); e++) {
                for (int f = 0; f < root["lightColorEventBoxGroups"][i]["e"][e]["e"].size(); i++){
                    BGOBJ::lightEventData LED(root["lightColorEventBoxGroups"][i]["e"][e]["e"][f]["b"].asFloat(), root["lightColorEventBoxGroups"][i]["e"][e]["e"][f]["s"].asFloat(), root["lightColorEventBoxGroups"][i]["e"][e]["e"][f]["i"].asInt(), root["lightColorEventBoxGroups"][i]["e"][e]["e"][f]["c"].asInt(), root["lightColorEventBoxGroups"][i]["e"][e]["e"][f]["f"].asInt());
                    LEDV.push_back(LED);
                }
                BGOBJ::lightEventBoxContainer LEBC(root["lightColorEventBoxGroups"][i]["e"][e]["w"].asFloat(),root["lightColorEventBoxGroups"][i]["e"][e]["d"].asInt(),root["lightColorEventBoxGroups"][i]["e"][e]["r"].asFloat(),root["lightColorEventBoxGroups"][i]["e"][e]["t"].asInt(),root["lightColorEventBoxGroups"][i]["e"][e]["b"].asInt(),BGOBJ::filter(root["lightColorEventBoxGroups"][i]["e"][e]["f"]["f"].asInt(),root["lightColorEventBoxGroups"][i]["e"][e]["f"]["p"].asInt(),root["lightColorEventBoxGroups"][i]["e"][e]["f"]["t"].asInt(),root["lightColorEventBoxGroups"][i]["e"][e]["f"]["r"].asInt()),LEDV);
                LEBCV.push_back(LEBC);
            }
            BGC.beatGenLightColorEvents.push_back(std::make_shared<BGOBJ::lightColorEvent>(root["lightColorEventBoxGroups"][i]["b"].asFloat(),root["lightColorEventBoxGroups"][i]["g"].asInt(),LEBCV));
        }
        for (int i = 0; i < root["lightRotationEventBoxGroups"].size(); i++) {
            std::vector<BGOBJ::lightRotationEventData> LEDV;
            std::vector<BGOBJ::lightRotationEventBoxContainer> LEBCV;
            for (int e = 0; e < root["lightRotationEventBoxGroups"][i]["e"].size(); e++) {
                for (int f = 0; f < root["lightRotationEventBoxGroups"][i]["e"][e]["e"].size(); i++){
                    BGOBJ::lightRotationEventData LED(root["lightRotationEventBoxGroups"][i]["e"][e]["e"][f]["b"].asFloat(), root["lightRotationEventBoxGroups"][i]["e"][e]["e"][f]["p"].asInt(), root["lightRotationEventBoxGroups"][i]["e"][e]["e"][f]["r"].asInt(), root["lightRotationEventBoxGroups"][i]["e"][e]["e"][f]["e"].asInt(), root["lightRotationEventBoxGroups"][i]["e"][e]["e"][f]["l"].asInt(), root["lightRotationEventBoxGroups"][i]["e"][e]["e"][f]["d"].asInt());
                    LEDV.push_back(LED);
                }
                BGOBJ::lightRotationEventBoxContainer LEBC(root["lightRotationEventBoxGroups"][i]["e"][e]["w"].asInt(),root["lightRotationEventBoxGroups"][i]["e"][e]["d"].asInt(),root["lightRotationEventBoxGroups"][i]["e"][e]["s"].asInt(),root["lightRotationEventBoxGroups"][i]["e"][e]["t"].asInt(),root["lightRotationEventBoxGroups"][i]["e"][e]["b"].asInt(), root["lightRotationEventBoxGroups"][i]["e"][e]["a"].asInt() , root["lightRotationEventBoxGroups"][i]["e"][e]["r"].asInt() , BGOBJ::filter(root["lightRotationEventBoxGroups"][i]["e"][e]["f"]["f"].asInt(),root["lightRotationEventBoxGroups"][i]["e"][e]["f"]["p"].asInt(),root["lightRotationEventBoxGroups"][i]["e"][e]["f"]["t"].asInt(),root["lightRotationEventBoxGroups"][i]["e"][e]["f"]["r"].asInt()),LEDV);
                LEBCV.push_back(LEBC);
            }
            BGC.beatGenLightRotationEvents.push_back(std::make_shared<BGOBJ::lightRotationEvent>(root["lightRotationEventBoxGroups"][i]["b"].asFloat(),root["lightRotationEventBoxGroups"][i]["g"].asInt(),LEBCV));
        }

        return BGC;
    }
}

#endif