#pragma once
#include<cmath>
enum PointType {
	FROM,
	TO,
};
class Point {
 public:
  int x;
  int y;
  PointType type;
  unsigned order_id;
  Point();
  Point(int x,int y);
  Point(int x, int y,PointType type,unsigned order_id);
  ~Point();
  static int GetDistant(const Point& from, const Point& to);
  static bool IsArrive(const Point& now, const Point& to);
  bool operator==(const Point& b) const;
  bool operator<(const Point& p) const;
  bool operator>(const Point& p) const;
};
