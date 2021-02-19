/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
 */


/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
#include "LeakedObjectDetector.h"
#include "RugbyTeam.h"
#include "SoccerTeam.h"
#include "Staff.h"
#include "TrainingComplex.h"
#include "Wrappers.h"

int main()
{
    //Example::main();
    //std::cout << "good to go!" << std::endl;

    //1) Team Program
    TeamProgramWrapper myTeam (new TeamProgram()) ;
    std::cout << "\n";
    std::cout << "-----------------------------------" << "\n";
    std::cout << "1) Team Program UDT" << "\n";
    
   
    myTeam.ptrToTeamProgram->currentBalance = 35459.f;
    std::cout << "Team's starting budget is: $" << myTeam.ptrToTeamProgram->currentBalance << "\n";
    myTeam.ptrToTeamProgram->startingBudget();
    
    myTeam.ptrToTeamProgram->numPlayersInProgram = 22;

    std::cout << "We've got " <<  myTeam.ptrToTeamProgram->numPlayersInProgram << " registered players and " <<  myTeam.ptrToTeamProgram->maxNumPlayersInProgram << " spots available." << std::endl;

    if(myTeam.ptrToTeamProgram->advertiseForPlayers() <= 0)
    {
        std::cout << "Roster is full!" << std::endl;
    }
    else
    {
        std::cout << "We have " << myTeam.ptrToTeamProgram->advertiseForPlayers() << " spots still left to fill!" << std::endl;
    }

    myTeam.ptrToTeamProgram->howManyPlayersDoWeNeed(22);

    std::cout << "-----------------------------------" << "\n";
    std::cout << "\n";

    //2) Staff
    StaffWrapper myStaffMember (new Staff());
    std::cout << "\n";
    std::cout << "-----------------------------------" << "\n";
    std::cout << "2) Staff UDT" << "\n";
    for(int i = 0; i < 3; ++i)
    {
        myStaffMember.ptrToStaff->daysAndHoursCalculator(1);
    }

    std::cout << "Staff member has worked " << myStaffMember.ptrToStaff->hoursOfWork << " hours this week over " << myStaffMember.ptrToStaff->daysOfWork << " days" << std::endl;

    myStaffMember.ptrToStaff->hoursWorked();

    std::cout << (myStaffMember.ptrToStaff->overtimeCalculator() ? "You have" : "You have NOT") << " hit overtime rate. You have racked up " << myStaffMember.ptrToStaff->hoursOfWork - myStaffMember.ptrToStaff->hoursOfWork << " overtime hours" << std::endl;
    
    myStaffMember.ptrToStaff->overtimeIndicator();

    std::cout << "-----------------------------------" << "\n";
    std::cout << "\n";
    
    //3) Training Complex
    TrainingComplexWrapper myTrainingGround(new TrainingComplex());
    std::cout << "\n";
    std::cout << "-----------------------------------" << "\n";
    std::cout << "3) Training Complex UDT" << "\n";
    
    std::cout << "The address of the complex is " << myTrainingGround.ptrToTrainingComplex->address << " and we have " << myTrainingGround.ptrToTrainingComplex->numCarParkSpots - (myTeam.ptrToTeamProgram->numPlayersInProgram + myTeam.ptrToTeamProgram->numCoaches)  << " car parking spots left most days" << std::endl;

    int numCarParkSpotsToday = { };
    int numStaffToday = 80;

    if(numStaffToday < myTrainingGround.ptrToTrainingComplex->numCarParkSpots)
    {
        for(int i = 0; i < numStaffToday; ++i)
        {
            ++numCarParkSpotsToday;
        }
        std::cout << "Today we have " << (myTrainingGround.ptrToTrainingComplex->numCarParkSpots - numCarParkSpotsToday) << " left" << std::endl;
    }
    else
    {
        std::cout << "We don't have enough spots for everyone today - please try and car pull!" << std::endl;
    }  
    
    myTrainingGround.ptrToTrainingComplex->numOfFreeParkingSpaces(80, *myTeam.ptrToTeamProgram);

    myTrainingGround.ptrToTrainingComplex->calculateNumStaffToFeed(75, 2);

    std::cout << "It will cost us $" << myTrainingGround.ptrToTrainingComplex->numMealsServed * myTrainingGround.ptrToTrainingComplex->costPerMeal << " to feed the staff." << std::endl;

    myTrainingGround.ptrToTrainingComplex->dailyMealsCost();

    std::cout << "-----------------------------------" << "\n";
    std::cout << "\n";

    //4) Soccer Team
    std::cout << "\n";
    std::cout << "-----------------------------------" << "\n";
    std::cout << "4) Soccer Team UDT" << "\n";
    SoccerTeamWrapper mySoccerTeam(new SoccerTeam());

    std::cout << "The gym currently has " << mySoccerTeam.ptrToSoccerTeam->numberOfLockersSpare() << " spare lockers." << std::endl;
    mySoccerTeam.ptrToSoccerTeam->printNumSpareLockers();

    std::cout << "-----------------------------------" << "\n";
    std::cout << "\n";
    
    //5) Rugby Team
    std::cout << "\n";
    std::cout << "-----------------------------------" << "\n";
    std::cout << "5) Rugby Team UDT" << "\n";
    RugbyTeamWrapper myRugbyTeam(new RugbyTeam());

    myRugbyTeam.ptrToRugbyTeam->whereAreWeTraining(0);

    myRugbyTeam.ptrToRugbyTeam->trainingDaysHours("Monday");

    std::cout << "After Monday, the coach has " << myRugbyTeam.ptrToRugbyTeam->coach.hoursOfWork << " hours left to work in the week and the player has " << myRugbyTeam.ptrToRugbyTeam->player.hoursOfWork << " hours left to work in the week" << std::endl;

    myRugbyTeam.ptrToRugbyTeam->hoursOfWorkLeft();

    std::cout << "-----------------------------------" << "\n";
    std::cout << "\n";
    
    /*
    

    std::cout << "Our coaches salary for this year will be $" << mySoccerTeam.coachWagesPerAnnum() << std::endl;

    myRugbyTeam.whereAreWeTraining(0);

    myRugbyTeam.trainingDaysHours("Monday");
    std::cout << "After Monday, the coach has " << myRugbyTeam.coach.hoursOfWork << " hours left to work in the week and the player has " << myRugbyTeam.player.hoursOfWork << " hours left to work in the week" << std::endl; 

     myRugbyTeam.trainingDaysHours("Wednesday");
     std::cout << "After Wednesday, the coach has " << myRugbyTeam.coach.hoursOfWork << " hours left to work in the week and the player has " << myRugbyTeam.player.hoursOfWork << " hours left to work in the week" << std::endl; 
     */

}
