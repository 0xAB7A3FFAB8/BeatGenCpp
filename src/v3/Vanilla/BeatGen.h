#ifndef BEATGEN_H_
#define BEATGEN_H_

#include "BeatGenOBJ.h"
#include "BeatGen.cpp"
#include <string>

namespace BeatGen {
    std::string genJson(BeatGenContainer BGC ,bool Styled);
}

#endif