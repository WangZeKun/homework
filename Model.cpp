#include "Model.h"

Model::Model(Point init_position)
    : init_position(init_position), __statu__(GOOD) {}

unsigned Model::num_outdate() { return 0; }

unsigned Model::money() { return 0; }

unsigned Model::now() { return 0; }

ProgramStatus Model::statu() { return ProgramStatus(); }

void Model::add_rider() {}

void Model::add_order(Order o) {}

void Model::step() {
  while (!waiting_order.empty()) {
    Solution ss;
    int index = -1, min = INT_MAX;
    for (auto i = 0; i < riders.size(); i++) {
      Solution s =
          cal_solution(riders[i].get_position(), waiting_order.front(),
                       riders[i].recived_orders, riders[i].sending_orders);
      if (s.all_cost - riders[i].all_cost < min) {
        ss = s, index = i, min = s.all_cost - riders[i].all_cost;
      } else if (s.all_cost - riders[i].all_cost == min &&
                 s.all_cost < ss.all_cost) {
        ss = s, index = i;
      }
    }
    if (ss.all_cost > 60 && money() >= 300) {
      add_rider();
      Solution s = cal_solution(riders[riders.size() - 1].get_position(),
                                waiting_order.front(),
                                riders[riders.size() - 1].recived_orders,
                                riders[riders.size() - 1].sending_orders);
      riders[riders.size() - 1].change_path(s.path, s.all_cost);
      riders[riders.size() - 1].recived_orders.insert(waiting_order.front());
    } else {
      riders[index].change_path(ss.path, ss.all_cost);
      riders[index].recived_orders.insert(waiting_order.front());
    }
    // waiting_order.erase(waiting_order.begin());
    waiting_order.pop();
  }
  for (auto i = 0; i < riders.size(); i++) {
    riders[i].step();
  }
  __time__++;
}

unsigned Model::num_finished() { return 0; }
