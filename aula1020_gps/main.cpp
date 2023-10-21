#include<iostream>
#include <string>

//encontrar no pacote a senteca desejada
// na sentenca desejada retirar a latidude e a longitude


class InformationPacket {
private:
	std::string packet = "0";
	std::string latitude = "0";
	std::string longitude = "0";

public:
	std::string cardinalDirLat;
	std::string cardinalDirLong;

	std::string getPacket() {
		return packet;
	}
	void setPacket(std::string data) {
		packet = data;
	}
	void setLatitude(std::string inLatitude) {
		latitude = inLatitude;
	}
	std::string getLatitude() {
		return latitude;
	}

	void setLongitude(std::string inLongitude) {
		longitude = inLongitude;
	}
	std::string getLongitude() {
		return longitude;
	}

	void findDesiredSentence(std::string sentence) {
		size_t start = packet.find(sentence);
		packet.erase(0,start);
		size_t end = packet.find("\n");
		packet.erase(end);
		std::cout << "The sentence you are looking for is: " << packet << ".\n";
	}
	virtual void findLatitude() {
		std::cout << "No sentence specified";
	}
	void printLat() {
		double lat = std::stod(getLatitude());
		int deg = lat / 100;
		int min = lat - deg*100;
		std::string stLat = getLatitude();
		size_t start = stLat.find(".");
		stLat.erase(0, start + 1);
		std::string sec = stLat;
		if (sizeof(sec) > 2)
		{
			sec.insert(2, ".");
		}
		std::cout << "Latitude " << deg << " degrees " << min << " minutes " << sec << " seconds " << cardinalDirLat<< "\n";
	}
	void printLong() {
		double longit = std::stod(getLongitude());
		int deg = longit / 100;
		int min = longit - deg * 100;
		std::string stLong = getLongitude();
		size_t start = stLong.find(".");
		stLong.erase(0, start + 1);
		std::string sec = stLong;
		if (sizeof(sec)>2)
		{
			sec.insert(2, ".");
		}
		std::cout << "Longitude " << deg << " degrees " << min << " minutes " << sec << " seconds " << cardinalDirLong << "\n";
	}
};

class GPRMC : public InformationPacket {
public:
	void findLatitude() {
		std::string sentence = getPacket();
		for (int i = 0; i < 3; i++)
		{
			size_t start = sentence.find(",");
			sentence.erase(0, start+1);
		}
		size_t end = sentence.find("N");
		if (end != std::string::npos)
		{
			sentence.erase(end - 1);
			cardinalDirLat = "north";
		}
		else {
			size_t end = sentence.find("S");
			sentence.erase(end - 1);
			cardinalDirLat = "south";
		}

		setLatitude(sentence);
		//std::cout << "Latitude information:" << getLatitude()<< " "<< cardinalDirLat <<"\n";
	}
	void findLongitude() {
		std::string sentence = getPacket();
		for (int i = 0; i < 5; i++)
		{
			size_t start = sentence.find(",");
			sentence.erase(0, start + 1);
		}
		size_t end = sentence.find("E");
		if (end != std::string::npos)
		{
			sentence.erase(end -1);
			cardinalDirLong = "east";
		}
		else {
			size_t end = sentence.find("W");
			sentence.erase(end -1);
			cardinalDirLong = "west";
		}

		setLongitude(sentence);
		//std::cout << "Longitude information:" << getLongitude() <<" " << cardinalDirLong << "\n";
	}
};


int main() {
	std::string information = "$GPGGA, 202041.00, 2252.84985, S, 04313.02346, W, 1, 06, 1.78, 13.4, M, -6.7, M, , * 7D\n";
	information += "$GPGSA,A,3,18,02,31,25,29,20,,,,,,,2.72,1.78,2.05*0B\n";
	information += "$GPGSV,3,1,12,02,45,155,24,05,51,087,19,11,11,139,15,12,57,053,17*74\n";
	information += "$GPGSV,3,2,12,15,06,033,,18,42,293,30,20,27,129,12,23,06,343,*70\n";
	information += "$GPGSV,3,3,12,24,09,001,,25,80,203,19,29,43,205,13,31,14,236,26*7F\n";
	information += "$GPGLL,2252.84985,S,04313.02346,W,202041.00,A,A*6A\n";
	information += "$GPRMC,202042.00,A,2252.84963,S,04313.02354,W,0.463,,020922,,,A*71\n";
	information += "$GPVTG,,T,,M,0.463,N,0.857,K,A*28\n";

	GPRMC dataCollected;
	dataCollected.setPacket(information);
	dataCollected.findDesiredSentence("$GPRMC");
	dataCollected.findLatitude();
	dataCollected.findLongitude();
	dataCollected.printLat();
	dataCollected.printLong();
}
//find, erase