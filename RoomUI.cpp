#include "RoomUI.h"

void RoomUI::ShowRoomInfo(string name, int roomNumber){
	ostringstream info;

	info << "Welcome to [" << name << "] # " << roomNumber;

	ShowInfo(info.str());
}

int RoomUI::ShowDevices(vector<int> deviceIds,vector<string> names){
	cout << "\nPlease select a Option from the following menu:\n";

	unsigned int i=0;
	for(; i<deviceIds.size(); i++)
	{
		cout << i << ") "<<"Device #"<< deviceIds[i] <<"-"<< names[i] << endl;
	}
	cout<< "To exit the program press "<< i << endl;
	cout << "Or any other number to return to the FloorMenu.\n\nSH> ";
	return GetCommand();
} 


