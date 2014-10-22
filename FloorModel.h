#ifndef __FloorModelEntity__
#define __FloorModelEntity__

#include "CommonDefs.h"
#include "RoomModel.h"

class FloorModel : public NamedEntity
{
private:
	int floorNumber;
	void loadRooms();
	void disposeRooms();

	vector<RoomModel*>rooms;
	
public:

	//constructor/destructor
	FloorModel(int floorNumber, string floorName);
	~FloorModel();

	//member functions
	int GetFloorNumber();
	int GetRoomCount();
   	vector<int> GetRoomNumbers();
   	vector<string> GetRoomNames();
   	RoomModel* GetRoom(int number);
};

#endif
