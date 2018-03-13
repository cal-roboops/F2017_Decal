#ifndef ROVER_JSON_H
#define ROVER_JSON_H

#include <utility>
#include <cstdint>
#include <list>
#include <initializer_list>

// Keys enum
typedef enum {
    // Critical/General Controls
    EMERGENCY_STOP = 0,
    SHUT_DOWN,

    // MUST REMAIN AT END OF CRITICAL SEGMENT
    // ----------------
    CRITICAL_END,
    // ----------------

    // START of DRIVE controls
    DT_M_Speed,

    DT_M_LD, // Value: 0 - Stop, 1 - Forward, 2 - Backward
    DT_M_RD, // Value: 0 - Stop, 1 - Forward, 2 - Backward

    // MUST REMAIN IN ORDER
    // ----------------
    DT_S_LF,
    DT_S_LM,
    DT_S_LB,
    DT_S_RF,
    DT_S_RM,
    DT_S_RB,
    // ----------------

    // MUST REMAIN AT END OF DRIVE SEGMENT
    // ----------------
    DRIVE_END,
    // ----------------

    // START of ARM controls
    ARM_BASE_ANGLE_UPPER,
    ARM_BASE_ANGLE_LOWER,
    ARM_BIFORM_ANGLE_UPPER,
    ARM_BIFORM_ANGLE_LOWER,
    ARM_ELBOW_ANGLE_UPPER,
    ARM_ELBOW_ANGLE_LOWER,

    // MUST REMAIN AT END OF ARM SEGMENT
    // ----------------
    ARM_END,
    // ----------------

    // START of OTHER controls
    CAMERA_PAN,
    CAMERA_TILT,
    DRAWER_OPEN,
    COMM_CONN, // Value: 0 - Disconnect, 1 - Connect
    EMERG_CONN, // Value: 0 - Disconnect, 1 - Connect
    COMMAND_STATUS, // Value: 0 - Success, 1 - Failed, 2 - Dropped

    // MUST REMAIN AT END OF ENUM
    // ----------------
    ENUM_END
    // ----------------
} rover_keys;

typedef enum {
    motor_stop = 0,
    motor_forward,
    motor_backward
} motor_dirs;

typedef enum {
    servo_zero = 90,
    servo_fourfive = servo_zero+45,
    servo_negfourfive = servo_zero-45,
    servo_ninezero = servo_zero+90,
} servo_dirs;

// Dynamic JSON creation
class Rover_JSON
{
public:
    Rover_JSON() { return; }
    ~Rover_JSON() { return; }

    static std::list<uint8_t> zeroAll;

    static std::list<uint8_t> stopDrive;
    static std::list<uint8_t> forwardDrive;
    static std::list<uint8_t> backwardDrive;

    static std::list<uint8_t> straightServo;
    static std::list<uint8_t> spinCenterServo;
    static std::list<uint8_t> sidewinderServo;

    static bool isValid(std::list<uint8_t> jsonVEC);
};


#endif // ROVER_JSON_H
