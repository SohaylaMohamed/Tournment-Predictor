//
// Created by sohayla on 13/03/19.
//

#ifndef TOURNMENT_PREDICTOR_SELECTOR_H
#define TOURNMENT_PREDICTOR_SELECTOR_H

#include <string>
#include <map>
#include "State.h"

using namespace std;
class Selector {
private:
    string index;
    State *currentState;
public:
    Selector(string index);
    string getSelection();
    void updateSelectionState(bool local, bool global, bool actual);
    string getIndex();
};


#endif //TOURNMENT_PREDICTOR_SELECTOR_H
