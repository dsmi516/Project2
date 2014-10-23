#include "CommonDefs.h"
#include "RoomUI.h"
#include "RoomModel.h"
#include "DeviceManager.h"


class RoomManager
{
private:
	// Members variables
	RoomUI* roomUI;
	RoomModel* roomModel;

public:	
	// Constructor/destructor
	RoomManager(RoomModel* roomModel);
	~RoomManager();

	// Member functions
	bool InvokeUserInteraction();
};
