#ifndef BEAT_GEN_READER_H_
#define BEAT_GEN_READER_H_


#include <string>
#include "BeatGenOBJ.h"

namespace BGR {
    BeatGen::BeatGenContainer readJson(std::string json); // this function creates an BGC object based on an given String in Json format.
}


#endif