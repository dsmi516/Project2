#include "DeviceUI.h"

// Displays device menu
int DeviceUI::ManageDevice(string name,int number){
	ostringstream info;

	info << "Welcome to [" << name << "] # " << number;
	ShowInfo(info.str());

	cout << " \nPlease select an option from the following menu:" << endl;
	cout << "0) Power Management" << endl;
	cout << "1) Check Status" << endl;
	cout << "2) Execute Command" << endl;
	cout << " \nPress 3 to EXIT SmartHome. " << endl;
	cout << "Press any other number to return to device selection.\n\nSH>";
	return GetCommand();
}

// Displays power (on/off) and online (online/offline) status
void DeviceUI::ShowOnlineAndPowerStatus(int deviceId, bool powerStatus, bool onlineStatus){

	cout << "The device (#" << deviceId << ") is currently powered ";
	
	if(powerStatus){
		cout << "on";
	} else {
		cout << "off";
	}

	cout << " and is ";

	if(onlineStatus){
		cout << "online." << endl;
	} else {
		cout << "offine." << endl;
	}
}

// Displays whether device is safety related and if so displays safety status
void DeviceUI::ShowSafetyStatus(bool isSafetyRelated, bool safetyStatus){
	cout << "The device is ";

	if(isSafetyRelated){
		cout << "safety related and is currently ";
		if(safetyStatus){
			cout << "safe." << endl;
		} else {
			cout << "unsafe." << endl;
		}

	} else {
		cout << "not safety related." << endl;;
	}
}

// Displays whether device is text enabled and if so displays text status
void DeviceUI::ShowTextStatus(bool isTextEnabled, string textStatus){

	cout << "The device is ";
	if(isTextEnabled){
		cout << "text capable. Current status: " << textStatus << endl;
	} else {
		cout << "not text capable" << endl;
	}
}

// Displays whether the deivce is command enabled and if so displays range of valid commands
void DeviceUI::ShowCommandStatus(bool isCommandEnabled, int maxCommand){
	
	cout << "The device ";
	if(isCommandEnabled){
		cout << "can execute commands [0-" << maxCommand << "]." << endl;
	} else {
		cout << "cannot execute commands." << endl;
	}

}

// Displays option to go back a level and does so when user presses any key
void DeviceUI::ShowGoBack(){
	cout << "Press any key to continue..." << endl;
	getch();
}

// Displays range of commands allowed and gets users selection
int DeviceUI::SelectCommand(int commands){
	cout<< "Please input a command to execute, (expecting [0-" << commands << "])"<<endl;
	return GetCommand();
}

// If device is offline, powered off or not command enabled; display the appropriate message.
void DeviceUI::CommandErrorHandler(int errorCase){
	
	switch(errorCase){
		case(0):
			cout<< "Error. Device is not command enabled."<<endl;
			break;
		case(1):
			cout << "Error. Device is currently powered off. " << endl;
			cout << "Please power device on before executing a command." << endl;
			break;
		case(2):
			cout << "Error. Device is currently offline." << endl;
			cout << "Please set device to online before executing a command" << endl;
			break;
		default:
			cout << "An unknown error has occured." << endl;
	}

}

// Displays that the command has been executed successfully
void DeviceUI::ShowCommandExecuted(bool isValidCommand){
	if(isValidCommand){
		cout << "Command successfully executed." << endl;
	} else {
		cout << "Invalid Command." << endl;
	}

}

// Displays power status (on/off) and asks user if they would like to change it (on->off or off-> on)
int DeviceUI::PowerOptions(bool isOn){
	
	cout<< "This device is currently powered ";

	if(isOn){
		cout << "on."<<endl;
		cout << "Would you like to turn it off? "<<endl;
	
	} else {
		cout << "off."<<endl;
		cout << "Would you like to turn it on?" << endl;
	} 
	
	cout << "0) No." << endl;
	cout << "1) Yes." << endl;
	return GetCommand();

}

// Displays that the device is offline
void DeviceUI::PowerErrorHandler(){
	cout << "Device is currently offline. Cannot adjust power settings." << endl;
}

void DeviceUI::SafetyErrorHandler(){
	cout<< "Device is currently unsafe. Cannot adjust settings."<<endl;
}

// Displays the new power status
void DeviceUI::ShowNewPowerStatus(bool isOn){
	cout << "This device is now powered ";

	if(isOn){
		cout << "on."<<endl;

	} else{
		cout << "off."<<endl;
	} 
	
}
