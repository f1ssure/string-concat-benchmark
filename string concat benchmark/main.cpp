//
//  main.cpp
//  string concat benchmark
//
//  Created by Gabrielius Bakas on 02/05/2025.
//

#include <iostream>
#include <string>
#include <chrono>

int main() {
    std::string short_str = "a";
    std::string long_str(1000000, 'b');
    
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 10000; ++i) {
        std::string str = long_str;
        str += short_str;
    }
    auto mid = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 10000; ++i) {
        std::string str = short_str;
        str += long_str;
    }
    auto end = std::chrono::high_resolution_clock::now();
    
    std::cout << "long += short: " << std::chrono::duration<double>(mid - start) << "\n";
    std::cout << "short += long: " << std::chrono::duration<double>(end - mid) << "\n";
        
    return 0;
}
