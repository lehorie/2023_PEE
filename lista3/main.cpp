//Pegue o exemplo de memoria no txt
//copie e cole caso deseje testar

#include <iostream>
#include <string>
#include<map>
#include <algorithm>
#include <vector>

int main() {
	std::string users; //para coletar o usuario
	double memory;	//para coletar a memoria
	double totalMemory;
	int numberDesired; //numero de usuarios desejados

	std::map<double, std::string> usMemMap;

	std::cout << "Insira o numero de usuarios:\n";
	std::cin >> numberDesired;
	std::cout << "Insira o usuario seguido da memoria utilizada\n";

	totalMemory = 0;

	for (int i = 0; i < numberDesired; i++)
	{
		std::cin >> users >> memory;
		memory = memory / 1000000;
		usMemMap[memory] = users;
		totalMemory += memory;
	}

	//map para ordenar
	std::map<double, std::string>::iterator it;

	//print no formato desejado
	int count = 0;
	for (it = usMemMap.begin(); it != usMemMap.end(); ++it) {
		float percentage;
		percentage = (it->first) / totalMemory *100;
		std::cout << count <<"		"<< it->second << "			";
		printf("%.2f		%.2f %\n", it->first, percentage);
		count++;
	}
	std::cout << "Espaco total ocupado: " << totalMemory << "MB\n";
	std::cout << "Espaco medio ocupado: " << totalMemory / numberDesired << " MB\n";
}