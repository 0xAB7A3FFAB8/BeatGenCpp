#ifndef BEATGEN_READER_H_
#define BEATGEN_READER_H_

#include <string>
#include "BeatGenOBJ.hpp"


namespace BGR {
    BeatGen::BeatGenContainer readJson(std::string json);
}
#endif