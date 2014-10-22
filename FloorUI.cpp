#include "FloorUI.h"

void FloorUI::ShowFloorInfo(string name,int number)
{
	ostringstream info;

	info << "Welcome to [" << name << "] # " << number;

	ShowInfo(info.str());
}

int FloorUI::ShowRooms(vector<int> roomNumbers,vector<string> roomNames){
	cout << "\nPlease select a Room from the following menu:\n";

		unsigned int i=0;
		for(; i<roomNumbers.size(); i++)
		{
			cout << roomNumbers[i] << ") " << roomNames[i] << "\n";
		}
		cout<< "To exit the program press "<< i << endl;
		cout << "Or any other number to return to the Floor Menu.\n\nSH> ";
	return GetCommand();
} 


