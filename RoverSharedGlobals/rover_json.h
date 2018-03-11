#ifndef ROVER_JSON_H
#define ROVER_JSON_H

#include <utility>
#include <cstdint>
#include <list>
#include <initializer_list>

// Keys enum
typedef enum {
    // Start of DRIVE controls
    DRIVE_START = 0,
    DT_M_Speed,

    DT_M_LD,
    DT_M_RD,

    DT_M_LF,
    DT_M_LM,
    DT_M_LB,

    DT_M_RF,
    DT_M_RM,
    DT_M_RB,

    DT_S_LF,
    DT_S_LM,
    DT_S_LB,

    DT_S_RF,
    DT_S_RM,
    DT_S_RB,

    // Start of ARM controls
    ARM_START,

    // START of OTHER controls
    OTHER_START
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
    static uint8_t servo_ninezero;

    static std::list<uint8_t> zeroAll;

    static std::list<uint8_t> stopDrive;
    static std::list<uint8_t> forwardDrive;
    static std::list<uint8_t> backwardDrive;

    static std::list<uint8_t> zeroServo;
    static std::list<uint8_t> fourfiveServo;
    static std::list<uint8_t> ninezeroServo;

    static bool isValid(std::list<uint8_t> jsonVEC);
};

// Precompiled JSONs for custom positions/targets


#endif // ROVER_JSON_H
