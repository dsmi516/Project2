#include "FloorUI.h"

void FloorUI::ShowFloorInfo(FloorModel* floor)
{
	ostringstream info;
	
	string name = floor->GetName();
	int number = floor->GetFloorNumber();

	info << "Welcome to [" << name << "] # " << number;

	ShowInfo(info.str());
}

int FloorUI::GetUserCommand(vector<RoomModel*> rooms)
{

	cout << "\nPlease select a room from the following menu:\n";

	vector<RoomModel*>::iterator roomIterator = rooms.begin();
		for(; roomIterator != rooms.end(); roomIterator++)
		{
			RoomModel* roomModel = *roomIterator;
			cout << roomModel->GetRoomNumber() << ") " << roomModel->GetName() << "\n";
		}

		cout << "Or any other number to exit.\n\nSH> ";

	return GetCommand();
}
