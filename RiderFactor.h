#pragma once
#include <set>
#include<queue>
#include<climits>
#include<cmath>
#include<tuple>
#include<algorithm>
#include"Point.h"
#include "Order.h"
#include "Rider.h"


std::tuple<std::queue<Point>, int> cal_solution(const Rider &r,const Order &new_order,const int time);

static bool check(int S, int i, int received_num);
static void get_path(int end, int S, int **from, Point P[],
                     std::queue<Point> &path);
