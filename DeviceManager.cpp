#include "DeviceManager.h"

DeviceManager::DeviceManager(DeviceModel* device) {
	// Initialize all members
	deviceModel = device;
	deviceUI = new DeviceUI();
}

DeviceManager::~DeviceManager() {
	// Dispose all members
	delete deviceUI;
	//delete deviceModel;
}

bool DeviceManager::InvokeUserInteraction() {

	// Top level interaction is repeating loop
	while(true)
	{
		// Show the device menu for selected device and get user command
		int commandId = deviceUI->ManageDevice(deviceModel->GetName(),deviceModel->GetDeviceId());
		
		// Select the appropriate option from user command
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
				// Exits the program
				return false;
			default:
				return true;
		}
	}
}

// Enters Exeute Command where the user can choose a command to send to a given device
void DeviceManager::ExecuteCommand(){
	
	bool isSafe;
	
	if(deviceModel->IsSafetyRelated()){
	isSafe = deviceModel->GetSafetyStatus();
	} else {
	isSafe = true;
	}

	if(isSafe){
	
		// Checks that device is command enabled
		if(deviceModel->IsCommandEnabled()){
		
			// Checks that the device is powered on
			if(!deviceModel->GetPowerStatus()){
				deviceUI->CommandErrorHandler(1);

			// Checks that the device is online
			} else if(!deviceModel->GetOnlineStatus()){
				deviceUI->CommandErrorHandler(2);

			} else {
				// Takes in user input and executes desired command
				int selection = deviceUI->SelectCommand(deviceModel->GetMaxCommand());
			
				// Checks that command is valid
				if(selection <= deviceModel->GetMaxCommand() && selection >= 0){
					deviceModel->ExecuteCommand(selection);
					deviceUI->ShowCommandExecuted(true);
				} else {
					deviceUI->ShowCommandExecuted(false);
				}
			
			}

		} else {
			deviceUI->CommandErrorHandler(0);
		} 
	}else{
		deviceUI->SafetyErrorHandler();
	}

	// Allows user to go back to the previous menu
	deviceUI->ShowGoBack();
	
}

// Enters Power Management where the user can see current power status and turn it on/off for the selected device.
void DeviceManager::PowerManagement(){
	bool isSafe;
	
	if(deviceModel->IsSafetyRelated()){
	isSafe = deviceModel->GetSafetyStatus();
	} else {
	isSafe = true;
	}
	
	// Checks that the device is online
	if(deviceModel->GetOnlineStatus()){
		if(isSafe){
			bool isOn = deviceModel->GetPowerStatus();
			int selection = deviceUI->PowerOptions(isOn);

			// If user wishes to change power setting
			if(selection == 1){
		 		deviceModel->SetPowerStatus(!isOn);
		 		// Show status of power setting after change
				deviceUI->ShowNewPowerStatus(deviceModel->GetPowerStatus());
			} else {
				return;
			}
		}else {
			deviceUI->SafetyErrorHandler();
		}
	} else {
		deviceUI->PowerErrorHandler();
	}
 	// Allows user to go back to the previous menu
	deviceUI->ShowGoBack();
}

// Enters Check Status where the user can see the all statuses for the selected device
void DeviceManager::CheckStatus(){
	
	int deviceId = deviceModel->GetDeviceId();

	// Display online/offline and power status 
	deviceUI->ShowOnlineAndPowerStatus(deviceId, deviceModel->GetPowerStatus(), deviceModel->GetOnlineStatus());

	// Display safety status if safety enabled
	if(deviceModel->IsSafetyRelated()) {
		deviceUI->ShowSafetyStatus(true, deviceModel->GetSafetyStatus());
	} else {
		deviceUI->ShowSafetyStatus(false, false);
	}

	// Display text status if text enabled
	if(deviceModel->IsTextCapable()){
		deviceUI->ShowTextStatus(true, deviceModel->GetTextStatus());
	} else {
		deviceUI->ShowTextStatus(false, "");
	}

	// Display list of possible commands if command enabled
	if(deviceModel->IsCommandEnabled()){
		deviceUI->ShowCommandStatus(true, deviceModel->GetMaxCommand());
	} else {
		deviceUI->ShowCommandStatus(false, 0);
	}

	// Allows user to go back to the previous menu
	deviceUI->ShowGoBack();

}
