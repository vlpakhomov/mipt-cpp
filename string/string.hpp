#include <cstring>
#include <locale>
#include <limits>
#include <istream>
#include <vector>
#include <iostream>

class String {
private:
    size_t sz = 0;
    size_t cap = 0;
    char* data = nullptr;
public:
    String() = default; 

    String(size_t n, char c);

    String(char const* new_data);

	String(String const& s);
	String& operator=(String const& s);
    ~String();

    void Clear();

    void PushBack(char c);

    void PopBack();

    void Resize(size_t new_sz);

    void Resize(size_t new_sz, char c);

    void Reserve(size_t new_cap);

    void ShrinkToFit();
    
    void Swap(String& s);

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

    String& operator+=(String const& s);

    String& operator*=(size_t n); 

    std::vector<String> Split(const String& delim = " ") const;
    
    String Join(const std::vector<String>& strings) const;

    size_t Find(String const& s, size_t pos = 0) const;

    String String::Substr(size_t pos, size_t count = std::string::npos) const;
};

bool operator<(String const& s1, String const& s2);
bool operator>(String const& s1, String const& s2);
bool operator<=(String const& s1, String const& s2);
bool operator>=(String const& s1, String const& s2);
bool operator==(String const& s1, String const& s2);
bool operator!=(String const& s1, String const& s2);

String operator+(String const& s1, String const& s2);

std::ostream& operator<<(std::ostream& out, String const& s);
std::istream& operator>>(std::istream& in, String& s);
