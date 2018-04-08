#define CATCH_CONFIG_RUNNER
#include <catch2.hpp>
#include <string.h>
#define ConstASCIIMap_TEST
#include "../ConstASCIIMap.h"
#include "./testUtils.h"

ConstASCIIMap<int>* createDict(size_t entryc, char str[], int nums[]) {
    return new ConstASCIIMap<int>(entryc, str, nums);
}

TEST_CASE("Create Dict") { 
    SECTION("per constructor") {
        SECTION("without duplicates") {
            char str[] = "abcdefghjklmnopqrstuvwxyz";
            int nums[strlen(str)] = {};  
            for(int i=0; i<strlen(str); i++) {
                nums[i] = i;
            }
            ConstASCIIMap<int> dict = ConstASCIIMap<int>(strlen(str), str, nums);

            REQUIRE(dict.size() == strlen(str));
            for(int i=0; i<strlen(str); i++) {
                REQUIRE(dict.keys()[i] == str[i]);
                REQUIRE(dict.values()[i] == nums[i]);
                REQUIRE(*dict.get(dict.keys()[i]) == nums[i]);
                REQUIRE(dict.hasKey(str[i]));
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
            ConstASCIIMap<int> dict = ConstASCIIMap<int>(strlen(str), str, nums);

            REQUIRE(dict.size() == strlen(strSorted));
            for(int i=0; i<strlen(strSorted); i++) {
                REQUIRE(dict.keys()[i] == strSorted[i]);
                REQUIRE(dict.values()[i] == numsSorted[i]);
                REQUIRE(*dict.get(dict.keys()[i]) == numsSorted[i]);
                REQUIRE(dict.hasKey(strSorted[i]));
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
            ConstASCIIMap<int>* dict = createDict(strlen(str), str, nums);

            REQUIRE(dict->size() == strlen(str));
            for(int i=0; i<strlen(str); i++) {
                REQUIRE(dict->keys()[i] == str[i]);
                REQUIRE(dict->values()[i] == nums[i]);
                REQUIRE(*dict->get(dict->keys()[i]) == nums[i]);
                REQUIRE(dict->hasKey(str[i]));
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
            ConstASCIIMap<int>* dict = createDict(strlen(str), str, nums);

            REQUIRE(dict->size() == strlen(strSorted));
            for(int i=0; i<strlen(strSorted); i++) {
                REQUIRE(dict->keys()[i] == strSorted[i]);
                REQUIRE(dict->values()[i] == numsSorted[i]);
                REQUIRE(*dict->get(dict->keys()[i]) == numsSorted[i]);
                REQUIRE(dict->hasKey(strSorted[i]));
            }
            delete dict;
        }
        
    }
}

TEST_CASE("Method hasKey") {
    SECTION("with all possible chars") {
        byte length = 128;
        char str[length] = {};
        for(int i=0; i<length; i++) {
            str[i] = (char)i;
        }

        int nums[length] = {};
        for(int i=0; i<length; i++) {
            nums[i] = i;
        }
        ConstASCIIMap<int> dict = ConstASCIIMap<int>(length, str, nums);
    }
}

TEST_CASE("Method Update") {
    size_t entryc = 26;
    char str[entryc] = {};
    int nums[entryc] = {};
    randStr(entryc, str, strlen(alphabet_a2z), alphabet_a2z, true);
    randNums(entryc, nums, 1000, 10000);

    ConstASCIIMap<int> dict = ConstASCIIMap<int>(entryc, str, nums);
    REQUIRE(dict.size() == entryc);

    for(int i=0; i<dict.size(); i++) {
        int newVal = rand() % 1000;
        REQUIRE(dict.hasKey(str[i]));
        dict.update(str[i], newVal);
        REQUIRE(*dict.get(str[i]) == newVal);
    }
}

int main(int argc, char* argv[]) {
    std::cout << "ConstASCIIMap size: " << sizeof(ConstASCIIMap<int>) << std::endl;
    int result = Catch::Session().run( argc, argv );
    return result;
}