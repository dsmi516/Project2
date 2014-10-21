#include "RoomModel.h"

RoomModel::RoomModel(int rNumber,int fNumber)
{
   roomNumber=rNumber;
   floorNumber=fNumber;

   //get the name of the floor
   name = SHAPI_GetRoomName(floorNumber, roomNumber);

   loadDevices();
}

RoomModel::~RoomModel()
{
	//dispose all members
	disposeDevices();
}

int RoomModel::GetRoomNumber()
{
	//return floor number
	return roomNumber;
}

void RoomModel::loadDevices()
{
	//get the number of floors in this building
	vector<int> &deviceIDs = *SHAPI_GetDevices(floorNumber,roomNumber);
	int deviceCount = SHAPI_GetDeviceCount(floorNumber,roomNumber);

	//iterate and load floors
	for(int index = 0; index < deviceCount ; index++)
	{
		
		//create new floor entity
		DeviceModel* deviceModel = new DeviceModel(deviceIDs[index]);
		devices.push_back(deviceModel);
	}
}


void RoomModel::disposeDevices()
{
	//iterate over all floors and dispose one by one
	vector<DeviceModel*>::iterator deviceIterator = devices.begin();
	for(; deviceIterator != devices.end(); deviceIterator++)
	{
		DeviceModel* deviceModel = *deviceIterator;
		delete deviceModel;
	}
}

