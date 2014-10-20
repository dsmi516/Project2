#include "CommonDefs.h"
#include "DeviceModel.h"
#include "BaseUI.h"

class DeviceUI : public BaseUI
{
public:
	//members functions
	void ShowDeviceMenu(DeviceModel* device);
	int GetUserCommand();
	void ShowStatus(DeviceModel* device);
	void ShowCommands(DeviceModel* device);
	void ShowPower(DeviceModel* device);
};
