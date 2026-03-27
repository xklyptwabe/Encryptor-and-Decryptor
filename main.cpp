#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "func.h"

int main() {
    std::cout << "--- Testing Raw Pointers Class ---\n";

    CEncryptor* enc1 = new CEncryptor("HelloWorld", 3);

    std::cout << "Original: " << *enc1 << "\n";
    ++(*enc1);
    std::cout << "Encrypted (++): " << *enc1 << "\n";
    --(*enc1);
    std::cout << "Decrypted (--): " << *enc1 << "\n";

    CEncryptor* enc2 = new CEncryptor(*enc1);
    std::cout << "Copy == Original? " << (*enc1 == *enc2 ? "Yes" : "No") << "\n";

    delete enc1;
    delete enc2;

    std::cout << "\n--- Testing Smart Pointers Class ---\n";
    CEncryptorSmart* encSmart = new CEncryptorSmart("SecretData", 5);
    std::cout << "Original Smart: " << *encSmart << "\n";
    encSmart->Encrypt();
    std::cout << "Encrypted Smart: " << *encSmart << "\n";

    delete encSmart;

    return 0;
}