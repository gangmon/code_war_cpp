//
// Created by kemi on 2023/6/17.
//
#include <string>
#include <vector>
#include "direction_reduction.h"
#include <bandit/bandit.h> // Bandit testing framework
#include "igloo/igloo_alt.h"
#include "snowhouse/snowhouse.h" // Igloo for assertions

void testequal(std::vector<std::string> ans, std::vector<std::string> sol)
{
    AssertThat(ans, Equals(sol));
}
Describe(dirReduc_Tests)
{
        It(Fixed_Tests)
        {
            std::vector<std::string> d1 = {"NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST"};
            std::vector<std::string> ans1 = DirReduction::dirReduc(d1);
            std::vector<std::string> sol1 = {"WEST"};
            testequal(ans1, sol1);

            std::vector<std::string> d2 = {"NORTH","SOUTH","SOUTH","EAST","WEST","NORTH", "NORTH"};
            std::vector<std::string> ans2 = DirReduction::dirReduc(d2);
            std::vector<std::string> sol2 = {"NORTH"};
            testequal(ans2, sol2);
        }
};

