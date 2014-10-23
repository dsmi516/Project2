#include "CommonDefs.h"
#include "DeviceModel.h"
#include "BaseUI.h"

class DeviceUI : public BaseUI
{
public:
	//members functions
	int ManageDevice(string name, int number);
	//int GetUserCommand();

	void ShowOnlineAndPowerStatus(int deviceId, bool powerStatus, bool onlineStatus);
	void ShowSafetyStatus(bool isSafetyRelated, bool safetyStatus);
	void ShowTextStatus(bool isTextEnabled, string textStatus);
	void ShowCommandStatus(bool isCommandEnabled, int numberOfCommands);

	int SelectCommand(int NumberOfCommands);
	void CommandErrorHandler(int errorCase);

	void PowerErrorHandler();
	void ShowGoBack();
	void ShowCommandExecuted(bool isValidCommand);

	int PowerOptions(bool isOn);
	void ShowNewPowerStatus(bool isOn);
};
