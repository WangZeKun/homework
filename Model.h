#include <cstdio>
#include <vector>
#include "Order.h"
#include "Rider.h"

#ifndef MAIN_H
#define MAIN_H
enum ProgramStatus {
  GOOD,
  BREAK,  // 破产
  REVOKE  //吊销执照
};

class Model {
 public:
  std::vector<Order> waiting_order;
  std::vector<Rider> riders;

  Model(std::pair<unsigned int, unsigned int> init_position);
  void add_order(Order o);
  void step();  //这个函数我写
  unsigned int num_finished();
  unsigned int num_outdate();
  unsigned int money();
  unsigned int time();
  ProgramStatus statu();

 private:
  void add_rider(Rider r);
  std::pair<unsigned int, unsigned int> init_position;  //骑手初始位置

  ProgramStatus __statu__;
  unsigned int __time__ = 0;
};
#endif  // !MAIN_H
