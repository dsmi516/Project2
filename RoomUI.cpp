#include "RoomUI.h"

void RoomUI::ShowRoomInfo(RoomModel* room){
	ostringstream info;
	
	string name = room->GetName();
	int number = room->GetRoomNumber();

	info << "Welcome to [" << name << "] # " << number;

	ShowInfo(info.str());
}
int RoomUI::GetUserCommand(){
	cout<< " \nlist still under development\n";
	cout << "Press any other number to exit.\n\nSH> ";
	
	return GetCommand();
}
