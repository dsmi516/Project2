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
	bool InvokeUserInteraction();
	void ExecuteCommand();
	void PowerManagement();
	void CheckStatus();
};
