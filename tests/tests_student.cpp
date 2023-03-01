#include <catch2/catch_test_macros.hpp>
#include "tests_helper.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

#include "List.h"

using namespace cs225;

// You may write your own test cases in this file to test your code.
// Test cases in this file are not graded.

TEST_CASE("My Test Case", "[student]") {
    List<int> list;
    for (int i = 1; i <= 13; i++)
        list.insertBack(i);
    list.waterfall();
    stringstream s;
    list.print(s);
    REQUIRE("< 1 3 5 7 9 11 13 4 8 12 6 2 10 >" == s.str());
}

TEST_CASE("ReverseCustom", "[student]") {
    List<int> list;
    for (int i = 1; i <= 5; i++)
        list.insertBack(i);
    list.reverse();
    stringstream s;
    list.print(s);
    REQUIRE("< 5 4 3 2 1 >" == s.str());
}

TEST_CASE("ReverseCustom2", "[student]") {
    List<int> list;
    for (int i = 1; i <= 6; i++)
        list.insertBack(i);
    list.reverseNth(2);
    stringstream s;
    list.print(s);
    REQUIRE("< 2 1 4 3 6 5 >" == s.str());
}

