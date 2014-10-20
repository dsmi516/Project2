#include "DeviceUI.h"

void DeviceUI::ShowDeviceMenu(DeviceModel* deviceModel){
	ostringstream info;

	string name = deviceModel->GetDeviceType();
	int number = deviceModel->GetDeviceId();

	info << "Welcome to [" << name << "] # " << number;
	ShowInfo(info.str());

}

int DeviceUI::GetUserCommand(){
	
	cout << "Please select an option from the following menu:" << endl;
	cout << "0) Power Management." << endl;
	cout << "1) Check Status" << endl;
	cout << "2) Execute Command." << endl;
	cout << "Press any other number to exit.\n\nSH> ";
	
	return GetCommand();
}


void DeviceUI::ShowStatus(DeviceModel* deviceModel){
	
	cout << "The device (#" << deviceModel->getDeviceId() << ") and is currently powered ";
	
	if(deviceModel->getPowerStatus()){
		cout << "on";
	} else {
		cout << "off";
	}

	cout << " and is ";

	if(deviceModel->getOnlineStatus()){
		cout << "online." << endl;
	} else {
		cout << "offine." << endl;
	}

	cout << "The device is ";
	if(deviceModel->isSafetyRelated()){
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
	if(deviceModel->isTextCapable()){
		cout << "text capable. Current status: " << deviceModel->getTextStatus() << endl;
	} else {
		cout << "is not text capable" << endl;
	}

	cout << "The device "
	if(deviceModel->isCommandEnabled()){
		cout << "can execute commands [0-" << deviceModel->GetNumberOfCommands() << "]" << endl;
	} else {
		cout << "cannot execute commands." << endl;
	}

	cout << "Press any key to continue." << endl;

}
void DeviceUI::ShowCommands(DeviceModel* device){}
void DeviceUI::ShowPower(DeviceModel* device){}