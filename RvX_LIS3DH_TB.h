#ifndef RvX_LIS3DH_TB_h
#define RvX_LIS3DH_TB_h
#include <Adafruit_LIS3DH.h>
#include <math.h>

class RvX_LIS3DH_TB : public Adafruit_LIS3DH {
    public:
        enum class Orientation : uint8_t {
            NONE = 0x00,
            EARS_UP = 0x01, 
            EARS_UP_LEFT = 0x02, 
            EARS_LEFT = 0x03, 
            EARS_DOWN_LEFT = 0x04, 
            EARS_DOWN = 0x05, 
            EARS_DOWN_RIGHT = 0x06, 
            EARS_RIGHT = 0x07, 
            EARS_UP_RIGHT = 0x08,
            EARS_FRONT = 0x09,
            EARS_FRONT_UP = 0x0A,
            EARS_FRONT_DOWN = 0x0B,
            EARS_BACK = 0x0C,
            EARS_BACK_UP = 0x0D,
            EARS_BACK_DOWN = 0x0E
        };
        enum class TapOn : uint8_t {
            NONE = 0x00,
            LEFT = 0x01,
            RIGHT = 0x02,
            FRONT = 0x04,
            BACK = 0x08,
            TOP = 0x10,
            BOTTOM = 0x20,

            LEFT_FRONT = LEFT + FRONT,
            RIGHT_FRONT = RIGHT + FRONT,
            LEFT_BACK = LEFT + BACK,
            RIGHT_BACK = RIGHT + BACK
        };

        RvX_LIS3DH_TB::TapOn getTap(); 
        void read(void);
        
        float pitch = 0.0f;
        float roll = 0.0f; 

        RvX_LIS3DH_TB::Orientation orientation = Orientation::NONE;     

    private:

        const float pitchRoll[15][3] = {
            {0.0, 0.0, 0.0},           // NONE
            {0.0, 0.0, 1.0},           // xEARS_UP
            {-45.0, 0.0, 1.0},         // xEARS_UP_LEFT
            {-90.0, -90.0, 1.0},       // xEARS_LEFT
            {-45.0, 180.0, 1.0},       // xEARS_DOWN_LEFT
            {0.0, 180.0, 1.0},         // xEARS_DOWN
            {45.0, 180.0, 1.0},        // xEARS_DOWN_RIGHT
            {90.0, 90.0, 1.0},         // xEARS_RIGHT
            {45.0, 0.0, 1.0},          // xEARS_UP_RIGHT
            {0.0, 90.0, 1.0},          // xEARS_FRONT
            {0.0, 45.0, 1.0},          // xEARS_FRONT_UP
            {0.0, 135.0, 1.0},         // xEARS_FRONT_DOWN
            {0.0, -90.0, 1.0},         // xEARS_BACK
            {0.0, -45.0, 1.0},         // xEARS_BACK_UP
            {0.0, -135.0, 1.0}         // xEARS_BACK_DOWN
        };
        void _calcOrientation();
};

#endif