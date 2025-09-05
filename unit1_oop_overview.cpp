/* 
 unit1_oop_overview.cpp
 Demonstrates the difference between structured programming and a simple OOP approach.
 Compile: g++ -std=c++17 -Wall unit1_oop_overview.cpp -o unit1_oop_overview
 Run: ./unit1_oop_overview
*/

#include <iostream>
#include <string>

// Structured approach (C style)
int add_score_structured(int a, int b) {
    return a + b;
}

// Object Oriented approach
class Student {
public:
    std::string name;
    int score1;
    int score2;

    Student(const std::string& n = "", int s1 = 0, int s2 = 0) : name(n), score1(s1), score2(s2) {}

    int total_score() const { return score1 + score2; }

    void print() const {
        std::cout << "Student: " << name << ", score1=" << score1 << ", score2=" << score2
                  << ", total=" << total_score() << '\n';
    }
};

int main() {
    std::cout << "Structured: add_score_structured(45, 40) = "
              << add_score_structured(45, 40) << "\n";

    Student s("Asha", 45, 40);
    s.print();

    return 0;
}