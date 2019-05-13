#include "Rider.h"

Rider::Rider(Point position) : position(position), all_cost(0) {}

Rider::~Rider() { std::cout << "delete Rider"; }

void Rider::step(unsigned time) {
  auto next = path.front();
  int x = next.x - position.x;
  int y = next.y - position.y;
  int i = 0;
  if (x > 0 && y > 0) {
    if ( position.x + 2 != next.x && position.x + 1 != next.x) {
      position.x = position.x + 2;
    } 
	else if ((position.x + 2 == next.x) || (position.x + 1 == next.x && position.y + 1 == next.y)) {
      position.x = position.x + 1;
      position.y = position.y + 1;
    } 
	else if (position.x + 1 == next.x && position.y + 1 != next.y){
      position.y = position.y + 2;
    }
  } 
  else if (x < 0 && y < 0) {
    if (position.x - 2 != next.x && position.x - 1 != next.x) {
      position.x = position.x - 2;
    } 
	else if ((position.x - 2 == next.x) ||
               (position.x - 1 == next.x && position.y - 1 == next.y)) {
      position.x = position.x - 1;
      position.y = position.y - 1;
    } 
	else if (position.x - 1 == next.x && position.y - 1 != next.y) {
      position.y = position.y - 2;
    }
  } 
  else if (x < 0 && y > 0) {
    if (position.x - 2 != next.x && position.x - 1 != next.x) {
      position.x = position.x - 2;
	} else if ((position.x - 2 == next.x) ||
               (position.x - 1 == next.x && position.y + 1 == next.y)) {
      position.x = position.x - 1;
      position.y = position.y + 1;
    } 
	else if (position.x - 1 == next.x && position.y + 1 != next.y) {
          position.y = position.y + 2;
        }
  } else if (x > 0 && y < 0) {
    if (position.x + 2 != next.x && position.x + 1 != next.x) {
      position.x = position.x + 2;
    } else if ((position.x + 2 == next.x) ||
               (position.x + 1 == next.x && position.y - 1 == next.y)) {
      position.x = position.x + 1;
      position.y = position.y - 1;
    } else if (position.x + 1 == next.x && position.y - 1 != next.y) {
      position.y = position.y - 2;
    }
  }
  
 
	  
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

Point Rider::get_position() { return position; }
