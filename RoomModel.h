#ifndef __RoomModelEntity__
#define __RoomModelEntity__


#include "CommonDefs.h"

class RoomModel: public NamedEntity
{
    private:
    int roomNumber;

    public:
    RoomModel(int roomNumber,string roomName);
    ~RoomModel();

   int GetRoomNumber();
};

#endif
