#include "FloorUI.h"

// Displays floor name and number of current floor
void FloorUI::ShowFloorInfo(string name,int number)
{
	ostringstream info;

	info << "Welcome to [" << name << "] # " << number;

	ShowInfo(info.str());
}
// Diplays all rooms on the floor and asks user to select one
int FloorUI::SelectRoom(vector<int> roomNumbers,vector<string> roomNames){
	cout << "\nPlease select a Room from the following menu:\n";

		unsigned int i=0;
		for(; i<roomNumbers.size(); i++) {
			cout << roomNumbers[i] << ") " << roomNames[i] << endl;
		}

		cout << " \nPress " << i << " to EXIT SmartHome. " << endl;
		cout << "Or any other number to return to floor selection.\n\nSH>";
		
	return GetCommand();
} 


