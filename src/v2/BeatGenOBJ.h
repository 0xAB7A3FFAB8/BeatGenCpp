#ifndef BEATGENOBJ_H_
#define BEATGENOBJ_H_

#include <memory>
#include <string>
#include <vector>

namespace BGOBJ {
    class note{ //Note class for BeatGen
        public:
        float beat;
        int x,y,type,direction;
        note(int x,int y, int type, int direction,float beat): x(x), y(y), type(type), direction(direction), beat(beat) {};
    };
    class wall{ //Wall class for BeatGen
        public:
        int x,width,type;
        float duration,beat;
        wall(int x, int width, int type, float duration, float beat) : x(x),width(width),type(type),duration(duration),beat(beat) {};
    };
    class event{ //Event class for BeatGen
        public:
        int type,value;
        float valuef,beat;
        event(int type, int value, float valuef, float beat) : type(type), value(value), valuef(valuef), beat(beat) {};
    };
    class sliderpart{ //Sliderpart class for Sliders
        public:
        int x,y,direction;
        float controlPointLengthMultiplier, beat;
        sliderpart(int x,int y, int direction,float controlPointLengthMultiplier,float beat): x(x), y(y), direction(direction), controlPointLengthMultiplier(controlPointLengthMultiplier), beat(beat) {};
    };
    class slider{
        public:
        int type,sliderMidAnchorMode;
        BGOBJ::sliderpart sliderHead,sliderTail;
        slider(int type, int sliderMidAnchorMode, BGOBJ::sliderpart sliderHead, BGOBJ::sliderpart sliderTail) : type(type), sliderMidAnchorMode(sliderMidAnchorMode), sliderHead(sliderHead), sliderTail(sliderTail) {};
    };
}
namespace BeatGen {
    class BeatGenContainer { //Container class for BeatGen Objects
        public:
            std::string version;
            std::vector<BGOBJ::event> beatGenEvents;
            std::vector<BGOBJ::note> beatGenNotes;	
            std::vector<BGOBJ::wall> beatGenWalls;
            std::vector<BGOBJ::slider> beatGenSliders;
            std::vector<BGOBJ::slider> beatGenAutoSliders;
    };
}

#endif