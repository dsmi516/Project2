#include "CommonDefs.h"
#include "FloorModel.h"
#include "BaseUI.h"

class FloorUI : public BaseUI
{
public:
	// Members functions
	void ShowFloorInfo(string name,int number);
	int SelectRoom(vector<int> deviceIds,vector<string> names);
};
