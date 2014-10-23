#include "CommonDefs.h"
#include "RoomModel.h"
#include "BaseUI.h"

class RoomUI : public BaseUI
{
public:
	//Member methods
	void ShowRoomInfo(string name, int roomNumber);
	int GetUserCommand(vector<DeviceModel*> devices);
	int SelectDevice(vector<int> deviceId, vector<string> deviceName);
};
