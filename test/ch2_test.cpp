/*
* Chapter 2 Tests
*/

#include <ch2.hpp>
#include <gtest/gtest.h>
#include <vector>
#include <iostream>

#define NUM_NODES 4

using namespace ll;

// Test Fixture for remove_dups
struct ch2_fix1 : public ::testing::Test {
	int intz = 789;
	ll::LList<int> *test_data;
	LList<int> *td2;
	LLNode<int> *tdn0 = new LLNode<int>(2);
	LLNode<int> *tdn1 = new LLNode<int>(1);
	LLNode<int> *tdn2 = new LLNode<int>(3);
	LList<int> *td3;
	LLNode<int> *tdn30 = new LLNode<int>(5);
	LLNode<int> *tdn31 = new LLNode<int>(9);
	LLNode<int> *tdn32 = new LLNode<int>(4);
	ll::LLNode<int> *i0 = new LLNode<int>(20);
	ll::LLNode<int> *i1 = new LLNode<int>(21);
	ll::LLNode<int> *i2 = new LLNode<int>(22);
	std::vector<int> test_compare = { 0, 1, 2, 3, 4 };
	ch2_fix1() {
        	LLNode<int> *a0 = new LLNode<int>(0);
		LLNode<int> *a1 = new LLNode<int>(1);
		LLNode<int> *a2 = new LLNode<int>(2);
		LLNode<int> *a3 = new LLNode<int>(3);
		LLNode<int> *a4 = new LLNode<int>(3);
		LLNode<int> *a5 = new LLNode<int>(4);
		LLNode<int> *a6 = new LLNode<int>(4);
		LLNode<int> *a7 = new LLNode<int>(1);
		LLNode<int> *a8 = new LLNode<int>(2);
		test_data = new LList<int>;
		td2 = new LList<int>;
		td2->insert_node(tdn2);
		td2->insert_node(tdn1);
		td2->insert_node(tdn0);
		td3 = new LList<int>;
		td3->insert_node(tdn32);
		td3->insert_node(tdn31);
		td3->insert_node(tdn30);
		test_data->insert_node(a0);
		test_data->insert_node(a1);
		test_data->insert_node(a2);
		test_data->insert_node(a3);
		test_data->insert_node(a4);
		test_data->insert_node(a5);
		test_data->insert_node(a6);
		test_data->insert_node(a7);
		test_data->insert_node(a8);
	}
protected:
	void SetUp() override {}
	void TearDown() override {}
};

struct ch2_fix2 : public ::testing::Test {
	ll::LList<int> test_data;
	ll::LLNode<int> *i0 = new LLNode<int>(20);
	ll::LLNode<int> *i1 = new LLNode<int>(21);
	ll::LLNode<int> *i2 = new LLNode<int>(22);
	std::vector<int> test_compare = { 0, 1, 2, 3, 4 };
	ch2_fix2() {
        	LLNode<int> *a0 = new LLNode<int>(0);
		LLNode<int> *a1 = new LLNode<int>(1);
		LLNode<int> *a2 = new LLNode<int>(223);
		LLNode<int> *a3 = new LLNode<int>(3);
		LLNode<int> *a4 = new LLNode<int>(3);
		LLNode<int> *a5 = new LLNode<int>(4);
		LLNode<int> *a6 = new LLNode<int>(4);
		LLNode<int> *a7 = new LLNode<int>(1);
		LLNode<int> *a8 = new LLNode<int>(2);
		test_data.insert_node(a0);
		test_data.insert_node(a1);
		test_data.insert_node(a2);
		test_data.insert_node(a3);
		test_data.insert_node(a4);
		test_data.insert_node(a5);
		test_data.insert_node(a6);
		test_data.insert_node(a7);
		test_data.insert_node(a8);
	}
protected:
	void SetUp() override {}
	void TearDown() override {}
};

struct ch2_fix3 : public ::testing::Test {
	LLNode<int> *nodes_td[NUM_NODES];
	LLNode<int> *nodes_tdc[NUM_NODES];
	LList<int> *test_data;
	LList<int> *test_data_compare;
	ch2_fix3() {
			test_data = new LList<int>();
			test_data_compare = new LList<int>();
			size_t sn = sizeof(nodes_td) / sizeof(typeof(nodes_td[0]));
			printf("sn = %ld\n", sn);
			for (int c = 0; c < sn; c++){
				nodes_td[c] = new LLNode<int>(c);
				nodes_tdc[c] = new LLNode<int>(c);
				test_data->insert_node(nodes_td[c]);
				if (c != 2){
					std::cout << "INSERTING and c = " << c << "\n";
					test_data_compare->insert_node(nodes_tdc[c]);
				}
			}

	}
protected:
	void SetUp() override {}
	void TearDown() override {}
};

TEST_F(ch2_fix1, ch2_q1_remove_dups){
	test_data->remove_dups();
	int counter = 0;
	LLNode<int> *n = test_data->head;
	while ((counter < test_compare.size()) && (n != nullptr)) {
		EXPECT_EQ(n->data, test_compare[counter]);
		++counter;
		n = n->next;
	}
	
}

TEST_F(ch2_fix1, ch2_q2_test_length_prop){
	EXPECT_EQ(test_data->length(), 9);
	test_data->insert_node(i0);
	EXPECT_EQ(test_data->length(), 10);
	test_data->insert_node(i1);
	EXPECT_EQ(test_data->length(), 11);
	test_data->insert_node(i2);
	EXPECT_EQ(test_data->length(), 12);
	test_data->delete_node(i0);
	EXPECT_EQ(test_data->length(), 11);
	test_data->delete_node(i1);
	EXPECT_EQ(test_data->length(), 10);
	test_data->delete_node(i2);
	EXPECT_EQ(test_data->length(), 9);
}

TEST_F(ch2_fix3, ch2_q3_test_remove_from_list){
	std::cout << "test_data:\n";
	test_data->print_nodes();
	std::cout << "test_data_compare:\n";
	test_data_compare->print_nodes();
	bool a = (*test_data == *test_data_compare);
	EXPECT_EQ(a, false);
	nodes_td[2]->remove_from_list();
	std::cout << "test_data:\n";
	test_data->print_nodes();
	std::cout << "test_data_compare:\n";
	printf("glagla = %d\n", (*test_data == *test_data_compare));
	test_data_compare->print_nodes();
	bool z = (*test_data == *test_data_compare);
	EXPECT_EQ(z, true);
}

TEST_F(ch2_fix1, ch2_q4_convertToNum){
	EXPECT_EQ(practice::convertToNum(td2), 213);
}
TEST_F(ch2_fix1, ch2_q4_convertToLList){
	EXPECT_EQ(practice::convertToNum(practice::convertToLList(213)), 213);
}
TEST_F(ch2_fix1, ch2_q4_addLListNums){
	EXPECT_EQ(practice::convertToNum(practice::addLListNums(td2,td3)), 807);
}

TEST_F(ch2_fix2, ch2_q2_test_index_operator){
	EXPECT_EQ(test_data[2].data, 223);			
}

TEST_F(ch2_fix2, ch2_q2_nth_last){
	std::cout << "HEYO\n";
	EXPECT_EQ(test_data.nth_last(6).data, 223);			
}
