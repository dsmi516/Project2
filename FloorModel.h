#ifndef __FloorModelEntity__
#define __FloorModelEntity__

#include "CommonDefs.h"
#include "RoomModel.h"

class FloorModel : public NamedEntity
{
private:
	int floorNumber;
	
public:
	vector<RoomModel*>rooms;

	//constructor/destructor
	FloorModel(int floorNumber, string floorName);
	~FloorModel();

	//member functions
	int GetFloorNumber();
};

#endif
