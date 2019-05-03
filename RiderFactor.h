#pragma once
#include <set>
#include<queue>
#include<climits>
#include<cmath>
#include<algorithm>
#include"Point.h"
#include "Order.h"
#include "Rider.h"


struct Solution {
  std::queue<Point> path;
  int all_cost;
};

Solution cal_solution(Point start, Order new_order,std::set<Order> received_order,
                      std::set<Order> sending_order);

static inline bool check(int S, int i);

