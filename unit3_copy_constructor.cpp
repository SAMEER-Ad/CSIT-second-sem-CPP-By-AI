/* 
 unit3_copy_constructor.cpp
 Demonstrates default, user-defined copy constructor and when it's used.
 Compile: g++ -std=c++17 -Wall unit3_copy_constructor.cpp -o unit3_copy_constructor
 Run: ./unit3_copy_constructor
*/

#include <iostream>
#include <cstring>

class MyString {
private:
    char* data;
public:
    MyString(const char* s = "") {
        data = new char[std::strlen(s) + 1];
        std::strcpy(data, s);
        std::cout << "Constructed: " << data << '\n';
    }
    // user-defined copy constructor (deep copy)
    MyString(const MyString& other) {
        data = new char[std::strlen(other.data) + 1];
        std::strcpy(data, other.data);
        std::cout << "Copy constructed: " << data << '\n';
    }
    ~MyString() {
        std::cout << "Destructing: " << data << '\n';
        delete[] data;
    }
    const char* c_str() const { return data; }
};

MyString make_string() {
    MyString tmp("temp");
    return tmp; // will invoke copy/move semantics
}

int main() {
    MyString a("Hello");
    MyString b = a; // copy constructor
    MyString c = make_string(); // copy/move
    std::cout << "a: " << a.c_str() << ", b: " << b.c_str() << ", c: " << c.c_str() << '\n';
    return 0;
}