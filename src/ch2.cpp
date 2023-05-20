#include <ch2.hpp>
#include <iostream>
#include <math.h>
namespace practice {
int convertToNum(LList<int> *list) {
  int s = list->length(), c = 0, r = 0;
  while (s - c > 0) {
    r += (*list)[c].data * pow(10, c);
    ++c;
  }
  return r;
}
LList<int> *convertToLList(int ins) {
  LList<int> *ret = new LList<int>();
  int tmp;
  while (ins) {
    tmp = ins % 10;
    ret->insert_node(new LLNode<int>(tmp));
    ins /= 10;
  }
  return ret;
}
LList<int> *addLListNums(LList<int> *list1, LList<int> *list2) {
  return convertToLList(convertToNum(list1) + convertToNum(list2));
}
} // namespace practice
