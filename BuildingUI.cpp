#include "BuildingUI.h"

void BuildingUI::ShowBuildingInfo(BuildingModel* building)
{
	ostringstream info;
	
	string name = building->GetName();
	string address = building->GetStreetAddress();
	
	info << "Welcome to [" << name << "] at " << address;
	
	ShowInfo(info.str());
}

int BuildingUI::GetUserCommand(vector<FloorModel*> floors)
{
	cout << "\nPlease select a floor from the following menu:\n";

	vector<FloorModel*>::iterator floorIterator = floors.begin();
	for(; floorIterator != floors.end(); floorIterator++)
	{
		FloorModel* floorModel = *floorIterator;
		cout << floorModel->GetFloorNumber() << ") " << floorModel->GetName() << "\n";
	}

	cout << "Or any other number to exit.\n\nSH> ";
	return GetCommand();
}
