#ifndef BPMEVENT_H_
#define BPMEVENT_H_

#include <memory>
#include <vector>
#include <string>

namespace BGOBJ {
    class bpmEvent { //bpmEvent class
        public:
        float bpm, beat;
        bpmEvent(float bpm,float beat) :bpm(bpm), beat(beat) {};

    };
    class rotationEvent { //rotationEvent class
        public:
        float beat,rotation;
        int early;
        rotationEvent(float beat,float rotation, int early):beat(beat),rotation(rotation),early(early){};
    };
    class note{ //note class
        public:
        float beat;
        int x,y,color,direction,angle_offset;
        note(int x,int y, int color, int direction,int angle_offset,float beat): x(x), y(y), color(color), direction(direction), angle_offset(angle_offset), beat(beat){};
    };
    class bomb{ //bomb class
        public:
        int x,y;
        float beat;
        bomb(int x, int y, float beat) : x(x),y(y),beat(beat) {};
    };
    class wall{ //wall class
    public:
        int y,x,width,height;
        float duration, beat;
        wall(int x, int y, int width, int height, float duration,float beat) : y(y),x(x),width(width),height(height),duration(duration), beat(beat) {};
    };
    class colorBoostEvent{ //colorBoostEvent class
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
    class slider{ //Slider class
        public:
        int color,sliderMidAnchorMode;
        BGOBJ::sliderpart sliderHead,sliderTail;
        slider(int color, int sliderMidAnchorMode, BGOBJ::sliderpart sliderHead, BGOBJ::sliderpart sliderTail) : color(color), sliderMidAnchorMode(sliderMidAnchorMode), sliderHead(sliderHead), sliderTail(sliderTail) {};
    };

    class autoSlider{ //autoSlider class
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
    class burstSlider{ //BurstSlider class
        public:
        float squish;
        int color,segmentCount;
        BGOBJ::burstSliderpart sliderHead,sliderTail;
        burstSlider(int color, int segmentCount, float squish, BGOBJ::burstSliderpart sliderHead, BGOBJ::burstSliderpart sliderTail) : color(color), segmentCount(segmentCount), squish(squish), sliderHead(sliderHead), sliderTail(sliderTail) {};
    };
    class basicEvent{ //BasicEvent class for BeatGen
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
    class lightColorEvent{ //LightColorEvent class
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
    class lightRotationEvent{ //LightRotationEvent class
        public:
        float beat;
        int group;
       std::vector<BGOBJ::lightRotationEventBoxContainer> eventBoxes;
        lightRotationEvent(float beat, int group, std::vector<BGOBJ::lightRotationEventBoxContainer> eventBoxes) : beat(beat), group(group), eventBoxes(eventBoxes) {};
    };
}

namespace BeatGen {
    class BeatGenContainer { //Container class for BeatGen Objects
        public:
            std::string version;
            std::vector<std::shared_ptr<BGOBJ::basicEvent>> beatGenBasicEvents;
            std::vector<std::shared_ptr<BGOBJ::note>> beatGenNotes;	
            std::vector<std::shared_ptr<BGOBJ::wall>> beatGenWalls;
            std::vector<std::shared_ptr<BGOBJ::slider>> beatGenSliders;
            std::vector<std::shared_ptr<BGOBJ::autoSlider>> beatGenAutoSliders;
            std::vector<std::shared_ptr<BGOBJ::burstSlider>> beatGenBurstSliders;
            std::vector<std::shared_ptr<BGOBJ::bomb>> beatGenBombs;
            std::vector<std::shared_ptr<BGOBJ::bpmEvent>> beatGenBpmEvents;
            std::vector<std::shared_ptr<BGOBJ::rotationEvent>> beatGenRotationEvents;
            std::vector<std::shared_ptr<BGOBJ::colorBoostEvent>> beatGenColorBoostEvents;
            std::vector<std::shared_ptr<BGOBJ::lightColorEvent>> beatGenLightColorEvents;
            std::vector<std::shared_ptr<BGOBJ::lightRotationEvent>> beatGenLightRotationEvents;
            bool nomalCompatible;
            BeatGenContainer(bool normalCompatible, std::string version) : nomalCompatible(normalCompatible), version(version) {}
    };
}

#endif