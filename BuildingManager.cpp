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

void BuildingManager::InvokeUserInteraction()
{
	int commandId;
	
	//get the number of floors in the building
	int floorCount = buildingModel->floors.size();

	//top level interaction is reapting loop
	while(true)
	{
		//show the building info as a welcome message;
		buildingUI->ShowBuildingInfo(buildingModel);

		//show the menu and get user command
		commandId = buildingUI->GetUserCommand(buildingModel->floors);

		//user wants to exit this interaction		
		if((commandId < 0) || (commandId >= floorCount))
			break;

		//invoke floor manager with commandId as floor number
		FloorManager* floorManager = new FloorManager(buildingModel->floors.at(commandId));
		floorManager->InvokeUserInteraction();
		delete floorManager;

	}
}
