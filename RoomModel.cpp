#include "RoomModel.h"

// Constructs the room with its room name and number
RoomModel::RoomModel(int rNumber,int fNumber){
   roomNumber=rNumber;
   floorNumber=fNumber;
   name = SHAPI_GetRoomName(floorNumber, roomNumber);

   loadDevices();
}

RoomModel::~RoomModel(){
	// Dispose all members
	disposeDevices();
}

//Gets rooms number
int RoomModel::GetRoomNumber(){
	return roomNumber;
}

// Gets number of devices in room
int RoomModel::GetNumberOfDevices(){
	return devices.size();
}


void RoomModel::loadDevices(){
	// Get the number of floors in this building
	vector<int> &deviceIDs = *SHAPI_GetDevices(floorNumber,roomNumber);
	int deviceCount = SHAPI_GetDeviceCount(floorNumber,roomNumber);

	// Iterate and load floors
	for(int index = 0; index < deviceCount ; index++)
	{
		
		// Create new floor entity
		DeviceModel* deviceModel = new DeviceModel(deviceIDs[index]);
		devices.push_back(deviceModel);
	}
}

// Iterate over all floors and dispose one by one
void RoomModel::disposeDevices(){

	vector<DeviceModel*>::iterator deviceIterator = devices.begin();
	for(; deviceIterator != devices.end(); deviceIterator++)
	{
		DeviceModel* deviceModel = *deviceIterator;
		delete deviceModel;
	}
}

// Gets a vector of all device IDs in the room
vector<int> RoomModel::GetDeviceIDs(){
	vector<int> deviceIDs;
	vector<DeviceModel*>::iterator deviceIterator = devices.begin();

	for(; deviceIterator != devices.end(); deviceIterator++)
	{
		DeviceModel* deviceModel = *deviceIterator;
		deviceIDs.push_back(deviceModel->GetDeviceId());
	}
	return deviceIDs;
}

// Gets a vector of all device names in the room
vector<string> RoomModel::GetDeviceNames()
{
	vector<string> deviceNames;
	vector<DeviceModel*>::iterator deviceIterator = devices.begin();

	for(; deviceIterator != devices.end(); deviceIterator++)
	{
		DeviceModel* deviceModel = *deviceIterator;
		deviceNames.push_back(deviceModel->GetName());
	}
	return deviceNames;
}

// Gets a given device
DeviceModel* RoomModel::GetDevice(int Id){
	return devices.at(Id);
}

