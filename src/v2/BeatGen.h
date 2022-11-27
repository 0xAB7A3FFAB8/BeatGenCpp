#ifndef BEATGEN_H_
#define BEATGEN_H_

#include "BeatGenOBJ.h"

namespace BeatGen {
    std::string genJson(BeatGenContainer& BGC,bool FastWrite); // this function creates an BGC object based on an given String in Json format.
}

#endif