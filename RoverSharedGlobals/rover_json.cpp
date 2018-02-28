#include "rover_json.h"

char* Rover_JSON::make_json(std::initializer_list<std::pair<int, int>> kv)
{
    std::size_t kSize= kv.size();
    char* jsonSTR = new char[(2*kSize)+1];

    int pos;
    for (int i = 0; i < kSize; i++)
    {
        pos = 2*i;
        jsonSTR[pos] = kv[i].first();
        jsonSTR[pos+1] = kv[i].seocnd();
    }
    jsonSTR[kSize] = '\0';

    return jsonSTR;
}

void Rover_JSON::cleanup_json(char* jsonSTR)
{
    delete jsonSTR;
}

bool Rover_JSON::valid_json(char* str)
{
    return ((strlen(str) % 2) == 0)
}
