// Copyright 2023 Vladislav Pakhomov

#include "string.hpp"

#include <algorithm>
#include <cstring>
#include <iostream>
#include <istream>
#include <limits>
#include <locale>
#include <utility>
#include <vector>

String::String(size_t num, char chr)
    : sz_(num), cap_(sz_), data_(new char[cap_]) {
  std::fill(data_, data_ + sz_, chr);
}

String::String(char const* str)
    : sz_(strlen(str)), cap_(sz_), data_(new char[cap_]) {
  std::copy(str, str + sz_, data_);
}

String::String(String const& str)
    : sz_(str.sz_), cap_(str.cap_), data_(new char[cap_]) {
  std::copy(str.data_, str.data_ + str.sz_, data_);
}
String& String::operator=(String const& str) {
  String copy = str;
  Swap(copy);
  return *this;
}
String::~String() { delete[] data_; }

void String::Clear() { sz_ = 0; }

void String::PushBack(char chr) {
  if (sz_ == cap_) {
    Reserve(sz_ == 0 ? 1 : sz_ * 2);
  }
  data_[sz_] = chr;
  ++sz_;
}

void String::PopBack() {
  if (sz_ > 0) {
    --sz_;
  }
}

void String::Resize(size_t new_sz) {
  if (new_sz > cap_) {
    Reserve(new_sz);
  }
  sz_ = new_sz;
}

void String::Resize(size_t new_sz, char chr) {
  size_t prev_sz = sz_;
  Resize(new_sz);
  if (new_sz > prev_sz) {
    for (size_t i = prev_sz; i < new_sz; ++i) {
      data_[i] = chr;
    }
  }
}

void String::Reserve(size_t new_cap) {
  if (new_cap > cap_) {
    char* new_data = new char[new_cap];
    std::copy(data_, data_ + sz_, new_data);
    delete[] data_;
    cap_ = new_cap;
    data_ = new_data;
  }
}

void String::ShrinkToFit() {
  if (cap_ > sz_) {
    char* new_data = new char[sz_];
    std::copy(data_, data_ + sz_, new_data);
    delete[] data_;
    cap_ = sz_;
    data_ = new_data;
  }
}

void String::Swap(String& str) {
  std::swap(sz_, str.sz_);
  std::swap(cap_, str.cap_);
  std::swap(data_, str.data_);
}

char& String::operator[](size_t idx) { return data_[idx]; }

const char& String::operator[](size_t idx) const { return data_[idx]; }

char& String::Front() { return data_[0]; }
const char& String::Front() const { return data_[0]; }

char& String::Back() { return data_[sz_ - 1]; }
const char& String::Back() const { return data_[sz_ - 1]; }

bool String::Empty() const { return (sz_ == 0); }

size_t String::Size() const { return sz_; }

size_t String::Capacity() const { return cap_; }

char* String::Data() { return data_; }
char const* String::Data() const { return data_; }

bool operator<(String const& str1, String const& str2) {
  size_t sz1 = str1.Size();
  size_t sz2 = str2.Size();
  for (size_t i1 = 0, i2 = 0; i1 < sz1 && i2 < sz2; ++i1, ++i2) {
    if (str1[i1] < str2[i2]) {
      return true;
    }
    if (str1[i1] > str2[i2]) {
      return false;
    }
  }
  return sz1 < sz2;
}
bool operator>(String const& str1, String const& str2) { return str2 < str1; }
bool operator<=(String const& str1, String const& str2) {
  return !(str1 > str2);
}
bool operator>=(String const& str1, String const& str2) {
  return !(str1 < str2);
}
bool operator==(String const& str1, String const& str2) {
  size_t sz1 = str1.Size();
  size_t sz2 = str2.Size();
  for (size_t i1 = 0, i2 = 0; i1 < sz1 && i2 < sz2; ++i1, ++i2) {
    if (str1[i1] != str2[i2]) {
      return false;
    }
  }
  return sz1 != sz2;
}
bool operator!=(String const& str1, String const& str2) {
  return !(str1 == str2);
}

String& String::operator+=(String const& str) {
  size_t new_sz = sz_ + str.Size();
  if (new_sz > cap_) {
    Reserve(new_sz * 2);
  }
  for (size_t i = sz_; i < new_sz; ++i) {
    data_[i] = str[i];
  }
  sz_ = new_sz;
  return *this;
}

String operator+(String const& str1, String const& str2) {
  String copy = str1;
  copy += str2;
  return copy;
}

String& String::operator*=(size_t num) {
  Reserve(num * sz_);
  for (size_t i = 1; i < num; ++i) {
    std::copy(data_, data_ + sz_, data_ + i * sz_);
  }
  sz_ *= num;
  return *this;
}

std::ostream& operator<<(std::ostream& out, String const& str) {
  size_t size = str.Size();
  for (size_t i = 0; i < size; ++i) {
    out << str[i];
  }
  return out;
}

std::istream& operator>>(std::istream& inp, String& str) {
  std::istream::sentry snt(inp);
  if (snt) {
    str.Clear();

    std::streamsize wth = inp.width();
    if (wth == 0) {
      wth = std::numeric_limits<std::streamsize>::max();
    }
    char chr;
    while (inp.get(chr)) {
      str.PushBack(chr);

      --wth;
      bool space = std::isspace(inp.peek(), inp.getloc());
      if (wth == 0 || inp.peek() == EOF || space) {
        break;
      }
    }
  }

  inp.width(0);
  return inp;
}

std::vector<String> String::Split(String const& delim) const {
  size_t pos_start = 0;
  size_t pos_end;

  size_t delim_len = delim.Size();

  String token;
  std::vector<String> tmp;

  while ((pos_end = (*this).Find(delim, pos_start)) != String::kNpos) {
    token = (*this).Substr(pos_start, pos_end - pos_start);
    pos_start = pos_end + delim_len;
    tmp.push_back(token);
  }

  tmp.push_back((*this).Substr(pos_start));
  return tmp;
}

String String::Join(std::vector<String> const& strings) const {
  size_t v_size = strings.size();
  if (v_size == 0) {
    return String("");
  }
  size_t amount_len = 0;
  for (size_t i = 0; i < v_size; ++i) {
    amount_len += strings[i].Size();
  }
  String tmp;
  tmp.Reserve(amount_len + (v_size - 1) * sz_);
  for (size_t i = 0; i < v_size; ++i) {
    tmp += strings[i];
    if (i != v_size - 1) {
      tmp += *this;
    }
  }
  return tmp;
}

size_t String::Find(String const& str, size_t pos) const {
  size_t str_sz = str.Size();
  size_t start;
  size_t match;
  for (size_t i = pos; i < sz_ - 1; ++i) {
    start = i;
    match = 0;
    for (; match < str_sz && (i + match) < sz_ - 1; ++match) {
      if (data_[i + match] != str[match]) {
        break;
      }
    }
    if (match == str_sz) {
      return start;
    }
  }
  return (str_sz != 0 ? String::kNpos : 0);
}

String String::Substr(size_t pos, size_t count) const {
  if (count > sz_ - 1 - pos) {
    return String(data_ + pos);
  }
  char chr = data_[pos + count];
  data_[pos + count] = '\0';
  String copy(data_ + pos);
  data_[pos + count] = chr;
  return copy;
}
