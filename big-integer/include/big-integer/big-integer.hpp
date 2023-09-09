#pragma once
// Copyright 2023 Vladislav Pakhomov

#include <cmath>
#include <cstdint>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

class BigInt {
  public:
    static int const kBase = 10;
    // log10(kBase - 1) + 1
    static int const kDigitSize = 1;

    BigInt() = default;
    BigInt(BigInt const& bi) = default;
    ~BigInt() = default;
    
    void Swap(BigInt& bi);
    BigInt& operator=(BigInt const& bi);

    explicit BigInt(std::string const& str);
    BigInt(std::int64_t num);

    BigInt& operator+=(BigInt const& bi); 
    BigInt& operator-=(BigInt const& bi);
    BigInt& operator*=(BigInt const& bi);
    BigInt& operator/=(BigInt const& bi);
    BigInt& operator%=(BigInt const& bi);
  
    BigInt& operator++();
    BigInt operator++(int);
    BigInt& operator--();
    BigInt operator--(int);

    BigInt operator-() const;
   
    explicit operator bool() const;

    std::string ToString() const;
   
    int GetDigit(int k) const;

    int NumDigits() const; 
    
    bool IsNeg() const;
    
    static bool UComp(BigInt const& bi1, BigInt const& bi2);
  private:
    std::vector<int> digits_ = {0};
    bool is_neg_ = false;

    void Normalize();

    static std::string Dtos(int digit);

    static int Stod(std::string const& str);

    static int Quotient(BigInt const& numtr, BigInt const& denumtr); 
};

//int const BigInt::kDigitSize = BigInt::DigitSize();


BigInt operator+(BigInt const& bi1, BigInt const& bi2);
BigInt operator-(BigInt const& bi1, BigInt const& bi2);
BigInt operator*(BigInt const& bi1, BigInt const& bi2);
BigInt operator/(BigInt const& bi1, BigInt const& bi2);
BigInt operator%(BigInt const& bi1, BigInt const& bi2);

bool operator<(BigInt const& bi1, BigInt const& bi2);
bool operator>(BigInt const& bi1, BigInt const& bi2);
bool operator<=(BigInt const& bi1, BigInt const& bi2);
bool operator>=(BigInt const& bi1, BigInt const& bi2);
bool operator==(BigInt const& bi1, BigInt const& bi2);
bool operator!=(BigInt const& bi1, BigInt const& bi2);

std::ostream& operator<<(std::ostream& out, BigInt const& bi);
std::istream& operator>>(std::istream& inp, BigInt& bi);
