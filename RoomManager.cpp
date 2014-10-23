#include "RoomManager.h"

RoomManager::RoomManager(RoomModel* room)
{
	// Initialize all members
	roomModel = room;
	roomUI = new RoomUI();
}

RoomManager::~RoomManager()
{
	// Dispose all members
	delete roomUI;
	//delete roomModel;
}

bool RoomManager::InvokeUserInteraction()
{
	int commandId;
	bool isRunning=true;
	
	// Get the number of devices on this room
	int deviceCount = roomModel->GetNumberOfDevices(); //should have correct device count

	// Top level interaction is repeating loop
	while(isRunning)
	{
		// Show the room info as a welcome message;
		roomUI->ShowRoomInfo(roomModel->GetName(),roomModel->GetRoomNumber());

		// Show the menu and get user command
		commandId = roomUI->SelectDevice(roomModel->GetDeviceIDs(),roomModel->GetDeviceNames());

		// User wants to exit this interaction		
		if((commandId < 0) || (commandId > deviceCount))
			break;

		// User wants to exit the program
		if(commandId == deviceCount){
			return false;
		}

		// Invoke device manager with commandId as device number
		DeviceManager* deviceManager = new DeviceManager(roomModel->GetDevice(commandId));
		isRunning = deviceManager->InvokeUserInteraction();
		delete deviceManager;

	}
	return isRunning;
}

