#ifndef BPMEVENT_H_
#define BPMEVENT_H_

namespace BeatGenOBJ {
    class bpmEvent {
        public:
        float bpm, beat;
        bpmEvent(float bpm,float beat) :bpm(bpm), beat(beat) {};

    };
    class rotationEvent {
        public:
        float beat,rotation;
        bool early;
        rotationEvent(float beat,float rotation, bool early):beat(beat),rotation(rotation),early(early){};
    };
    class note{
        public:
        float beat;
        int x,y,color,direction,angle_offset;
        note(int x,int y, int color, int direction,int angle_offset,float beat): x(x), y(y), color(color), direction(direction), angle_offset(angle_offset), beat(beat){};
    };
    class bomb{
        public:
        int x,y;
        float beat;
        bomb(int x, int y, float beat) : x(x),y(y),beat(beat) {};
    };
    class wall{
        int y,x,width,hight;
        float duration;
        wall(int y, int x, int width, int hight, float duration) : y(y),x(x),width(width),hight(hight),duration(duration) {};
    };
    class colorBoostEvent{
        float beat;
        bool on;
        colorBoostEvent(float beat, bool on) : beat(beat), on(on) {};
    };
    
}

#endif