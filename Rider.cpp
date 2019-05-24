#include "rider.h"

Rider::Rider(Point position) : position_(position), all_cost_(0),finished_orders_(0),illegal_orders_(0),outdate_orders_(0){}

Rider::~Rider() {}

void Rider::Step(unsigned time) {
  if (path_.empty()) {
    return;
  }

	position_ = Point::Move(position_, path_.front());
	dock_points_.clear();
  while (!path_.empty() && Point::IsArrive(position_, path_.front())) {
    if (path_.front().type == FROM) {
      auto tmp2 = received_orders_.find(Order(path_.front().order_id));
      if (tmp2 != received_orders_.end()) {
        sending_orders_.insert(*tmp2);
        received_orders_.erase(tmp2);
      }
    } else {
      auto tmp1 = sending_orders_.find(Order(path_.front().order_id));
      if (tmp1 != sending_orders_.end()) {
        if (time - (*tmp1).time <= 30) {
          finished_orders_.push_back(*tmp1);
				}
        sending_orders_.erase(tmp1);
      }
    }
    dock_points_.push_back(path_.front());
    path_.pop();
  }

  for (auto it = received_orders_.begin(); it != received_orders_.end(); it++) {
    if ((*it).time + 30 < time) {
      outdate_orders_.push_back(*it);  // 是否超时
    } else if ((*it).time + 60 < time) {
      outdate_orders_.push_back(*it);  //是否废单
    }
  }
  for (auto it = sending_orders_.begin(); it != sending_orders_.end(); it++) {
    if ((*it).time + 30 < time) {
      outdate_orders_.push_back(*it);  // 是否超时
    } else if ((*it).time + 60 < time) {
      outdate_orders_.push_back(*it);  //是否废单
    }
  }

  if (all_cost_ >= 2) {
    all_cost_ -= 2;
  }
}

void Rider::ChangePath(std::queue<Point> path, int all_cost) {
  this->path_ = path;
  this->all_cost_ = all_cost;
}

void Rider::AddOrder(Order o) { received_orders_.insert(o); }

Point Rider::position() const { return position_; }

int Rider::illegal_orders() const { return illegal_orders_; }

const std::vector<Order> &Rider::outdate_orders() const { return outdate_orders_; }

const std::vector<Order> &Rider::finished_orders() const { return finished_orders_; }

const std::set<Order> &Rider::received_orders() const { return received_orders_; }

const std::set<Order> &Rider::sending_orders() const { return sending_orders_; }

const std::vector<Point>& Rider::dock_points() const { return dock_points_; }

int Rider::all_cost() const { return all_cost_; }
