#pragma once
#include <cstdio>
#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
#include "Order.h"
#include "Point.h"
#include "Path.h"

class Rider {
 public:
  Rider(Point position);
  ~Rider();

  std::set<Order> outdate_orders;
  std::set<Order> finished_orders;
  std::set<Order> received_orders;
  std::set<Order> sending_orders;

  int all_cost;

  void step(unsigned time);
  void add_order(Order r);
  void change_path(std::queue<Point> path, int all_cost);
  Point get_position();

 private:
  std::queue<Point> path;
  Point position;
};

