#include "point.h"

Point::Point() : x(-1), y(-1), type(FROM), order_id(-1) {}

Point::Point(int x, int y) : x(x), y(y), type(FROM), order_id(-1) {}

Point::Point(int x, int y, PointType type, unsigned order_id)
    : x(x), y(y), type(type), order_id(order_id) {}

Point::~Point() {}

int Point::GetDistant(const Point& from, const Point& to) {
  return abs(from.x - to.x) + abs(from.y - to.y);
}

bool Point::IsArrive(const Point& now, const Point& to) {
  int x = abs(now.x - to.x), y = abs(now.y - to.y);
  return (x == 1 && y == 0) || (x == 0 && y == 1);
}

Point Point::Move(const Point& position, const Point& destination) {
  int x = destination.x - position.x;
  int y = destination.y - position.y;
  Point p = position;
  if (x == 0) {
    p.x += position.x == 16 ? -1 : 1;
    p.y += y > 0 ? 1 : -1;
  } else if (y == 0) {
    p.y += position.y == 16 ? -1 : 1;
    p.x += x > 0 ? 1 : -1;
  } else if (abs(x) > 2 && x % 2 == 0) {
    p.x += abs(x) / x * 2;
  } else if (abs(y) > 2 && y % 2 == 0) {
    p.y += abs(y) / y * 2;
  } else if (position.x == 1 && x < 0 || position.x == 15 && x > 0) {
    p.y += abs(y) / y * 2;
  } else if (position.y == 1 && y < 0 || position.y == 15 && y > 0) {
    p.x += abs(x) / x * 2;
  } else {
    p.x += abs(x) / x;
    p.y += abs(y) / y;
  }
  return p;
}

bool Point::operator==(const Point& p) const { return x == p.x && y == p.y; }

bool Point::operator<(const Point& p) const { return x + y < p.x + p.y; }

bool Point::operator>(const Point& p) const { return p.x + p.y < x + y; }
