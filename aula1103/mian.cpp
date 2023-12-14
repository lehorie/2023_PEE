#include <iostream>
#include <vector>

class Packer {
public:
    std::vector<char> insertHeader(const std::vector<char>& pack, char ID) {
        if (pack.size() > 15) {
            throw std::invalid_argument("Tamanho do pacote excede 15 bytes.");
        }

        // Combina os 4 bits mais significativos (ID) e os 4 bits menos significativos (tamanho do pacote) em um único byte.
        char header = (ID << 4) | static_cast<char>(pack.size());

        std::vector<char> packWithHeader;
        packWithHeader.push_back(header);
        packWithHeader.insert(packWithHeader.end(), pack.begin(), pack.end());
        return packWithHeader;
    }
};