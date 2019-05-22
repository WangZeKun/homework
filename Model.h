#pragma once
#include <cstdio>
#include <vector>
#include "Order.h"
#include "Point.h"
#include "Rider.h"
#include "algorithm.h"

enum ProgramStatus {
  GOOD,     //正常运行
  BREAK,    // 破产
  REVOKE,   //吊销执照
  FINISHED  //没有正在派送的订单
};


//模型类，用于存储整个数据
//初始化传入骑手的初始位置
//Example: 
//	Model m = Model({1,2})
class Model {
 public:
  //初始化Model
  Model(Point init_position);

  //添加新接的订单
  void add_order(Order o);

  // 行走一个单位时间
  // 干的事情包含：1. 将当前时间的订单分配给骑手
  //							 2. 每个骑手向前行进一格
  void step();

  //返回已接单加派送中的订单
  unsigned num_sending() const;

  //返回已完成的订单
  unsigned num_finished() const;

  //返回超时的订单
  unsigned num_outdate() const;

  //返回现有的钱数
  unsigned money() const;

  //返回当前时间
  unsigned now() const;

  //返回当前状态
  ProgramStatus statu() const;

  //待添加的订单
  std::queue<Order> waiting_order;

  //骑手
  std::vector<Rider> riders;
 private:
  //添加新招聘的骑手
  void add_rider();

	//检查是否破产，如果破产，则标记__statu__
  void check_is_break();

	//检查是否被吊销执照,如果是，则标记__statu__
  void check_is_revoke();

	//检查是否没有正在派送的订单，如果是，则标记__statu__
  void check_is_finished();

  //骑手初始位置
  Point init_position;

  //当前状态
  ProgramStatus __statu__;

  //当前时间
  unsigned int __time__;

};
