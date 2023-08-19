#include <algorithm>
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

	String(const String& s);
	String& operator=(const String& s);
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
