#include "FloorManager.h"

FloorManager::FloorManager(FloorModel* floor)
{
	//initialize all members
	floorModel = floor;
	floorUI = new FloorUI();
}

FloorManager::~FloorManager()
{
	//dispose all members
	delete floorUI;
}

void FloorManager::InvokeUserInteraction()
{
	int commandId;
	
	//get the number of rooms on this floor
	int roomCount = 0; //TODO: should have correct room count 

	//top level interaction is repeating loop
	while(true)
	{
		//show the floor info as a welcome message;
		floorUI->ShowFloorInfo(floorModel);

		//show the menu and get user command
		commandId = floorUI->GetUserCommand();

		//user wants to exit this interaction		
		if((commandId < 0) || (commandId >= roomCount))
			break;

		//TODO: invoke room manager with commandId as room number
		//see BuildingManager.cpp for an example
	}
}
