#include "roomManager.h"

roomManager::roomManager(roomModel* room)
{
	//initialize all members
	roomModel = room;
	roomUI = new roomUI();
}

roomManager::~roomManager()
{
	//dispose all members
	delete roomUI;
}

void roomManager::InvokeUserInteraction()
{
	int commandId;
	
	//get the number of rooms on this room
	int roomCount = 0; //TODO: should have correct room count 

	//top level interaction is repeating loop
	while(true)
	{
		//show the room info as a welcome message;
		roomUI->ShowroomInfo(roomModel);

		//show the menu and get user command
		commandId = roomUI->GetUserCommand();

		//user wants to exit this interaction		
		if((commandId < 0) || (commandId >= roomCount))
			break;

		//TODO: invoke room manager with commandId as room number
		//see BuildingManager.cpp for an example
	}
}
