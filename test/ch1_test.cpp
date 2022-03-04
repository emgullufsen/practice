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

struct ch1_fix2 : public ::testing::Test {
	std::vector<std::tuple<char *, char *>> test_data;
	char a[7] = {'E','V','A','N','N','E','\0'};
	char a_r[7] = {'E','N','N','A','V','E','\0'}; 
	ch1_fix2() {
		test_data.push_back(std::tuple<char *, char *>(a, a_r));
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

struct ch1_fix4 : public ::testing::Test {
	std::vector<std::tuple<std::tuple<std::string, std::string>, bool>> test_data; 
	ch1_fix4() {
		test_data.push_back(
			std::make_tuple(
				std::make_tuple("eric gullufsen", 
						"fsgu eienulrlc"),
				true));

	}
protected:
	void SetUp() override {}
	void TearDown() override {}
};

TEST_F(ch1_fix1, ch1_q1_unique_chars){
	EXPECT_EQ(practice::unique_chars(std::get<0>(test_data[0])),
		std::get<1>(test_data[0]));
}

TEST_F(ch1_fix2, ch1_q2_reverse_cstr){
	for (auto [dat, ret] : test_data){
		EXPECT_STREQ(practice::reverse_cstr(dat), ret);
	}
}

TEST_F(ch1_fix3, ch1_q3_remove_dups){
	for (auto [dat,ret] : test_data){
		EXPECT_EQ(practice::remove_dups(dat), ret);
	}
}

TEST_F(ch1_fix4, ch1_q4_anagrams){
	for (auto& [dat, ret] : test_data){
		EXPECT_EQ(practice::anagrams(std::get<0>(dat), std::get<1>(dat)), ret);
	}
}
