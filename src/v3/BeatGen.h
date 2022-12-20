#ifndef BEATGEN_H_
#define BEATGEN_H_

#include "BeatGenOBJ.h"
#include <string>
#include <vector>
#include "include/json/value.h"

namespace BeatGen {
    std::string genJson(BeatGenContainer& BGC ,bool Styled); //this Function Generates the json string of an BGC object, when the Styled flag is true it will create an stilized json output

    Json::Value genBpmEvent(BGOBJ::bpmEvent bpmEvent); //this function generates the json of a bpmEvent object

    Json::Value genRotationEvent(BGOBJ::rotationEvent rotationEvent); //this function generates the json of a rotationEvent object

    Json::Value genNote(BGOBJ::note note); //this function generates the json of a note object

    Json::Value genBomb(BGOBJ::bomb bomb); //this function generates the json of a bomb object

    Json::Value genWall(BGOBJ::wall wall); //this function generates the json of a wall object

    Json::Value genColorBoostEvent(BGOBJ::colorBoostEvent colorBoostEvent); //this function generates the json of a colorBoostEvent object

    Json::Value genSlider(BGOBJ::slider slider); //this function generates the json of a slider object

    Json::Value genAutoSlider(BGOBJ::autoSlider autoSlider); //this function generates the json of a autoSlider object

    Json::Value genBurstSlider(BGOBJ::burstSlider burstSlider); //this function generates the json of a burstSlider object

    Json::Value genBasicEvent(BGOBJ::basicEvent basicEvent); //this function generates the json of a basicEvent object

    Json::Value genLightColorEvent(BGOBJ::lightColorEvent lightColorEvent); //this function generates the json of a lightColorEvent object

    Json::Value genLightRotationEvent(BGOBJ::lightRotationEvent lightRotationEvent); //this function generates the json of a lightRotationEvent object

    //Json::Value genCustomDatan(BGOBJ::CustomData CD);

    //extern std::vector<std::string> ids;
}

#endif