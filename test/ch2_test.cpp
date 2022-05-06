/*
* Chapter 1 Tests
*/

#include <ch2_ll.hpp>
#include <gtest/gtest.h>
#include <vector>

using namespace ll;

// Test Fixture for remove_dups
struct ch2_fix1 : public ::testing::Test {
	ll::LList<int> *test_data;
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

TEST_F(ch2_fix1, ch2_q1_remove_dups){
    int counter = 0;
    LLNode<int> *n = test_data->head;
    while ((counter < test_compare.size()) && (n != nullptr)) {
        EXPECT_EQ(n->data, test_compare[counter]);
        ++counter;
        n = n->next;
    }
	
}