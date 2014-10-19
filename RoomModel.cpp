#include "RoomModel.h"

RoomModel::RoomModel(int rNumber,string Name):NamedEntity(Name)
{
   roomNumber=rNumber;
}

RoomModel::~RoomModel()
{
	//dispose all members
}

int RoomModel::GetRoomNumber()
{
	//return floor number
	return roomNumber;
}

