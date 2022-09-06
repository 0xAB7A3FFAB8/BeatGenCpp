#ifndef BEATGENTOKS_H_
#define BEATGENTOKS_H_

namespace BGToks {
    enum Direction {
        Up = 0,
        Down = 1,
        Left = 2,
        Right = 3,
        UpLeft = 4,
        UpRight = 5,
        DownLeft = 6,
        DownRight = 7,
        Any = 8
    };
    enum Color {
        Red = 0,
        LeftColor = 0,
        Blue = 1,
        RightColor = 1, 
    };
}

#endif