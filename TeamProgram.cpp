#include <iostream>

#include "TeamProgram.h"

TeamProgram::TeamProgram()
{
    maxAge = 40;
    numCoaches = 6;
    maxNumPlayersInProgram = 24;
}

TeamProgram::~TeamProgram()
{
    std::cout << "Team Program destructed" << std::endl;
}

std::string TeamProgram::enterALeague(float costToEnterLeague)
{
    if(costToEnterLeague > budgetPerAnnum){
        return "We can't afford to enter this league";
    }

    for(int i = 0; i < 3; ++i)
    {
        currentBalance -= costToEnterLeague;
        if(currentBalance < 0)
        {
            return "We've run out of cash!";
        }
        else
        {
            std::cout << "We can enter for another year" << std::endl;
            if(i > 2)
            {
                std::cout << "We can enter the league for 3 seasons" << std::endl;
            }
        }
    }
    return "We've still got some money left!";
}

int TeamProgram::numCoachesRequired()
{
    if(isGameAtHome)
    {
        return numCoaches;
    }
    return int(numCoaches/2);
}

int TeamProgram::advertiseForPlayers()
{
    return maxNumPlayersInProgram - numPlayersInProgram;
}

void TeamProgram::startingBudget()
{
    std::cout << "Team's starting budget is: $" << this->currentBalance << "\n";
}

void TeamProgram::howManyPlayersDoWeNeed(int playersInProgram)
{
    this->numPlayersInProgram = playersInProgram;

    std::cout << "We've got " << this->numPlayersInProgram << " registered players and " << this->maxNumPlayersInProgram << " spots available." << std::endl;

    if(this->advertiseForPlayers() <= 0)
    {
        std::cout << "Roster is full!" << std::endl;
    }
    else
    {
    std::cout << "We have " << this->advertiseForPlayers() << " spots still left to fill!" << std::endl;
    }
}
