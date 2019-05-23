#pragma once
#include <cstdio>
#include <vector>
#include "point.h"

enum OrderStatus {
  MISS,      //未接单
  RECEIVED,  //已接单
  SENDING,   //正在派送
  END,       //已结束
};

//订单类 用来记录订单数据
class Order {
 public:
  //订单id
  const unsigned id;

  //餐馆
  const Point from;

  //食客
  const Point to;

  //下单时间
  const unsigned time;

  //订单状态
  OrderStatus statu;

  Order(const unsigned id);
  Order(const unsigned id, const Point restaurant, const Point customer,
        const unsigned time);
  ~Order();


  bool operator==(const Order& b) const;
  bool operator<(const Order& b) const;
  Order operator=(Order& b);
};
