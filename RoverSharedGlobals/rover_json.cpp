#include "rover_json.h"
#include <string.h>

uint8_t Rover_JSON::motor_stop = 0;
uint8_t Rover_JSON::motor_forward = 1;
uint8_t Rover_JSON::motor_backward = 2;

uint8_t Rover_JSON::servo_zero = 45;
uint8_t Rover_JSON::servo_fourfive = servo_zero+45;
uint8_t Rover_JSON::servo_negfourfive = servo_zero-45;
uint8_t Rover_JSON::servo_ninezero = servo_zero+90;

std::list<uint8_t> Rover_JSON::zeroAll {
                                            rover_keys::DT_M_LF, Rover_JSON::motor_stop,
                                            rover_keys::DT_M_LM, Rover_JSON::motor_stop,
                                            rover_keys::DT_M_LB, Rover_JSON::motor_stop,

                                            rover_keys::DT_M_RF, Rover_JSON::motor_stop,
                                            rover_keys::DT_M_RM, Rover_JSON::motor_stop,
                                            rover_keys::DT_M_RB, Rover_JSON::motor_stop,

                                            rover_keys::DT_S_LF, Rover_JSON::servo_zero,
                                            rover_keys::DT_S_LM, Rover_JSON::servo_zero,
                                            rover_keys::DT_S_LB, Rover_JSON::servo_zero,

                                            rover_keys::DT_S_RF, Rover_JSON::servo_zero,
                                            rover_keys::DT_S_RM, Rover_JSON::servo_zero,
                                            rover_keys::DT_S_RB, Rover_JSON::servo_zero
                                      };

std::list<uint8_t> Rover_JSON::stopDrive {
                                            rover_keys::DT_M_LD, Rover_JSON::motor_stop,
                                            rover_keys::DT_M_RD, Rover_JSON::motor_stop
                                      };

std::list<uint8_t> Rover_JSON::forwardDrive {
                                            rover_keys::DT_M_LD, Rover_JSON::motor_forward,
                                            rover_keys::DT_M_RD, Rover_JSON::motor_forward
                                      };

std::list<uint8_t> Rover_JSON::backwardDrive {
                                            rover_keys::DT_M_LD, Rover_JSON::motor_backward,
                                            rover_keys::DT_M_RD, Rover_JSON::motor_backward
                                      };

std::list<uint8_t> Rover_JSON::zeroServo {
                                            rover_keys::DT_S_LF, Rover_JSON::servo_zero,
                                            rover_keys::DT_S_LM, Rover_JSON::servo_zero,
                                            rover_keys::DT_S_LB, Rover_JSON::servo_zero,

                                            rover_keys::DT_S_RF, Rover_JSON::servo_zero,
                                            rover_keys::DT_S_RM, Rover_JSON::servo_zero,
                                            rover_keys::DT_S_RB, Rover_JSON::servo_zero
                                      };

std::list<uint8_t> Rover_JSON::fourfiveServo {
                                            rover_keys::DT_S_LF, Rover_JSON::servo_fourfive,
                                            rover_keys::DT_S_LM, Rover_JSON::servo_zero,
                                            rover_keys::DT_S_LB, Rover_JSON::servo_negfourfive,

                                            rover_keys::DT_S_RF, Rover_JSON::servo_negfourfive,
                                            rover_keys::DT_S_RM, Rover_JSON::servo_zero,
                                            rover_keys::DT_S_RB, Rover_JSON::servo_fourfive
                                      };

std::list<uint8_t> Rover_JSON::ninezeroServo {
                                            rover_keys::DT_S_LF, Rover_JSON::servo_ninezero,
                                            rover_keys::DT_S_LM, Rover_JSON::servo_ninezero,
                                            rover_keys::DT_S_LB, Rover_JSON::servo_ninezero,

                                            rover_keys::DT_S_RF, Rover_JSON::servo_ninezero,
                                            rover_keys::DT_S_RM, Rover_JSON::servo_ninezero,
                                            rover_keys::DT_S_RB, Rover_JSON::servo_ninezero
                                      };

bool Rover_JSON::isValid(std::list<uint8_t> jsonVEC)
{
    return ((jsonVEC.size() % 2) == 0);
}
