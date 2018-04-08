#define CATCH_CONFIG_RUNNER
#include <catch2.hpp>
#include <iostream>
#include <string.h>
#define CharDictionary_TEST
#include "../MinCharDictionary.h"

int main(int argc, char* argv[]) {
    int result = Catch::Session().run( argc, argv );
    return result;
}

MinCharDictionary<int>* createDict(size_t entryc, char str[], int nums[]) {
    return new MinCharDictionary<int>(entryc, str, nums);
}

TEST_CASE("Create Dict") {
    char str[] = "abcdefghjklmnop";
    int nums[strlen(str)] = {};
    for(int i=0; i<strlen(str); i++) {
        nums[i] = i;
    }
    
    SECTION("with constructor") {
        MinCharDictionary<int> dict = MinCharDictionary<int>(strlen(str), str, nums);
        REQUIRE(dict.mSize == strlen(str));
        for(int i=0; i<strlen(str); i++) {
            REQUIRE(dict.mKeys[i] == str[i]);
            REQUIRE(dict.mValues[i] == nums[i]);
        }
    }

    SECTION("in another Method") {
        MinCharDictionary<int>* dict = createDict(strlen(str), str, nums);
        REQUIRE(dict->mSize == strlen(str));
        for(int i=0; i<strlen(str); i++) {
            REQUIRE(dict->mKeys[i] == str[i]);
            REQUIRE(dict->mValues[i] == nums[i]);
        }
        delete dict;
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