#include "RoomManager.h"

RoomManager::RoomManager(RoomModel* room)
{
	//initialize all members
	roomModel = room;
	roomUI = new RoomUI();
}

RoomManager::~RoomManager()
{
	//dispose all members
	delete roomUI;
}

void RoomManager::InvokeUserInteraction()
{
	int commandId;
	
	//get the number of devices on this room
	int deviceCount = 2; //TODO: should have correct device count

	//top level interaction is repeating loop
	while(true)
	{
		//show the room info as a welcome message;
		roomUI->ShowRoomInfo(roomModel);

		//show the menu and get user command
		commandId = roomUI->GetUserCommand();

		//user wants to exit this interaction		
		if((commandId < 0) || (commandId >= deviceCount))
			break;

		//TODO: invoke device manager with commandId as device number
		//see BuildingManager.cpp for an example
	}
}
