/* 
 unit5_inheritance.cpp
 Demonstrates base/derived classes, access specifiers, multiple types of inheritance example,
 constructors/destructors order, and aggregation.
 Compile: g++ -std=c++17 -Wall unit5_inheritance.cpp -o unit5_inheritance
 Run: ./unit5_inheritance
*/

#include <iostream>
#include <string>

// Base class
class Person {
protected:
    std::string name;
public:
    Person(const std::string& n = "Unknown") : name(n) { std::cout << "Person constructor\n"; }
    virtual ~Person() { std::cout << "Person destructor\n"; }
    void speak() const { std::cout << "Hi, I'm " << name << '\n'; }
};

// Derived class (public inheritance)
class Student : public Person {
    int roll;
public:
    Student(const std::string& n, int r): Person(n), roll(r) { std::cout << "Student constructor\n"; }
    ~Student() { std::cout << "Student destructor\n"; }
    void info() const { std::cout << "Student: " << name << ", roll=" << roll << '\n'; }
};

// Aggregation: Department has Student pointer (does not own)
class Department {
    std::string deptName;
public:
    Department(const std::string& d): deptName(d) {}
    void show(Student* s) const {
        std::cout << "Department: " << deptName << '\n';
        if (s) s->info();
    }
};

int main() {
    {
        Student s("Rahul", 101);
        s.speak();
        s.info();
        Department d("Computer Science");
        d.show(&s); // aggregation example
    } // destructors will be called in reverse order
    return 0;
}