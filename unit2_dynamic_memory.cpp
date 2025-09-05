/* 
 unit2_dynamic_memory.cpp
 Demonstrates dynamic memory allocation with new/delete and basic error check.
 Compile: g++ -std=c++17 -Wall unit2_dynamic_memory.cpp -o unit2_dynamic_memory
 Run: ./unit2_dynamic_memory
*/

#include <iostream>

int main() {
    std::cout << "Allocating array of 5 ints on heap\n";
    int *arr = new int[5]; // dynamic allocation
    for (int i = 0; i < 5; ++i) arr[i] = (i + 1) * 10;
    for (int i = 0; i < 5; ++i) std::cout << "arr[" << i << "] = " << arr[i] << '\n';
    delete[] arr; // free memory

    // single object
    double *pd = new double(3.14);
    std::cout << "Allocated double with value " << *pd << '\n';
    delete pd;

    return 0;
}