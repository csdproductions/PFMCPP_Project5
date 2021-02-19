#include "TrainingComplex.h"

TrainingComplex::TrainingComplex()
{
    numMealsServed = 0;
    therapyType = { };
}

TrainingComplex::~TrainingComplex()
{
    std::cout << "Training Complex destructed" << std::endl;
}

void TrainingComplex::numOfFreeParkingSpaces(int numStaffToday, TeamProgram myTeam)
{
    std::cout << "The address of the complex is " << this->address << " and we have " << numCarParkSpots - (myTeam.numPlayersInProgram + myTeam.numCoaches)  << " car parking spots left most days" << std::endl;

    int numCarParkSpotsToday = { };

    if(numStaffToday < this->numCarParkSpots)
    {
        for(int i = 0; i < numStaffToday; ++i)
        {
            ++numCarParkSpotsToday;
        }
        std::cout << "Today we have " << (this->numCarParkSpots - numCarParkSpotsToday) << " left" << std::endl;
    }
    else
    {
        std::cout << "We don't have enough spots for everyone today - please try and car pull!" << std::endl;
    }  
}

void TrainingComplex::calculateNumStaffToFeed(int howManyStaffWorkingToday, int numTrainingSessions)
{
    this->numMealsServed = howManyStaffWorkingToday * numTrainingSessions;
}

void TrainingComplex::providePlayerRehab(Staff player)
{
    if(player.injuryType == "Muscular")
    {
       therapyType = "Massage";
       std::cout << player.name << " has Muscular pain and will require " << therapyType << " treatment" << "\n";
    }
}

void TrainingComplex::dailyMealsCost()
{
        std::cout << "It will cost us $" << this->numMealsServed * this->costPerMeal << " to feed the staff." << std::endl;
}
