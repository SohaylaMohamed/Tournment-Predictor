//
// Created by sohayla on 13/03/19.
//

#ifndef TOURNMENT_PREDICTOR_LOCALPREDICTOR_H
#define TOURNMENT_PREDICTOR_LOCALPREDICTOR_H

#include <string>
#include "State.h"

using namespace std;
class LocalPredictor {
private:
    string index;
    State *currentState;
public:
    LocalPredictor(string index);
    bool getLocalPrediction();
    void updateTaken();
    void updateNotTaken();
    string getIndex();
    void updateState(bool branchResolution);

};


#endif //TOURNMENT_PREDICTOR_LOCALPREDICTOR_H
