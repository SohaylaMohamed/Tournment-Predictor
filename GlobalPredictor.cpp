//
// Created by sohayla on 13/03/19.
//

#include "GlobalPredictor.h"

GlobalPredictor::GlobalPredictor(string index) {
    this->index = index;
    this->currentState = new State();
}

bool GlobalPredictor::getGlobalPrediction() {
    int counterValue = currentState->getState();
    if(counterValue > 1) {
        return true;
    }

    return false;
}

void GlobalPredictor::updateNotTaken() {
    this->currentState->decrementState();
}

void GlobalPredictor::updateTaken() {
    this->currentState->incrementState();
}


void GlobalPredictor::updateState(bool branchResolution) {
    if(branchResolution) {
        this->updateTaken();
    } else {
        this->updateNotTaken();
    }
}

string GlobalPredictor::getIndex() {
    return this->index;
}