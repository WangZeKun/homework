#pragma once
#include<cstdio>
#include<vector>
#include "Point.h"


enum OrderStatus {
  MISS,      //未接单
  RECEIVED,  //已接单
  SENDING,   //正在派送
  END,       //已结束
};

class Order {
 public:
  const unsigned id;
  const Point from;
  const Point to;
  const unsigned time;
  OrderStatus statu;

	Order(const unsigned id);
  Order(const unsigned  id,const Point  restaurant,
        const Point customer, const unsigned  time);
  ~Order();
  bool operator==(const Order& b) const;
  bool operator<(const Order& b) const;
  Order operator=(Order& b);

 private:
};
