#pragma once
#include <cstdio>
#include <vector>
#include "point.h"

enum OrderStatus {
  MISS,      //δ�ӵ�
  RECEIVED,  //�ѽӵ�
  SENDING,   //��������
  END,       //�ѽ���
};

//������ ������¼��������
class Order {
 public:
  //����id
  const unsigned id;

  //�͹�
  const Point from;

  //ʳ��
  const Point to;

  //�µ�ʱ��
  const unsigned time;

  //����״̬
  OrderStatus statu;

  Order(const unsigned id);
  Order(const unsigned id, const Point restaurant, const Point customer,
        const unsigned time);
  ~Order();


  bool operator==(const Order& b) const;
  bool operator<(const Order& b) const;
  Order operator=(Order& b);
};
