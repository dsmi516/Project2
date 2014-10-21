#include "DeviceManager.h"

DeviceManager::DeviceManager(DeviceModel* device)
{
	//initialize all members
	deviceModel = device;
	deviceUI = new DeviceUI();
}

DeviceManager::~DeviceManager()
{
	//dispose all members
	//delete DeviceUI;
}

void DeviceManager::InvokeUserInteraction()
{
	int commandId;
	bool isRunning=true;

	//top level interaction is repeating loop
	while(isRunning)
	{
		//show the room info as a welcome message;
		deviceUI->ShowDeviceMenu(deviceModel);

		//show the menu and get user command
		commandId = deviceUI->GetUserCommand();	
		switch(commandId){

			case(0):
				PowerManagement(deviceModel);
				break;
			case(1):
				CheckStatus(deviceModel);
				break;
			case(2):
				ExecuteCommand(deviceModel);
				break;
			default:
				isRunning=false;
				break;
		}
	}
}

void DeviceManager::ExecuteCommand(DeviceModel* deviceModel){
	int selection = deviceUI->ShowCommands(deviceModel);
	if(deviceModel->IsCommandEnabled()){
	deviceModel->ExecuteCommand(selection);
	}else{
	cout<<"command is not enabled";
	} 
	
}
void DeviceManager::PowerManagement(DeviceModel* deviceModel){
	deviceUI->ShowPower(deviceModel);
	int selection = deviceUI->GetUserCommand();

	if(selection == 0 || selection == 1){
	 deviceModel->SetPowerStatus(selection);
	}else{
	return;
	}
	deviceUI->ShowPowerStatus(deviceModel);
}
void DeviceManager::CheckStatus(DeviceModel* deviceModel){
	deviceUI->ShowStatus(deviceModel);
}
