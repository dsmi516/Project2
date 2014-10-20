#include "FloorManager.h"

FloorManager::FloorManager(FloorModel* inputfloorModel)
{
	//initialize all members
	floorUI = new FloorUI();
	floorModel = inputfloorModel;
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
	int roomCount = floorModel->rooms.size();

	//top level interaction is repeating loop
	while(true)
	{
		//show the floor info as a welcome message;
		floorUI->ShowFloorInfo(floorModel);

		//show the menu and get user command
		commandId = floorUI->GetUserCommand(floorModel->rooms);

		//user wants to exit this interaction		
		if((commandId < 0) || (commandId >= roomCount))
			break;

		//invoke room manager with commandId as room number
		RoomManager* roomManager = new RoomManager(floorModel->rooms.at(commandId));
		roomManager->InvokeUserInteraction();
		delete roomManager;

	}
}
