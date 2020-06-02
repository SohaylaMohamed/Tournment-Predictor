//
// Created by sohayla on 13/03/19.
//

#include "State.h"
State::State() {
    this->state = 0;
}

void State::incrementState() {
    if(this->state < 3) {
        this->state++;
    }
}


void State::decrementState() {
    if(this->state > 0) {
        this->state--;
    }
}

int State::getState() {
    return  this->state;
}
