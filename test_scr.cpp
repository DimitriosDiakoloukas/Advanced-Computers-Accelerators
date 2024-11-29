#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <cstdint>

#define lm 4
#define ln 4
#define lp 4
#define m (1 << lm)
#define n (1 << ln)
#define p (1 << lp)

#define DATA_SIZE m  

int main() {
    std::vector<std::vector<uint32_t>> source_in1(DATA_SIZE, std::vector<uint32_t>(DATA_SIZE));  
    std::vector<std::vector<uint32_t>> source_in2(DATA_SIZE, std::vector<uint32_t>(DATA_SIZE));           
    std::vector<std::vector<uint32_t>> source_hw_results(DATA_SIZE, std::vector<uint32_t>(DATA_SIZE, 0));  
    std::vector<std::vector<uint32_t>> source_sw_results(DATA_SIZE, std::vector<uint32_t>(DATA_SIZE, 0));  

    auto rand_gen = []() { return rand() % 256; };

    for (auto& row : source_in1) {
        std::generate(row.begin(), row.end(), rand_gen);
    }
    for (auto& row : source_in2) {
        std::generate(row.begin(), row.end(), rand_gen);
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            uint32_t sum = 0;
            for (int k = 0; k < n; k++) {
                sum += source_in1[i][k] * source_in2[k][j];
            }
            source_sw_results[i][j] = sum;
        }
    }

    std::cout << "Source SW Results: " << std::endl;
    for (const auto& row : source_sw_results) {
        for (const auto& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
