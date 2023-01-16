#include <iostream>
#include <string>
#include <sstream>
//#include <cstdlib>
std::string XOREncryption(std::string plaintext, std::string key) {
std::string ciphertext;
// XOR plaintext dengan key
for (int i = 0; i < plaintext.length(); i++) {
    ciphertext += plaintext[i] ^ key[i % key.length()];
}

// Konversi ke Hexadecimal
std::stringstream stream;
for (int i = 0; i < ciphertext.length(); i++) {
    stream << std::hex << (int)(unsigned char)ciphertext[i];
}

return stream.str();
}

std::string XORDecryption(std::string ciphertext, std::string key) {
std::string plaintext;
// Konversi dari Hexadecimal ke ASCII
std::stringstream stream;
for (int i = 0; i < ciphertext.length(); i += 2) {
    std::string byte = ciphertext.substr(i, 2);
   	char chr = (char) (int)strtol(byte.c_str(), NULL, 16);
    plaintext += chr;
}

// XOR plaintext dengan key
for (int i = 0; i < plaintext.length(); i++) {
    plaintext[i] = plaintext[i] ^ key[i % key.length()];
}

return plaintext;
}

int main() {
std::string plaintext, key;
std::string ciphertext;
int choice;
std::cout << "Menu:" << std::endl;
std::cout << "1. Enkripsi" << std::endl;
std::cout << "2. Dekripsi" << std::endl;
std::cout << "Masukkan pilihan: ";
std::cin >> choice;

if (choice == 1) {
    std::cout << "Masukkan plaintext: ";
    std::cin.ignore();
    std::getline(std::cin, plaintext);
    std::cout << "Masukkan key: ";
    std::getline(std::cin, key);

    ciphertext = XOREncryption(plaintext, key);
    std::cout << "Ciphertext dalam bentuk hexadecimal: " << ciphertext << std::endl;
} else if (choice == 2) {
    std::cout << "Masukkan ciphertext dalam bentuk hexadecimal: ";
    std::cin.ignore();
    std::getline(std::cin, ciphertext);
    std::cout << "Masukkan key: ";
    std::getline(std::cin, key);

    plaintext = XORDecryption(ciphertext, key);
    std::cout << "Plaintext: " << plaintext << std::endl;
} else {
    std::cout << "Pilihan tidak valid" << std::endl;
}

return 0;
}
