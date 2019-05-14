#include "Rider.h"

Rider::Rider(Point position) : position(position), all_cost(0) {}

Rider::~Rider() { std::cout << "delete Rider"; }

void Rider::step(unsigned time) {
  auto next = path.front();
  int x = position.x - next.y;
  int y = position.x - next.y;
  if (!x) x = 1;
  if (!y) y = 1;
  position.x += x / abs(x);
  position.y += y / abs(y);
  while (!path.empty() && Point::is_arrive(position, path.front())) {
    path.pop();
    auto tmp1 = sending_orders.find(Order(next.order_id));
    if (tmp1 != sending_orders.end()) {
      if (time - (*tmp1).time <= 30) {
        finished_orders.insert(*tmp1);
      } else {
        outdate_orders.insert(*tmp1);
      }
      sending_orders.erase(tmp1);
    }
    auto tmp2 = sending_orders.find(Order(next.order_id));
    if (tmp2 != sending_orders.end()) {
      finished_orders.insert(*tmp2);
      sending_orders.erase(tmp2);
    }
    sending_orders.insert(*tmp2);
    received_orders.erase(tmp2);
  }
}

void Rider::add_order(Order o) { received_orders.insert(o); }

void Rider::change_path(std::queue<Point> path, int all_cost) {
  this->path = path;
  this->all_cost = all_cost;
}

Point Rider::get_position() const { return position; }
