#include "CommonDefs.h"
#include "BuildingModel.h"
#include "BaseUI.h"

class BuildingUI : public BaseUI
{
public:
	// Member methods
	void ShowBuildingInfo(string name, string address);
	int SelectFloor(vector<int> floorNumbers,vector<string> floorNames);
	void LeaveBuilding(string name);
};

