#include "RvX_LIS3DH_TB.h"

RvX_LIS3DH_TB::TapOn RvX_LIS3DH_TB::getTap() { 
    return TapOn::NONE;
}

void RvX_LIS3DH_TB::read(void) {
    Adafruit_LIS3DH::read();

    float x_norm = sin(45) * y_g + cos(45) * z_g;
    float y_norm = cos(45) * y_g - sin(45) * z_g;
    float z_norm = -x_g; 

    pitch = atan2(-x_norm, sqrt(y_norm * y_norm + z_norm * z_norm)) * 180 / M_PI;
    roll = atan2(y_norm, z_norm) * 180 / M_PI;
    _calcOrientation();
}

void RvX_LIS3DH_TB::_calcOrientation() {
    orientation = Orientation::NONE;
    float nearest_distance = 900;
    for (int i = 1; i < 15; ++i) {
        //float pitch_distance = fabs(pitch - pitchRoll[i][0]);
        //float roll_distance = fabs(roll - pitchRoll[i][1]);
        float pitch_distance = fabs(fmod(pitch - pitchRoll[i][0] + 540.0, 360.0) - 180.0);
        float roll_distance = fabs(fmod(roll - pitchRoll[i][1] + 540.0, 360.0) - 180.0);
        float current_distance = (pitch_distance + roll_distance) / pitchRoll[i][2];
        if (current_distance < nearest_distance) {
            nearest_distance = current_distance;
            orientation = (Orientation)i;
        }
    }
}