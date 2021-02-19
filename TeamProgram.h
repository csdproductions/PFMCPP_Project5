#pragma once

#include "LeakedObjectDetector.h"

struct TeamProgram
{
    //sex
    bool isMale { };
    //maximum age
    int maxAge;
    //professional status
    std::string profStatus { };
    //number of staff
    int numCoaches;
    //total number of programs
    int numPlayersInProgram = 0;
    int maxNumPlayersInProgram;

    float budgetPerAnnum = 0.f;
    float currentBalance = 0.f;

    bool isGameAtHome = { };
    
    TeamProgram();

    ~TeamProgram();

    //enter a league
    std::string enterALeague(float costToEnterLeague);
    //determine number of coaches required
    int numCoachesRequired();
    //advertise for players
    int advertiseForPlayers();

    void startingBudget();

    void howManyPlayersDoWeNeed(int playersInProgram);

    JUCE_LEAK_DETECTOR(TeamProgram)

};
