#include "CommonDefs.h"
#include "roomUI.h"
#include "roomModel.h"
#include "FloorManager.h"

class roomManager
{
private:
	//members variables
	roomUI* roomUI;
	roomModel* roomModel;

public:	
	//constructor/destructor
	roomManager();
	~roomManager();

	//member functions
	void InvokeUserInteraction();
};
