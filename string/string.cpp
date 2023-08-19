#include <algorithm>
#include <iostream>


String::String(size_t n, char c): sz(n), cap(sz), data(new char[cap]) {
    std::fill(data, data + sz, c);
}

String::String(char const* s): sz(strlen(s)), cap(sz), data(new char[cap]) {
    std::copy(s, s + sz, data);
}

String::String(const String& s): sz(s.sz), cap(s.cap), data(new char[cap]) {
	std::copy(s.data, s.data + s.sz, data);
}
String::String& operator=(const String& s) {
	String copy = s;
	swap(copy);
	return *this;
}
String::~String() {
    delete[] data;
}

void String::Clear() {
    sz = 0;
}
void String::PushBack(char c) {
    if (sz == cap) {
        Reserve(sz * 2);
    }
    data[sz] = c;
    ++sz;
} 

void String::PopBack() {
    if (sz > 0) {
        --sz;
    }
}

void String::Resize(size_t new_sz) {
    if (new_sz > cap) {
        Reserve(new_sz);
    }
    sz = new_sz;
}

void String::Resize(size_t new_sz, char c) {
    size_t prev_sz = sz;
    Resize(new_sz);
    if (new_sz > prev_sz) {
        for (size_t i = prev_sz; i < new_sz; ++i) {
            data[i] = c;
        }
    }
}

void String::Reserve(size_t new_cap) {
    if (new_cap > cap) {
        char* new_data = new char[new_cap];
        std::copy(data, data + sz, new_data);
        delete[] data;
        cap = new_cap;
        data = new_data;
    }
}

void String::ShrinkToFit() {
    if (cap > sz) {
        char* new_data = new char[sz];
        std::copy(data, data + sz, new_data);
        delete[] data;
        cap = sz; 
        data = new_data;
    }
}

void String::Swap(String& s) {
    std::swap(sz, s.sz);
    std::swap(cap, s.cap);
    std::swap(data, s.data);
}

char& operator[](size_t idx) {
    return data[idx];
}

const char& operator[](size_t idx) const{
    return data[idx];
}

char& Front() {
  return data[0];
}
const char& Front() const {
  return data[0];
}

char& Back() 
  return data[sz - 1];
}
const char& Back() const {
  return data[sz - 1];
}

bool String::Empty() const {
    return (sz == 0);
}

size_t String::Size() const {
    return sz;
}

size_t String::Capacity() const {
    return cap;
}

char* String::Data() {
    return data;
}
char const* String::Data() const {
    return data;
}

bool operator<(const String& s1, const String& s2) {
    size_t sz1 = s1.Size();
    size_t sz2 = s2.Size();
    for (int i1 = 0, i2 = 0; i1 < sz1 && i2 < sz2; ++i1, ++i2) {
        if (s1[i1] < s2[i2]) {
            return true;
        } else if (s1[i1] > s2[i2]) {
            return false;
        }
    }
    return sz1 < sz2;
}
bool operator>(const String& s1, const String& s2) {
    return s2 < s1;
}
bool operator<=(const String& s1, const String& s2) {
    return !(s1 > s2)    
}
bool operator>=(const String& s1, const String& s2) {
    return !(s1 < s2);
}
bool operator==(const String& s1, const String& s2) {
    size_t sz1 = s1.Size();
    size_t sz2 = s2.Size();
    for (int i1 = 0, i2 = 0; i1 < sz1 && i2 < sz2; ++i1, ++i2) {
        if (s1[i1] != s2[i2]) {
            return false;
        }
    }
    return sz1 != sz2;
}
bool operator!=(const String& s1, const String& s2) {
    return !(s1 == s2);
}

String& String::operator+=(const String& s) {
    size_t new_sz = sz + s.Size();
    if (new_sz > cap) {
        Reserve(new_sz * 2);
    }
    for (int i = sz; i < new_sz; ++i) {
        data[i] = s[i];
    }
    sz = new_sz;
}

String operator+(const String& s1, const String& s2) {
    String copy = s1;
    copy += s2;
    return copy;
}

std::ostream& operator<<(std::ostream& out, const String& s) {
    size_t sz = s.length();
    for (size_t i = 0; i < sz; ++i) {
        out << s;
    }
    return out;
}

std::istream& operator>>(std::istream& in, String& s) {

}

