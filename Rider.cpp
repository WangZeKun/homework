#include "Rider.h"

Rider::Rider() { std::cout << "new Rider"; }

Rider::~Rider() { std::cout << "delete Rider"; }

void Rider::step() { 
	auto next = path[0];
  int x = position.first - next.first;
  int y = position.second - next.second;
  if (abs(x) > abs(y))
    position.first += x / abs(x);
  else
    position.second += y / abs(y);
  if (next == position) {
    path.erase(path.begin());
    for (size_t i = 0; i < sending_orders.size(); i++) {
      if (next == sending_orders[i].diner) {
        finished_orders.push_back(sending_orders[i]);
        sending_orders.erase(sending_orders.begin() + i);
        return;
			}
    }
    for (size_t i = 0; i < recived_orders.size(); i++) {
      if (next == recived_orders[i].restaurant) {
        sending_orders.push_back(recived_orders[i]);
        recived_orders.erase(recived_orders.begin() + i);
        return;
			}
    }
	}
}

void Rider::add_orders(Order r) {
  this->recived_orders.push_back(r);
  path.push_back(r.restaurant);
  path.push_back(r.diner);
}

std::pair<unsigned int, unsigned int> Rider::get_position() { return position; }
