#include "DeviceUI.h"

void DeviceUI::ShowDeviceMenu(string name,int number){
	ostringstream info;

	info << "Welcome to [" << name << "] # " << number;
	ShowInfo(info.str());

	cout << "Please select an option from the following menu:" << endl;
	cout << "0) Power Management." << endl;
	cout << "1) Check Status" << endl;
	cout << "2) Execute Command." << endl;
	cout << "Press any other number to exit.\n\nSH> ";

}

int DeviceUI::GetUserCommand(){
	
	return GetCommand();
}


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

void DeviceUI::ShowTextStatus(bool isTextEnabled, string textStatus){

	cout << "The device is ";
	if(isTextEnabled){
		cout << "text capable. Current status: " << textStatus << endl;
	} else {
		cout << "is not text capable" << endl;
	}
}

void DeviceUI::ShowCommandStatus(bool isCommandEnabled, int numberOfCommands){
	
	cout << "The device ";
	if(isCommandEnabled){
		cout << "can execute commands [0-" << numberOfCommands << "]." << endl;
	} else {
		cout << "cannot execute commands." << endl;
	}

	cout << "Press any key to continue." << endl;
	GetCommand();

}

int DeviceUI::ShowNumberOfCommands(int commands){

	cout<< "Please input a command to execute, (expecting [0-" << commands << "])"<<endl;

	return GetCommand();
}

void DeviceUI::CommandErrorHandler(){
	cout<< "Error command in not Enabled"<<endl;
}




int DeviceUI::PowerOptions(bool isOn){
	
	cout<< "This device is ";

	if(isOn){
	cout << "on."<<endl;
	cout << "To Turn off the device Press 1."<<endl;
	}else{
	cout << "off."<<endl;
	cout << "To Turn on the device Press 1."<<endl;
	} 

	cout << "To Go back Press 0"<<endl;

	int selection = GetCommand();

	return selection;
}

void DeviceUI::ShowPowerStatus(bool isOn){
	
	cout<< "\nThis device is now Powered ";

	if(isOn){
	cout << "On"<<endl;

	} else{
	cout << "Off"<<endl;
	} 
	cout<<"Press any key to continue"<<endl;
	GetCommand();
	
}
