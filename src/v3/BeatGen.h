#ifndef BEATGEN_H_
#define BEATGEN_H_

#include "BeatGenOBJ.h"
#include <string>
#include <vector>

namespace BeatGen {
    std::string genJson(BeatGenContainer& BGC ,bool Styled); //this Function Generates the json of an BGC object, when the Styled flag is true it will create an stilized json output

    //Json::Value genCustomDatan(BGOBJ::CustomData CD);

    //extern std::vector<std::string> ids;
}

#endif