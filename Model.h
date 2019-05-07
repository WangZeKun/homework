#pragma once
#include <cstdio>
#include <vector>
#include "Order.h"
#include "Point.h"
#include "Rider.h"
#include "RiderFactor.h"

enum ProgramStatus {
  GOOD,
  BREAK,  // �Ʋ�
  REVOKE  //����ִ��
};

class Model {
 public:
  std::queue<Order> waiting_order;
  std::vector<Rider> riders;

  Model(Point init_position);
  void add_order(Order o);
  void step();  //���������д
  unsigned num_finished();
  unsigned num_outdate();
  unsigned money();
  unsigned now();
  ProgramStatus statu();

 private:
  void add_rider();
  Point init_position;  //���ֳ�ʼλ��

  ProgramStatus __statu__;
  unsigned int __time__ = 0;
};
