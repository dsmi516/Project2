#include "DeviceModel.h"

DeviceModel::DeviceModel(int dNumber)
{
   deviceId =dNumber;
   name=SHAPI_GetDeviceName(deviceId);

}

DeviceModel::~DeviceModel()
{
	//dispose all members
}


int DeviceModel::GetDeviceId() {
	return deviceId;
}
	
bool DeviceModel::IsCommandEnabled() {
	return SHAPI_IsCommandEnabled(deviceId);
}

int DeviceModel::GetMaxCommand() {
	return SHAPI_GetMaxCommandId(deviceId);
}


bool DeviceModel::GetPowerStatus() {
	return SHAPI_GetDevicePoweredOn(deviceId);
}

bool DeviceModel::SetPowerStatus(bool newStatus) {
	return SHAPI_SetDevicePoweredOn(deviceId, newStatus);
}


bool DeviceModel::GetOnlineStatus() {
	return SHAPI_GetDeviceOnlineStatus(deviceId);
}

bool DeviceModel::SetOnlineStatus(bool newStatus) {
	return SHAPI_SetDeviceOnlineStatus(deviceId, newStatus);
}


bool DeviceModel::GetSafetyStatus() {
	return SHAPI_GetSafetyStatus(deviceId);
}
bool DeviceModel::IsSafetyRelated() {
	return SHAPI_IsSafetyRelated(deviceId);
}


bool DeviceModel::ExecuteCommand(int commandId) {
	return SHAPI_ExecuteCommand(deviceId, commandId);
}


bool DeviceModel::IsTextCapable() {
	return SHAPI_IsTextEnabled(deviceId);
}

string DeviceModel::GetTextStatus() {
	return SHAPI_GetTextStatus(deviceId);
}

