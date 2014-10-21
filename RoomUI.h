#include "CommonDefs.h"
#include "RoomModel.h"
#include "BaseUI.h"

class RoomUI : public BaseUI
{
public:
	//members functions
	void ShowRoomInfo(RoomModel* floor);
	int GetUserCommand(vector<DeviceModel*> devices);
};
