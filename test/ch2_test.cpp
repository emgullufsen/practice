/*
 * Chapter 2 Tests
 */

#include <ch2.hpp>
#include <gtest/gtest.h>
#include <iostream>
#include <vector>

#define NUM_NODES 4

using namespace ll;

// Test Fixture for remove_dups
struct ch2_fix1 : public ::testing::Test {
  LList<int> *test_data, *td2, *td3;

  LLNode<int> *i0 = new LLNode<int>(20);
  LLNode<int> *i1 = new LLNode<int>(21);
  LLNode<int> *i2 = new LLNode<int>(22);

  std::vector<int> test_compare = {0, 1, 2, 3, 4};

  ch2_fix1() {
    int test_data_arr[9] = {0, 1, 2, 3, 3, 4, 4, 1, 2};
    test_data =
        new LList<int>(test_data_arr, sizeof(test_data_arr) / sizeof(int));

    int td2_arr[3] = {3, 1, 2};
    td2 = new LList<int>(td2_arr, sizeof(td2_arr) / sizeof(int));

    int td3_arr[3] = {4, 9, 5};
    td3 = new LList<int>(td3_arr, sizeof(td3_arr) / sizeof(int));
  }

protected:
  void SetUp() override {}
  void TearDown() override {}
};

struct ch2_fix2 : public ::testing::Test {
  ll::LList<int> test_data;

  ch2_fix2() {
    int arr[9] = {0, 1, 223, 3, 3, 4, 4, 1, 2};
    for (const auto &s : arr) {
      LLNode<int> *a = new LLNode<int>(s);
      test_data.insert_node(a);
    }
  }

protected:
  void SetUp() override {}
  void TearDown() override {}
};

struct ch2_fix3 : public ::testing::Test {
  LLNode<int> *nodes_td[NUM_NODES];
  LLNode<int> *nodes_tdc[NUM_NODES];
  LLNode<int> *nodes_big[NUM_NODES + 1];
  LList<int> *test_data;
  LList<int> *test_data_compare;
  LList<int> *test_data_big;
  ch2_fix3() {
    test_data = new LList<int>();
    test_data_compare = new LList<int>();
    test_data_big = new LList<int>();
    size_t sn = sizeof(nodes_td) / sizeof(typeof(nodes_td[0]));
    for (int c = 0; c < sn; c++) {
      nodes_td[c] = new LLNode<int>(c);
      nodes_tdc[c] = new LLNode<int>(c);
      test_data->insert_node(nodes_td[c]);
      if (c != 2) {
        test_data_compare->insert_node(nodes_tdc[c]);
      }
    }

    for (int d = 0; d < (NUM_NODES + 1); d++) {
      nodes_big[d] = new LLNode<int>(d);
      test_data_big->insert_node(nodes_big[d]);
    }
  }

protected:
  void SetUp() override {}
  void TearDown() override {}
};

TEST_F(ch2_fix1, ch2_q1_remove_dups) {
  test_data->remove_dups();
  int counter = 0;
  LLNode<int> *n = test_data->head;
  while ((counter < test_compare.size()) && (n != nullptr)) {
    EXPECT_EQ(n->data, test_compare[counter]);
    ++counter;
    n = n->next;
  }
}

TEST_F(ch2_fix1, ch2_q2_test_length_prop) {
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

TEST_F(ch2_fix1, ch2_q4_convertToNum) {
  EXPECT_EQ(practice::convertToNum(td2), 213);
}
TEST_F(ch2_fix1, ch2_q4_convertToLList) {
  EXPECT_EQ(practice::convertToNum(practice::convertToLList(213)), 213);
}
TEST_F(ch2_fix1, ch2_q4_addLListNums) {
  EXPECT_EQ(practice::convertToNum(practice::addLListNums(td2, td3)), 807);
}

TEST_F(ch2_fix2, ch2_q2_test_index_operator) {
  EXPECT_EQ(test_data[2].data, 223);
  EXPECT_THROW(test_data[200], std::out_of_range);
}

TEST_F(ch2_fix2, ch2_q2_nth_last) {
  EXPECT_EQ(test_data.nth_last(6).data, 223);
  EXPECT_THROW(test_data.nth_last(200), std::out_of_range);
}

TEST_F(ch2_fix3, ch2_q3_test_remove_from_list) {
  bool a = (*test_data == *test_data_compare);
  EXPECT_EQ(a, false);
  bool b = (*test_data == *test_data_big);
  EXPECT_EQ(b, false);
  nodes_td[2]->remove_from_list();
  bool z = (*test_data == *test_data_compare);
  EXPECT_EQ(z, true);
}

TEST_F(ch2_fix3, ch2_llist_iterator) {
  // testing iterator
  std::cout << "*****PRINTING USING ITERATOR*****" << std::endl;
  for (auto i : *test_data) {
    std::cout << std::to_string(i.data) << std::endl;
  }
}
