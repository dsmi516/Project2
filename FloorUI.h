#include "CommonDefs.h"
#include "FloorModel.h"
#include "BaseUI.h"

class FloorUI : public BaseUI
{
public:
	//members functions
	void ShowFloorInfo(FloorModel* floor);
	int GetUserCommand(vector<RoomModel*> rooms);
};
