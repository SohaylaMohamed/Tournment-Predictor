//
// Created by sohayla on 13/03/19.
//

#include "LocalPredictor.h"
LocalPredictor::LocalPredictor(string index) {
    this->index = index;
    this->currentState = new State();
}

bool LocalPredictor::getLocalPrediction() {
    int counterValue = currentState->getState();
    if(counterValue > 1) {
        return true;
    }

    return false;
}

void LocalPredictor::updateNotTaken() {
    this->currentState->decrementState();
}

void LocalPredictor::updateTaken() {
    this->currentState->incrementState();
}


void LocalPredictor::updateState(bool branchResolution) {
    if(branchResolution) {
        this->updateTaken();
    } else {
        this->updateNotTaken();
    }
}

string LocalPredictor::getIndex() {
    return this->index;
}