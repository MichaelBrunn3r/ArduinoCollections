#define CATCH_CONFIG_MAIN
#include <catch2.hpp>
#include "../Dictionary.h"
#include <stdlib.h> 

void createRandStr(const size_t length, char* str) {
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    for(int i=0; i<length; i++) {
        str[i] = alphabet[rand() % 26];
    }
}

TEST_CASE("Creating empty Dictionary", "[dict]") {
    Dictionary<char, char> dict = Dictionary<char, char>();
    REQUIRE(dict.size() == 0);
    REQUIRE(dict.isEmpty());
    REQUIRE_FALSE(dict.isFull());
}

TEST_CASE("Put", "[dict]") {
    Dictionary<char, int> dict = Dictionary<char, int>(26);
    
    char str[] = "abcdefghijklmnopqrstuvwxyz";
    size_t entryc = strlen(str);

    REQUIRE(dict.size() == 0);
    for(int i=0; i<entryc; i++) {
        dict.put(str[i], i);
        REQUIRE(dict.size() == i+1);
        REQUIRE(dict.hasKey(str[i]));
        REQUIRE(*dict.get(str[i]) == i);
    }
    REQUIRE(dict.size() == entryc);

    char* keys = dict.keys();
    int* vals = dict.values();
    for(int i=0; i<entryc; i++) {
        REQUIRE(dict.hasKey(str[i]));
        REQUIRE(*(dict.get(str[i])) == i);
        REQUIRE(keys[i] == str[i]);
        REQUIRE(vals[i] == i);
    }
}

TEST_CASE("Put All", "[dict]") {
    Dictionary<char, unsigned long> dict = Dictionary<char, unsigned long>(1);

    char keys[] = "abcdefghijklmnopqrstuvwxyz";
    unsigned long values[] = {};
    for(int i=0; i<strlen(keys); i++) {
        values[i] == i;
    }

    dict.putAll(strlen(keys), keys, values, false);
    REQUIRE(dict.size() == strlen(keys));
    
}

