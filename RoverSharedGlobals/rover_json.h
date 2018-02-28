#ifndef ROVER_JSON_H
#define ROVER_JSON_H

#include <utility>
#include <list>
#include <initializer_list>

// Keys enum
typedef enum {
    DT_M_RD = 0,
    DT_M_LD,
    DT_S_FL,
    DT_S_FR,
    DT_S_ML,
    DT_S_MR,
    DT_S_BL,
    DT_S_BR
} rover_keys;

// Precompiled JSONs for custom positions/targets

// Dynamic JSON creation
class Rover_JSON
{
public:
    Rover_JSON() { return; }
    ~Rover_JSON() { return; }

    static char* make_json(std::initializer_list<std::pair<int, int>> kv);
    static void cleanup_json(char* jsonSTR);
    static bool valid_json(std::pair<int, int> kv);
};

#endif // ROVER_JSON_H
