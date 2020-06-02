//
// Created by sohayla on 13/03/19.
//

#ifndef TOURNMENT_PREDICTOR_GLOBALPREDICTOR_H
#define TOURNMENT_PREDICTOR_GLOBALPREDICTOR_H

#include <string>
#include "State.h"

using namespace std;

class GlobalPredictor {
private:
    string index;
    State *currentState;
public:
    GlobalPredictor(string index);
    bool getGlobalPrediction();
    void updateTaken();
    void updateNotTaken();
    string getIndex();
    void updateState(bool branchResolution);


};


#endif //TOURNMENT_PREDICTOR_GLOBALPREDICTOR_H
