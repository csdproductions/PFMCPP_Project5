#pragma once

#include "Staff.h"
#include "TrainingComplex.h"

#include "LeakedObjectDetector.h"

struct RugbyTeam
{
     TeamProgram rugbyProgram;
     Staff coach;
     Staff player;
     TrainingComplex practiseField;
     TrainingComplex gymnasium;

     RugbyTeam();
     ~RugbyTeam();

     void whereAreWeTraining(bool);
     void trainingDaysHours(std::string);

     void hoursOfWorkLeft();
     
     JUCE_LEAK_DETECTOR(RugbyTeam)
};
