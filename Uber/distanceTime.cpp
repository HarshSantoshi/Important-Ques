#include <iostream>
#include <vector>
#include <algorithm>

std::pair<int, int> find_distance_time(std::vector<int>& values) {
    std::sort(values.begin(), values.end());

    do {
        int uSpeed = values[0];
        int uAlpha = values[1];
        int uBeta = values[2];
        int uDelta = values[3];
        
        for (int distance = 1; distance <= 100000; ++distance) {
            int time_1 = uAlpha - distance;
            int time_2 = distance - uDelta;
            
            if (time_1 > 0 && distance / time_1 == uSpeed && distance * time_1 == uBeta) {
                return {distance, time_1};
            }
            if (time_2 > 0 && distance / time_2 == uSpeed && distance * time_2 == uBeta) {
                return {distance, time_2};
            }
        }
    } while (std::next_permutation(values.begin(), values.end()));

    return {-1, -1};
}

int main() {
    int t;
    std::cin >> t;
    std::vector<std::pair<int, int>> results;

    for (int i = 0; i < t; ++i) {
        std::vector<int> test_case(4);
        for (int j = 0; j < 4; ++j) {
            std::cin >> test_case[j];
        }
        
        auto result = find_distance_time(test_case);
        results.push_back(result);
    }
}