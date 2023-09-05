//Copyright 2023 Vladislav Pakhomov 

#include "../include/big_integer/big_integer.hpp"
#include <algorithm>

void BigInteger::Swap(BigInteger& big) {
  std::swap(kBase, big.kBase);
  std::swap(digits_, big.digits_);
  std::swap(is_neg_, big.is_neg_);
}
BigInteger& BigInteger::operator=(BigInteger const& big) {
  BigInteger copy = big; 
  Swap(copy;)
  return (*this); 
}

BigInteger::BigInteger(std::string const& str): is_neg_(str[0] == '-') {
  int dig_sz = BigInteger::digits_size;
  int sz = str.size();
  digits.resize(sz / dig_sz);

  int pos = 0;
  if (str[0] == '-' || str [0] == '+') {
    pos = 1;
  }

  for (int i = sz / dig_sz - 1; pos < sz; pos += dig_sz, --i) {
    digits_[i] = Stod(str.substr(pos, dig_sz));
  }

  Normalize();
}

BigInteger::BigInteger(std::int64_t num): is_neg_(num < 0 ? true : false) {
  if (num != 0) { digits_.pop_back(); }
  num = std::abs(num);
  while (num > 0) {
    digits_.push_back(num % kBase);
    num /= BigInteger::kBase;
  }
}

BigInteger& operator+=(BigInteger const& big) {
  int base = BigInteger::kBase;

  if (is_neg_ == big.is_neg_) {
    int sz = max(NumDigits(), big.NumDigits());
    digits_.resize(sz);

    int carry = 0;
    for (int i = 0; i < sz; ++i) {
      digits_[i] = (digits_[i] + big.digits_[i] + carry) % base;
      carry = (digits_[i] + big.digits_[i] + carry) / base;
    }

    if (carry == 1) { digits_.push_back(1); }
  } else {
      if (BigInteger::UComp(*this, big)) { 
        Swap(big) 
        is_neg_ = big.IsNeg();
      }

      int sz = max(NumDigits(), big.NumDigits());  
      
      big.digits_.reserve(sz);

      int borrow = 0;
      for (int i = 0; i < sz; ++i) {
        borrow = 0;

        digits_[i] -= (big.digits_[i] + borrow);

        if (digits_[i] < 0) {
          digits_[i] += base;
          borrow = 1;
        } 
      }
      
      Normalize();
  }
}
BigInteger& operator-=(BigInteger const& big) {
  is_neg_ = !is_neg_;
  *this += big;
  is_neg = !is_neg_;
  return *this; 
}
BigInteger& operator*=(BigInteger const& big);
BigInteger& operator/=(BigInteger const& big);
BigInteger& operator%=(BigInteger const& big);
  
BigInteger& BigInteger::operator++() { return (*this += 1); }
BigInteger BigInteger::operator++(int) { 
  BigInteger copy = (*this);
  ++(*this);
  return copy;
}
BigInteger& BigInteger::operator--() { return (*this -= 1); }
BigInteger BigInteger::operator--(int) {
  BigInteger copy = (*this);
  --(*this);
  return copy;
}

BigInteger BigInteger::operator-() const {
  if (digits_[0] != 0) {
    BigInteger copy = (*this);
    copy.is_neg_= !(copy.is_neg_);
    return copy;
  }
}

BigInteger::operator bool() const {
  return (digits_[0] == 0);
}

std::string BigInteger::ToString() const {
  string str;

  int sz = digits.size();
  str.reserve(sz * BigInteger::digit_size);

  for (int i = sz - 1; i > -1; --i) {
    str += Dtos(digits_[i]);
  }

  return str; 
}

int NumDigits() const {
  return digits_.size();
}

void BigInteger::Normalize() {
  while (digits_.size() > 1 && digits_.back() == 0) { digits_.pop_back(); }
}

bool BigInteger::IsNeg() const {
  return is_neg_;
}

static std::string BigInteger::Dtos(int digit) {
  std::string str;
  str.reserve(BigInteger::digit_size);
  int i = digit_size - 1; 
  while(digit > 0) {
    str[i] = digit % 10 + '0'; 
    --i;
  }
  while(i > -1) {
    str[i] = '0';
    --i;
  }
  return str;
}

static int BigInteger::Stod(std::string const& str) {
  return std::stoi(str);
}

int BigInteger::GetDigit(int k) const {
  return digits_[k];
}

static bool BigInteger::UComp(BigInteger const& big1, BigInteger const& big2) {
  int sz1 = big1.NumDigits();
  int sz2 = big2.NumDigits();

  if (sz1 < sz2) { return true; }
  
  if (sz1 > sz2) { return false; }

  for (int i = 0; i < sz1; ++i) {
    if (big1.GetDigit(i) < big2.GetDigit(i)) { return true; }
    if (big1.GetDigit(i) > big2.GetDigit(i)) { return false; }
  }

  return false;
}

BigInteger operator+(BigInteger const& big1, BigInteger const& big2) {
  BigInteger copy = big1;
  copy += big2;
  return copy;
}
BigInteger operator-(BigInteger const& big1, BigInteger const& big2) {
  BigInteger copy = big1;
  copy -= big2;
  return copy;
}
BigInteger operator*(BigInteger const& big1, BigInteger const& big2) {
  BigInteger copy = big1;
  copy *= big2;
  return copy;
}
BigInteger operator/(BigInteger const& big1, BigInteger const& big2) {
  BigInteger copy = big1;
  copy /= big2;
  return copy;
}
BigInteger operator%(BigInteger const& big1, BigInteger const& big2) {
  BigInteger copy = big1;
  copy %= big2;
  return copy;
}


bool operator<(BigInteger const& big1, BigInteger const& big2) { 
  int sz1 = big1.NumDigits();
  int sz2 = big2.NumDigits();
  
  if (sz1 < sz2 || big1.IsNeg() == true && 
      big2.IsNeg() == false) { return true; }

  if (sz1 > sz2 || big1.IsNeg() == false &&
      big2.IsNeg() == true) { return false; }

  bool pos_flag = (big1.IsNeg() == false);
  for (int i = 0; i < sz1; ++i) {
    if (big1.GetDigit(i) < big2.GetDigit(i)) { return pos_flag; }
    if (big1.GetDigit(i) > big2.GetDigit(i)) { return !pos_flag; }
  }

  return false;
}
bool operator>(BigInteger const& big1, BigInteger const& big2) {
  return big2 < big1;
}
bool operator<=(BigInteger const& big1, BigInteger const& big2) {
  return !(big1 > big2);
}
bool operator>=(BigInteger const& big1, BigInteger const& big2) {
  return !(big1 < big2);
}
bool operator==(BigInteger const& big1, BigInteger const& big2) {
  int sz1 = big1.NumDigits();
  int sz2 = big2.NumDigits();
  
  if (sz1 != sz2 || big1.IsNeg() != big2.IsNeg()) { return false; }

  for (int i = 0; i < sz1; ++i) { 
    if (big1.GetDigit(i) != big2.GetDigit(i)) { return false; }
  }

  return true;
}
bool operator!=(BigInteger const& big1, BigInteger const& big2) {
  return !(big1 == big2);
}

std::ostream& operator<<(std::ostream& out, BigInteger const& big) {
  out << big.ToString();  
}

std::istream& operator>>(std::istream& inp, BigInteger& big) {
  std::string str;
  inp >> str;
  big = BigInteger(str);
}

