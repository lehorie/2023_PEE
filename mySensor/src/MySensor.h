#pragma once

#include <string>

class MySensor
{
public:
	virtual std::string getName() = 0;
	virtual std::string getValue() = 0;
};

