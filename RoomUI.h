#include "CommonDefs.h"
#include "RoomModel.h"
#include "BaseUI.h"

class RoomUI : public BaseUI
{
public:
	//members functions
	void ShowRoomInfo(string name, int roomNumber);
	int GetUserCommand(vector<DeviceModel*> devices);
	int ShowDevices(vector<int> deviceId, vector<string> deviceName);
};
