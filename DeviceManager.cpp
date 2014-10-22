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

	if(deviceModel->IsCommandEnabled()){
		
		if(!deviceModel->GetPowerStatus()){
			deviceUI->CommandErrorHandler(1);

		} else if(!deviceModel->GetOnlineStatus()){
			deviceUI->CommandErrorHandler(2);

		} else {
			int selection = deviceUI->SelectCommand(deviceModel->GetMaxCommands());
			
			if(selection <= deviceModel->GetMaxCommands() && selection >= 0){
				deviceModel->ExecuteCommand(selection);
				deviceUI->ShowCommandExecuted(true);
			} else {
				deviceUI->ShowCommandExecuted(false);
			}
			
		}

	} else {
		deviceUI->CommandErrorHandler(0);
	} 

	deviceUI->ShowGoBack();
	
}
void DeviceManager::PowerManagement(){
	if(!deviceModel->GetOnlineStatus()){
		deviceUI->PowerErrorHandler();
	} else {

		bool isOn = deviceModel->GetPowerStatus();
		int selection = deviceUI->PowerOptions(isOn);

		//is user wishes to change power setting
		if(selection == 1){
	 		deviceModel->SetPowerStatus(!isOn);
	 		//show status of power setting after change
			deviceUI->ShowPowerStatus(deviceModel->GetPowerStatus());
		} else {
			return;
		}
	}

 
	deviceUI->ShowGoBack();
}
void DeviceManager::CheckStatus(){
	
	int deviceId = deviceModel->GetDeviceId();

	deviceUI->ShowOnlineAndPowerStatus(deviceId, deviceModel->GetPowerStatus(), deviceModel->GetOnlineStatus());

	if(deviceModel->IsSafetyRelated()) {
		deviceUI->ShowSafetyStatus(true, deviceModel->GetSafetyStatus());
	} else {
		deviceUI->ShowSafetyStatus(false, false);
	}

	if(deviceModel->IsTextCapable()){
		deviceUI->ShowTextStatus(true, deviceModel->GetTextStatus());
	} else {
		deviceUI->ShowTextStatus(false, "");
	}

	if(deviceModel->IsCommandEnabled()){
		deviceUI->ShowCommandStatus(true, deviceModel->GetMaxCommands());
	} else {
		deviceUI->ShowCommandStatus(false, 0);
	}
	deviceUI->ShowGoBack();

}
