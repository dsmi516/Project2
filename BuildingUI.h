#include "CommonDefs.h"
#include "BuildingModel.h"
#include "BaseUI.h"

class BuildingUI : public BaseUI
{
public:
	//members functions
	void ShowBuildingInfo(string name, string address);
	int ShowFloors(vector<int> floorNumbers,vector<string> floorNames);
	void LeaveBuilding(string name);
};

