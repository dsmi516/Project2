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

bool DeviceManager::InvokeUserInteraction()
{
	int commandId;

	//top level interaction is repeating loop
	while(true)
	{
		//show the room info as a welcome message;
		deviceUI->ShowDeviceMenu(deviceModel->GetName(),deviceModel->GetDeviceId());

		//show the menu and get user command
		commandId = deviceUI->GetUserCommand();	
		switch(commandId){

			case(0):
				PowerManagement();
				break;
			case(1):
				CheckStatus();
				break;
			case(2):
				ExecuteCommand();
				break;
			case(3):
				return false;
			default:
				return true;
		}
	}
}

void DeviceManager::ExecuteCommand(){

	/*if(deviceModel->IsCommandEnabled()){
		int selection = deviceUI->ShowNumberOfCommands( deviceModel->GetNumberOfCommands());
		deviceModel->ExecuteCommand(selection)
		}
	}else{
	deviceUI->CommandErrorHandler();
	} */
	
}
void DeviceManager::PowerManagement(){
	bool isOn = deviceModel->GetPowerStatus();
	int selection = deviceUI->PowerOptions(isOn);

	//is user wishes to change power setting
	if(selection == 1){

		//turn device on or off
		if(isOn){
	 		deviceModel->SetPowerStatus(!isOn);
		}else{
			deviceModel->SetPowerStatus(!isOn);
		}
	}else{
	return;
	}

	//show status of power setting after change
	deviceUI->ShowPowerStatus(deviceModel->GetPowerStatus()); 
}
void DeviceManager::CheckStatus(){
	//deviceUI->ShowStatus(deviceModel);
}
