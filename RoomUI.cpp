#include "RoomUI.h"

void RoomUI::ShowRoomInfo(string name, int roomNumber){
	ostringstream info;

	info << "Welcome to [" << name << "] # " << roomNumber;

	ShowInfo(info.str());
}

int RoomUI::ShowDevices(vector<int> deviceIds,vector<string> names){
	cout << "\nPlease select a Device from the following menu:\n";

		unsigned int i=0;
		for(; i<deviceIds.size(); i++)
		{
			cout << deviceIds[i] << ") " << names[i] << "\n";
		}

		cout << "Or any other number to exit.\n\nSH> ";
	return GetCommand();
} 


