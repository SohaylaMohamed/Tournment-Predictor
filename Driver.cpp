//
// Created by sohayla on 13/03/19.
//

#include "Driver.h"
Driver::Driver() {
    correctGlobal = 0;
    correctLocal = 0;
    correctTournment = 0;
    local = "l";
    global = "g";
    globalIndex = "nnnn"; //Based on 4 previous prediction
}

void Driver::updateGlobalIndex(bool prediction) {
    if(prediction) {
        globalIndex = globalIndex.substr(1) + "t";
    } else {
        globalIndex = globalIndex.substr(1) + "n";
    }
}

bool Driver::getGlobalPrediction(bool correctPrediction) {
    GlobalPredictor *globalPredictor;
    if(globalMap.count(globalIndex)) {
        globalPredictor = globalMap[globalIndex];
    } else {
        globalPredictor = new GlobalPredictor(globalIndex);
        globalMap.insert(pair<string, GlobalPredictor*>(globalIndex, globalPredictor));
    }
    bool prediction = globalPredictor->getGlobalPrediction();
    globalPredictor->updateState(correctPrediction);
    updateGlobalIndex(prediction);
    return  prediction;
}

bool Driver::getLocalPrediction(string index, bool correctPrediction) {
    LocalPredictor *localPredictor;
    if(localMap.count(index)) {
        localPredictor = localMap[index];
    } else {
        localPredictor = new LocalPredictor(index);
        localMap.insert(pair<string, LocalPredictor*>(index, localPredictor));
    }
    bool prediction = localPredictor->getLocalPrediction();
    localPredictor->updateState(correctPrediction);
    return  prediction;
}

string Driver::getSelectorPrediction(string index, bool correctPrediction, bool localPrediction, bool globalPrediction) {
    Selector *selector;
    if(selectorMap.count(index)) {
        selector = selectorMap[index];
    } else {
        selector = new Selector(index);
        selectorMap.insert(pair<string, Selector*>(index, selector));
    }
    string prediction = selector->getSelection();
    selector->updateSelectionState(localPrediction, globalPrediction, correctPrediction);
    return  prediction;
}

bool Driver::getCorrectPrediction(bool local_p, bool global_p, string selector_p) {
    if(local == selector_p) {
        return local_p;
    } else {
        return global_p;
    }
}

void Driver::updateCorrectness(bool local_p, bool global_p, bool final, bool correct) {
    if((correct && local_p) || (!correct && !local_p)) {
        correctLocal++;
    }
    if((correct && local_p) || (!correct && !global_p)) {
        correctGlobal++;
    }
    if((correct && final) || (!correct && !final)) {
        correctTournment++;
    }
}

int Driver::getcorrectLocal() {
    return  correctLocal;
}
int Driver::getCorrectGlobal() {
    return  correctGlobal;
}
int Driver::getCorrectTournment() {
    return correctTournment;
}