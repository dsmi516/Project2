#include "BuildingUI.h"

void BuildingUI::ShowBuildingInfo(string name,string address)
{
	ostringstream info;
	
	info << "Welcome to [" << name << "] at " << address;
	ShowInfo(info.str());

}

int BuildingUI::ShowFloors(vector<int> floorNumbers, vector<string> floorNames){
	cout << "\nPlease select a Device from the following menu:\n";

		unsigned int i=0;
		for(; i<floorNumbers.size(); i++)
		{
			cout << floorNumbers[i] << ") " << floorNames[i] << "\n";
		}

		cout << "Or any other number to exit.\n\nSH> ";
	return GetCommand();
} 

void BuildingUI::LeaveBuilding(string name)
{
	ostringstream info;
	info<<"Thankyou for using "<< name;
	ShowInfo(info.str());
	cout<<endl;
}
