#define _CRT_SECURE_NO_WARNINGS
#include "func.h"
#include <cstring> 
#include <cctype>
#include <utility> 

CEncryptor::CEncryptor() : m_text(nullptr), m_length(0), m_shift(0) {}

CEncryptor::CEncryptor(const char* text, int shift) : m_shift(shift) {
    m_length = std::strlen(text);
    m_text = new char[m_length + 1];
    std::strcpy(m_text, text);
}

CEncryptor::CEncryptor(const CEncryptor& other) : m_length(other.m_length), m_shift(other.m_shift) {
    if (other.m_text) {
        m_text = new char[m_length + 1];
        std::strcpy(m_text, other.m_text);
    }
    else {
        m_text = nullptr;
    }
}

CEncryptor::CEncryptor(CEncryptor&& other) noexcept : m_text(nullptr), m_length(0), m_shift(0) {
    std::swap(m_text, other.m_text);
    std::swap(m_length, other.m_length);
    std::swap(m_shift, other.m_shift);
}

CEncryptor& CEncryptor::operator=(const CEncryptor& other) { 
    if (this != &other) {
        delete[] m_text;
        m_length = other.m_length;
        m_shift = other.m_shift;
        if (other.m_text) {
            m_text = new char[m_length + 1];
            std::strcpy(m_text, other.m_text);
        }
        else {
            m_text = nullptr;
        }
    }
    return *this;
}

CEncryptor& CEncryptor::operator=(CEncryptor&& other) noexcept {
    if (this != &other) {
        delete[] m_text;
        m_text = nullptr;
        m_length = 0;
        m_shift = 0;
        std::swap(m_text, other.m_text);
        std::swap(m_length, other.m_length);
        std::swap(m_shift, other.m_shift);
    }
    return *this;
}

CEncryptor::~CEncryptor() {
    delete[] m_text;
}

void CEncryptor::SetShift(int shift) {
    m_shift = shift;
}

void CEncryptor::Encrypt() {
    if (!m_text) return;
    for (size_t i = 0; i < m_length; ++i) {
        if (isalpha(m_text[i])) {
            char base = islower(m_text[i]) ? 'a' : 'A';
            m_text[i] = (m_text[i] - base + m_shift) % 26 + base;
        }
    }
}

void CEncryptor::Decrypt() {
    if (!m_text) return;
    for (size_t i = 0; i < m_length; ++i) {
        if (isalpha(m_text[i])) {
            char base = islower(m_text[i]) ? 'a' : 'A';
            m_text[i] = (m_text[i] - base - (m_shift % 26) + 26) % 26 + base;
        }
    }
}

CEncryptor& CEncryptor::operator++() {
    Encrypt();
    return *this;
}

CEncryptor& CEncryptor::operator--() {
    Decrypt();
    return *this;
}

bool CEncryptor::operator==(const CEncryptor& other) const {
    if (!m_text && !other.m_text) return true;
    if (!m_text || !other.m_text) return false;
    return std::strcmp(m_text, other.m_text) == 0 && m_shift == other.m_shift;
}

std::istream& operator>>(std::istream& is, CEncryptor& obj) {
    char buffer[1024]; 
    is >> buffer;
    delete[] obj.m_text; 
    obj.m_length = std::strlen(buffer);
    obj.m_text = new char[obj.m_length + 1];
    std::strcpy(obj.m_text, buffer);
    return is;
}

std::ostream& operator<<(std::ostream& os, const CEncryptor& obj) {
    if (obj.m_text) os << obj.m_text;
    else os << "Empty";
    return os;
}

CEncryptorSmart::CEncryptorSmart() : m_length(0), m_shift(0) {}

CEncryptorSmart::CEncryptorSmart(const char* text, int shift) : m_shift(shift) {
    m_length = std::strlen(text);
    m_text = std::make_unique<char[]>(m_length + 1);
    std::strcpy(m_text.get(), text);
}

void CEncryptorSmart::Encrypt() {
    if (!m_text) return;
    for (size_t i = 0; i < m_length; ++i) {
        if (isalpha(m_text[i])) {
            char base = islower(m_text[i]) ? 'a' : 'A';
            m_text[i] = (m_text[i] - base + m_shift) % 26 + base;
        }
    }
}

std::ostream& operator<<(std::ostream& os, const CEncryptorSmart& obj) {
    if (obj.m_text) os << obj.m_text.get();
    return os;
}