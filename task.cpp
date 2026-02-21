//
// Created by Lenovo on 21.02.2026.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include "random"
#include "limits"

int main (int argc, char**argv) {

    const int X = 10;
    const int Y = 10;

    auto Print = [](const std::vector<int>& elems, const std::string& containerName) {
        std::cout << containerName + " : ";
        for (const auto& val : elems)
            std::cout << val << " ";
        std::cout << "\n";
    };

    auto Fill = [](std::vector<int>& elems) -> void {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_int_distribution<> dist(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());

        for (auto& val : elems)
            val = dist(gen);
    };

    std::vector<int> x (X, 0),
                     y (Y, 0);

    Fill(x);
    Fill(y);

    std::sort(x.begin(), x.end());
    std::sort(y.begin(), y.end());

    Print(x, "X");
    Print(y, "Y");

    int maxValue = *std::max_element(y.begin(),y.end());
    int minValue = *std::min_element(x.begin(), x.end());

    std::cout << "MaxValue in Y = " << maxValue << "; MinValue in X = " << minValue << std::endl;

    std::vector<int> z;

    std::copy_if(y.begin(),y.end(), std::back_inserter(z), [minValue](int val){return val < minValue;});
    std::copy_if(x.begin(),x.end(), std::back_inserter(z), [maxValue](int val){return val > maxValue;});

    Print(z, "Z");

    return 0;
}