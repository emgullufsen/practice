/*
* Chapter 1 Tests
*/

#include <ch1.hpp>
#include <gtest/gtest.h>
#include <vector>
#include <cstddef>

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

struct ch1_fix5 : public ::testing::Test {
	std::vector<std::tuple<std::string, std::string>> test_data; 
	std::string s2{"r%20r%20r%20r%20"};
	ch1_fix5() {
		test_data.push_back(
			std::make_tuple("e r","e%20r"));
		test_data.push_back(std::make_tuple(
			"r r r r ", s2));

	}
protected:
	void SetUp() override {}
	void TearDown() override {}
};

struct ch1_fix6 : public ::testing::Test {
	std::byte test_data[2][2][4] = { 
		 { { std::byte{0x00}, 
		     std::byte{0x01}, 
		     std::byte{0x03}, 
		     std::byte{0x04} }, 
		   { std::byte{0x05}, 
		     std::byte{0x06}, 
		     std::byte{0x07}, 
		     std::byte{0x08} } },
		 { { std::byte{0x09}, 
		     std::byte{0x0A}, 
		     std::byte{0x0B}, 
		     std::byte{0x0C} }, { 
		     std::byte{0x0D}, 
		     std::byte{0x0E}, 
		     std::byte{0x0F}, 
		     std::byte{0x10} } }
	};
	std::byte test_data_r[2][2][4] = {
		 { { std::byte{0x09}, 
		     std::byte{0x0A}, 
		     std::byte{0x0B}, 
		     std::byte{0x0C} }, { 
		     std::byte{0x00}, 
		     std::byte{0x01}, 
		     std::byte{0x03}, 
		     std::byte{0x04} } },
		 { { std::byte{0x0D}, 
		     std::byte{0x0E}, 
		     std::byte{0x0F}, 
		     std::byte{0x10} }, { 
		     std::byte{0x05}, 
		     std::byte{0x06}, 
		     std::byte{0x07}, 
		     std::byte{0x08} } }
	};
	ch1_fix6() {

	}
protected:
	void SetUp() override {}
	void TearDown() override {}
};

struct ch1_fix7 : public ::testing::Test {
	practice::matrix test_data = { {1,0,1,1}, 
						 {1,1,1,1}, 
						 {1,1,1,0}, 
						 {1,1,1,1} };
	practice::matrix test_data_c = { {0,0,0,0}, 
						   {1,0,1,0}, 
						   {0,0,0,0}, 
						   {1,0,1,0} };
	ch1_fix7() {
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

TEST_F(ch1_fix5, ch1_q5_replace_spaces){
	for (auto& [dat, ret] : test_data){
		EXPECT_EQ(practice::replace_spaces(dat), ret);
	}
}

TEST_F(ch1_fix6, ch1_q6_rotate_90){
	practice::rotate_90(test_data);
	for (int i = 0; i < 2; ++i){
		for (int j = 0; j < 2; ++j){
			for (int u = 0; u < 4; ++u){
				EXPECT_EQ(test_data[i][j][u],
				test_data_r[i][j][u]);
			}
		}
	}
}

TEST_F(ch1_fix7, ch1_fix7_row_col_zero){
	practice::row_col_zero(test_data);
	for (int i; i < test_data.size(); ++i){
		for (int j; j < test_data[i].size(); ++j){
			EXPECT_EQ(test_data[i][j], test_data_c[i][j]);
		}
	}
	
}