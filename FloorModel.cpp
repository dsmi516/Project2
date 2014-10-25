#include "FloorModel.h"

FloorModel::FloorModel(int fNumber) {
	
	// Initialize members
	floorNumber = fNumber;

	// Get the name of the floor
	name=SHAPI_GetFloorName(fNumber);

	loadRooms();
}

FloorModel::~FloorModel(){
	// Dispose all members
	disposeRooms();
}

void FloorModel::loadRooms(){
	// Get the number of rooms on this floor
	int count = SHAPI_GetRoomCount(floorNumber);

	// Iterate and load rooms
	for(int index = 0; index < count; index++)
	{
		// Create new room entity
		RoomModel* roomModel = new RoomModel(index, floorNumber);
		rooms.push_back(roomModel);
	}
}

// Iterate over all floors and dispose one by one
void FloorModel::disposeRooms(){
	
	vector<RoomModel*>::iterator roomIterator = rooms.begin();
	for(; roomIterator != rooms.end(); roomIterator++) {
		RoomModel* roomModel = *roomIterator;
		delete roomModel;
	}
}

// Gets floor number
int FloorModel::GetFloorNumber(){
	return floorNumber;
}

// Gets room at given index
RoomModel* FloorModel::GetRoom(int number){
	return rooms.at(number);
}

// Gets number of rooms on the floor
int FloorModel::GetRoomCount(){
	return rooms.size();
}

// Gets a vector of all room numbers on the floor
vector<int> FloorModel::GetRoomNumbers()
{
	vector<int> roomNumbers;
	vector<RoomModel*>::iterator roomIterator = rooms.begin();

	for(; roomIterator != rooms.end(); roomIterator++){
		RoomModel* roomModel = *roomIterator;
		roomNumbers.push_back(roomModel->GetRoomNumber());
	}
	return roomNumbers;
}

// Gets a vector of all room names on the floor
vector<string> FloorModel::GetRoomNames()
{
	vector<string> roomNames;
	vector<RoomModel*>::iterator roomIterator = rooms.begin();

	for(; roomIterator != rooms.end(); roomIterator++){
		RoomModel* roomModel = *roomIterator;
		roomNames.push_back(roomModel->GetName());
	}
	return roomNames;
}

