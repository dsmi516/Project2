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

    public:
    vector<DeviceModel*> devices;

    RoomModel(int roomNumber,int floorNumber);
    ~RoomModel();

   int GetRoomNumber();
};

#endif
