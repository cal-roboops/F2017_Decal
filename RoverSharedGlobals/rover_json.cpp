#include "rover_json.h"
#include <string.h>

std::list<uint8_t> Rover_JSON::zeroAll {
                                            rover_keys::DT_M_LD, motor_dirs::motor_stop,
                                            rover_keys::DT_M_RD, motor_dirs::motor_stop,

                                            rover_keys::DT_S_LF, servo_dirs::servo_zero,
                                            rover_keys::DT_S_LM, servo_dirs::servo_zero,
                                            rover_keys::DT_S_LB, servo_dirs::servo_zero,

                                            rover_keys::DT_S_RF, servo_dirs::servo_zero,
                                            rover_keys::DT_S_RM, servo_dirs::servo_zero,
                                            rover_keys::DT_S_RB, servo_dirs::servo_zero
                                      };

std::list<uint8_t> Rover_JSON::stopDrive {
                                            rover_keys::DT_M_LD, motor_dirs::motor_stop,
                                            rover_keys::DT_M_RD, motor_dirs::motor_stop
                                      };

std::list<uint8_t> Rover_JSON::forwardDrive {
                                            rover_keys::DT_M_LD, motor_dirs::motor_forward,
                                            rover_keys::DT_M_RD, motor_dirs::motor_forward
                                      };

std::list<uint8_t> Rover_JSON::backwardDrive {
                                            rover_keys::DT_M_LD, motor_dirs::motor_backward,
                                            rover_keys::DT_M_RD, motor_dirs::motor_backward
                                      };

std::list<uint8_t> Rover_JSON::straightServo {
                                            rover_keys::DT_S_LF, servo_dirs::servo_zero,
                                            rover_keys::DT_S_LM, servo_dirs::servo_zero,
                                            rover_keys::DT_S_LB, servo_dirs::servo_zero,

                                            rover_keys::DT_S_RF, servo_dirs::servo_zero,
                                            rover_keys::DT_S_RM, servo_dirs::servo_zero,
                                            rover_keys::DT_S_RB, servo_dirs::servo_zero
                                      };

std::list<uint8_t> Rover_JSON::spinCenterServo {
                                            rover_keys::DT_S_LF, servo_dirs::servo_fourfive,
                                            rover_keys::DT_S_LM, servo_dirs::servo_zero,
                                            rover_keys::DT_S_LB, servo_dirs::servo_negfourfive,

                                            rover_keys::DT_S_RF, servo_dirs::servo_fourfive,
                                            rover_keys::DT_S_RM, servo_dirs::servo_zero,
                                            rover_keys::DT_S_RB, servo_dirs::servo_negfourfive
                                      };

std::list<uint8_t> Rover_JSON::sidewinderServo {
                                            rover_keys::DT_S_LF, servo_dirs::servo_ninezero,
                                            rover_keys::DT_S_LM, servo_dirs::servo_ninezero,
                                            rover_keys::DT_S_LB, servo_dirs::servo_ninezero,

                                            rover_keys::DT_S_RF, servo_dirs::servo_ninezero,
                                            rover_keys::DT_S_RM, servo_dirs::servo_ninezero,
                                            rover_keys::DT_S_RB, servo_dirs::servo_ninezero
                                      };

bool Rover_JSON::isValid(std::list<uint8_t> jsonVEC)
{
    return ((jsonVEC.size() % 2) == 0);
}
