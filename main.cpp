/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 3) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 4) write the name of your class where it says "OwnerClass"
 
 5) write wrapper classes for each type similar to how it was shown in the video
 
 7) update main() 
      replace your objects with your wrapper classes, which have your UDTs as pointer member variables.
      
    This means if you had something like the following in your main() previously: 
*/
#if false
 Axe axe;
 std::cout << "axe sharpness: " << axe.sharpness << "\n";
 #endif
 /*
    you would update that to use your wrappers:
    
 */

#if false
AxeWrapper axWrapper( new Axe() );
std::cout << "axe sharpness: " << axWrapper.axPtr->sharpness << "\n";
#endif
/*
notice that the object name has changed from 'axe' to 'axWrapper'
You don't have to do this, you can keep your current object name and just change its type to your Wrapper class

 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example

 you can safely ignore any warnings about exit-time-destructors.
 if you would like to suppress them, add -Wno-exit-time-destructors to the .replit file 
   with the other warning suppression flags
 */





#include <iostream>

/*
 copied UDT 1:
 */
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

    void startingBudget()
    {
        std::cout << "Team's starting budget is: $" << this->currentBalance << "\n";
    }

    void howManyPlayersDoWeNeed(int playersInProgram)
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
    
};

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

/*
 copied UDT 2:
 */
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

    void hoursWorked()
    {
        std::cout << "Staff member has worked " << this->hoursOfWork << " hours this week over " << this->daysOfWork << " days" << std::endl;
    }

    void overtimeIndicator()
    {
        std::cout << (overtimeCalculator() ? "You have" : "You have NOT") << " hit overtime rate. You have racked up " << this->hoursOfWork - this->hoursOfWork << " overtime hours" << std::endl;
    }
       
};

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
    if(hoursOfWork < 0)
    {
        return true;
    }
    return false;
}

void Staff::attendMeeting()
{
    std::cout << "All onsite meetings cancelled - login to Zoom" << std::endl;
}

bool Staff::signContract(float contractOffer)
{
    if(contractOffer > 20000.f)
    {
        return true;
    }
    return false;
}

/*
 copied UDT 3:
 */
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

    void dailyMealsCost()
    {
        std::cout << "It will cost us $" << this->numMealsServed * this->costPerMeal << " to feed the staff." << std::endl;
    }
};

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

/*
 new UDT 4:
 with 2 member functions
 */
 struct SoccerTeam
 {
    TeamProgram soccerProgram;
    Staff headCoach;
    Staff offenceCoach;
    TrainingComplex teamGym;

    SoccerTeam();

    ~SoccerTeam();

    int numberOfLockersSpare();
    float coachWagesPerAnnum();

    void printNumSpareLockers()
    {
        std::cout << "The gym currently has " << this->numberOfLockersSpare() << " spare lockers." << std::endl;
    }
    
 };

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

/*
 new UDT 5:
 with 2 member functions
 */
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

     void hoursLeftOfWork(){         
         std::cout << "After Monday, the coach has " << this->coach.hoursOfWork << " hours left to work in the week and the player has " << this->player.hoursOfWork << " hours left to work in the week" << std::endl; 
     }
     
 };

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
int main()
{
    Example::main();
    //std::cout << "good to go!" << std::endl;

    //1) Team Program
    TeamProgram myTeam;
    std::cout << "\n";
    std::cout << "-----------------------------------" << "\n";
    std::cout << "1) Team Program UDT" << "\n";
    
    myTeam.currentBalance = 35459.f;
    std::cout << "Team's starting budget is: $" << myTeam.currentBalance << "\n";
    myTeam.startingBudget();
    
    myTeam.numPlayersInProgram = 22;

    std::cout << "We've got " << myTeam.numPlayersInProgram << " registered players and " << myTeam.maxNumPlayersInProgram << " spots available." << std::endl;

    if(myTeam.advertiseForPlayers() <= 0)
    {
        std::cout << "Roster is full!" << std::endl;
    }
    else
    {
        std::cout << "We have " << myTeam.advertiseForPlayers() << " spots still left to fill!" << std::endl;
    }

    myTeam.howManyPlayersDoWeNeed(22);

    std::cout << "-----------------------------------" << "\n";
    std::cout << "\n";

    //2) Staff
    Staff myStaffMember;
    std::cout << "\n";
    std::cout << "-----------------------------------" << "\n";
    std::cout << "2) Staff UDT" << "\n";
    for(int i = 0; i < 3; ++i)
    {
        myStaffMember.daysAndHoursCalculator(1);
    }

    std::cout << "Staff member has worked " << myStaffMember.hoursOfWork << " hours this week over " << myStaffMember.daysOfWork << " days" << std::endl;

    myStaffMember.hoursWorked();

    std::cout << (myStaffMember.overtimeCalculator() ? "You have" : "You have NOT") << " hit overtime rate. You have racked up " << myStaffMember.hoursOfWork - myStaffMember.hoursOfWork << " overtime hours" << std::endl;
    
    myStaffMember.overtimeIndicator();

    std::cout << "-----------------------------------" << "\n";
    std::cout << "\n";
    
    //3) Training Complex
    TrainingComplex myTrainingGround;
    std::cout << "\n";
    std::cout << "-----------------------------------" << "\n";
    std::cout << "3) Training Complex UDT" << "\n";
    
    std::cout << "The address of the complex is " << myTrainingGround.address << " and we have " << myTrainingGround.numCarParkSpots - (myTeam.numPlayersInProgram + myTeam.numCoaches)  << " car parking spots left most days" << std::endl;

    int numCarParkSpotsToday = { };
    int numStaffToday = 80;

    if(numStaffToday < myTrainingGround.numCarParkSpots)
    {
        for(int i = 0; i < numStaffToday; ++i)
        {
            ++numCarParkSpotsToday;
        }
        std::cout << "Today we have " << (myTrainingGround.numCarParkSpots - numCarParkSpotsToday) << " left" << std::endl;
    }
    else
    {
        std::cout << "We don't have enough spots for everyone today - please try and car pull!" << std::endl;
    }  
    
    myTrainingGround.numOfFreeParkingSpaces(80, myTeam);

    myTrainingGround.calculateNumStaffToFeed(75, 2);

    std::cout << "It will cost us $" << myTrainingGround.numMealsServed * myTrainingGround.costPerMeal << " to feed the staff." << std::endl;

    myTrainingGround.dailyMealsCost();

    std::cout << "-----------------------------------" << "\n";
    std::cout << "\n";

    //4) Soccer Team
    std::cout << "\n";
    std::cout << "-----------------------------------" << "\n";
    std::cout << "4) Soccer Team UDT" << "\n";
    SoccerTeam mySoccerTeam;

    std::cout << "The gym currently has " << mySoccerTeam.numberOfLockersSpare() << " spare lockers." << std::endl;
    mySoccerTeam.printNumSpareLockers();

    std::cout << "-----------------------------------" << "\n";
    std::cout << "\n";
    
    //5) Rugby Team
    std::cout << "\n";
    std::cout << "-----------------------------------" << "\n";
    std::cout << "5) Rugby Team UDT" << "\n";
    RugbyTeam myRugbyTeam;

    myRugbyTeam.whereAreWeTraining(0);

    myRugbyTeam.trainingDaysHours("Monday");

    std::cout << "After Monday, the coach has " << myRugbyTeam.coach.hoursOfWork << " hours left to work in the week and the player has " << myRugbyTeam.player.hoursOfWork << " hours left to work in the week" << std::endl;

    myRugbyTeam.hoursLeftOfWork(); 

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
