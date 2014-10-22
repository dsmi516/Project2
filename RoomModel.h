#ifndef __RoomModelEntity__
#define __RoomModelEntity__


#include "CommonDefs.h"
#include "DeviceModel.h"

class RoomModel: public NamedEntity
{
    private:
    int roomNumber;
    int floorNumber;
    
    void loadDevices();
    void disposeDevices();

    vector<DeviceModel*> devices;

    public:

    RoomModel(int roomNumber,int floorNumber);
    ~RoomModel();

   int GetRoomNumber();
   int GetNumberOfDevices();
   vector<int> GetDeviceIDs();
   vector<string> GetDeviceNames();
   DeviceModel* GetDevice(int id);

   
};

#endif
