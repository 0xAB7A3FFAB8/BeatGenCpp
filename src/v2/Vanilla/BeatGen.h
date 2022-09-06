#ifndef BEATGEN_H_
#define BEATGEN_H_

#include "BeatGenOBJ.h"
#include "dist/json/json.h"
#include "dist/jsoncpp.cpp"
#include <vector>

#include <iostream>
#include <string>

namespace BeatGen {
    class BeatGenContainer {
        public:
            std::vector<BGOBJ::event> beatGenEvents;
            std::vector<BGOBJ::note> beatGenNotes;	
            std::vector<BGOBJ::wall> beatGenWalls;
    };
    inline void genJson(BeatGenContainer BGC)
    {
        Json::Value root;
        //root.append("_version");
        root["_version"] = "2.6.0";
        root["_notes"] = Json::arrayValue;
        root["_sliders"] = Json::arrayValue;
        root["_obstacles"] = Json::arrayValue;
        root["_events"] = Json::arrayValue;
        root["_waypoints"] = Json::arrayValue;

        for (int i = 0; i < BGC.beatGenNotes.size(); i++)
        {
            Json::Value note;
            note["_time"] = BGC.beatGenNotes[i].beat;
            note["_lineIndex"] = BGC.beatGenNotes[i].x;
            note["_lineLayer"] = BGC.beatGenNotes[i].y;
            note["_type"] = BGC.beatGenNotes[i].type;
            note["_cutDirection"] = BGC.beatGenNotes[i].direction;
            root["_notes"].append(note);
        }

        for (int i = 0; i < BGC.beatGenWalls.size(); i++)
        {
            Json::Value wall;
            wall["_time"] = BGC.beatGenWalls[i].beat;
            wall["_lineIndex"] = BGC.beatGenWalls[i].x;
            wall["_type"] = BGC.beatGenWalls[i].type;
            wall["_duration"] = BGC.beatGenWalls[i].duration;
            wall["_width"] = BGC.beatGenWalls[i].width;
            root["_obstacles"].append(wall);
        }

        for (int i = 0; i < BGC.beatGenEvents.size(); i++)
        {
            Json::Value event;
            event["_time"] = BGC.beatGenEvents[i].beat;
            event["_type"] = BGC.beatGenEvents[i].type;
            event["_value"] = BGC.beatGenEvents[i].value;
            event["_floatValue"] = BGC.beatGenEvents[i].valuef;
            root["_events"].append(event);
        }

        
        Json::FastWriter fastwriter;
        std::string message = fastwriter.write(root);
        std::cout<<message<<std::endl;
    }
}

#endif