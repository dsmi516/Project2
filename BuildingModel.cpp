#include "BuildingModel.h"

BuildingModel::BuildingModel()
{
	//load building attributes
	name = SHAPI_GetBuildingName();
	address = SHAPI_GetBuildingStreetAddress();

	//load floors in the building
	loadFloors();
}

BuildingModel::~BuildingModel()
{
	//dispose all members
	disposeFloors();
}

void BuildingModel::loadFloors()
{
	//get the number of floors in this building
	int count = SHAPI_GetFloorCount();

	//iterate and load floors
	for(int index = 0; index < count; index++)
	{
		//get the name of the floor
		string floorName = SHAPI_GetFloorName(index);
		
		//create new floor entity 
		FloorModel* floorModel = new FloorModel(index, floorName);
		floors.push_back(floorModel);
	}	
}

void BuildingModel::disposeFloors()
{
	//iterate over all floors and dispose one by one
	vector<FloorModel*>::iterator floorIterator = floors.begin();
	for(; floorIterator != floors.end(); floorIterator++)
	{
		FloorModel* floorModel = *floorIterator;
		delete floorModel;
	}
}

string BuildingModel::GetStreetAddress()
{
	return address;
}

FloorModel* BuildingModel::GetFloor(int id)
{
	return floors.at(id);
}

int BuildingModel::GetFloorCount()
{
	return floors.size();
}

vector<int> BuildingModel::GetFloorNumbers()
{
	vector<int> floorNumbers;
	vector<FloorModel*>::iterator floorIterator = floors.begin();

	for(; floorIterator != floors.end(); floorIterator++)
	{
		FloorModel* floorModel = *floorIterator;
		floorNumbers.push_back(floorModel->GetFloorNumber());
	}
	return floorNumbers;
}
vector<string> BuildingModel::GetFloorNames()
{
	vector<string> floorNames;
	vector<FloorModel*>::iterator floorIterator = floors.begin();

	for(; floorIterator != floors.end(); floorIterator++)
	{
		FloorModel* floorModel = *floorIterator;
		floorNames.push_back(floorModel->GetName());
	}
	return floorNames;
	
}
