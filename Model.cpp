#include "Model.h"

Model::Model(Point init_position)
    : init_position(init_position), __statu__(GOOD) {}

unsigned Model::num_outdate() const {
  int outdate = 0;
  for (int i = 0; i < riders.size(); i++) {
    outdate = outdate + riders[i].outdate_orders.size();
  }
  return outdate;
}

unsigned Model::money() const {
  int total = 1000 - riders.size() * 300;
  for (int i = 0; i < riders.size(); i++) {
    total = total + 10 * riders[i].finished_orders.size();
    total = total - 50 * riders[i].outdate_orders.size();
  }
  return total;
}

unsigned Model::now() const { return __time__; }

ProgramStatus Model::statu() const { return __statu__; }

void Model::add_rider() { riders.push_back(Rider(init_position)); }

void Model::add_order(Order o) {
  Order NewOrder = o;
  waiting_order.push(NewOrder);
}

void Model::step() {
  while (!waiting_order.empty()) {
    std::queue<Point> path;
    int index = -1, min = INT_MAX, cost = 100;
    for (auto i = 0; i < riders.size(); i++) {
      if (riders[i].sending_orders.size() +
              riders[i].received_orders.size() * 2 >
          18)
        continue;
      auto [path_tmp, cost_tmp] =
          cal_solution(riders[i], waiting_order.front(), __time__);
      if (cost_tmp - riders[i].all_cost < min) {
        path = path_tmp, cost = cost_tmp, index = i,
        min = cost - riders[i].all_cost;
      } else if (cost_tmp - riders[i].all_cost == min &&
                 (cost_tmp < cost ||
                  (cost_tmp == cost && path_tmp.size() < path.size()))) {
        path = path_tmp, cost = cost_tmp, index = i;
      }
    }
    if (cost > 60 && money() >= 300) {
      add_rider();
      auto [path_tmp, cost_tmp] = cal_solution(riders[riders.size() - 1],
                                               waiting_order.front(), __time__);
      riders[riders.size() - 1].change_path(path_tmp, cost_tmp);
      riders[riders.size() - 1].received_orders.insert(waiting_order.front());
    } else {
      riders[index].change_path(path, cost);
      riders[index].received_orders.insert(waiting_order.front());
    }
    // waiting_order.erase(waiting_order.begin());
    waiting_order.pop();
  }
  for (auto i = 0; i < riders.size(); i++) {
    riders[i].step(__time__);
  }
  __time__++;
  int flag = 0;
  for (int i = 0; i < riders.size(); i++) {
    if (riders[i].received_orders.size() != 0 ||
        riders[i].sending_orders.size() != 0) {
      flag = 1;
    }
  }
  if (flag == 0) {
    __statu__ = FINISHED;
  }
  if (money()<0) {
    __statu__ = BREAK;
  }
}

unsigned Model::num_finished() const {
  int finished = 0;
  for (int i = 0; i < riders.size(); i++) {
    finished = finished + riders[i].finished_orders.size();
  }
  return finished;
}
