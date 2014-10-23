#ifndef __DeviceModelEntity__
#define __DeviceModelEntity__


#include "CommonDefs.h"

class DeviceModel: public NamedEntity
{
    private:
    // Member variables
    int deviceId;   

    public:
    // Constructor/Destructor
    DeviceModel(int deviceId);
    ~DeviceModel();
   	
    // Member functions
   	int GetDeviceId();
   	string GetDeviceName();
   	
   	bool IsCommandEnabled();
   	int GetMaxCommand();

   	bool GetPowerStatus();
   	bool SetPowerStatus(bool newStatus);

   	bool GetOnlineStatus();

   	bool GetSafetyStatus();
   	bool IsSafetyRelated();

   	bool ExecuteCommand(int commandId);
    string GetTextStatus();
   	bool IsTextCapable();

};

#endif
