#include "BuildingManager.h"

BuildingManager::BuildingManager()
{
	//initialize all members
	buildingUI = new BuildingUI();
	buildingModel = new BuildingModel();

	
}

BuildingManager::~BuildingManager()
{
	//dispose all members
	delete buildingUI;
	delete buildingModel;
}

bool BuildingManager::InvokeUserInteraction()
{
	int commandId;
	bool isRunning=true;
	
	//get the number of floors in the building
	int floorCount = buildingModel->GetFloorCount();

	//top level interaction is reapting loop
	while(isRunning)
	{
		//show the building info as a welcome message;
		buildingUI->ShowBuildingInfo(buildingModel->GetName(),buildingModel->GetStreetAddress());

		//show the menu and get user command
		commandId = buildingUI->ShowFloors(buildingModel->GetFloorNumbers(),buildingModel->GetFloorNames());

		//user wants to exit this interaction		
		if((commandId < 0) || (commandId >= floorCount))
			break;

		//invoke floor manager with commandId as floor number
		FloorManager* floorManager = new FloorManager(buildingModel->GetFloor(commandId));
		isRunning = floorManager->InvokeUserInteraction();
		delete floorManager;

	}
	buildingUI->LeaveBuilding(buildingModel->GetName());
	return isRunning;
}
