#include "FloorManager.h"

FloorManager::FloorManager(FloorModel* inputfloorModel)
{
	// Initialize all members
	floorUI = new FloorUI();
	floorModel = inputfloorModel;
}

FloorManager::~FloorManager()
{
	// Dispose all members
	delete floorUI;
	//delete floorModel;
}

bool FloorManager::InvokeUserInteraction()
{
	int commandId;
	bool isRunning = true;
	
	// Get the number of rooms on this floor
	int roomCount = floorModel->GetRoomCount();

	// Top level interaction is repeating loop
	while(isRunning)
	{
		// Show the floor info as a welcome message
		floorUI->ShowFloorInfo(floorModel->GetName(),floorModel->GetFloorNumber());

		// Show the menu and get user command
		commandId = floorUI->SelectRoom(floorModel->GetRoomNumbers(),floorModel->GetRoomNames());

		// User wants to exit this interaction		
		if((commandId < 0) || (commandId > roomCount))
			break;

		// User wants to exit the program
		if(commandId == roomCount) 
			return false;

		// Invoke room manager with commandId as room number
		RoomManager* roomManager = new RoomManager(floorModel->GetRoom(commandId));
		isRunning = roomManager->InvokeUserInteraction();
		delete roomManager;

	}
	return isRunning;
}
