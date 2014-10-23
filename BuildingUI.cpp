#include "BuildingUI.h"

// Displays name and address of building
void BuildingUI::ShowBuildingInfo(string name,string address) {
	ostringstream info;
	
	info << "Welcome to [" << name << "] at " << address;
	ShowInfo(info.str());

}

// Displays all floors in the building and asks user to select one.
int BuildingUI::SelectFloor(vector<int> floorNumbers, vector<string> floorNames) {
	cout << "\nPlease select a Floor from the following menu:\n";

		unsigned int i=0;
		for(; i<floorNumbers.size(); i++)
		{
			cout << floorNumbers[i] << ") " << floorNames[i] << endl;
		}

		cout << "Or any  other number to EXIT SmartHome. \n\nSH>";

	return GetCommand();
} 

// Displays exit message
void BuildingUI::LeaveBuilding(string name) {
	ostringstream info;
	info<<"Thank you for using "<< name;
	ShowInfo(info.str());
	cout<<endl;
}
