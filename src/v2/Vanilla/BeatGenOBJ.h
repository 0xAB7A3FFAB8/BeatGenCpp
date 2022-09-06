#ifndef BEATGENOBJ_H_
#define BEATGENOBJ_H_

namespace BGOBJ {
    class note{
        public:
        float beat;
        int x,y,type,direction;
        note(int x,int y, int type, int direction,float beat): x(x), y(y), type(type), direction(direction), beat(beat) {};
    };
    class wall{
        public:
        int x,width,type;
        float duration,beat;
        wall(int x, int width, int type, float duration, float beat) : x(x),width(width),type(type),duration(duration),beat(beat) {};
    };
    class event{
        public:
        int type,value;
        float valuef,beat;
        event(int type, int value, float valuef, float beat) : type(type), value(value), valuef(valuef), beat(beat) {};
    };
}

#endif