#include "Point.h"

Point::Point() : x(-1), y(-1), type(FROM), order_id(0) {}

Point::Point(int x, int y, PointType type, unsigned order_id)
    : x(x), y(y), type(type), order_id(order_id) {}

Point::~Point() {}

int Point::get_dis(const Point& from, const Point& to) {
  return abs(from.x - to.x) + abs(from.y - to.y);
}

bool Point::is_arrive(const Point& now, const Point& to) {
  int x = abs(now.x - to.x), y = abs(now.y - to.y);
  return (x == 1 && y == 0) || (x == 0 & y == 1);
}

bool Point::operator==(const Point& p) const { return x == p.x && y == p.y; }

bool Point::operator<(const Point& p) const { return x + y < p.x + p.y; }

bool Point::operator>(const Point& p) const { return p.x + p.y < x + y; }
