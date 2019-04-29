#include "Model.h"

Model::Model(std::pair<unsigned int, unsigned int> init_position)
    : init_position(init_position), __statu__(GOOD) {}

unsigned int Model::num_outdate() { return 0; }

unsigned int Model::money() { return 0; }

unsigned int Model::time() { return 0; }

ProgramStatus Model::statu() { return ProgramStatus(); }

void Model::add_rider(Rider r) {}

void Model::add_order(Order o) {}

void Model::step() {
  int index = 0;
  while (!waiting_order.empty()) {
    riders[index++].recived_orders.push_back(waiting_order.front());
    waiting_order.erase(waiting_order.begin());
    index %= riders.size();
  }
  for (size_t i = 0; i < riders.size(); i++) {
    riders[i].step();
  }
  __time__++;
}

unsigned int Model::num_finished() { return 0; }
