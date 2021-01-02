/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor. 

 Destructors
        
 0) move all of your implementations of all functions to OUTSIDE of the class. 
 
 1) Copy 3 of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
 2) add destructors
        make the destructors do something like print out the name of the class.

 3) add 2 new UDTs that use only the types you copied above as member variables.

 4) add 2 member functions that use your member variables to each of these new UDTs

 5) Add constructors and destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 6) copy over your main() from the end of Project3 and get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.
 
 7) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
 
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
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
    
    TeamProgram() : maxAge(40), numCoaches(6), maxNumPlayersInProgram(24) { }

    ~TeamProgram();

    //enter a league
    std::string enterALeague(float costToEnterLeague);
    //determine number of coaches required
    int numCoachesRequired();
    //advertise for players
    int advertiseForPlayers();
};

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
    return numCoaches/2;
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
    float costToFeedStaff(int howManyStaffWorkingToday = 75, int numTrainingSessions = 2);
    //provide player rehab
    void providePlayerRehab(Staff player);
};

TrainingComplex::TrainingComplex()
{
    numMealsServed = 0;
    therapyType = { };
}

TrainingComplex::~TrainingComplex()
{
    std::cout << "Training Complex Destructed" << std::endl;
}

void TrainingComplex::numOfFreeParkingSpaces(int numStaffToday, TeamProgram myTeam)
{
    std::cout << "The address of the complex is " << address << " and we have " << numCarParkSpots - (myTeam.numPlayersInProgram + myTeam.numCoaches)  << " car parking spots left most days" << std::endl;

    int numCarParkSpotsToday = { };

    if(numStaffToday < numCarParkSpots)
    {
        for(int i = 0; i < numStaffToday; ++i)
        {
            ++numCarParkSpotsToday;
        }
        std::cout << "Today we have " << (numCarParkSpots - numCarParkSpotsToday) << " left" << std::endl;
    }
    else
    {
        std::cout << "We don't have enough spots for everyone today - please try and car pull!" << std::endl;
    }  
}

float TrainingComplex::costToFeedStaff(int howManyStaffWorkingToday, int numTrainingSessions)
{
    numMealsServed = howManyStaffWorkingToday * numTrainingSessions;
    return numMealsServed * costPerMeal;
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

/*
 new UDT 5:
 with 2 member functions
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
int main()
{
    //std::cout << "good to go!" << std::endl;

    TeamProgram myTeam;

    TrainingComplex myComplex;

    Staff myStaff;
}
