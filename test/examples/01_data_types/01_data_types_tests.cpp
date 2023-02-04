#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "int.h"//c++ will find my echo_variable function code
#include "decimals.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

/*test case echo_variable */
TEST_CASE("Test Echo variable", "validation") {
	REQUIRE(echo_variable(5) == 5);//test case 1
	REQUIRE(echo_variable(10) == 10);//test case 2
	REQUIRE(echo_variable(100) == 100);//test case 3
	REQUIRE(echo_variable(1000) == 1000);// test case 4 
}
/*test case add_to_double_1 with 0 as parameter*/

/*test case add_to_double_1 with 1 as parameter*/

/*test case add_to_double_2 with 0 as parameter*/

/*test case add_to_double_2 with 1 as parameter*/

/*test case char test ASCII values */

/*test case string test ASCII values Joe characters are equal to 74, 111, and 101*/

