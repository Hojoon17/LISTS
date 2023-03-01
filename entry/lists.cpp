#include "List.h"
#include <iostream>

int main() {
  List<int> list;

    list.insertBack(1);
    list.insertBack(2);
    list.insertBack(3);
    list.insertBack(4);

    for (auto it = list.begin(); it != list.end(); it++){
      std::cout << *it << std::endl; 
    } 
    return 0;
}
