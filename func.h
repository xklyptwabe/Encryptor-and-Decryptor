#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <memory>

// Basic Constructor
class CEncryptor {
private:
    char* m_text; 
    size_t m_length; 
    int m_shift; // Step Shift

public:
    CEncryptor();
    CEncryptor(const char* text, int shift);

    CEncryptor(const CEncryptor& other); // Copy constructor
    CEncryptor(CEncryptor&& other) noexcept; // Move constructor 
    CEncryptor& operator=(const CEncryptor& other);
    CEncryptor& operator=(CEncryptor&& other) noexcept;
    ~CEncryptor();

    void SetShift(int shift);
    void Encrypt();
    void Decrypt();

    CEncryptor& operator++(); // Encryption
    CEncryptor& operator--(); // Decipher
    bool operator==(const CEncryptor& other) const;

    friend std::istream& operator>>(std::istream& is, CEncryptor& obj);
    friend std::ostream& operator<<(std::ostream& os, const CEncryptor& obj);
};

// Smart Constructor
class CEncryptorSmart {
private:
    std::unique_ptr<char[]> m_text;
    size_t m_length;
    int m_shift;

public:
    CEncryptorSmart();
    CEncryptorSmart(const char* text, int shift);

    void Encrypt();

    friend std::ostream& operator<<(std::ostream& os, const CEncryptorSmart& obj);
};