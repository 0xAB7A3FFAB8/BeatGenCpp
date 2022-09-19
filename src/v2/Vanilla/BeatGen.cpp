#include <vector>
#include <string>
#include <memory>
#ifndef LIB_JSONCPP_JSON_TOOL_H_INCLUDED
#include "dist/jsoncpp.cpp"
#endif
#include "BeatGenOBJ.h"

std::string genJson(BeatGen::BeatGenContainer BGC,bool FastWrite)
{
    Json::Value root;
    //root.append("_version");
    root["_version"] = BGC.version;
    root["_notes"] = Json::arrayValue;
    root["_sliders"] = Json::arrayValue;
    root["_obstacles"] = Json::arrayValue;
    root["_events"] = Json::arrayValue;
    root["_waypoints"] = Json::arrayValue;

    for (int i = 0; i < BGC.beatGenNotes.size(); i++) //appends Data from Note class to json
    {
        Json::Value note;
        note["_time"] = BGC.beatGenNotes[i]->beat;
        note["_lineIndex"] = BGC.beatGenNotes[i]->x;
        note["_lineLayer"] = BGC.beatGenNotes[i]->y;
        note["_type"] = BGC.beatGenNotes[i]->type;
        note["_cutDirection"] = BGC.beatGenNotes[i]->direction;
        root["_notes"].append(note);
    }

    for (int i = 0; i < BGC.beatGenWalls.size(); i++) //appends Data from Wall class to json
    {
        Json::Value wall;
        wall["_time"] = BGC.beatGenWalls[i]->beat;
        wall["_lineIndex"] = BGC.beatGenWalls[i]->x;
        wall["_type"] = BGC.beatGenWalls[i]->type;
        wall["_duration"] = BGC.beatGenWalls[i]->duration;
        wall["_width"] = BGC.beatGenWalls[i]->width;
        root["_obstacles"].append(wall);
    }

    for (int i = 0; i < BGC.beatGenEvents.size(); i++) //appends Data from Event class to json
    {
        Json::Value event;
        event["_time"] = BGC.beatGenEvents[i]->beat;
        event["_type"] = BGC.beatGenEvents[i]->type;
        event["_value"] = BGC.beatGenEvents[i]->value;
        event["_floatValue"] = BGC.beatGenEvents[i]->valuef;
        root["_events"].append(event);
    }

    for (int i = 0; i < BGC.beatGenSliders.size(); i++) {
        Json::Value slider;
        slider["_colorType"] = BGC.beatGenSliders[i]->type;
        slider["_headTime"] = BGC.beatGenSliders[i]->sliderHead.beat;
        slider["_tailTime"] = BGC.beatGenSliders[i]->sliderTail.beat;
        slider["_headLineIndex"] = BGC.beatGenSliders[i]->sliderHead.x;
        slider["_tailLineIndex"] = BGC.beatGenSliders[i]->sliderTail.x;
        slider["_headLineLayer"] = BGC.beatGenSliders[i]->sliderHead.y;
        slider["_tailLineLayer"] = BGC.beatGenSliders[i]->sliderTail.y;
        slider["_headDirection"] = BGC.beatGenSliders[i]->sliderHead.direction;
        slider["_tailDirection"] = BGC.beatGenSliders[i]->sliderTail.direction;
        slider["_headControlPointLengthMultiplier"] = BGC.beatGenSliders[i]->sliderHead.controlPointLengthMultiplier;
        slider["_tailControlPointLengthMultiplier"] = BGC.beatGenSliders[i]->sliderTail.controlPointLengthMultiplier;
        slider["_sliderMidAnchorMode"] = BGC.beatGenSliders[i]->sliderMidAnchorMode;
        root["_sliders"].append(slider);
    }
    
    for (int i = 0; i < BGC.beatGenAutoSliders.size(); i++) {
        Json::Value slider;
        slider["_colorType"] = BGC.beatGenAutoSliders[i]->type;
        slider["_headTime"] = BGC.beatGenAutoSliders[i]->sliderHead.beat;
        slider["_tailTime"] = BGC.beatGenAutoSliders[i]->sliderTail.beat;
        slider["_headLineIndex"] = BGC.beatGenAutoSliders[i]->sliderHead.x;
        slider["_tailLineIndex"] = BGC.beatGenAutoSliders[i]->sliderTail.x;
        slider["_headLineLayer"] = BGC.beatGenAutoSliders[i]->sliderHead.y;
        slider["_tailLineLayer"] = BGC.beatGenAutoSliders[i]->sliderTail.y;
        slider["_headDirection"] = BGC.beatGenAutoSliders[i]->sliderHead.direction;
        slider["_tailDirection"] = BGC.beatGenAutoSliders[i]->sliderTail.direction;
        slider["_headControlPointLengthMultiplier"] = BGC.beatGenAutoSliders[i]->sliderHead.controlPointLengthMultiplier;
        slider["_tailControlPointLengthMultiplier"] = BGC.beatGenAutoSliders[i]->sliderTail.controlPointLengthMultiplier;
        slider["_sliderMidAnchorMode"] = BGC.beatGenAutoSliders[i]->sliderMidAnchorMode;
        
        Json::Value head;
        head["_time"] = BGC.beatGenAutoSliders[i]->sliderHead.beat;
        head["_lineIndex"] = BGC.beatGenAutoSliders[i]->sliderHead.x;
        head["_lineLayer"] = BGC.beatGenAutoSliders[i]->sliderHead.y;
        head["_type"] = BGC.beatGenAutoSliders[i]->type;
        head["_cutDirection"] = BGC.beatGenAutoSliders[i]->sliderHead.direction;
        root["_notes"].append(head);

        Json::Value tail;
        tail["_time"] = BGC.beatGenAutoSliders[i]->sliderTail.beat;
        tail["_lineIndex"] = BGC.beatGenAutoSliders[i]->sliderTail.x;
        tail["_lineLayer"] = BGC.beatGenAutoSliders[i]->sliderTail.y;
        tail["_type"] = BGC.beatGenAutoSliders[i]->type;
        tail["_cutDirection"] = BGC.beatGenAutoSliders[i]->sliderTail.direction;
        root["_notes"].append(tail);

        root["_sliders"].append(slider);
    }

    if (FastWrite) {
        Json::FastWriter writer;
        return writer.write(root);
    } else {
        Json::StyledWriter writer;
        return writer.write(root);
    }
}