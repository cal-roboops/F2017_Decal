#include "rover_json.h"
#include <string.h>

uint8_t Rover_JSON::motor_stop = 0;
uint8_t Rover_JSON::motor_forward = 1;
uint8_t Rover_JSON::motor_backward = 2;

uint8_t Rover_JSON::servo_zero = 45;
uint8_t Rover_JSON::servo_fourfive = servo_zero+45;
uint8_t Rover_JSON::servo_negfourfive = servo_zero-45;
uint8_t Rover_JSON::servo_ninezero = servo_zero+90;

char* Rover_JSON::zeroAll = Rover_JSON::make_json({
                                            {rover_keys::DT_M_LF, Rover_JSON::motor_stop},
                                            {rover_keys::DT_M_LM, Rover_JSON::motor_stop},
                                            {rover_keys::DT_M_LB, Rover_JSON::motor_stop},

                                            {rover_keys::DT_M_RF, Rover_JSON::motor_stop},
                                            {rover_keys::DT_M_RM, Rover_JSON::motor_stop},
                                            {rover_keys::DT_M_RB, Rover_JSON::motor_stop},

                                            {rover_keys::DT_S_LF, Rover_JSON::servo_zero},
                                            {rover_keys::DT_S_LM, Rover_JSON::servo_zero},
                                            {rover_keys::DT_S_LB, Rover_JSON::servo_zero},

                                            {rover_keys::DT_S_RF, Rover_JSON::servo_zero},
                                            {rover_keys::DT_S_RM, Rover_JSON::servo_zero},
                                            {rover_keys::DT_S_RB, Rover_JSON::servo_zero}
                                      });

char* Rover_JSON::stopDrive = Rover_JSON::make_json({
                                            {rover_keys::DT_M_LD, Rover_JSON::motor_stop},
                                            {rover_keys::DT_M_RD, Rover_JSON::motor_stop},
                                      });

char* Rover_JSON::forwardDrive = Rover_JSON::make_json({
                                            {rover_keys::DT_M_LD, Rover_JSON::motor_forward},
                                            {rover_keys::DT_M_RD, Rover_JSON::motor_forward},
                                      });

char* Rover_JSON::backwardDrive = Rover_JSON::make_json({
                                            {rover_keys::DT_M_LD, Rover_JSON::motor_backward},
                                            {rover_keys::DT_M_RD, Rover_JSON::motor_backward},
                                      });

char* Rover_JSON::zeroServo = Rover_JSON::make_json({
                                            {rover_keys::DT_S_LF, Rover_JSON::servo_zero},
                                            {rover_keys::DT_S_LM, Rover_JSON::servo_zero},
                                            {rover_keys::DT_S_LB, Rover_JSON::servo_zero},

                                            {rover_keys::DT_S_RF, Rover_JSON::servo_zero},
                                            {rover_keys::DT_S_RM, Rover_JSON::servo_zero},
                                            {rover_keys::DT_S_RB, Rover_JSON::servo_zero}
                                      });

char* Rover_JSON::fourfiveServo = Rover_JSON::make_json({
                                            {rover_keys::DT_S_LF, Rover_JSON::servo_fourfive},
                                            {rover_keys::DT_S_LM, Rover_JSON::servo_zero},
                                            {rover_keys::DT_S_LB, Rover_JSON::servo_negfourfive},

                                            {rover_keys::DT_S_RF, Rover_JSON::servo_negfourfive},
                                            {rover_keys::DT_S_RM, Rover_JSON::servo_zero},
                                            {rover_keys::DT_S_RB, Rover_JSON::servo_fourfive}
                                      });

char* Rover_JSON::ninezeroServo = Rover_JSON::make_json({
                                            {rover_keys::DT_S_LF, Rover_JSON::servo_ninezero},
                                            {rover_keys::DT_S_LM, Rover_JSON::servo_ninezero},
                                            {rover_keys::DT_S_LB, Rover_JSON::servo_ninezero},

                                            {rover_keys::DT_S_RF, Rover_JSON::servo_ninezero},
                                            {rover_keys::DT_S_RM, Rover_JSON::servo_ninezero},
                                            {rover_keys::DT_S_RB, Rover_JSON::servo_ninezero}
                                      });

char* Rover_JSON::make_json(std::initializer_list<std::pair<uint8_t, uint8_t>> kv)
{
    std::size_t kSize= kv.size();
    char* jsonSTR = new char[(2*kSize)+1];

    int pos = 0;
    for (auto curr = kv.begin(); curr != kv.end(); ++curr)
    {        
        jsonSTR[pos] = curr->first;
        jsonSTR[pos+1] = curr->second;
        pos += 2;
    }
    jsonSTR[kSize] = '\0';

    return jsonSTR;
}

void Rover_JSON::cleanup_json(char* jsonSTR)
{
    delete jsonSTR;
}

bool Rover_JSON::valid_json(char* jsonSTR)
{
    return ((strlen(jsonSTR) % 2) == 0);
}
