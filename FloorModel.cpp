#include "FloorModel.h"

FloorModel::FloorModel(int fNumber, string fName)
	: NamedEntity(fName)
{
	//initialize members
	floorNumber = fNumber;
	name=fName;

	loadRooms();
}

FloorModel::~FloorModel()
{
	//dispose all members
	disposeRooms();
}

int FloorModel::GetFloorNumber()
{
	//return floor number
	return floorNumber;
}

void FloorModel::loadRooms()
{
	//get the number of floors in this building
	int count = SHAPI_GetRoomCount(floorNumber);

	//iterate and load rooms
	for(int index = 0; index < count; index++)
	{

		//create new floor entity
		RoomModel* roomModel = new RoomModel(index, floorNumber);
		rooms.push_back(roomModel);
	}
}

void FloorModel::disposeRooms()
{
	//iterate over all floors and dispose one by one
	vector<RoomModel*>::iterator roomIterator = rooms.begin();
	for(; roomIterator != rooms.end(); roomIterator++)
	{
		RoomModel* roomModel = *roomIterator;
		delete roomModel;
	}
}

