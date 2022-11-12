#ifndef BEATGEN_H_
#define BEATGEN_H_

#include "BeatGenOBJ.hpp"
#include <string>
#include <vector>
#include "include/json/writer.h"

namespace BeatGen {
    std::string genJson(BeatGenContainer BGC ,bool Styled);

    Json::Value genCustomDatan(BGOBJ::CustomData CD);

    extern std::vector<std::string> ids;
}

#endif