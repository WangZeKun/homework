#include "Rider.h"

Rider::Rider(Point position) : position(position) {}

Rider::~Rider() { std::cout << "delete Rider"; }

void Rider::step() {
  auto next = path.front();
  int x = position.x - next.y;
  int y = position.x - next.y;
  if (!x) x = 1;
  if (!y) y = 1;
  position.x += x / abs(x);
  position.y += y / abs(y);
  if (Point::is_arrive(position, next)) {
    path.pop();
    auto tmp1 = sending_orders.find(Order(next.order_id));
    finished_orders.insert(*tmp1);
    sending_orders.erase(tmp1);
    auto tmp2 = sending_orders.find(Order(next.order_id));
    sending_orders.insert(*tmp2);
    recived_orders.erase(tmp2);
  }
}

void Rider::add_order(Order r) {}

void Rider::change_path(std::queue<Point> path, int all_cost) {}

Point Rider::get_position() { return position; }
