/*
* Chapter 1 Tests
*/

#include <ch1.hpp>
#include <gtest/gtest.h>
#include <vector>

// Test Fixture for unique_chars

struct ch1_fix1 : public ::testing::Test {
	std::vector<std::tuple<std::string, bool>> test_data;
	ch1_fix1() {
		test_data = 
		{ 
		  { "eric gullufsen", false },
		  { "abcdefghijklmnopqrstuvwxyz", true }
		};
	}
protected:
	void SetUp() override {}
	void TearDown() override {}
};

struct ch1_fix3 : public ::testing::Test {
	std::vector<std::tuple<std::string, std::string>> test_data; 
	ch1_fix3() {
		test_data = 
		{ 
		  { "eric gullufsen", "eric gulfsn" },
		  { "abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyz"
		  },
		  {"",""}
		};
	}
protected:
	void SetUp() override {}
	void TearDown() override {}
};

TEST_F(ch1_fix1, ch1_q1_unique_chars){
	EXPECT_EQ(practice::unique_chars(std::get<0>(test_data[0])),
		std::get<1>(test_data[0]));
}

TEST_F(ch1_fix3, ch1_q3_remove_dups){
	for (auto [dat,ret] : test_data){
		EXPECT_EQ(practice::remove_dups(dat), ret);
	}
}
