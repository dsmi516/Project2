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
	int ShowCommands(DeviceModel* device);
	void ShowPower(DeviceModel* device);
	void ShowPowerStatus(DeviceModel* device);
};
