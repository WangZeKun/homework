#include <cstdio>
#include <vector>
#include "Order.h"
#include "Rider.h"

#ifndef MAIN_H
#define MAIN_H
enum ProgramStatus {
  GOOD,
  BREAK,  // �Ʋ�
  REVOKE  //����ִ��
};

class Model {
 public:
  std::vector<Order> waiting_order;
  std::vector<Rider> riders;

  Model(std::pair<unsigned int, unsigned int> init_position);
  void add_order(Order o);
  void step();  //���������д
  unsigned int num_finished();
  unsigned int num_outdate();
  unsigned int money();
  unsigned int time();
  ProgramStatus statu();

 private:
  void add_rider(Rider r);
  std::pair<unsigned int, unsigned int> init_position;  //���ֳ�ʼλ��

  ProgramStatus __statu__;
  unsigned int __time__ = 0;
};
#endif  // !MAIN_H
