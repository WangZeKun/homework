#pragma once
#include<cstdio>
#include<vector>
#include "Point.h"


enum OrderStatus {
  MISS,      //δ�ӵ�
  RECEIVED,  //�ѽӵ�
  SENDING,   //��������
  END,       //�ѽ���
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
