#include "CommonDefs.h"
#include "DeviceModel.h"
#include "BaseUI.h"

class DeviceUI : public BaseUI
{
public:
	//members functions
	void ShowDeviceMenu(string name, int number);
	int GetUserCommand();

	void ShowStatus(DeviceModel* device);

	int ShowNumberOfCommands(int NumberOfCommands);
	void CommandErrorHandler();

	int PowerOptions(bool isOn);
	void ShowPowerStatus(bool isOn);
};
