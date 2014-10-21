#include "RoomUI.h"

void RoomUI::ShowRoomInfo(RoomModel* room){
	ostringstream info;
	
	string name = room->GetName();
	int number = room->GetRoomNumber();

	info << "Welcome to [" << name << "] # " << number;

	ShowInfo(info.str());
}

int RoomUI::GetUserCommand(vector<DeviceModel*> devices){
	cout << "\nPlease select a Device from the following menu:\n";

	vector<DeviceModel*>::iterator deviceIterator = devices.begin();
		for(; deviceIterator != devices.end(); deviceIterator++)
		{
			DeviceModel* deviceModel = *deviceIterator;
			cout << deviceModel->GetDeviceId() << ") " << deviceModel->GetName() << "\n";
		}

		cout << "Or any other number to exit.\n\nSH> ";

	return GetCommand();
}
