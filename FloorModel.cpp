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

	//iterate and load floors
	for(int index = 0; index < count; index++)
	{
		//get the name of the floor
		string roomName = SHAPI_GetRoomName(floorNumber, index);

		//create new floor entity
		RoomModel* roomModel = new RoomModel(index, roomName);
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

