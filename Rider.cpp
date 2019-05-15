#include "Rider.h"

Rider::Rider(Point position) : position(position), all_cost(0) {}

Rider::~Rider() {}

void Rider::step(unsigned time) {
  if (path.empty()) {
    return;
  }

  auto next = path.front();
  int x = next.x - position.x;
  int y = next.y - position.y;
  if (x == 0 && y > 0) {
    position.x += position.x == 16 ? -1 : 1;
    position.y += y > 0 ? 1 : -1;
  } else if (y == 0 && x > 0) {
    position.y += position.y == 16 ? -1 : 1;
    position.x += x > 0 ? 1 : -1;
  } else if (abs(x) > 2) {
    position.x += abs(x) / x * 2;
  } else if (abs(y) > 2) {
    position.y += abs(y) / y * 2;
  } else if ((abs(x) == 2 && abs(y) != 1) || (abs(y) == 2 && abs(x) != 1)) {
    position.x += abs(x) / x;
    position.y += abs(y) / y;
  } else if (abs(x) > 1) {
    position.x += abs(x) / x * 2;
  } else if (abs(y) > 1) {
    position.y += abs(y) / y * 2;
  }

  while (!path.empty() && Point::is_arrive(position, path.front())) {
    if (path.front().type == FROM) {
      auto tmp2 = received_orders.find(Order(path.front().order_id));
      if (tmp2 != received_orders.end()) {
        sending_orders.insert(*tmp2);
        received_orders.erase(tmp2);
      }
    } else {
      auto tmp1 = sending_orders.find(Order(path.front().order_id));
      if (tmp1 != sending_orders.end()) {
        if (time - (*tmp1).time <= 30) {
          finished_orders.insert(*tmp1);
        } else {
          outdate_orders.insert(*tmp1);
        }
        sending_orders.erase(tmp1);
      }
    }
    path.pop();
  }
}

void Rider::add_order(Order o) { received_orders.insert(o); }

void Rider::change_path(std::queue<Point> path, int all_cost) {
  this->path = path;
  this->all_cost = all_cost;
}

Point Rider::get_position() const { return position; }
