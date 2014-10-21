#include "CommonDefs.h"
#include "BuildingModel.h"
#include "BaseUI.h"

class BuildingUI : public BaseUI
{
public:
	//members functions
	void ShowBuildingInfo(BuildingModel* building);
	int GetUserCommand(vector<FloorModel*> floors);
	void LeaveBuilding();
};

