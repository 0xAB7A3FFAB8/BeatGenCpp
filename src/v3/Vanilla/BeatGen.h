#ifndef BEATGEN_H_
#define BEATGEN_H_

#include "BeatGenOBJ.h"
#include "BeatGen.cpp"
#include <string>
#include <vector>
#ifndef LIB_JSONCPP_JSON_TOOL_H_INCLUDED
#include "dist/jsoncpp.cpp"
#endif

namespace BeatGen {
    std::string genJson(BeatGenContainer BGC ,bool Styled);

    Json::Value genCustomDatan(BGOBJ::CustomData CD);

    extern std::vector<std::string> ids;
}

#endif