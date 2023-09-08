//Copyright 2023 Vladislav Pakhomov 

#include "../include/big-integer/big-integer.hpp"
#include <cctype>
#include <climits>
#include <algorithm>

void BigInt::Swap(BigInt& bi) {
  std::swap(digits_, bi.digits_);
  std::swap(is_neg_, bi.is_neg_);
}
BigInt& BigInt::operator=(BigInt const& bi) {
  BigInt copy = bi; 
  Swap(copy);
  return (*this); 
}

BigInt::BigInt(std::string const& str): is_neg_(str[0] == '-' && 
    str[1] != '0') {
  int pos = static_cast<int>(str[0] == '-' || str[0] == '+');
  int dig_sz = BigInt::kDigitSize;
  int sz = str.size();
  digits_.resize((sz - pos) / dig_sz);

  for (int i = 0; pos < sz; pos += dig_sz, ++i) {
    digits_[i] = Stod(str.substr(pos, dig_sz));
  }

  Normalize();
}

BigInt::BigInt(std::int64_t num): is_neg_(num < 0) {
  if (num != 0) { digits_.pop_back(); }
  num = std::abs(num);
  while (num > 0) {
    digits_.push_back(num % BigInt::kBase);
    num /= BigInt::kBase;
  }
}

BigInt& BigInt::operator+=(BigInt const& bi) {
  int base = BigInt::kBase;
  if (is_neg_ == bi.is_neg_) {
    int sz = std::max(NumDigits(), bi.NumDigits());
    digits_.resize(sz);
    int carry = 0;
    for (int i = 0; i < sz; ++i) {
      digits_[i] = (digits_[i] * 1LL + bi.digits_[i] + carry) % base;
      carry = (digits_[i] + bi.digits_[i] + carry) / base;
    }
    if (carry == 1) { digits_.push_back(1); }
  } else {
      BigInt copy = bi;
      if (BigInt::UComp(*this, copy)) { 
        Swap(copy);
        is_neg_ = bi.IsNeg();
      }
      int sz = std::max(NumDigits(), copy.NumDigits());  
      digits_.reserve(sz);
      int borrow = 0;
      for (int i = 0; i < sz; ++i) {
        digits_[i] -= (copy.digits_[i] + borrow);
        if (digits_[i] < 0) {
          digits_[i] += base;
        } 
        borrow = digits_[i] < 0 ? -1 : 0;
      }
      Normalize();
  }
  return (*this);
}
BigInt& BigInt::operator-=(BigInt const& bi) {
  is_neg_ = !is_neg_;
  *this += bi;
  is_neg_ = !is_neg_;
  return *this; 
}
BigInt& BigInt::operator*=(BigInt const& bi) {
  is_neg_ = !(is_neg_ != bi.IsNeg());

  BigInt copy = (*this);
      
  int sz1 = bi.NumDigits();
  int sz2 = NumDigits();
  digits_.resize(sz1 + sz2);

  for (int i = 0; i < sz1; ++i) {
    for (int j = 0, carry = 0; j < sz2 || carry == 1; ++i) {
      long long cur = GetDigit(i+j) + 
        copy.GetDigit(i) * 1LL *  (j < sz2 ? bi.GetDigit(j) : 0) + carry;
      digits_[i+j] = cur % BigInt::kBase;
      carry = cur / BigInt::kBase;
    }
  }
  Normalize();
  return (*this);
}
BigInt& BigInt::operator/=(BigInt const& bi) {
  if ((*this) < bi) { 
    (*this) = 0;
  } else {
      is_neg_ = !(is_neg_ != bi.IsNeg());

      int sz1 = NumDigits();
      int sz2 = bi.NumDigits();  
      BigInt numerator;
      numerator.digits_.reserve(sz2);

      int idx = 0;
      do {
        bool flag = false;
        std::copy(digits_.rbegin() + idx, 
            digits_.rbegin() + idx + sz2, numerator.digits_.begin());
        if (numerator < bi && idx + sz2 < sz1) { 
          int num = digits_[sz1 - idx - sz2];
          numerator.digits_.insert(numerator.digits_.begin(), num);
          flag = true;
        }
        int q = BigInt::Quotient(numerator, bi);
        //if (flag) { numerator.digits_.begin(); }
        idx += sz2;
      } while(idx + sz2 < sz1);
  }

  return (*this);
}
BigInt& BigInt::operator%=(BigInt const& bi) {
  return (*this) -= (*this)/bi * bi;
}
  
BigInt& BigInt::operator++() { return (*this += 1); }
BigInt BigInt::operator++(int) { 
  BigInt copy = (*this);
  ++(*this);
  return copy;
}
BigInt& BigInt::operator--() { return (*this -= 1); }
BigInt BigInt::operator--(int) {
  BigInt copy = (*this);
  --(*this);
  return copy;
}

