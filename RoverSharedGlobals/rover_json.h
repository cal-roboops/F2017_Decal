#ifndef ROVER_JSON_H
#define ROVER_JSON_H

#include <utility>
#include <cstdint>
#include <list>
#include <initializer_list>

// Keys enum
typedef enum {
    DT_M_Speed = 0,

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
    DT_S_RB
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

    static char* zeroAll;

    static char* stopDrive;
    static char* forwardDrive;
    static char* backwardDrive;

    static char* zeroServo;
    static char* fourfiveServo;
    static char* ninezeroServo;

    static char* make_json(std::initializer_list<std::pair<uint8_t, uint8_t>> kv);
    static void cleanup_json(char* jsonSTR);
    static bool valid_json(char* jsonSTR);
};

// Precompiled JSONs for custom positions/targets


#endif // ROVER_JSON_H
