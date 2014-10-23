#include "CommonDefs.h"
#include "FloorUI.h"
#include "FloorModel.h"
#include "RoomManager.h"

class FloorManager
{
private:
	// Members variables
	FloorUI* floorUI;
	FloorModel* floorModel;

public:	
	// Constructor/destructor
	FloorManager(FloorModel* floorModel);
	~FloorManager();

	// Member functions
	bool InvokeUserInteraction();
};
