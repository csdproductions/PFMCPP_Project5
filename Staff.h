#pragma once

#include "LeakedObjectDetector.h"

struct Staff
{
    //type
    std::string type;
    //sex
    bool isPlayerMale;
    //age
    int age;
    //hours of work
    float hoursOfWork;
    float requiredHoursOfWork;
    //days of work
    int daysOfWork;
    
    bool hitOvertime;

    std::string injuryType;
    std::string name;

    float salary;

    Staff();

    ~Staff();

    void daysAndHoursCalculator(int typeOfDay);

    //go to work
    bool overtimeCalculator();
    //attend meeting
    void attendMeeting();
    //sign a contract
    bool signContract(float contractOffer = 20000.f);

    void hoursWorked();

    void overtimeIndicator();
    
    JUCE_LEAK_DETECTOR(Staff)
};
