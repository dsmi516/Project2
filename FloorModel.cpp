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


RoomModel* FloorModel::GetRoom(int number)
{
	return rooms.at(number);
}

int FloorModel::GetRoomCount()
{
	return rooms.size();
}

vector<int> FloorModel::GetRoomNumbers()
{
	vector<int> roomNumbers;
	vector<RoomModel*>::iterator roomIterator = rooms.begin();

	for(; roomIterator != rooms.end(); roomIterator++)
	{
		RoomModel* roomModel = *roomIterator;
		roomNumbers.push_back(roomModel->GetRoomNumber());
	}
	return roomNumbers;
}
vector<string> FloorModel::GetRoomNames()
{
	vector<string> roomNames;
	vector<RoomModel*>::iterator roomIterator = rooms.begin();

	for(; roomIterator != rooms.end(); roomIterator++)
	{
		RoomModel* roomModel = *roomIterator;
		roomNames.push_back(roomModel->GetName());
	}
	return roomNames;
}

