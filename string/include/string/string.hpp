#pragma once
// Copyright 2023 Vladislav Pakhomov

#include <istream>
#include <limits>
#include <vector>

class String {
 public:
  static size_t const kNpos = std::numeric_limits<size_t>::max();

  String() = default;

  String(size_t num, char chr);

  explicit String(char const* str);

  String(String const& str);
  String& operator=(String const& str);
  ~String();

  void Clear();

  void PushBack(char chr);

  void PopBack();

  void Resize(size_t new_sz);

  void Resize(size_t new_sz, char chr);

  void Reserve(size_t new_cap);

  void ShrinkToFit();

  void Swap(String& str);

  char& operator[](size_t idx);
  char const& operator[](size_t idx) const;

  char& Front();
  char const& Front() const;

  char& Back();
  char const& Back() const;

  bool Empty() const;

  size_t Size() const;

  size_t Capacity() const;

  char* Data();
  char const* Data() const;

  String& operator+=(String const& str);

  String& operator*=(size_t num);

  std::vector<String> Split(String const& delim = String(" ")) const;

  String Join(std::vector<String> const& strings) const;

  size_t Find(String const& str, size_t pos = 0) const;

  String Substr(size_t pos, size_t count = String::kNpos) const;

 private:
  size_t sz_ = 0;
  size_t cap_ = 0;
  char* data_ = nullptr;
};

bool operator<(String const& str1, String const& str2);
bool operator>(String const& str1, String const& str2);
bool operator<=(String const& str1, String const& str2);
bool operator>=(String const& str1, String const& str2);
bool operator==(String const& str1, String const& str2);
bool operator!=(String const& str1, String const& str2);

String operator+(String const& str1, String const& str2);

String operator*(String const& str, size_t n);

std::ostream& operator<<(std::ostream& out, String const& str);
std::istream& operator>>(std::istream& inp, String& str);
