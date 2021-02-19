#include "RugbyTeam.h"

RugbyTeam::RugbyTeam()
{
    practiseField.address = "567 Practise Field, 41048";
    gymnasium.address = "89 Gymnasium Road, 41048";

    rugbyProgram.maxNumPlayersInProgram = 35;
    rugbyProgram.numPlayersInProgram = 32;

    if(rugbyProgram.maxNumPlayersInProgram > rugbyProgram.numPlayersInProgram)
    {
        std::cout << "We still have " << rugbyProgram.advertiseForPlayers() << " spaces for this year!" << std::endl;
    }
}

RugbyTeam::~RugbyTeam()
{
    std::cout << "Rugby Team destructed" << std::endl;

}

void RugbyTeam::whereAreWeTraining(bool oddOrEven)
{
    if(oddOrEven)
    {
        std::cout << "We're at the Practise Field! Make sure you head to " + practiseField.address << "." << std::endl;
    }
    else
    {
        std::cout << "We're at the Gym! Make sure you head to " + gymnasium.address << "." << std::endl;
    }
}

void RugbyTeam::trainingDaysHours(std::string day)
{   
    if(day == "Monday")
    {
        coach.daysAndHoursCalculator(1);
    }else if(day == "Wednesday")
    {
        coach.daysAndHoursCalculator(1);
        player.daysAndHoursCalculator(1);
    }   
}

void RugbyTeam::hoursOfWorkLeft()
{
    std::cout << "After Monday, the coach has " << this->coach.hoursOfWork << " hours left to work in the week and the player has " << this->player.hoursOfWork << " hours left to work in the week" << std::endl;
}
