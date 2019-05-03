#pragma once
#include<vector>
#include<set>
#include"Point.h"
class Path {
 public:
  const Point start;
  const std::vector<Point> path;
	
  Path(const Point start,const std::vector<Point> path);
  ~Path();
  int dis();
  bool check();

 private:
  std::set<int> isSending;
  int __dis__;
};
