#ifndef BEATGEN_H_
#define BEATGEN_H_

#include "BeatGenOBJ.h"
#include <string>
#include <vector>
#include "include/json/value.h"

namespace BeatGen {
    std::string genJson(BeatGenContainer BGC ,bool Styled);

    //Json::Value genCustomDatan(BGOBJ::CustomData CD);

    //extern std::vector<std::string> ids;
}

#endif