#include "CommonDefs.h"
#include "DeviceModel.h"
#include "BaseUI.h"

class DeviceUI : public BaseUI
{
public:
	//members functions
	void ShowDeviceMenu(string name, int number);
	int GetUserCommand();

	void ShowOnlineAndPowerStatus(int deviceId, bool powerStatus, bool onlineStatus);
	void ShowSafetyStatus(bool isSafetyRelated, bool safetyStatus);
	void ShowTextStatus(bool isTextEnabled, string textStatus);
	void ShowCommandStatus(bool isCommandEnabled, int numberOfCommands);

	int ShowNumberOfCommands(int NumberOfCommands);
	void CommandErrorHandler();

	int PowerOptions(bool isOn);
	void ShowPowerStatus(bool isOn);
};
