#ifndef BEATGENTOKS_H_
#define BEATGENTOKS_H_

/*
All tokens used by BeatGen
These tokens are used to make the code more readable
*/



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
    enum Type {
        Red = 0,
        LeftColor = 0,
        Blue = 1,
        RightColor = 1,
        Bomb = 3,
        Unused = 2,
        FullHight = 0,
        CrouchHight = 1
    };
    namespace Events {
        namespace value {
            enum Type {
                Off = 0,
                On_R = 1,
                Flash_R = 2,
                Fade_R = 3,
                Transition_R = 4,
                On_L = 5,
                Flash_L = 6,
                Fade_L = 7,
                Transition_L = 8,
                On_W = 9,
                Flash_W = 10,
                Fade_W = 11,
                Transition_W = 12,
                BoostOff = 0,
                BoostOn = 1,
                AllCarsNoHydraulics = 0,
                AllCars = 1,
                LeftCars = 2,
                RightCars = 3,
                FrontCars = 4,
                FrontMiddleCars = 5,
                BackMiddleCars = 6,
                BackCars = 7
            };
        }
        enum Events{
            BackLaser = 0,
            RingLaser = 1,
            LeftRotatingLaser = 2,
            RightRotatingLaser = 3,
            CenterLight = 4,
            BoostLightColor = 5,
            ExtraLeftLight = 6,
            ExtraRightLight = 7,
            RingSpin = 8,
            RingZoom = 9,
            LeftRotatingLaserSpeed = 12,
            RightRotatingLaserSpeed = 13,
            EarlyRotate = 14,
            LateRotate = 15
        };
        namespace gaga {
            enum Events{
                MiddleLeftTowerHight = 16,
                MiddleRightTowerHight = 17,
                OuterLeftTowerHight = 18,
                OuterRightTowerHight = 19
            };
        }
        namespace billie {
            enum Events{
                LeftSideLaser = 10,
                RightSideLaser = 11,

            };
        }
         namespace interscope {
            enum Events{
                LowerCarHydraulics = 16,
                RiseCarHydraulics = 17,
            };
        }
        namespace RotateLevels {
            enum Events{
                SixtyDGCCW = 0,
                FourtyFiveDGCCW = 1,
                ThirtyDGCCW = 2,
                FifteenDGCCW = 3,
                FifteenDGCW = 4,
                ThirtyDGCW = 5,
                FourtyFiveDGCW = 6,
                SixtyDGCW = 7
            };
        }
    }
}

#endif