#include <functional>
#include <vector>
#include <string>
#include <memory>
#include "BeatGenToks.h"
#include "include/json/writer.h"
#include "include/json/value.h"
#include "BeatGenOBJ.h"



namespace BeatGen {
    /*
    std::vector<std::string> ids;
    
    

    Json::Value genCustomData(BGOBJ::CustomData CD){
        Json::Value root;
        for(int i = 0; i < CD.Data.size(); i++){
            if (CD.type == BGCToks::INT){
                root[CD.Data[i].name] = CD.Data[i].value;
            }else if (CD.type == BGCToks::FLOAT){
                root[CD.Data[i].name] = CD.Data[i].fvalue;
            }else if (CD.type == BGCToks::STRING){
                root[CD.Data[i].name] = CD.Data[i].svalue;
            }else if (CD.type == BGCToks::BOOL){
                root[CD.Data[i].name] = bool(CD.Data[i].value);
            }else if (CD.type == BGCToks::OBJ){
                Json::Value obj;
                obj[CD.Data[i].name] = genCustomData(CD.Data[i]);
                root.append(obj);
            }else if (CD.type == BGCToks::ARRAY){
                Json::Value arr;
                arr[CD.Data[i].name] = genCustomData(CD.Data[i]);
                root[CD.Data[i].name] = arr;
            }
        }
        return root;
    }
    */

    std::string genJson(BeatGen::BeatGenContainer& BGC ,bool Styled)
    {
        Json::Value root;

        root["version"] = BGC.version;
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
            root["bpmEvents"].append(bpmEvent);
        }


        for (int i = 0; i < BGC.beatGenRotationEvents.size(); i++) {
            Json::Value rotationEvent;
            rotationEvent["b"] = BGC.beatGenRotationEvents[i].beat;
            rotationEvent["e"] = BGC.beatGenRotationEvents[i].early;
            rotationEvent["r"] = BGC.beatGenRotationEvents[i].rotation;
            root["rotationEvents"].append(rotationEvent);
        }

        for (int i = 0; i < BGC.beatGenNotes.size(); i++) {
            Json::Value note;
            note["b"] = BGC.beatGenNotes[i].beat;
            note["x"] = BGC.beatGenNotes[i].x;
            note["y"] = BGC.beatGenNotes[i].y;
            note["c"] = BGC.beatGenNotes[i].color;
            note["d"] = BGC.beatGenNotes[i].direction;
            note["a"] = BGC.beatGenNotes[i].angle_offset;
            /*
            if (BGC.beatGenNotes[i].customData.empty() == false) {
                for (int e = 0; e < BGC.beatGenNotes[i].customData.size(); e++) {
                    for (int r = 0; r < BGC.beatGenNotes[r].customData.size(); r++) {
                        note["customData"] = genCustomData(BGC.beatGenNotes[i].customData[ids[e]][r]);
                    }
                }
            }
            */
            root["colorNotes"].append(note);
        }

        for (int i = 0; i < BGC.beatGenBombs.size(); i++) {
            Json::Value bomb;
            bomb["b"] = BGC.beatGenBombs[i].beat;
            bomb["x"] = BGC.beatGenBombs[i].x;
            bomb["y"] = BGC.beatGenBombs[i].y;
            root["bombNotes"].append(bomb);
        }


        for (int i = 0; i < BGC.beatGenWalls.size(); i++) {
            Json::Value wall;
            wall["b"] = BGC.beatGenWalls[i].beat;
            wall["x"] = BGC.beatGenWalls[i].x;
            wall["y"] = BGC.beatGenWalls[i].y;
            wall["d"] = BGC.beatGenWalls[i].duration;
            wall["w"] = BGC.beatGenWalls[i].width;
            wall["h"] = BGC.beatGenWalls[i].height;
            root["obstacles"].append(wall);
        }

        for (int i = 0; i < BGC.beatGenColorBoostEvents.size(); i++) {
            Json::Value colorBoostEvent;
            colorBoostEvent["b"] = BGC.beatGenColorBoostEvents[i].beat;
            colorBoostEvent["o"] = BGC.beatGenColorBoostEvents[i].on;
            root["colorBoostBeatmapEvents"].append(colorBoostEvent);
        }

        for (int i = 0; i < BGC.beatGenSliders.size(); i++) {
            Json::Value slider;
            slider["b"] = BGC.beatGenSliders[i].sliderHead.beat;
            slider["c"] = BGC.beatGenSliders[i].color;
            slider["x"] = BGC.beatGenSliders[i].sliderHead.x;
            slider["y"] = BGC.beatGenSliders[i].sliderHead.y;
            slider["d"] = BGC.beatGenSliders[i].sliderHead.direction;
            slider["mu"] = BGC.beatGenSliders[i].sliderHead.controlPointLengthMultiplier;
            slider["tb"] = BGC.beatGenSliders[i].sliderTail.beat;
            slider["tx"] = BGC.beatGenSliders[i].sliderTail.x;
            slider["ty"] = BGC.beatGenSliders[i].sliderTail.y;
            slider["tc"] = BGC.beatGenSliders[i].sliderTail.direction;
            slider["tmu"] = BGC.beatGenSliders[i].sliderTail.controlPointLengthMultiplier;
            slider["m"] = BGC.beatGenSliders[i].sliderMidAnchorMode;
            root["sliders"].append(slider);
        }

