#define CATCH_CONFIG_RUNNER
#include <catch2.hpp>
#include <iostream>
#include <string.h>
#define CharDictionary_TEST
#include "../MinCharDictionary.h"

MinCharDictionary<int>* createDict(size_t entryc, char str[], int nums[]) {
    return new MinCharDictionary<int>(entryc, str, nums);
}

TEST_CASE("Create Dict") { 
    SECTION("per constructor") {
        SECTION("without duplicates") {
            char str[] = "abcdefghjklmnopqrstuvwxyz";
            int nums[strlen(str)] = {};  
            for(int i=0; i<strlen(str); i++) {
                nums[i] = i;
            }
            MinCharDictionary<int> dict = MinCharDictionary<int>(strlen(str), str, nums);

            REQUIRE(dict.mSize == strlen(str));
            for(int i=0; i<strlen(str); i++) {
                REQUIRE(dict.mKeys[i] == str[i]);
                REQUIRE(dict.mValues[i] == nums[i]);
            }
        }
        SECTION("with duplicates") {
            char strSorted[] = "abcdefghijklmnopqrstuvwxyz";
            char str[] = "vstpomistnqtuikrabmyxcidbgefnvwgvhmahzoyqvzxjklmknpowiwzqpza";
            int nums[strlen(str)] = {};  
            for(int i=0; i<strlen(str); i++) {
                nums[i] = i;
            }
            int numsSorted[strlen(strSorted)] = {};
            for(int i=0; i<strlen(strSorted); i++) {
                for(int k=0; k<strlen(str); k++) {
                    if(strSorted[i] == str[k]) numsSorted[i] = nums[k]; 
                }
            }
            MinCharDictionary<int> dict = MinCharDictionary<int>(strlen(str), str, nums);

            REQUIRE(dict.mSize == strlen(strSorted));
            for(int i=0; i<strlen(strSorted); i++) {
                REQUIRE(dict.mKeys[i] == strSorted[i]);
                REQUIRE(dict.mValues[i] == numsSorted[i]);
            }
        }
    }

    SECTION("in another Method") {
        SECTION("without duplicates") {
            char str[] = "abcdefghjklmnopqrstuvwxyz";
            int nums[strlen(str)] = {};  
            for(int i=0; i<strlen(str); i++) {
                nums[i] = i;
            }
            MinCharDictionary<int>* dict = createDict(strlen(str), str, nums);

            REQUIRE(dict->mSize == strlen(str));
            for(int i=0; i<strlen(str); i++) {
                REQUIRE(dict->mKeys[i] == str[i]);
                REQUIRE(dict->mValues[i] == nums[i]);
            }
            delete dict;
        }

        SECTION("with duplicates") {
            char strSorted[] = "abcdefghijklmnopqrstuvwxyz";
            char str[] = "vstpomistnqtuikrabmyxcidbgefnvwgvhmahzoyqvzxjklmknpowiwzqpza";
            int nums[strlen(str)] = {};  
            for(int i=0; i<strlen(str); i++) {
                nums[i] = i;
            }
            int numsSorted[strlen(strSorted)] = {};
            for(int i=0; i<strlen(strSorted); i++) {
                for(int k=0; k<strlen(str); k++) {
                    if(strSorted[i] == str[k]) numsSorted[i] = nums[k]; 
                }
            }
            MinCharDictionary<int>* dict = createDict(strlen(str), str, nums);

            REQUIRE(dict->mSize == strlen(strSorted));
            for(int i=0; i<strlen(strSorted); i++) {
                REQUIRE(dict->mKeys[i] == strSorted[i]);
                REQUIRE(dict->mValues[i] == numsSorted[i]);
            }
            delete dict;
        }
        
    }
}

TEST_CASE("Method hasKey") {
    char str[] = "abcdefghjklmnop";
    int nums[strlen(str)] = {};
    for(int i=0; i<strlen(str); i++) {
        nums[i] = i;
    }
    MinCharDictionary<int> dict = MinCharDictionary<int>(strlen(str), str, nums);
    REQUIRE(dict.mSize == strlen(str));

    for(int i=0; i<strlen(str); i++) {
        REQUIRE(dict.hasKey(str[i]));
    }
}

int main(int argc, char* argv[]) {
    int result = Catch::Session().run( argc, argv );
    return result;
}