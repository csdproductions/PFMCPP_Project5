#include "Wrappers.h"

#include "Staff.h"
#include "TrainingComplex.h"

RugbyTeamWrapper::RugbyTeamWrapper(RugbyTeam* ptr) : ptrToRugbyTeam(ptr)
{

}

RugbyTeamWrapper::~RugbyTeamWrapper()
{
	delete ptrToRugbyTeam;
	ptrToRugbyTeam = nullptr;
}


SoccerTeamWrapper::SoccerTeamWrapper(SoccerTeam* ptr) : ptrToSoccerTeam(ptr)
{

}

SoccerTeamWrapper::~SoccerTeamWrapper()
{
	delete ptrToSoccerTeam;
	ptrToSoccerTeam = nullptr;
}


StaffWrapper::StaffWrapper(Staff* ptr) : ptrToStaff (ptr)
{

}

StaffWrapper::~StaffWrapper()
{
	delete ptrToStaff;
	ptrToStaff = nullptr;
}


TeamProgramWrapper::TeamProgramWrapper(TeamProgram* ptr) : ptrToTeamProgram (ptr)
{

}

TeamProgramWrapper::~TeamProgramWrapper()
{
	delete ptrToTeamProgram;
	ptrToTeamProgram = nullptr;
}


TrainingComplexWrapper::TrainingComplexWrapper(TrainingComplex* ptr) : ptrToTrainingComplex(ptr)
{

}

TrainingComplexWrapper::~TrainingComplexWrapper()
{
	delete ptrToTrainingComplex;
	ptrToTrainingComplex = nullptr;
}
