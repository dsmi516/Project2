#include "FloorUI.h"

void FloorUI::ShowFloorInfo(string name,int number)
{
	ostringstream info;

	info << "Welcome to [" << name << "] # " << number;

	ShowInfo(info.str());
}

int FloorUI::ShowRooms(vector<int> roomNumbers,vector<string> roomNames){
	cout << "\nPlease select a Device from the following menu:\n";

		unsigned int i=0;
		for(; i<roomNumbers.size(); i++)
		{
			cout << roomNumbers[i] << ") " << roomNames[i] << "\n";
		}

		cout << "Or any other number to exit.\n\nSH> ";
	return GetCommand();
} 


