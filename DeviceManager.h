#include "CommonDefs.h"
#include "DeviceUI.h"
#include "DeviceModel.h"


class DeviceManager
{
private:
	// Members variables
	DeviceUI* deviceUI;
	DeviceModel* deviceModel;

public:	
	// Constructor/destructor
	DeviceManager(DeviceModel* deviceModel);
	~DeviceManager();

	// Member functions
	bool InvokeUserInteraction();
	void ExecuteCommand();
	void PowerManagement();
	void CheckStatus();
};
