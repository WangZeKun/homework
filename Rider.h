#include <cstdio>
#include <iostream>
#include <vector>
#include "Order.h"

#ifndef RIDER_H
#define RIDER_H
enum Way {
  UP,
  DOWN,
  LEFT,
  RIGHT,
};

class Rider {
 public:
  Rider();
  ~Rider();

  std::vector<Order> outdate_orders;
  std::vector<Order> finished_orders;
  std::vector<Order> recived_orders;
  std::vector<Order> sending_orders;
  std::vector<std::pair<unsigned int, unsigned int>> path;

  void step();
  void add_orders(Order r);
  std::pair<unsigned int, unsigned int> get_position();

 private:
  std::pair<unsigned int, unsigned int> position;
};
#endif  // !RIDER_H
