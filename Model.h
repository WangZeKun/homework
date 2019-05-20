#pragma once
#include <cstdio>
#include <vector>
#include "Order.h"
#include "Point.h"
#include "Rider.h"
#include "RiderFactor.h"

enum ProgramStatus {
  GOOD,   //��������
  BREAK,  // �Ʋ�
  REVOKE, //����ִ��
  END  //�������
};

class Model {
 public:
  std::queue<Order> waiting_order;
  std::vector<Rider> riders;

  Model(Point init_position);
  void add_order(Order o); //����½ӵĶ���
  void step();  //
  unsigned num_finished();  //��������ɵĶ���
  unsigned num_outdate();  //���س�ʱ�Ķ���
  unsigned money(); //�������е�Ǯ��
  unsigned now();  //���ص�ǰʱ��
  ProgramStatus statu();  //��ǵ�ǰ״̬

 private:
  void add_rider();  //�������Ƹ������
  Point init_position;  //���ֳ�ʼλ��

  ProgramStatus __statu__; //��¼��ǰ״̬
  unsigned int __time__ = 0;
};
