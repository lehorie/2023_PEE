#pragma once
#include <vector>
#include "MySensor.h"
class Communication
{
protected:
	std::vector<MySensor*> mySensors;
public:
	bool registerSensor(MySensor* sensor);
	void run();
};

