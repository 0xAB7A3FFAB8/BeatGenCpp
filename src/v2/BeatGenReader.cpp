#include <string>
#include "BeatGenOBJ.h"
#include "include/json/reader.h"
#include "include/json/value.h"
#include <iostream>

BeatGen::BeatGenContainer readJson(std::string json){
    Json::Value root;
    Json::Reader reader;
    bool parsingSuccessful = reader.parse(json, root);
    if (!parsingSuccessful)
    {
        // report to the user the failure and their locations in the document.
        std::cout << "Failed to parse configuration\n"
            << reader.getFormattedErrorMessages();
    }
    BeatGen::BeatGenContainer BGC;
    BGC.version = root["_version"].asString();
    for (int i = 0; i < root["_notes"].size(); i++) {
        BGC.beatGenNotes.push_back(std::make_shared<BGOBJ::note>(root["_notes"][i]["_lineIndex"].asInt(), root["_notes"][i]["_linerLayer"].asInt(), root["_notes"][i]["_type"].asInt(), root["_notes"][i]["_cutdirection"].asInt(), root["_notes"][i]["_beat"].asFloat()));
    }
    for (int i = 0; i < root["_obstacles"].size(); i++) {
        BGC.beatGenWalls.push_back(std::make_shared<BGOBJ::wall>(root["_obstacles"][i]["_layerIndex"].asInt(), root["_obstacles"][i]["_width"].asInt(), root["_obstacles"][i]["_type"].asInt(), root["_obstacles"][i]["_duration"].asFloat(), root["_obstacles"][i]["_beat"].asFloat()));
    }
    for (int i = 0; i < root["_events"].size(); i++) {
        BGC.beatGenEvents.push_back(std::make_shared<BGOBJ::event>( root["_events"][i]["_type"].asInt(), root["_events"][i]["_value"].asInt(), root["_events"][i]["_floatValue"].asFloat(),root["_events"][i]["_time"].asFloat()));
    }
    for (int i = 0; i < root["_sliders"].size(); i++) {
        BGC.beatGenSliders.push_back(std::make_shared<BGOBJ::slider>(root["_sliders"][i]["_colorType"].asInt(), root["_slider"][i]["_sliderMidAnchorMode"].asFloat() , BGOBJ::sliderpart( root["_slider"][i]["_headLineIndex"].asInt(),root["_slider"][i]["_headLineLayer"].asInt(),root["_slider"][i]["_headDirection"].asInt(),root["_slider"][i]["_headControlPointLengthMultiplier"].asFloat(),root["_slider"][i]["_headTime"].asFloat()), BGOBJ::sliderpart(root["_slider"][i]["_tailLineIndex"].asInt(),root["_slider"][i]["_tailLineLayer"].asInt(),root["_slider"][i]["_tailDirection"].asInt(),root["_slider"][i]["_tailControlPointLengthMultiplier"].asFloat(),root["_slider"][i]["_tailTime"].asFloat())));
    }

    return BGC;
}