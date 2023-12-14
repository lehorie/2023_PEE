#include<iostream>
#include"src/Communication.h"
#include "src/framework.h"
#include "src/MySensor.h"
#include "src/pch.h"
#include "src/SensorSimulation.h"

class TimeSensor : public MySensor {
public: 
	std::string getName() override {
		std::string name = "Horie : Time";
			return name;
	}
	std::string getValue() override {
		SensorSimulation simValue1;
		int value;
		value = simValue1.simulateValue(1, 10);
		std::string stringValue = std::to_string(value);
		return stringValue;
	}
};

class AccSensor : public MySensor {
public:
	std::string getName() override {
		std::string name = "Horie : Acceleration";
		return name;
	}
	std::string getValue() override {
		SensorSimulation simValue1;
		int value;
		value = simValue1.simulateValue(1,10);
		std::string stringValue = std::to_string(value);
		return stringValue;
	}
};


int main() {
	Communication com;
	TimeSensor timer;
	AccSensor acc;

	com.registerSensor(&timer);
	com.registerSensor(&acc);
	com.run();
	return 0;
}


//cria projeto
//linkar com a biblioteca
//utilizar ela
//classes
//na main fazer o passo a passo