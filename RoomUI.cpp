#include "RoomUI.h"

// Displays room name and number
void RoomUI::ShowRoomInfo(string name, int roomNumber){
	ostringstream info;

	info << "Welcome to [" << name << "] # " << roomNumber;
	ShowInfo(info.str());
}

// Displays device options for given room and asks user to select one
int RoomUI::SelectDevice(vector<int> deviceIds,vector<string> names){
	cout << "\nPlease select a Option from the following menu:" << endl;

	unsigned int i=0;
	for(; i < deviceIds.size(); i++){
		cout << i << ") " << names[i] <<"(Device #" << deviceIds[i] << ")" << endl;
	}

	cout << " \nPress " << i << " to EXIT SmartHome. " << endl;
	cout << "Or any other number to return to room selection.\n\nSH> ";
	return GetCommand();
} 


