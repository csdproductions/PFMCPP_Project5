#pragma once

// Not using these objects, just asking for a pointer of these types
struct RugbyTeam;
struct SoccerTeam;
struct Staff;
struct TrainingComplex;
struct TeamProgram;

struct RugbyTeamWrapper
{
    RugbyTeamWrapper(RugbyTeam* ptr);
    ~RugbyTeamWrapper();
    
    RugbyTeam* ptrToRugbyTeam = nullptr;
};

struct SoccerTeamWrapper
{
    SoccerTeamWrapper(SoccerTeam* ptr);
    ~SoccerTeamWrapper();

    SoccerTeam* ptrToSoccerTeam = nullptr;
};

struct StaffWrapper
{
    StaffWrapper(Staff* ptr);
    ~StaffWrapper();

    Staff* ptrToStaff = nullptr;
};

struct TeamProgramWrapper
{
    TeamProgramWrapper(TeamProgram* ptr);
    ~TeamProgramWrapper();
    
    TeamProgram* ptrToTeamProgram = nullptr;
};

struct TrainingComplexWrapper
{
    TrainingComplexWrapper(TrainingComplex* ptr);
    ~TrainingComplexWrapper();

    TrainingComplex* ptrToTrainingComplex = nullptr;
};