BigInt BigInt::operator-() const {
  BigInt copy = (*this);
  if (digits_[0] != 0) {
    copy.is_neg_= !(copy.is_neg_);
  }
  return copy;
}

BigInt::operator bool() const {
  return (digits_[0] == 0);
}

std::string BigInt::ToString() const {
  std::string str;

  int sz = digits_.size();
  str.reserve(sz * BigInt::kDigitSize);

  for (int i = sz - 1; i > -1; --i) {
    str += Dtos(digits_[i]);
  }

  return str; 
}

int BigInt::GetDigit(int k) const {
  return digits_[k];
}

int BigInt::NumDigits() const {
  return digits_.size();
}

void BigInt::Normalize() {
  while (digits_.size() > 1 && digits_.back() == 0) { digits_.pop_back(); }
}

bool BigInt::IsNeg() const {
  return is_neg_;
}

//constexpr int BigInt::DigitSize() {
  //return std::log10(BigInt::kBase - 1) + 1;
//}

std::string BigInt::Dtos(int digit) {
  std::string str(BigInt::kDigitSize, ' ');
  int i = BigInt::kDigitSize - 1;
  int const kBase = 10;
  while(digit > 0) {
    str[i] = digit % kBase + '0';
    digit /= kBase;
    --i;
  }
  while(i > -1) {
    str[i] = '0';
    --i;
  }
  return str;
}

int BigInt::Stod(std::string const& str) {
  return std::stoi(str);
}

bool BigInt::UComp(BigInt const& bi1, BigInt const& bi2) {
  int sz1 = bi1.NumDigits();
  int sz2 = bi2.NumDigits();

  if (sz1 < sz2) { return true; }
  
  if (sz1 > sz2) { return false; }

  for (int i = 0; i < sz1; ++i) {
    if (bi1.GetDigit(i) < bi2.GetDigit(i)) { return true; }
    if (bi1.GetDigit(i) > bi2.GetDigit(i)) { return false; }
  }

  return false;
}

int BigInt::Quotient(BigInt const& numtr, 
    BigInt const& denumtr) {
  int l = 0;
  int r = INT_MAX; 
  while(r - l > 1) {
    int m = (r + l) / 2;
    if (m * denumtr <= numtr) { l = m; }
    else { r = m; }
  }

  return l;
}

BigInt operator+(BigInt const& bi1, BigInt const& bi2) {
  BigInt copy = bi1;
  copy += bi2;
  return copy;
}
BigInt operator-(BigInt const& bi1, BigInt const& bi2) {
  BigInt copy = bi1;
  copy -= bi2;
  return copy;
}
BigInt operator*(BigInt const& bi1, BigInt const& bi2) {
  BigInt copy = bi1;
  copy *= bi2;
  return copy;
}
BigInt operator/(BigInt const& bi1, BigInt const& bi2) {
  BigInt copy = bi1;
  copy /= bi2;
  return copy;
}
BigInt operator%(BigInt const& bi1, BigInt const& bi2) {
  BigInt copy = bi1;
  copy %= bi2;
  return copy;
}


bool operator<(BigInt const& bi1, BigInt const& bi2) { 
  int sz1 = bi1.NumDigits();
  int sz2 = bi2.NumDigits();
  
  if (sz1 < sz2 || bi1.IsNeg() && 
      !bi2.IsNeg()) { return true; }

  if (sz1 > sz2 || !bi1.IsNeg() &&
      bi2.IsNeg()) { return false; }

  bool pos_flag = (!bi1.IsNeg());
  for (int i = sz1 - 1; i > 0; --i) {
    if (bi1.GetDigit(i) < bi2.GetDigit(i)) { return pos_flag; }
    if (bi1.GetDigit(i) > bi2.GetDigit(i)) { return !pos_flag; }
  }

  return false;
}
bool operator>(BigInt const& bi1, BigInt const& bi2) {
  return bi2 < bi1;
}
bool operator<=(BigInt const& bi1, BigInt const& bi2) {
  return !(bi1 > bi2);
}
bool operator>=(BigInt const& bi1, BigInt const& bi2) {
  return !(bi1 < bi2);
}
bool operator==(BigInt const& bi1, BigInt const& bi2) {
  int sz1 = bi1.NumDigits();
  int sz2 = bi2.NumDigits();
  
  if (sz1 != sz2 || bi1.IsNeg() != bi2.IsNeg()) { return false; }

  for (int i = 0; i < sz1; ++i) { 
    if (bi1.GetDigit(i) != bi2.GetDigit(i)) { return false; }
  }

  return true;
}
bool operator!=(BigInt const& bi1, BigInt const& bi2) {
  return !(bi1 == bi2);
}

std::ostream& operator<<(std::ostream& out, BigInt const& bi) {
  out << bi.ToString(); 
  return out;
}

std::istream& operator>>(std::istream& inp, BigInt& bi) {
  std::string str;
  inp >> str;
  bi = BigInt(str);
  return inp;
}

