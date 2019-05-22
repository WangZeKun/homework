#include "rider.h"

Rider::Rider(Point position) : position_(position), all_cost_(0),finished_orders_(0),illegal_orders_(0),outdate_orders_(0){}

Rider::~Rider() {}

void Rider::Step(unsigned time) {
  if (path_.empty()) {
    return;
  }

  auto next = path_.front();
  int x = next.x - position_.x;
  int y = next.y - position_.y;
  if (x == 0) {
    position_.x += position_.x == 16 ? -1 : 1;
    position_.y += y > 0 ? 1 : -1;
  } else if (y == 0) {
    position_.y += position_.y == 16 ? -1 : 1;
    position_.x += x > 0 ? 1 : -1;
  } else if (abs(x) > 2 && x % 2 == 0) {
    position_.x += abs(x) / x * 2;
  } else if (abs(y) > 2 && y % 2 == 0) {
    position_.y += abs(y) / y * 2;
  } else if (position_.x == 1 && x < 0 || position_.x == 15 && x > 0) {
    position_.y += abs(y) / y * 2;
  } else if (position_.y == 1 && y < 0 || position_.y == 15 && y > 0) {
    position_.x += abs(x) / x * 2;
  } else {
    position_.x += abs(x) / x;
    position_.y += abs(y) / y;
  }

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
          finished_orders_++;
        } else if(time-(*tmp1).time <= 60){
          outdate_orders_++;
        } else {
          illegal_orders_++;        
				}
        sending_orders_.erase(tmp1);
      }
    }
    path_.pop();
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

int Rider::outdate_orders() const { return outdate_orders_; }

int Rider::finished_orders() const { return finished_orders_; }

std::set<Order> Rider::received_orders() const { return received_orders_; }

std::set<Order> Rider::sending_orders() const { return sending_orders_; }

int Rider::all_cost() const { return all_cost_; }
