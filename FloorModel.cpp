#include "FloorModel.h"

FloorModel::FloorModel(int fNumber, string fName)
	: NamedEntity(fName)
{
	//initialize members
	floorNumber = fNumber;
}

FloorModel::~FloorModel()
{
	//dispose all members
}

int FloorModel::GetFloorNumber()
{
	//return floor number
	return floorNumber;
}
