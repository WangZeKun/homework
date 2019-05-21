#pragma once
#include <cstdio>
#include <vector>
#include "Order.h"
#include "Point.h"
#include "Rider.h"
#include "RiderFactor.h"

enum ProgramStatus {
  GOOD,
  BREAK,  // 破产
  REVOKE, //吊销执照
  FINISHED  //程序结束
};

class Model {
 public:
  std::queue<Order> waiting_order;
  std::vector<Rider> riders;

  Model(Point init_position);
  void add_order(Order o);
  void step();  //这个函数我写
  unsigned num_finished() const;
  unsigned num_outdate() const;
  void aaa();
  unsigned money() const;
  unsigned now() const;
  ProgramStatus statu() const;

 private:
  void add_rider();
  Point init_position;  //骑手初始位置

  ProgramStatus __statu__;
  unsigned int __time__ = 0;
};
