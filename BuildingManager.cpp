#include "BuildingManager.h"

BuildingManager::BuildingManager()
{
	// Initialize all members
	buildingUI = new BuildingUI();
	buildingModel = new BuildingModel();

	
}

BuildingManager::~BuildingManager()
{
	// Dispose all members
	delete buildingUI;
	delete buildingModel;
}

bool BuildingManager::InvokeUserInteraction() {
	int commandId;
	bool isRunning = true;
	
	// Get the number of floors in the building
	int floorCount = buildingModel->GetFloorCount();

	// Top level interaction is repeating loop
	while(isRunning)
	{
		// Show the building info as a welcome message;
		buildingUI->ShowBuildingInfo(buildingModel->GetName(),buildingModel->GetStreetAddress());

		// Show the menu and get user command
		commandId = buildingUI->SelectFloor(buildingModel->GetFloorNumbers(),buildingModel->GetFloorNames());

		// User wants to exit this interaction		
		if((commandId < 0) || (commandId >= floorCount))
			break;

		// Invoke floor manager with commandId as floor number
		FloorManager* floorManager = new FloorManager(buildingModel->GetFloor(commandId));
		isRunning = floorManager->InvokeUserInteraction();
		delete floorManager;

	}
	// Exit the program
	buildingUI->LeaveBuilding(buildingModel->GetName());
	return isRunning; 
}
