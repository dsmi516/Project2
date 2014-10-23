#include "CommonDefs.h"
#include "BuildingUI.h"
#include "BuildingModel.h"
#include "FloorManager.h"

class BuildingManager
{
private:
	// Member variables
	BuildingUI* buildingUI;
	BuildingModel* buildingModel;

public:	
	// Constructor/destructor
	BuildingManager();
	~BuildingManager();

	// Member functions
	bool InvokeUserInteraction();
};
