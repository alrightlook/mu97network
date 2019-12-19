#include "Library.h"

namespace Network
{
	bool Event::initComponents()
	{
		if(!HappyHour::initComponents())
		{
			return false;
		}

		return true;
	}
}