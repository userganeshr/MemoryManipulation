#include "../src/MemoryManipulation.hpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("memcpy For C array with src and dest at same size"){
    int src[5]{1,2,3,4,5};
    int dest[5]{6,7,8,9,0};
    vTitan::memCopy(dest,src);
    REQUIRE(dest[0] == 1);
    REQUIRE_FALSE(dest[0] == 6);
}

TEST_CASE("memcpy For std c++ array"){
    std::array<int,5> src{1,2,3,4,5};
    std::array<int,5> dest{6,7,8,9,0};
    vTitan::memCopy(dest,src);
    REQUIRE(dest[0] == 1);
    REQUIRE_FALSE(dest[0] == 6);
}

// TEST_CASE("memcpy For std c++ array"){
//     std::array<int,6> src{1,2,3,4,5,7};
//     std::array<int,5> dest{6,7,8,9,0};
//     vTitan::memCopy(dest,src);
//     REQUIRE(dest[0] == 1);
//     REQUIRE_FALSE(dest[0] == 6);
// }

struct Temp
{
    int x[2];
};
struct Temp1
{
    int y[2];
};

TEST_CASE("memcpy For structure"){
    Temp a;
    Temp1 b;
    a.x[0] = 5;
    a.x[1] = 10;
    vTitan::memCopy(b,a);
    REQUIRE(b.y[0] == 5);
    REQUIRE_FALSE(b.y[0] != 5);
}