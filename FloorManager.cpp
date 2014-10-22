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

bool FloorManager::InvokeUserInteraction()
{
	int commandId;
	bool isRunning = true;
	
	//get the number of rooms on this floor
	int roomCount = floorModel->GetRoomCount();

	//top level interaction is repeating loop
	while(isRunning)
	{
		//show the floor info as a welcome message;
		floorUI->ShowFloorInfo(floorModel->GetName(),floorModel->GetFloorNumber());

		//show the menu and get user command
		commandId = floorUI->ShowRooms(floorModel->GetRoomNumbers(),floorModel->GetRoomNames());

		//user wants to exit this interaction		
		if((commandId < 0) || (commandId > roomCount))
			break;

		if(commandId == roomCount)
			return false;

		//invoke room manager with commandId as room number
		RoomManager* roomManager = new RoomManager(floorModel->GetRoom(commandId));
		isRunning = roomManager->InvokeUserInteraction();
		delete roomManager;

	}
	return isRunning;
}
