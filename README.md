🔐 **CEncryptor: Caesar Cipher and Memory Management in C++**

This project is a custom implementation of the classic Caesar cipher in C++.

The program is written **without using standard STL containers** `(such as std::string or std::vector)`. All memory management for text (C-strings) is **implemented by hand**, which makes this repository an excellent example of the application of the **"Rule of Five"** and the **RAII idiom**.

✨ **Main features**

**Encryption and decryption:** Shifting text characters along the English alphabet by a given number of steps.

**Two approaches to architecture:**
  
  ➤ CEncryptor is a class with **manual memory management** `(new/delete)` that demonstrates the work of **copy/move constructors** and **corresponding assignment operators** `(Rule of Five)`.
  
  ➤ CEncryptorSmart is a **modern alternative** that uses `std::unique_ptr` **for automatic resource release** `(Rule of Zero / RAII)`.

**Intuitive syntax:** Thanks to operator overloading, the class is very convenient to use:

`++` **for encrypting text**.

`--` **for decrypting text**.

`==` **for checking objects for equality**.

`>>` and `<<` **for working with standard I/O streams**.

🚀 **How it works (Usage example)**
```
#include <iostream>
#include "CEncryptor.h"

int main() {
    // Create an object in dynamic memory with text and shift key 3
    CEncryptor* myCipher = new CEncryptor("SecretMessage", 3);
    
    std::cout << "Оригінал: " << *myCipher << "\n";
    
    // Encrypt in one click!
    ++(*myCipher); 
    std::cout << "Зашифровано: " << *myCipher << "\n";
    
    // Decrypt back
    --(*myCipher); 
    std::cout << "Розшифровано: " << *myCipher << "\n";

    // Don't forget to free the memory
    delete myCipher; 
    
    return 0;
}
```


⚙️ **How to run locally**

`1.` **Clone the repository:**

**git clone https://github.com/xklyptwabe/Encryptor-and-Decryptor.git**

`2.` **Compile the files using your favorite compiler (e.g. GCC):**

**g++ main.cpp CEncryptor.cpp -o cipher_app**

`3.` **Run the program:**

**./cipher_app**
