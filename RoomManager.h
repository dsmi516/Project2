#include "CommonDefs.h"
#include "RoomUI.h"
#include "RoomModel.h"


class RoomManager
{
private:
	//members variables
	RoomUI* roomUI;
	RoomModel* roomModel;

public:	
	//constructor/destructor
	RoomManager(RoomModel* roomModel);
	~RoomManager();

	//member functions
	void InvokeUserInteraction();
};
