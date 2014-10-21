#include "CommonDefs.h"
#include "RoomUI.h"
#include "RoomModel.h"
#include "DeviceManager.h"


class RoomManager
{
private:
	//members variables
	RoomUI* roomUI;
	RoomModel* roomModel;

public:	
	//constructor/destructor
	RoomManager(RoomModel* roomModel);
	~RoomManager();

	//member functions
	bool InvokeUserInteraction();
};
