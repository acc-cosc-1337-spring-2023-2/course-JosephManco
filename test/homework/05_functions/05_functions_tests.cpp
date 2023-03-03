#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "func.h"
TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify get dna complement")
{
	string dna1 = "AAAACCCGGT";
	string dna2 = "CCCGGAAAAT";
	REQUIRE(get_dna_complement(dna1) == "ACCGGGTTTT");
	REQUIRE(get_dna_complement(dna2) == "ATTTTCCGGG");
}

TEST_CASE("Verify get_reverse_string")
{
	REQUIRE(reverse_string("AGCTATAG") == "GATATCGA");
	REQUIRE(reverse_string("CGCTATAG") == "GATATCGC");
}

TEST_CASE("Verify GC_content")
{
	string dna1 = "AGCTATAG";
	string dna2 = "CGCTATAG";
	REQUIRE(get_gc_content(dna1) == .375);
	REQUIRE(get_gc_content(dna2) == .50);
}