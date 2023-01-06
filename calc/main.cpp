#include <iostream>
#include <typeinfo>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <cmath>
int main (int argc, char* argv[])
{
    if (argc == 1) {
        std::cout << "Parametrs:\n aver - среднее арифметическое\n med  - медиана\n" << std::endl;
        return 0;
    }
    bool hasOption;
    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "-o") == 0) {
            hasOption = true;
        }
    }
    if (!hasOption) {
        std::cout << "there's no option '-o'" << std::endl;
        return 0;
    }
    if (hasOption and strcmp(argv[1], "-o") != 0) {
        std::cout << "option has to be the first argument" << std::endl;
        return 0;
    }
    if (argc < 10) {
        std::cout << "not enough arguments";
        return 0;
    }
    if (argc > 12) {
        std::cout << "too many arguments";
        return 0;
    }
    if (strcmp(argv[2], "aver") == 0) {
        for (int i = 4; i < argc; i++) {
            try {
                std::stof(argv[i]);
            } catch(std::invalid_argument& e) {
                std::cout << "can only receive numbers";
                return 0;
            }
        }
        float res = std::stof(argv[3]);
        int k = 1;
        for (int i = 4; i < argc; i++) {
            res = res + std::stof(argv[i]);
            k += 1;
        }
        res = res / k;
        std::cout << res << std::endl;
    } 
    
    else if (strcmp(argv[2], "med") == 0) {
        for (int i = 4; i < argc; i++) {
            float num;
            try {
                num = std::stof(argv[i]);
            } catch(std::invalid_argument& e) {
                std::cout << "can only receive numbers";
                return 0;
            }
        }
        std::vector<float> arr(argc-3);
        for (int i = 0; i < argc-3; i++) {
            arr[i] = std::stof(argv[i+3]);
        }
        std::sort(arr.begin(), arr.end());
        float res = std::stof(argv[3]);
        if (argc-3 == 9 or argc-3 == 7) {
            int k = ceil((argc-3) / 2);
            res = arr[k];
        }
        else if (argc-3 == 8) {
            int k = ((argc-3) / 2);
            res = (arr[k-1]+arr[k]) / 2;
        }
        std::cout << res << std::endl;
    } else {
        std::cout << "wrong option" << std::endl;
        return 0;
    }
    return 0;
}
