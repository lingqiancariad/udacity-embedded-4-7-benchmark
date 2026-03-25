#include <iostream>
#include <vector>
#include <chrono>

int main() {
    // 1. Setup: Create a massive array of 100 million items
    const int size = 100'000'000;
    std::vector<int> data(size, 1);
    long long sum = 0;

    /*-----------------normal process---------------------*/
    std::cout << "Starting benchmark normal process..." << std::endl;

    // 2. Start the clock
    auto start_time = std::chrono::high_resolution_clock::now();

    // 3. The "Hot" Loop
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }

    // 4. Stop the clock
    auto end_time = std::chrono::high_resolution_clock::now();

    // 5. Calculate the duration in milliseconds
    std::chrono::duration<double, std::milli> elapsed = end_time - start_time;

    // 6. Print the results
    std::cout << "Execution Time: " << elapsed.count() << " ms\n";
    
    // We MUST print 'sum' or the compiler will optimize the entire loop away!
    std::cout << "Total Sum: " << sum << "\n"; 
    
    /*-----------------optimized process----------------------*/
    std::cout << "Starting benchmark optimized process..." << std::endl;
    
    sum = 0;
    // 2. Start the clock
    start_time = std::chrono::high_resolution_clock::now();

    // 3. The "Hot" Loop optimized with pragma
    #pragma GCC unroll 4 
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }

    // 4. Stop the clock
    end_time = std::chrono::high_resolution_clock::now();

    // 5. Calculate the duration in milliseconds
    elapsed = end_time - start_time;

    // 6. Print the results
    std::cout << "Execution Time: " << elapsed.count() << " ms\n";
    
    // We MUST print 'sum' or the compiler will optimize the entire loop away!
    std::cout << "Total Sum: " << sum << "\n"; 

    return 0;
}