#include "DeviceManager.h"

DeviceManager::DeviceManager(DeviceModel* device)
{
	//initialize all members
	deviceModel = device;
	//deviceUI = new DeviceUI();
}

DeviceManager::~DeviceManager()
{
	//dispose all members
	//delete DeviceUI;
}

void DeviceManager::InvokeUserInteraction()
{
	int commandId;

	//top level interaction is repeating loop
	while(true)
	{
		//show the room info as a welcome message;
		//deviceUI->ShowDeviceMenu(deviceModel);

		//show the menu and get user command
		//commandId = deviceUI->GetUserCommand();	

		switch(commandId){

			case(0):
				//PowerManagement(deviceModel);
				break;
			case(1):
				//CheckStatus(deviceModel);
				break;
			case(2):
				//ExecuteCommand(deviceModel);
				break;
			default:
				break;
		}
	}
}

void ExecuteCommand(DeviceModel* deviceModel){
	//deviceUI->ShowCommands(deviceModel);
}
void PowerManagement(DeviceModel* deviceModel){
	//deviceUI->ShowPower(deviceModel);
}
void CheckStatus(DeviceModel* deviceModel){
	
	while(true) { 
		//deviceUI->ShowStatus(deviceModel);
		//if(GetCommand() >= -1) //If user presses any key (non integers default to -1 as seen in BaseUI) this level will be exited.
		//break;
	}	
}
