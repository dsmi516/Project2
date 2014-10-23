#include "BuildingModel.h"

// Load building attributes
BuildingModel::BuildingModel() {

	name = SHAPI_GetBuildingName();
	address = SHAPI_GetBuildingStreetAddress();

	//load floors in the building
	loadFloors();
}

BuildingModel::~BuildingModel() {
	// Dispose all members
	disposeFloors();
}

void BuildingModel::loadFloors() {
	// Get the number of floors in this building
	int count = SHAPI_GetFloorCount();

	// Iterate and load floors
	for(int index = 0; index < count; index++){
		// Get the name of the floor
		string floorName = SHAPI_GetFloorName(index);
		
		// Create new floor entity 
		FloorModel* floorModel = new FloorModel(index, floorName);
		floors.push_back(floorModel);
	}	
}

void BuildingModel::disposeFloors() {
	//iterate over all floors and dispose one by one
	vector<FloorModel*>::iterator floorIterator = floors.begin();
	for(; floorIterator != floors.end(); floorIterator++){
		FloorModel* floorModel = *floorIterator;
		delete floorModel;
	}
}

// Gets the building address
string BuildingModel::GetStreetAddress() {
	return address;
}

// Gets floor from vector of floors
FloorModel* BuildingModel::GetFloor(int id) {
	return floors.at(id);
}

// Gets number of floors in builing
int BuildingModel::GetFloorCount() {
	return floors.size();
}

// Gets a vector of all floor numbers on the building
vector<int> BuildingModel::GetFloorNumbers() {
	
	vector<int> floorNumbers;
	vector<FloorModel*>::iterator floorIterator = floors.begin();

	for(; floorIterator != floors.end(); floorIterator++) {
		FloorModel* floorModel = *floorIterator;
		floorNumbers.push_back(floorModel->GetFloorNumber());
	}
	return floorNumbers;
}

// Gets a vector of all floor names in the building
vector<string> BuildingModel::GetFloorNames() {
	
	vector<string> floorNames;
	vector<FloorModel*>::iterator floorIterator = floors.begin();

	for(; floorIterator != floors.end(); floorIterator++) {
		FloorModel* floorModel = *floorIterator;
		floorNames.push_back(floorModel->GetName());
	}

	return floorNames;
	
}
