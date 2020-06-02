//
// Created by sohayla on 13/03/19.
//

#ifndef TOURNMENT_PREDICTOR_STATE_H
#define TOURNMENT_PREDICTOR_STATE_H


class State {
private:
    int state;
public:
    State();
    void incrementState();
    void decrementState();
    int getState();

};


#endif //TOURNMENT_PREDICTOR_STATE_H
