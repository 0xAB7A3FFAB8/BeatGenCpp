#ifndef BEATGENOBJ_H_
#define BEATGENOBJ_H_

#include <memory>
#include <vector>
#include <string>
#include <map>


namespace BGOBJ {
    class CustomData{
        public:
        int type,value;
        float fvalue;
        std::string name,svalue;
        std::vector<CustomData> Data;
        CustomData(int type,std::string name) : type(type),name(name){};
    };
}

namespace BGOBJ {
    class baseOBJ{
        public:
        std::map<std::string,std::vector<CustomData>> customData;
    };

    class bpmEvent:public baseOBJ { //bpmEvent class
        public:
        float bpm, beat;
        bpmEvent(float bpm,float beat) :bpm(bpm), beat(beat) {};

    };
    class rotationEvent:public baseOBJ { //rotationEvent class
        public:
        float beat,rotation;
        int early;
        rotationEvent(float beat,float rotation, int early):beat(beat),rotation(rotation),early(early){};
    };
    class note:public baseOBJ{ //note class
        public:
        float beat;
        int x,y,color,direction,angle_offset;
        note(int x,int y, int color, int direction,int angle_offset,float beat): x(x), y(y), color(color), direction(direction), angle_offset(angle_offset), beat(beat){};
    };
    class bomb:public baseOBJ{ //bomb class
        public:
        int x,y;
        float beat;
        bomb(int x, int y, float beat) : x(x),y(y),beat(beat) {};
    };
    class wall:public baseOBJ{ //wall class
    public:
        int y,x,width,height;
        float duration, beat;
        wall(int x, int y, int width, int height, float duration,float beat) : y(y),x(x),width(width),height(height),duration(duration), beat(beat) {};
    };
    class colorBoostEvent:public baseOBJ{ //colorBoostEvent class
    public:    
        float beat;
        bool on;
        colorBoostEvent(float beat, bool on) : beat(beat), on(on) {};
    };
    class sliderpart{ //Sliderpart class for Sliders
    public:
        int x,y,direction;
        float controlPointLengthMultiplier, beat;
        sliderpart(int x,int y, int direction,float controlPointLengthMultiplier,float beat): x(x), y(y), direction(direction), controlPointLengthMultiplier(controlPointLengthMultiplier), beat(beat) {};
    };
    class slider:public baseOBJ{ //Slider class
        public:
        int color,sliderMidAnchorMode;
        BGOBJ::sliderpart sliderHead,sliderTail;
        slider(int color, int sliderMidAnchorMode, BGOBJ::sliderpart sliderHead, BGOBJ::sliderpart sliderTail) : color(color), sliderMidAnchorMode(sliderMidAnchorMode), sliderHead(sliderHead), sliderTail(sliderTail) {};
    };

    class autoSlider:public baseOBJ{ //autoSlider class
        public:
        int color,sliderMidAnchorMode;
        BGOBJ::sliderpart sliderHead,sliderTail;
        autoSlider(int color, int sliderMidAnchorMode, BGOBJ::sliderpart sliderHead, BGOBJ::sliderpart sliderTail) : color(color), sliderMidAnchorMode(sliderMidAnchorMode), sliderHead(sliderHead), sliderTail(sliderTail) {};
    };

