#ifndef __DeviceModelEntity__
#define __DeviceModelEntity__


#include "CommonDefs.h"

class DeviceModel: public NamedEntity
{
    private:
    
    int deviceId;
    //vector<bool> deviceStatus;    

    //bool isCommandEnabled;
    //int numberOfCommands;
   
    //bool powerStatus;
    //bool onlineStatus;
    
    //bool safetyStatus;
    //bool isSafetyRelated;
   
    //bool isTextCapable;

    public:
    
    DeviceModel(int deviceId);
    ~DeviceModel();
   	
   	int GetDeviceId();
   	string GetDeviceName();
   	
   	bool IsCommandEnabled();
   	int GetMaxCommands();

   	bool GetPowerStatus();
   	bool SetPowerStatus(bool newStatus);

   	bool GetOnlineStatus();
   	bool SetOnlineStatus(bool newStatus);

   	bool GetSafetyStatus();
   	bool IsSafetyRelated();

   	bool ExecuteCommand(int commandId);

	string GetTextStatus();
   	bool IsTextCapable();

};

#endif