        for (int i = 0; i < BGC.beatGenAutoSliders.size(); i++) {
            Json::Value slider;
            slider["b"] = BGC.beatGenAutoSliders[i].sliderHead.beat;
            slider["c"] = BGC.beatGenAutoSliders[i].color;
            slider["x"] = BGC.beatGenAutoSliders[i].sliderHead.x;
            slider["y"] = BGC.beatGenAutoSliders[i].sliderHead.y;
            slider["d"] = BGC.beatGenAutoSliders[i].sliderHead.direction;
            slider["mu"] = BGC.beatGenAutoSliders[i].sliderHead.controlPointLengthMultiplier;
            slider["tb"] = BGC.beatGenAutoSliders[i].sliderTail.beat;
            slider["tx"] = BGC.beatGenAutoSliders[i].sliderTail.x;
            slider["ty"] = BGC.beatGenAutoSliders[i].sliderTail.y;
            slider["tc"] = BGC.beatGenAutoSliders[i].sliderTail.direction;
            slider["tmu"] = BGC.beatGenAutoSliders[i].sliderTail.controlPointLengthMultiplier;
            slider["m"] = BGC.beatGenAutoSliders[i].sliderMidAnchorMode;
            root["sliders"].append(slider);
            Json::Value note;
            note["b"] = BGC.beatGenAutoSliders[i].sliderHead.beat;
            note["x"] = BGC.beatGenAutoSliders[i].sliderHead.x;
            note["y"] = BGC.beatGenAutoSliders[i].sliderHead.y;
            note["c"] = BGC.beatGenAutoSliders[i].color;
            note["d"] = BGC.beatGenAutoSliders[i].sliderHead.direction;
            note["a"] = 0;
            root["colorNotes"].append(note);
            Json::Value tailNote;
            tailNote["b"] = BGC.beatGenAutoSliders[i].sliderTail.beat;
            tailNote["x"] = BGC.beatGenAutoSliders[i].sliderTail.x;
            tailNote["y"] = BGC.beatGenAutoSliders[i].sliderTail.y;
            tailNote["c"] = BGC.beatGenAutoSliders[i].color;
            tailNote["d"] = BGC.beatGenAutoSliders[i].sliderTail.direction;
            tailNote["a"] = 0;
            root["colorNotes"].append(tailNote);
        }

        for (int i = 0; i < BGC.beatGenBurstSliders.size(); i++) {
            Json::Value burstSlider;
            burstSlider["b"] = BGC.beatGenBurstSliders[i].sliderHead.beat;
            burstSlider["c"] = BGC.beatGenBurstSliders[i].color;
            burstSlider["x"] = BGC.beatGenBurstSliders[i].sliderHead.x;
            burstSlider["y"] = BGC.beatGenBurstSliders[i].sliderHead.y;
            burstSlider["d"] = BGC.beatGenBurstSliders[i].sliderHead.direction;
            burstSlider["tb"] = BGC.beatGenBurstSliders[i].sliderTail.beat;
            burstSlider["tx"] = BGC.beatGenBurstSliders[i].sliderTail.x;
            burstSlider["ty"] = BGC.beatGenBurstSliders[i].sliderTail.y;
            burstSlider["sc"] = BGC.beatGenBurstSliders[i].segmentCount;
            burstSlider["s"] = BGC.beatGenBurstSliders[i].squish;
            root["burstSliders"].append(burstSlider);
        }

        for (int i = 0; i < BGC.beatGenBasicEvents.size(); i++) {
            Json::Value basicEvent;
            basicEvent["b"] = BGC.beatGenBasicEvents[i].beat;
            basicEvent["et"] = BGC.beatGenBasicEvents[i].type;
            basicEvent["i"] = BGC.beatGenBasicEvents[i].value;
            basicEvent["f"] = BGC.beatGenBasicEvents[i].valuef;
            root["basicBeatmapEvents"].append(basicEvent);
        }
        
