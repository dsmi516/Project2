#include "CommonDefs.h"
#include "FloorUI.h"
#include "FloorModel.h"

class FloorManager
{
private:
	//members variables
	FloorUI* floorUI;
	FloorModel* floorModel;

public:	
	//constructor/destructor
	FloorManager(FloorModel* floorModel);
	~FloorManager();

	//member functions
	void InvokeUserInteraction();
};
