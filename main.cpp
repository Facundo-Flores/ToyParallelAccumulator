#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <chrono>
#include <random>
#include "ParallelAccumulate.cpp"

int main()
{
    // Create a vector with large number of elements
    std::vector<int> numbers(100000000);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);

    // Filling the numbers vector with random numbers
    std::generate(numbers.begin(), numbers.end(), [&]() { return dis(gen); });

    // Standard accumulate
    auto start = std::chrono::high_resolution_clock::now();
    auto standard_sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout << "Standard accumulate took " << duration.count() << " milliseconds.\n";

    // Parallel accumulate
    start = std::chrono::high_resolution_clock::now();
    auto parallel_sum = parallel_accumulate(numbers.begin(), numbers.end(), 0);
    stop = std::chrono::high_resolution_clock::now();

    duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout << "Parallel accumulate took " << duration.count() << " milliseconds.\n";

    // Compare the results of both accumulate and parallel_accumulate methods
    if(standard_sum == parallel_sum){
        std::cout << "The results are equal." << "\n";
    } else {
        std::cout << "The results are not equal." << "\n";
    }

    return 0;
}
