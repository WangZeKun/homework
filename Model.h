#pragma once
#include <cstdio>
#include <vector>
#include "Order.h"
#include "Point.h"
#include "Rider.h"
#include "RiderFactor.h"

enum ProgramStatus {
  GOOD,   //正常运行
  BREAK,  // 破产
  REVOKE, //吊销执照
  END  //程序结束
};

class Model {
 public:
  std::queue<Order> waiting_order;
  std::vector<Rider> riders;

  Model(Point init_position);
  void add_order(Order o); //添加新接的订单
  void step();  //
  unsigned num_finished() const;  //返回已完成的订单
  unsigned num_outdate() const;  //返回超时的订单
  unsigned money() const; //返回现有的钱数
  unsigned now() const;  //返回当前时间
  ProgramStatus statu() const;  //标记当前状态

 private:
  void add_rider();  //添加新招聘的骑手
  Point init_position;  //骑手初始位置

  ProgramStatus __statu__; //记录当前状态
  unsigned int __time__ = 0;
};
