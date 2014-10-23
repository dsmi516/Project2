#ifndef __BuildingModelEntity__
#define __BuildingModelEntity__

#include "CommonDefs.h"
#include "FloorModel.h"

class BuildingModel : public NamedEntity
{
private:
	string address;
	vector<FloorModel*> floors;

	// Construct and destruct the floors
	void loadFloors();
	void disposeFloors();

public:

	// Constructor/Destructor
	BuildingModel();
	~BuildingModel();

	// Member methods
	string GetStreetAddress();
	int GetFloorCount();

	vector<int> GetFloorNumbers();
	vector<string> GetFloorNames();

	FloorModel* GetFloor(int id);
	
};

#endif
