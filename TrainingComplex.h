#pragma once

#include "LeakedObjectDetector.h"
#include "TeamProgram.h"
#include "Staff.h"

struct TrainingComplex
{
    //address of complex
    std::string address = "1234 Sports Street";
    //no of meals served in canteen a day
    int numMealsServed;
    //maximum deadlift weight in gym
    float maxDeadliftWeight = 500.f;
    //no of lockers in locker room
    int numLockers = 100;
    //no of car park spots
    int numCarParkSpots = 75;

    float costPerMeal = 1.23f;

    std::string therapyType;

    TrainingComplex();

    ~TrainingComplex();

    //host training session
    void numOfFreeParkingSpaces(int, TeamProgram);
    //feed staff
    void calculateNumStaffToFeed(int howManyStaffWorkingToday = 75, int numTrainingSessions = 2);
    //provide player rehab
    void providePlayerRehab(Staff player);

    void dailyMealsCost();

    JUCE_LEAK_DETECTOR(TrainingComplex)

};
