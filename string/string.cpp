#include "string.hpp"


String::String(size_t n, char c): sz(n), cap(sz), data(new char[cap]) {
    std::fill(data, data + sz, c);
}

String::String(char const* s): sz(strlen(s)), cap(sz), data(new char[cap]) {
    std::copy(s, s + sz, data);
}

String::String(String const& s): sz(s.sz), cap(s.cap), data(new char[cap]) {
	std::copy(s.data, s.data + s.sz, data);
}
String& String::operator=(String const& s) {
	String copy = s;
	Swap(copy);
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

char& String::operator[](size_t idx) {
    return data[idx];
}

const char& String::operator[](size_t idx) const{
    return data[idx];
}

char& String::Front() {
  return data[0];
}
const char& String::Front() const {
  return data[0];
}

char& String::Back() {
  return data[sz - 1];
}
const char& String::Back() const {
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

bool operator<(String const& s1, String const& s2) {
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
bool operator>(String const& s1, String const& s2) {
    return s2 < s1;
}
bool operator<=(String const& s1, String const& s2) {
    return !(s1 > s2);
}
bool operator>=(String const& s1, String const& s2) {
    return !(s1 < s2);
}
bool operator==(String const& s1, String const& s2) {
    size_t sz1 = s1.Size();
    size_t sz2 = s2.Size();
    for (int i1 = 0, i2 = 0; i1 < sz1 && i2 < sz2; ++i1, ++i2) {
        if (s1[i1] != s2[i2]) {
            return false;
        }
    }
    return sz1 != sz2;
}
bool operator!=(String const& s1, String const& s2) {
    return !(s1 == s2);
}

String& String::operator+=(String const& s) {
    size_t new_sz = sz + s.Size();
    if (new_sz > cap) {
        Reserve(new_sz * 2);
    }
    for (int i = sz; i < new_sz; ++i) {
        data[i] = s[i];
    }
    sz = new_sz;
    return *this;
}

String operator+(String const& s1, String const& s2) {
    String copy = s1;
    copy += s2;
    return copy;
}

String& String::operator*=(size_t n) {
    Reserve(n * sz);
    for (size_t i = 1; i < n; ++i) {
        std::copy(data, data + sz, data + i * sz);
    }
    sz *= n;
    return *this;
    
}

std::ostream& operator<<(std::ostream& out, String const& s) {
    size_t sz = s.Size();
    for (size_t i = 0; i < sz; ++i) {
        out << s;
    }
    return out;
}

std::istream& operator>>(std::istream& in, String& s) {
    std::istream::sentry snt(in); 
    if (snt) {
        s.Clear();

        std::streamsize n = in.width();
        if (n == 0) n = std::numeric_limits<std::streamsize>::max() ;

        char c;
        while (in.get(c)) 
        {
            s.PushBack(c);

            if (--n == 0) break;
            if (in.peek() == std::istream::traits_type::eof()) break; 
            if (std::isspace(in.peek(), in.getloc())) break; 
        }
    }

    in.width(0); 
    return in;  
}

std::vector<String> String::Split(String const& delim) const {
    size_t pos_start = 0, pos_end, delim_len = delim.Size();
    String token;
    std::vector<String> tmp;

    while ((pos_end = (*this).Find(delim, pos_start)) != std::string::npos) {
        token = (*this).Substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        tmp.push_back(token);
    }

    tmp.push_back((*this).Substr(pos_start));
    return tmp;
}
    
String String::Join(const std::vector<String>& strings) const {
    size_t n = strings.size();
    if (n == 0) return String("");
    size_t len = 0;
    for (size_t i = 0; i < n; ++i) {
        len += strings[i].Size();
    }
    String tmp;
    tmp.Reserve(len + (n - 1) * sz);
    for (size_t i = 0; i < n; ++i) {
        tmp += strings[i];
        if (i != n - 1) {
            tmp += *this;
        }
    }
    return tmp;
}

size_t String::Find(const String& s, size_t pos) const {
  size_t start;
  size_t j;
  for (size_t i = pos; i < sz - 1; ++i) {
    start = i;
    j = 0;
      for (; j < s.Size() && (i + j) < sz - 1; ++j) {
        if (data[i + j] != s[j]) break;
      }
      if (j == s.Size()) return start;
  }
  return (s.Size() ? std::string::npos : 0);
}

String String::Substr(size_t pos, size_t count) const {
  if (count > sz - 1 - pos) return String(data + pos);
  char c = data[pos + count];
  data[pos + count] = '\0';
  String copy(data + pos);
  data[pos + count] = c;
  return copy;
}

