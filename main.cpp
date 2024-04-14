#include <iostream>
#include "header/vowel_count.h"
#include "header/duplicate_encoder.h"
#include "header/convert_string_to_camel_case.h"
#include "header/calc.h"
#include "header/direction_reduction.h"
#include <cassert>
#include "header/common_denominators.h"
#include "header/counting_deplicates.h"
#include "header/which_are_in.h"
#include <string>
#include "header/parse_int_reload.h"

using namespace std;

int main() {
//    std::string input = "one thousand three hundred and thirty-seven";
//    int res = parse_int(input);
//    cout << res << endl;

//    std::vector<std::string> arr1 = { "arp", "live", "strong" };
//    std::vector<std::string> arr2 = { "lively", "alive", "harp", "sharp", "armstrong" };

//    std::vector<std::string> arr1 = {"arp", "mice", "bull"};
//    std::vector<std::string> arr2 = {"lively","alive","harp","sharp","armstrong"};

    std::vector<std::string> arr1 = {"cod","code","wars","ewar","pillow","bed","phht"};
    std::vector<std::string> arr2 = {"lively","alive","harp","sharp","armstrong","codewars"};
    auto output = WhichAreIn::inArray(arr1, arr2);
    for (const auto &str : output){
        cout << str << ",";
    }
    return 0;


//    char* input = "abcde";
//    size_t res = duplicateCount(input);
//    assert(res == 0);
//
//    char* input2 = "aAbbcde";
//    size_t res2 = duplicateCount(input2);
//    assert(res2 == 2);
//
//    return 0;
//
//    std::vector<std::vector<unsigned long long>> r1 = { {1, 2}, {1, 3}, {1, 4} };
//    std::string ans1 = Fracts::convertFrac(r1);
//    std::string sol1 = "(6,12)(4,12)(3,12)";
//    assert(ans1 == sol1);
//
//    std::vector<std::vector<unsigned long long>> r2 = {{69,130}, {87,1310}, {3,4}};
//    std::string ans2 = Fracts::convertFrac(r2);
//    std::string sol2 = "(18078,34060)(2262,34060)(25545,34060)";
////            "(1703,221390)(169,221390)(55347,221390)"
//    assert(ans2 == sol2);
//    return 0;
//
////    std::cout << "Hello, World!" << std::endl;
////    cout << getCount("dede") << endl;
////    cout << duplicate_encoder("Success") << endl;
////    cout << to_camel_case("the_stealth_warrior") << endl;
////    cout << to_camel_case("The-Stealth-Warrior") << endl;
////    cout << to_camel_case("The-Pippi_Is_evil") << endl;
////    cout << to_camel_case("A_Cat-Is-cute") << endl;
//
//
////    cout << calc("1 + 1") << endl;
////    cout << calc("8/16") << endl;
////    cout << calc("3 -(-1)") << endl;
////    cout << calc("5 + 4 * 2)") << endl;
//
////    Assert::That(calc("1 + 1"), Equals(2));
////    Assert::That(calc("8/16"), Equals(0.5));
////    Assert::That(calc("3 -(-1)"), Equals(4));
////    Assert::That(calc("2 + -2"), Equals(0));
////    Assert::That(calc("10- 2- -5"), Equals(13));
////    Assert::That(calc("(((10)))"), Equals(10));
////    Assert::That(calc("3 * 5"), Equals(15));
////    Assert::That(calc("-7 * -(6 / 3)"), Equals(14));
////    std::vector<std::string> d1 = {"NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST"};
////    std::vector<std::string> ans1 = DirReduction::dirReduc(d1);
////    std::vector<std::string> sol1 = {"WEST"};
////    for (const auto &str : ans1){
////        cout << str << ",";
////    }
////    assert(ans1 == sol1);
////
////
////    cout << "endl" << endl;
////    std::vector<std::string> d2 = {"NORTH","SOUTH","SOUTH","EAST","WEST","NORTH", "NORTH"};
////    std::vector<std::string> ans2 = DirReduction::dirReduc(d2);
////    std::vector<std::string> sol2 = {"NORTH"};
////    for (const auto &str : ans2){
////        cout << str << ",";
////    }
////    assert(ans2 == sol2);
////
////    cout << "endl" << endl;
////    std::vector<std::string> d3 = {"SOUTH", "EAST", "EAST", "EAST", "EAST", "NORTH", "WEST", "SOUTH", "SOUTH", "EAST" };
////    std::vector<std::string> ans3 = DirReduction::dirReduc(d3);
////    std::vector<std::string> sol3 = {"SOUTH", "EAST", "EAST", "EAST", "EAST", "NORTH", "WEST", "SOUTH", "SOUTH", "EAST" };
////    for (const auto &str : ans3){
////        cout << str << ",";
////    }
////    assert(ans3 == sol3);
////    cout << "endl" << endl;
////    std::vector<std::string> d4 = { "NORTH", "WEST", "SOUTH", "EAST" };
////    std::vector<std::string> ans4 = DirReduction::dirReduc(d4);
////    std::vector<std::string> sol4 = {"NORTH", "WEST", "SOUTH", "EAST"};
////    for (const auto &str : ans4){
////        cout << str << ",";
////    }
////    assert(ans4 == sol4);

    return 0;
}