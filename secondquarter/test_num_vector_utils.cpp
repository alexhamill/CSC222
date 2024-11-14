#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <string>
#include <vector>
#include "num_vector_utils.h"
using namespace std;

TEST_CASE("Testing render_num_vector") {
    vector<int> nums = {1, 3, 7};
    string numstr = render_num_vector(nums);
    string expected = "1 3 7";
    CHECK(numstr == expected);
}
TEST_CASE("Testing multipul_render_num_vector") {
    vector<int> nums = {1, 3, 7, 4, 5, 6};
    string numstr = render_num_vector(nums);
    string expected = "1 3 7 4 5 6";
    CHECK(numstr == expected);
}
TEST_CASE("Testing no_render_num_vector") {
    vector<int> nums = {};
    string numstr = render_num_vector(nums);
    string expected = "";
    CHECK(numstr == expected);
}