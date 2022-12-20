#include <functional>
#include <vector>
#include <string>
#include <memory>
#include "BeatGenToks.h"
#include "include/json/writer.h"
#include "include/json/value.h"
#include "BeatGenOBJ.h"
#include <algorithm>
#include <execution>
#include <stdexcept>


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

    Json::Value genBpmEvent(BGOBJ::bpmEvent& bpmEvent){
        Json::Value bpmEventJ;
        bpmEventJ["b"] = bpmEvent.beat;
        bpmEventJ["m"] = bpmEvent.bpm;
        return bpmEventJ;
    }

    Json::Value genRotationEvent(BGOBJ::rotationEvent& rotationEvent){
        Json::Value rotationEventJ;
        rotationEventJ["b"] = rotationEvent.beat;
        rotationEventJ["e"] = rotationEvent.early;
        rotationEventJ["r"] = rotationEvent.rotation;
        return rotationEventJ;
    }

    Json::Value genNote(BGOBJ::note& note){
        Json::Value noteJ;
        noteJ["b"] = note.beat;
        noteJ["x"] = note.x;
        noteJ["y"] = note.y;
        noteJ["c"] = note.color;
        noteJ["d"] = note.direction;
        noteJ["a"] = note.angle_offset;
        /*
        if (note.customData.empty() == false) {
            for (int e = 0; e < note.customData.size(); e++) {
                for (int r = 0; r < BGC.beatGenNotes[r].customData.size(); r++) {
                    noteJ["customData"] = genCustomData(note.customData[ids[e]][r]);
                }
            }
        }
        */
        return noteJ;
    }

    Json::Value genBomb(BGOBJ::bomb& bomb){
        Json::Value bombJ;
        bombJ["b"] = bomb.beat;
        bombJ["x"] = bomb.x;
        bombJ["y"] = bomb.y;
        return bombJ;
    }

    Json::Value genWall(BGOBJ::wall& wall){
        Json::Value wallJ;
        wallJ["b"] = wall.beat;
        wallJ["x"] = wall.x;
        wallJ["y"] = wall.y;
        wallJ["d"] = wall.duration;
        wallJ["w"] = wall.width;
        wallJ["h"] = wall.height;
        return wallJ;
    }

    Json::Value genColorBoostEvent(BGOBJ::colorBoostEvent& colorBoostEvent){
        Json::Value colorBoostEventJ;
        colorBoostEventJ["b"] = colorBoostEvent.beat;
        colorBoostEventJ["o"] = colorBoostEvent.on;
        return colorBoostEventJ;
    }

    Json::Value genSlider(BGOBJ::slider& slider){
        Json::Value sliderJ;
        sliderJ["b"] = slider.sliderHead.beat;
        sliderJ["c"] = slider.color;
        sliderJ["x"] = slider.sliderHead.x;
        sliderJ["y"] = slider.sliderHead.y;
        sliderJ["d"] = slider.sliderHead.direction;
        sliderJ["mu"] = slider.sliderHead.controlPointLengthMultiplier;
        sliderJ["tb"] = slider.sliderTail.beat;
        sliderJ["tx"] = slider.sliderTail.x;
        sliderJ["ty"] = slider.sliderTail.y;
        sliderJ["tc"] = slider.sliderTail.direction;
        sliderJ["tmu"] = slider.sliderTail.controlPointLengthMultiplier;
        sliderJ["m"] = slider.sliderMidAnchorMode;
        return sliderJ;
    }

    std::vector<Json::Value> genAutoSlider(BGOBJ::autoSlider& autoSlider){
            Json::Value sliderJ;
            sliderJ["b"] = autoSlider.sliderHead.beat;
            sliderJ["c"] = autoSlider.color;
            sliderJ["x"] = autoSlider.sliderHead.x;
            sliderJ["y"] = autoSlider.sliderHead.y;
            sliderJ["d"] = autoSlider.sliderHead.direction;
            sliderJ["mu"] = autoSlider.sliderHead.controlPointLengthMultiplier;
            sliderJ["tb"] = autoSlider.sliderTail.beat;
            sliderJ["tx"] = autoSlider.sliderTail.x;
            sliderJ["ty"] = autoSlider.sliderTail.y;
            sliderJ["tc"] = autoSlider.sliderTail.direction;
            sliderJ["tmu"] = autoSlider.sliderTail.controlPointLengthMultiplier;
            sliderJ["m"] = autoSlider.sliderMidAnchorMode;
            Json::Value noteJ;
            noteJ["b"] = autoSlider.sliderHead.beat;
            noteJ["x"] = autoSlider.sliderHead.x;
            noteJ["y"] = autoSlider.sliderHead.y;
            noteJ["c"] = autoSlider.color;
            noteJ["d"] = autoSlider.sliderHead.direction;
            noteJ["a"] = 0;
            Json::Value tailNoteJ;
            tailNoteJ["b"] = autoSlider.sliderTail.beat;
            tailNoteJ["x"] = autoSlider.sliderTail.x;
            tailNoteJ["y"] = autoSlider.sliderTail.y;
            tailNoteJ["c"] = autoSlider.color;
            tailNoteJ["d"] = autoSlider.sliderTail.direction;
            tailNoteJ["a"] = 0;
            return {sliderJ,noteJ,tailNoteJ};
    }

    Json::Value genBurstSlider(BGOBJ::burstSlider& burstSlider){
        Json::Value burstSliderJ;
        burstSliderJ["b"] = burstSlider.sliderHead.beat;
        burstSliderJ["c"] = burstSlider.color;
        burstSliderJ["x"] = burstSlider.sliderHead.x;
        burstSliderJ["y"] = burstSlider.sliderHead.y;
        burstSliderJ["d"] = burstSlider.sliderHead.direction;
        burstSliderJ["tb"] = burstSlider.sliderTail.beat;
        burstSliderJ["tx"] = burstSlider.sliderTail.x;
        burstSliderJ["ty"] = burstSlider.sliderTail.y;
        burstSliderJ["sc"] = burstSlider.segmentCount;
        burstSliderJ["s"] = burstSlider.squish;
        return burstSliderJ;
    }

    Json::Value genBasicEvent(BGOBJ::basicEvent& basicEvent){
        Json::Value basicEventJ;
        basicEventJ["b"] = basicEvent.beat;
        basicEventJ["et"] = basicEvent.type;
        basicEventJ["i"] = basicEvent.value;
        basicEventJ["f"] = basicEvent.valuef;
        return basicEventJ;
    }

    Json::Value genLightColorEvent(BGOBJ::lightColorEvent& lightColorEvent){
        Json::Value lightColorEventJ;
        lightColorEventJ["b"] = lightColorEvent.beat;
        lightColorEventJ["g"] = lightColorEvent.group;
        lightColorEventJ["e"] = Json::arrayValue;
        
        for (int e = 0; e < lightColorEvent.eventBoxes.size(); e++) {
            Json::Value eventBox;
            eventBox["f"] = Json::objectValue;
            eventBox["f"]["f"] = lightColorEvent.eventBoxes[e].filter.type;
            eventBox["f"]["p"] = lightColorEvent.eventBoxes[e].filter.parameter1;
            eventBox["f"]["t"] = lightColorEvent.eventBoxes[e].filter.parameter2;
            eventBox["f"]["r"] = lightColorEvent.eventBoxes[e].filter.reverse;
            eventBox["w"] = lightColorEvent.eventBoxes[e].beatDistribution;
            eventBox["d"] = lightColorEvent.eventBoxes[e].beatDistributionType;
            eventBox["r"] = lightColorEvent.eventBoxes[e].brigthnessDistribution;
            eventBox["t"] = lightColorEvent.eventBoxes[e].brigthnessDistributionType;
            eventBox["b"] = lightColorEvent.eventBoxes[e].brigthnessDistributionAffectFirst;
            eventBox["e"] = Json::arrayValue;
            for (int d = 0; d < lightColorEvent.eventBoxes[e].eventData.size(); d++) {
                Json::Value event;
                event["b"] = lightColorEvent.eventBoxes[e].eventData[d].addedBeat;
                event["i"] = lightColorEvent.eventBoxes[e].eventData[d].transition;
                event["c"] = lightColorEvent.eventBoxes[e].eventData[d].color;
                event["s"] = lightColorEvent.eventBoxes[e].eventData[d].brightness;
                event["f"] = lightColorEvent.eventBoxes[e].eventData[d].flickerFrequency;
                eventBox["e"].append(event);
            }  
            lightColorEventJ["e"].append(eventBox);     
        }
        return lightColorEventJ;
    }

    Json::Value genLightRotationEvent(BGOBJ::lightRotationEvent& lightRotationEvent){
        Json::Value rotationColorEvent;
        rotationColorEvent["b"] = lightRotationEvent.beat;
        rotationColorEvent["g"] = lightRotationEvent.group;
        rotationColorEvent["e"] = Json::arrayValue;
        for (int e = 0; e < lightRotationEvent.eventBoxes.size(); e++) {
            Json::Value eventBox;
            eventBox["f"] = Json::objectValue;
            eventBox["f"]["f"] = lightRotationEvent.eventBoxes[e].filter.type;
            eventBox["f"]["p"] = lightRotationEvent.eventBoxes[e].filter.parameter1;
            eventBox["f"]["t"] = lightRotationEvent.eventBoxes[e].filter.parameter2;
            eventBox["f"]["r"] = lightRotationEvent.eventBoxes[e].filter.reverse;
            eventBox["w"] = lightRotationEvent.eventBoxes[e].beatDistribution;
            eventBox["d"] = lightRotationEvent.eventBoxes[e].beatDistributionType;
            eventBox["s"] = lightRotationEvent.eventBoxes[e].rotationDistribution;
            eventBox["t"] = lightRotationEvent.eventBoxes[e].rotationDistributionType;
            eventBox["b"] = lightRotationEvent.eventBoxes[e].rotationDistributionAffectFirst;
            eventBox["a"] = lightRotationEvent.eventBoxes[e].axis;
            eventBox["r"] = lightRotationEvent.eventBoxes[e].reverseRotration;
            eventBox["l"] = Json::arrayValue;
            for (int d = 0; d < lightRotationEvent.eventBoxes[e].eventData.size(); d++) {
                Json::Value event;
                event["b"] = lightRotationEvent.eventBoxes[e].eventData[d].beat;
                event["p"] = lightRotationEvent.eventBoxes[e].eventData[d].transition;
                event["e"] = lightRotationEvent.eventBoxes[e].eventData[d].ease;
                event["l"] = lightRotationEvent.eventBoxes[e].eventData[d].loops;
                event["r"] = lightRotationEvent.eventBoxes[e].eventData[d].rotation;
                event["o"] = lightRotationEvent.eventBoxes[e].eventData[d].direction;
                eventBox["l"].append(event);
            }
            rotationColorEvent["e"].append(eventBox);
        }
        return rotationColorEvent;
    }

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

        std::for_each(std::execution::par, BGC.beatGenBpmEvents.begin(), BGC.beatGenBpmEvents.end(), [&root](BGOBJ::bpmEvent& bpmEvent) {
            root["bpmEvents"].append(genBpmEvent(bpmEvent));
        });

        std::for_each(std::execution::par, BGC.beatGenRotationEvents.begin(), BGC.beatGenRotationEvents.end(), [&root](BGOBJ::rotationEvent& rotationEvent) {
            root["rotationEvents"].append(genRotationEvent(rotationEvent));
        });

        std::for_each(std::execution::par, BGC.beatGenNotes.begin(), BGC.beatGenNotes.end(), [&root](BGOBJ::note& note) {
            root["colorNotes"].append(genNote(note));
        });

        std::for_each(std::execution::par, BGC.beatGenBombs.begin(), BGC.beatGenBombs.end(), [&root](BGOBJ::bomb& bomb) {
            root["bombNotes"].append(genBomb(bomb));
        });

        std::for_each(std::execution::par, BGC.beatGenWalls.begin(), BGC.beatGenWalls.end(), [&root](BGOBJ::wall& wall) {
            root["obstacles"].append(genWall(wall));
        });

        std::for_each(std::execution::par, BGC.beatGenColorBoostEvents.begin(), BGC.beatGenColorBoostEvents.end(), [&root](BGOBJ::colorBoostEvent& colorBoostEvent) {
            root["colorBoostBeatmapEvents"].append(genColorBoostEvent(colorBoostEvent));
        });

        std::for_each(std::execution::par, BGC.beatGenSliders.begin(), BGC.beatGenSliders.end(), [&root](BGOBJ::slider& slider) {
            root["sliders"].append(genSlider(slider));
        });

        std::for_each(std::execution::par, BGC.beatGenAutoSliders.begin(), BGC.beatGenAutoSliders.end(), [&root](BGOBJ::autoSlider& autoSlider) {
            auto slider = genAutoSlider(autoSlider);
            root["sliders"].append(slider[0]);
            root["colorNotes"].append(slider[1]);
            root["colorNotes"].append(slider[2]);
        });

        std::for_each(std::execution::par, BGC.beatGenBurstSliders.begin(), BGC.beatGenBurstSliders.end(), [&root](BGOBJ::burstSlider& burstSlider) {
            root["burstSliders"].append(genBurstSlider(burstSlider));
        });

        std::for_each(std::execution::par, BGC.beatGenBasicEvents.begin(), BGC.beatGenBasicEvents.end(), [&root](BGOBJ::basicEvent& basicEvent) {
            root["basicBeatmapEvents"].append(genBasicEvent(basicEvent));
        });

        std::for_each(std::execution::par, BGC.beatGenLightColorEvents.begin(), BGC.beatGenLightColorEvents.end(), [&root](BGOBJ::lightColorEvent& lightColorEvent) {
            root["lightColorEventsBoxGroup"].append(genLightColorEvent(lightColorEvent));
        });
        
        std::for_each(std::execution::par, BGC.beatGenLightRotationEvents.begin(), BGC.beatGenLightRotationEvents.end(), [&root](BGOBJ::lightRotationEvent& lightRotationEvent) {
            root["lightRotationEventsBoxGroup"].append(genLightRotationEvent(lightRotationEvent));
        });
    
        if(!Styled){
            Json::FastWriter writer;
            return writer.write(root);
        }else {
            Json::StyledWriter writer;
            return writer.write(root);
        }
    
        throw std::runtime_error("Error: Somthing went wrong when generating json!");
        return "";
    }
}