    class burstSliderpart{ //BurstSliderpart class for Sliders
        public:
        int x,y,direction;
        float beat;
        burstSliderpart(int x,int y, int direction,float beat): x(x), y(y), direction(direction), beat(beat) {};
    };
    class burstSlider:public baseOBJ{ //BurstSlider class
        public:
        float squish;
        int color,segmentCount;
        BGOBJ::burstSliderpart sliderHead,sliderTail;
        burstSlider(int color, int segmentCount, float squish, BGOBJ::burstSliderpart sliderHead, BGOBJ::burstSliderpart sliderTail) : color(color), segmentCount(segmentCount), squish(squish), sliderHead(sliderHead), sliderTail(sliderTail) {};
    };
    class basicEvent:public baseOBJ{ //BasicEvent class for BeatGen
        public:
        int type,value;
        float valuef,beat;
        basicEvent(int type, int value, float valuef, float beat) : type(type), value(value), valuef(valuef), beat(beat) {};
    };
    class filter{ //Filter class for lightEventBox
        public:
        int type,parameter1,parameter2;
        int reverse;
        filter(int type, int parameter1, int parameter2, int reverse) : type(type), parameter1(parameter1), parameter2(parameter2), reverse(reverse) {};
    };
    class lightEventData{ //LightEventData class for lightEventBox
        public:
        float addedBeat,brightness;
        int transition,color,flickerFrequency;
        lightEventData(float addedBeat, float brightness, int transition, int color, int flickerFrequency) : addedBeat(addedBeat), brightness(brightness), transition(transition), color(color), flickerFrequency(flickerFrequency) {};
    };
    class lightEventBoxContainer{ //LightEventBoxContainer class for lightColorEvent
        public:
        float beatDistribution,brigthnessDistribution;
        int beatDistributionType,brigthnessDistributionType,brigthnessDistributionAffectFirst;
        BGOBJ::filter filter;
        std::vector<BGOBJ::lightEventData> eventData;
        lightEventBoxContainer(float beatDistribution, int beatDistributionType, float brigthnessDistribution, int brigthnessDistributionType, int brigthnessDistributionAffectFirst, BGOBJ::filter filter, std::vector<BGOBJ::lightEventData> eventData) : beatDistribution(beatDistribution), brigthnessDistribution(brigthnessDistribution), beatDistributionType(beatDistributionType), brigthnessDistributionType(brigthnessDistributionType), brigthnessDistributionAffectFirst(brigthnessDistributionAffectFirst), filter(filter), eventData(eventData) {};
    };
    class lightColorEvent:public baseOBJ{ //LightColorEvent class
        public:
        float beat;
        int group;
        std::vector<BGOBJ::lightEventBoxContainer> eventBoxes;
        lightColorEvent(float beat, int group, std::vector<BGOBJ::lightEventBoxContainer> eventBoxes) : beat(beat), group(group), eventBoxes(eventBoxes) {};
    };
    class lightRotationEventData{ //RotationEventData class for rotationEvent
        public:
        float beat;
        int transition,rotation,ease,loops,direction;
        lightRotationEventData(float beat, int transition, int rotation, int ease, int loops, int direction) : beat(beat), transition(transition), rotation(rotation), ease(ease), loops(loops), direction(direction) {};
    };
    class lightRotationEventBoxContainer{ //RotationEventBoxContainer class for rotationEvent
        public:
        float beatDistribution,rotationDistribution;
        int beatDistributionType,rotationDistributionType,rotationDistributionAffectFirst,axis,reverseRotration;
        BGOBJ::filter filter;
        std::vector<BGOBJ::lightRotationEventData> eventData;
        lightRotationEventBoxContainer(float beatDistribution, int beatDistributionType, float rotationDistribution, int rotationDistributionType, int rotationDistributionAffectFirst, int axis, int reverseRotration,BGOBJ::filter filter, std::vector<BGOBJ::lightRotationEventData> eventData) : beatDistribution(beatDistribution), rotationDistribution(rotationDistribution), beatDistributionType(beatDistributionType), rotationDistributionType(rotationDistributionType), rotationDistributionAffectFirst(rotationDistributionAffectFirst), axis(axis), reverseRotration(reverseRotration), eventData(eventData), filter(filter) {};
    };
    class lightRotationEvent:public baseOBJ{ //LightRotationEvent class
        public:
        float beat;
        int group;
       std::vector<BGOBJ::lightRotationEventBoxContainer> eventBoxes;
        lightRotationEvent(float beat, int group, std::vector<BGOBJ::lightRotationEventBoxContainer> eventBoxes) : beat(beat), group(group), eventBoxes(eventBoxes) {};
    };
}

namespace BeatGen {
    class BeatGenContainer:public BGOBJ::baseOBJ { //Container class for BeatGen Objects
        public:
            std::string version;
            std::vector<BGOBJ::basicEvent> beatGenBasicEvents;
            std::vector<BGOBJ::note> beatGenNotes;	
            std::vector<BGOBJ::wall> beatGenWalls;
            std::vector<BGOBJ::slider> beatGenSliders;
            std::vector<BGOBJ::autoSlider> beatGenAutoSliders;
            std::vector<BGOBJ::burstSlider> beatGenBurstSliders;
            std::vector<BGOBJ::bomb> beatGenBombs;
            std::vector<BGOBJ::bpmEvent> beatGenBpmEvents;
            std::vector<BGOBJ::rotationEvent> beatGenRotationEvents;
            std::vector<BGOBJ::colorBoostEvent> beatGenColorBoostEvents;
            std::vector<BGOBJ::lightColorEvent> beatGenLightColorEvents;
            std::vector<BGOBJ::lightRotationEvent> beatGenLightRotationEvents;
            bool nomalCompatible;
            BeatGenContainer(bool normalCompatible, std::string version) : nomalCompatible(normalCompatible), version(version) {}
    };
}

#endif