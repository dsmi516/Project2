#include "DeviceUI.h"

void DeviceUI::ShowDeviceMenu(DeviceModel* deviceModel){
	ostringstream info;

	string name = deviceModel->GetName();
	int number = deviceModel->GetDeviceId();

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


void DeviceUI::ShowStatus(DeviceModel* deviceModel){
	
	cout << "The device (#" << deviceModel->GetDeviceId() << ") and is currently powered ";
	
	if(deviceModel->GetPowerStatus()){
		cout << "on";
	} else {
		cout << "off";
	}

	cout << " and is ";

	if(deviceModel->GetOnlineStatus()){
		cout << "online." << endl;
	} else {
		cout << "offine." << endl;
	}

	cout << "The device is ";
	if(deviceModel->IsSafetyRelated()){
		cout << " safety related and is currently ";
		if(deviceModel->GetSafetyStatus()){
			cout << "safe." << endl;
		} else {
			cout << "unsafe." << endl;
		}

	} else {
		cout << "not safety related." << endl;;
	}

	cout << "The device is ";
	if(deviceModel->IsTextCapable()){
		cout << "text capable. Current status: " << deviceModel->GetTextStatus() << endl;
	} else {
		cout << "is not text capable" << endl;
	}

	cout << "The device ";
	if(deviceModel->IsCommandEnabled()){
		cout << "can execute commands [0-" << deviceModel->GetNumberOfCommands() << "]" << endl;
	} else {
		cout << "cannot execute commands." << endl;
	}

	cout << "Press any key to continue." << endl;

	GetCommand();
	return;
}
int DeviceUI::ShowCommands(DeviceModel* device){

	int commands=device->GetNumberOfCommands();

	cout<< "Please input a command to execute, (expecting [0-" << commands << "])"<<endl;

	int selection = GetCommand();
	
	return selection; 
}
void DeviceUI::ShowPower(DeviceModel* device){

	bool isOn= device->GetPowerStatus();
	
	cout<< "This device is ";

	if(isOn){
	cout << "on."<<endl;
	cout << "To turn off the device press 0"<<endl;
	
	}else{
	cout << "off."<<endl;
	cout << "To Turn on the device press 1"<<endl;
	} 

}

void DeviceUI::ShowPowerStatus(DeviceModel* device){

	bool isOn= device->GetPowerStatus();
	
	cout<< "\nThis device is now Powered ";

	if(isOn){
	cout << "On"<<endl;

	}else{
	cout << "Off"<<endl;
	} 

	cout<<"Press any key to continue"<<endl;

	GetCommand();
	
}
