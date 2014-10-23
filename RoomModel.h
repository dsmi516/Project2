#ifndef __RoomModelEntity__
#define __RoomModelEntity__


#include "CommonDefs.h"
#include "DeviceModel.h"

class RoomModel: public NamedEntity
{
    private:
    // Member variables
    int roomNumber;
    int floorNumber;
    vector<DeviceModel*> devices;
    
    // Member methods
    void loadDevices();
    void disposeDevices();

    
    public:

    // Constructor/Destructor
    RoomModel(int roomNumber,int floorNumber);
    ~RoomModel();
    
    // Member variables
    int GetRoomNumber();
    int GetNumberOfDevices();
    vector<int> GetDeviceIDs();
    vector<string> GetDeviceNames();
    DeviceModel* GetDevice(int id);

   
};

#endif
