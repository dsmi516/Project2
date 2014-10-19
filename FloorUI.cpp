#include "FloorUI.h"

void FloorUI::ShowFloorInfo(FloorModel* floor)
{
	ostringstream info;
	
	string name = floor->GetName();
	int number = floor->GetFloorNumber();

	info << "Welcome to [" << name << "] # " << number;

	ShowInfo(info.str());
}

int FloorUI::GetUserCommand()
{
	//TODO: Show the list of rooms in the floor
	//see BuildingUI.cpp for an example
	cout << "\n***This menu is under construction, visit us later.***\n\n";
	cout << "Enter any number to go back.\n\nSH> ";
	return GetCommand();
}
