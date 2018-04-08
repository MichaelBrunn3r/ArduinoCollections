#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iostream>

const char alphabet_a2z[] = "abcdefghijklmnopqrstuvwxyz";
const char alphabet_A2Z[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char alphabet_a2Z[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char alphabet_digit[] = "0123456789";

template <typename T_ARR>
void fisherYatesShuffle(size_t length, T_ARR arr[]) {
    srand(std::time(NULL));
    for(int i=0; i<length-2; i++) {
        int k = i + (rand() % (length-i));
        T_ARR tmp = arr[i];
        arr[i] = arr[k];
        arr[k] = tmp;
    }
}
void randStr(const size_t len, char str[], const size_t lenAlphabet, const char alphabet[], const bool uniqueChars) {
    if(uniqueChars) {
        char randAlphabet[lenAlphabet] = {};
        std::memcpy(randAlphabet, alphabet, sizeof(char) * lenAlphabet);

        fisherYatesShuffle(lenAlphabet, randAlphabet);
    
        std::memcpy(str, randAlphabet, sizeof(char) * len);
    } else {
        for(int i=0; i<len; i++) {
            str[i] = alphabet[rand() % lenAlphabet];
        }
    }
}

void randNums(const size_t len, int nums[], int min, int max) {
    for(int i=0; i<len; i++) {
        nums[i] = min + (rand() % (max-min));
    }
}


template <typename T_ARR>
void printArray(size_t len, T_ARR arr[], const char prefix[], const char seperator[], const char suffix[]) {
    std::cout << prefix;
    for(int i=0; i<len; i++) {
        std::cout << arr[i];
        if(i<len-1) std::cout << seperator;
    }
    std::cout << suffix;
}