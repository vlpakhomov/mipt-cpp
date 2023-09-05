#pragma once
// Copyright 2023 Vladislav Pakhomov

#include <cmath>
#include <cstdint>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

class BigInteger {
  public:
    static int const kBase = 10;
    static int const digit_size = log10(kBase - 1) + 1;

    BigInteger() = default;
    BigInteger(BigInteger const& big) = default;
    ~BigInteger() = default;
    
    void Swap(BigInteger& big);
    BigInteger& operator=(BigInteger const& big);

    explicit BigInteger(std::string const& str);
    BigInteger(std::int64_t num);

    BigInteger& operator+=(BigInteger const& big); 
    BigInteger& operator-=(BigInteger const& big);
    BigInteger& operator*=(BigInteger const& big);
    BigInteger& operator/=(BigInteger const& big);
    BigInteger& operator%=(BigInteger const& big);
  
    BigInteger& operator++();
    BigInteger operator++(int);
    BigInteger& operator--();
    BigInteger operator--(int);

    BigInteger operator-() const;
   
    explicit operator bool() const;

    std::string ToString() const;
    
    int NumDigits() const; 
    
    bool IsNeg() const;
  private:
    std::vector<int> digits_ = {0};
    bool is_neg_ = false;

    void Normalize();

    static std::string Dtos(int digit);

    static int Stod(std::string const& digit);
    
    int GetDigit(int k) const;

    static bool UComp(BigInteger const& big1, BigInteger const& big2);
};

BigInteger operator+(BigInteger const& big1, BigInteger const& big2);
BigInteger operator-(BigInteger const& big1, BigInteger const& big2);
BigInteger operator*(BigInteger const& big1, BigInteger const& big2);
BigInteger operator/(BigInteger const& big1, BigInteger const& big2);
BigInteger operator%(BigInteger const& big1, BigInteger const& big2);

bool operator<(BigInteger const& big1, BigInteger const& big2);
bool operator>(BigInteger const& big1, BigInteger const& big2);
bool operator<=(BigInteger const& big1, BigInteger const& big2);
bool operator>=(BigInteger const& big1, BigInteger const& big2);
bool operator==(BigInteger const& big1, BigInteger const& big2);
bool operator!=(BigInteger const& big1, BigInteger const& big2);

std::ostream& operator<<(std::ostream& out, BigInteger const& big);
std::istream& operator>>(std::istream& inp, BigInteger& big);
