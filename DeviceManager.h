#include "CommonDefs.h"
#include "DeviceUI.h"
#include "DeviceModel.h"


class DeviceManager
{
private:
	//members variables
	DeviceUI* deviceUI;
	DeviceModel* deviceModel;

public:	
	//constructor/destructor
	DeviceManager(DeviceModel* deviceModel);
	~DeviceManager();

	//member functions
	void InvokeUserInteraction();
	void ExecuteCommand(DeviceModel* deviceModel);
	void PowerManagement(DeviceModel* deviceModel);
	void CheckStatus(DeviceModel* deviceModel);
};
