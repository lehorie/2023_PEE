#include <iostream>

class format {
public:
	virtual void draw() {
		std::cout << "Formato nao especificado.\n";
	}
};

class square : public format {
public :
	void draw() {
		std::cout << " ____\n";
		std::cout << "|    |\n";
		std::cout << "|    |\n";
		std::cout << " ____\n";
	}
};

class triangle : public format {
public:
	void draw() {
		std::cout << "\n";
		std::cout << "   .  \n";
		std::cout << "  /\\  \n";
		std::cout << " /  \\\ \n";
		std::cout << "/____\\\n";
	}
};
int main(){
	format* f;
	square quad;
	triangle triang;
	f = &quad;
	f->draw();
	f = &triang;
	f->draw();
	std::cin.get();

	return 0;
}