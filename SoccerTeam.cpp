#include "SoccerTeam.h"

SoccerTeam::SoccerTeam()
 {
     soccerProgram.numCoaches = 9;
     soccerProgram.numPlayersInProgram = 21;
     teamGym.numLockers = 40;
     offenceCoach.salary = 22000;
     headCoach.salary = 30000;

     if(offenceCoach.signContract(offenceCoach.salary))
     {
         std::cout << "We have a offence coach!" << std::endl;
     }
 }

 SoccerTeam::~SoccerTeam()
 {
     std::cout << "Soccer Team destructed" << std::endl;
 }

int SoccerTeam::numberOfLockersSpare()
{
    return teamGym.numLockers - soccerProgram.numPlayersInProgram - soccerProgram.numCoaches;
}

float SoccerTeam::coachWagesPerAnnum()
{
    return offenceCoach.salary + headCoach.salary;
}
   
void SoccerTeam::printNumSpareLockers()
{
    std::cout << "The gym currently has " << this->numberOfLockersSpare() << " spare lockers." << std::endl;
}
