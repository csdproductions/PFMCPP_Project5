#include <iostream>

#include "Staff.h"

Staff::Staff()
{
    type = { };
    isPlayerMale = true;
    age = 0;
    hoursOfWork = 40.f;
    requiredHoursOfWork = 40.f;
    daysOfWork = 5;
    hitOvertime = false;
    injuryType = "None";
    salary = 0.f;
    name = { };
}

Staff::~Staff()
{
    std::cout << "Staff destructed" << std::endl;
}

void Staff::daysAndHoursCalculator(int dayType)
{
    if(dayType)
    {
        hoursOfWork -= 8.f;
        daysOfWork -= 1;
    }
    else
    {
        hoursOfWork -= 4.f;
        daysOfWork -= 0.5;
    }
}

bool Staff::overtimeCalculator()
{
    std::cout << "Standard working hours in a week for an employee must total " << requiredHoursOfWork << " before they hit overtime." << std::endl;
    
    return (hoursOfWork < 0);
}

void Staff::attendMeeting()
{
    std::cout << "All onsite meetings cancelled - login to Zoom" << std::endl;
}

bool Staff::signContract(float contractOffer)
{
    return (contractOffer > 20000.f);
}

void Staff::hoursWorked() 
{
    std::cout << "Staff member has worked " << this->hoursOfWork << " hours this week over " << this->daysOfWork << " days" << std::endl;
}

void Staff::overtimeIndicator()
{
    std::cout << (overtimeCalculator() ? "You have" : "You have NOT") << " hit overtime rate. You have racked up " << this->hoursOfWork - this->hoursOfWork << " overtime hours" << std::endl;
}

