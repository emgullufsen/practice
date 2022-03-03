/*
* Chapter 1 Tests
*/

#include <ch1.hpp>
#include <gtest/gtest.h>
#include <vector>

// Test Fixture for unique_chars

struct ch1_q1 : public ::testing::Test {
	std::vector<std::tuple<std::string, bool>> test_data = 
		{ 
		  { "eric gullufsen", false },
		  { "abcdefghijklmnopqrstuvwxyz", true }
		};
protected:
	void SetUp() override {}
	void TearDown() override {}
};

TEST_F(ch1_q1, ch1_q1_unique_chars){
	EXPECT_EQ(practice::unique_chars(std::get<0>(test_data[0])),
		std::get<1>(test_data[0]));
}
