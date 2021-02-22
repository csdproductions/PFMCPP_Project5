#pragma once

#include "LeakedObjectDetector.h"

#include "Staff.h"
#include "TrainingComplex.h"

struct SoccerTeam
{
    TeamProgram soccerProgram;
    Staff headCoach;
    Staff offenceCoach;
    TrainingComplex teamGym;

    SoccerTeam();

    ~SoccerTeam();

    int numberOfLockersSpare();
    float coachWagesPerAnnum();

    void printNumSpareLockers();

    JUCE_LEAK_DETECTOR(SoccerTeam)
};
