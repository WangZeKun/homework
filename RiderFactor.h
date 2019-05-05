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

static bool check(int S, int i, int received_num);
static void get_path(int end, int S, int from[20][1 << 20], Point P[],
                     std::queue<Point> &path);
