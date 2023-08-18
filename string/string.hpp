#include <algorithm>
#include <iostream>

class String {
private:
    size_t sz = 0;
    size_t cap = 0;
    char* str = nullptr;
public:
    String() = default; 
    
    String(size_t n, char c): sz(n), cap(sz), str(new char[cap]) {
        std::fill(str, str + sz, c);
    }

    String(char const* s): sz(strlen(s)), cap(sz), str(new char[cap]) {
        std::copy(s, s + sz, str);
    }

	String(const String& s): sz(s.sz), cap(s.cap), str(new char[cap]) {
	  std::copy(s.str, s.str + s.sz, str);
	}
	String& operator=(const String& s) {
	  String copy = s;
	  swap(copy);
	  return *this;
    }
    ~String() {
        delete[] str;
    }

    void Clear() {
        sz = 0;
    }
    
    void PopBack() {
        if (sz > 0) {
            --sz;
        }
    }

    void Resize(size_t new_sz) {
        if (new_sz > cap) {
            Reserve(new_sz);
        }
        sz = new_sz;
    }

    void Resize(size_t new_sz, char c) {
        size_t prev_sz = sz;
        Resize(new_sz);
        if (new_sz > prev_sz) {
            for (size_t i = prev_sz; i < new_sz; ++i) {
                str[i] = c;
            }
        }
    }

    void Reserve(size_t new_cap) {
        if (new_cap > cap) {
            char* new_str = new char[new_cap];
            std::copy(str, str + sz, new_str);
            delete[] str;
            cap = new_cap;
            str = new_str;
        }
    }

    void ShrinkToFit() {
        if (cap > size) {
            
        }
    }
    




    void swap(String& s) {
        std::swap(sz, s.sz);
        std::swap(cap, s.cap);
        std::swap(str, s.str);
    }

    char& operator[](size_t idx) {
        return str[idx];
    }

    const char& operator[](size_t idx) const{
        return str[idx];
   }

	size_t length() const {
	  return sz;
	}

    void push_back(char c) {
        if (sz == cap) {
            reserve(2 * cap);
        }
        str[sz] = c;
        ++sz;
    }

    void pop_back() {
        --sz;
    }
	char& front() {
	  return *str;
	}
	
	const char& front() const {
	  return *str;
	}
	
	char& back() {
	  return *(str + sz - 1);
	}
	
	const char& back() const {
	  return *(str + sz - 1);
	}
	
	bool empty() const{
	  return sz == 0;
	}
	
	void clear() {
	  sz = 0;
	  cap = 0;
	  delete[] str;
	}

};

bool operator==(const String& s1, const String& s2) {
    if (s1.length() != s2.length()) {
        return false;
    }
    int n = s1.length();
    for (int i = 0; i < n; ++i) {
        if (s1[i] != s2[i]) {
            return false;
        } 
    }
    return true;
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

