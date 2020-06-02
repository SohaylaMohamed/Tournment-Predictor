//
// Created by sohayla on 13/03/19.
//

#include "Selector.h"
Selector::Selector(string index) {
    this->index = index;
     currentState = new State();
}

void Selector::updateSelectionState(bool local, bool global, bool actual) {
    if((local && global) || (!local && !global)) {
        //do nothing
    } else if ((actual && global) || (!actual && !global)) {
        this->currentState->incrementState();
    } else {
        this->currentState->decrementState();
    }
}

string Selector::getSelection() {
    int counterValue = currentState->getState();
    if(counterValue > 1) {
        return "g";
    }

    return "l";
}

string Selector::getIndex() {
    return  this->index;
}