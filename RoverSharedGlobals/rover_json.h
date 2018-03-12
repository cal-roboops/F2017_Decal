#ifndef ROVER_JSON_H
#define ROVER_JSON_H

#include <utility>
#include <cstdint>
#include <list>
#include <initializer_list>

// Keys enum
typedef enum {
    // Critical Controls
    EMERGENCY_STOP = 0,
    SHUT_DOWN,

    // Start of DRIVE controls
    DT_M_Speed,

    DT_M_LD,
    DT_M_RD,

    // MUST REMAIN IN ORDER
    // ----------------
    DT_S_LF,
    DT_S_LM,
    DT_S_LB,
    DT_S_RF,
    DT_S_RM,
    DT_S_RB,
    // ----------------

    DRIVE_END,
    // Start of ARM controls
    ARM_BASE_ANGLE,
    ARM_BIFORM_ANGLE,
    ARM_ELBOW_ANGLE,

    ARM_END,
    // START of OTHER controls
    CAMERA_PAN,
    CAMERA_TILT,
    DRAWER_OPEN,

    ENUM_END
} rover_keys;

// Dynamic JSON creation
class Rover_JSON
{
public:
    Rover_JSON() { return; }
    ~Rover_JSON() { return; }

    static uint8_t motor_stop;
    static uint8_t motor_forward;
    static uint8_t motor_backward;

    static uint8_t servo_zero;
    static uint8_t servo_fourfive;
    static uint8_t servo_negfourfive;
    static uint8_t servo_ninezero;

    static std::list<uint8_t> zeroAll;

    static std::list<uint8_t> stopDrive;
    static std::list<uint8_t> forwardDrive;
    static std::list<uint8_t> backwardDrive;

    static std::list<uint8_t> straightServo;
    static std::list<uint8_t> spinCenterServo;
    static std::list<uint8_t> sidewinderServo;

    static bool isValid(std::list<uint8_t> jsonVEC);
};

// Precompiled JSONs for custom positions/targets


#endif // ROVER_JSON_H
