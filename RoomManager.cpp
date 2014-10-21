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

bool RoomManager::InvokeUserInteraction()
{
	int commandId;
	bool isRunning=true;
	
	//get the number of devices on this room
	int deviceCount = roomModel->devices.size(); //should have correct device count

	//top level interaction is repeating loop
	while(isRunning)
	{
		//show the room info as a welcome message;
		roomUI->ShowRoomInfo(roomModel);

		//show the menu and get user command
		commandId = roomUI->GetUserCommand(roomModel->devices);

		//user wants to exit this interaction		
		if((commandId < 0) || (commandId >= deviceCount))
			break;

		//invoke device manager with commandId as device number
		DeviceManager* deviceManager = new DeviceManager(roomModel->devices.at(commandId));
		isRunning = deviceManager->InvokeUserInteraction();
		delete deviceManager;

	}
	return isRunning;
}
