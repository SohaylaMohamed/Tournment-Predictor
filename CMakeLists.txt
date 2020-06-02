cmake_minimum_required(VERSION 3.12)
project(Tournment_Predictor)

set(CMAKE_CXX_STANDARD 14)

add_executable(Tournment_Predictor main.cpp LocalPredictor.cpp LocalPredictor.h GlobalPredictor.cpp GlobalPredictor.h Selector.cpp Selector.h State.cpp State.h Driver.cpp Driver.h)