        for (int i = 0; i < BGC.beatGenLightColorEvents.size(); i++) {
            Json::Value lightColorEvent;
            lightColorEvent["b"] = BGC.beatGenLightColorEvents[i].beat;
            lightColorEvent["g"] = BGC.beatGenLightColorEvents[i].group;
            lightColorEvent["e"] = Json::arrayValue;
            
            for (int e = 0; e < BGC.beatGenLightColorEvents[i].eventBoxes.size(); e++) {
                Json::Value eventBox;
                eventBox["f"] = Json::objectValue;
                eventBox["f"]["f"] = BGC.beatGenLightColorEvents[i].eventBoxes[e].filter.type;
                eventBox["f"]["p"] = BGC.beatGenLightColorEvents[i].eventBoxes[e].filter.parameter1;
                eventBox["f"]["t"] = BGC.beatGenLightColorEvents[i].eventBoxes[e].filter.parameter2;
                eventBox["f"]["r"] = BGC.beatGenLightColorEvents[i].eventBoxes[e].filter.reverse;
                eventBox["w"] = BGC.beatGenLightColorEvents[i].eventBoxes[e].beatDistribution;
                eventBox["d"] = BGC.beatGenLightColorEvents[i].eventBoxes[e].beatDistributionType;
                eventBox["r"] = BGC.beatGenLightColorEvents[i].eventBoxes[e].brigthnessDistribution;
                eventBox["t"] = BGC.beatGenLightColorEvents[i].eventBoxes[e].brigthnessDistributionType;
                eventBox["b"] = BGC.beatGenLightColorEvents[i].eventBoxes[e].brigthnessDistributionAffectFirst;
                eventBox["e"] = Json::arrayValue;
                for (int d = 0; d < BGC.beatGenLightColorEvents[i].eventBoxes[e].eventData.size(); d++) {
                    Json::Value event;
                    event["b"] = BGC.beatGenLightColorEvents[i].eventBoxes[e].eventData[d].addedBeat;
                    event["i"] = BGC.beatGenLightColorEvents[i].eventBoxes[e].eventData[d].transition;
                    event["c"] = BGC.beatGenLightColorEvents[i].eventBoxes[e].eventData[d].color;
                    event["s"] = BGC.beatGenLightColorEvents[i].eventBoxes[e].eventData[d].brightness;
                    event["f"] = BGC.beatGenLightColorEvents[i].eventBoxes[e].eventData[d].flickerFrequency;
                    eventBox["e"].append(event);
                }  
                lightColorEvent["e"].append(eventBox);     
            }
            root["lightColorEventBoxGroups"].append(lightColorEvent);
        }
        
        for (int i = 0; i < BGC.beatGenLightRotationEvents.size(); i++) {
            Json::Value rotationColorEvent;
            rotationColorEvent["b"] = BGC.beatGenLightRotationEvents[i].beat;
            rotationColorEvent["g"] = BGC.beatGenLightRotationEvents[i].group;
            rotationColorEvent["e"] = Json::arrayValue;
            for (int e = 0; e < BGC.beatGenLightRotationEvents[i].eventBoxes.size(); e++) {
                Json::Value eventBox;
                eventBox["f"] = Json::objectValue;
                eventBox["f"]["f"] = BGC.beatGenLightRotationEvents[i].eventBoxes[e].filter.type;
                eventBox["f"]["p"] = BGC.beatGenLightRotationEvents[i].eventBoxes[e].filter.parameter1;
                eventBox["f"]["t"] = BGC.beatGenLightRotationEvents[i].eventBoxes[e].filter.parameter2;
                eventBox["f"]["r"] = BGC.beatGenLightRotationEvents[i].eventBoxes[e].filter.reverse;
                eventBox["w"] = BGC.beatGenLightRotationEvents[i].eventBoxes[e].beatDistribution;
                eventBox["d"] = BGC.beatGenLightRotationEvents[i].eventBoxes[e].beatDistributionType;
                eventBox["s"] = BGC.beatGenLightRotationEvents[i].eventBoxes[e].rotationDistribution;
                eventBox["t"] = BGC.beatGenLightRotationEvents[i].eventBoxes[e].rotationDistributionType;
                eventBox["b"] = BGC.beatGenLightRotationEvents[i].eventBoxes[e].rotationDistributionAffectFirst;
                eventBox["a"] = BGC.beatGenLightRotationEvents[i].eventBoxes[e].axis;
                eventBox["r"] = BGC.beatGenLightRotationEvents[i].eventBoxes[e].reverseRotration;
                eventBox["l"] = Json::arrayValue;
                for (int d = 0; d < BGC.beatGenLightRotationEvents[i].eventBoxes[e].eventData.size(); d++) {
                    Json::Value event;
                    event["b"] = BGC.beatGenLightRotationEvents[i].eventBoxes[e].eventData[d].beat;
                    event["p"] = BGC.beatGenLightRotationEvents[i].eventBoxes[e].eventData[d].transition;
                    event["e"] = BGC.beatGenLightRotationEvents[i].eventBoxes[e].eventData[d].ease;
                    event["l"] = BGC.beatGenLightRotationEvents[i].eventBoxes[e].eventData[d].loops;
                    event["r"] = BGC.beatGenLightRotationEvents[i].eventBoxes[e].eventData[d].rotation;
                    event["o"] = BGC.beatGenLightRotationEvents[i].eventBoxes[e].eventData[d].direction;
                    eventBox["l"].append(event);
                }
                rotationColorEvent["e"].append(eventBox);
            }
            root["lightRotationEventBoxGroups"].append(rotationColorEvent);
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