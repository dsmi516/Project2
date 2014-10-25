#ifndef __FloorModelEntity__
#define __FloorModelEntity__

#include "CommonDefs.h"
#include "RoomModel.h"

class FloorModel : public NamedEntity
{
private:
	
	// Member variables
	int floorNumber;
	vector<RoomModel*>rooms;

	// Constructor/Destructor for floors
	void loadRooms();
	void disposeRooms();

	
	
public:

	// Constructor/destructor
	FloorModel(int floorNumber);
	~FloorModel();

	// Member functions
	int GetFloorNumber();
	int GetRoomCount();
   	vector<int> GetRoomNumbers();
   	vector<string> GetRoomNames();
   	RoomModel* GetRoom(int number);
};

#endif
