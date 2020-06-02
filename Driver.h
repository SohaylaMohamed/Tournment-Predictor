//
// Created by sohayla on 13/03/19.
//

#ifndef TOURNMENT_PREDICTOR_DRIVER_H
#define TOURNMENT_PREDICTOR_DRIVER_H

#include <map>
#include "LocalPredictor.h"
#include "Selector.h"
#include "GlobalPredictor.h"

using namespace std;
class Driver {
private:
    map<string, Selector*> selectorMap;
    map<string, LocalPredictor*> localMap;
    map<string, GlobalPredictor*> globalMap;
    int correctLocal, correctGlobal, correctTournment;
    string local, global;
    string globalIndex;
    void updateGlobalIndex(bool prediction);

public:
    Driver();
    string getSelectorPrediction(string index, bool correctPrediction, bool localPrediction, bool globalPrediction);
    bool getGlobalPrediction(bool correctPrediction);
    bool getLocalPrediction(string index, bool correctPrediction);
    bool getCorrectPrediction(bool local_p, bool global_p, string selector_p);
    void updateCorrectness(bool local_p, bool global_p, bool final, bool correct);
    int getcorrectLocal();
    int getCorrectGlobal();
    int getCorrectTournment();
};


#endif //TOURNMENT_PREDICTOR_DRIVER_H
