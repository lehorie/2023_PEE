#include <iostream>
#include<string>

class cifra {
public:
    std::string message;
    std::string keys = "ABCDEFGHIJKLMNOPQRSTUVWXYZ$*@().:,!?[]=+-%abcdefghijklmnopqrstuvwxyz";
    std::string keys2 = "zyxwvutsrqponmlkjihgfedcba%-+=[?!,:.)(*@$ZYXWVUTSRQPONMLKJIHGFEDCBA";
    void encrypt(std::string& input, int displacement) {
        int newPos;
        for (char& character : input) {
            size_t pos = keys.find(character);
            if (pos != std::string::npos) {
                newPos = displacement + pos;
                character = keys[newPos % keys.size()];
            }
        }
    }
    void decrypt(std::string& input, int displacement) {
        int newPos;
        for (char& character : input) {
            size_t pos = keys2.find(character);
            if (pos != std::string::npos) {
                newPos = pos + displacement;
                character = keys2[newPos % keys2.size()];
            }
        }
    }
};


int main()
{
    cifra teste;
    teste.message = "opqz";
    std::cout << teste.message << "\n";
    teste.encrypt(teste.message, 5);
    std::cout << teste.message << "\n";
    teste.decrypt(teste.message, 5);
    std::cout << teste.message << "\n";

}

