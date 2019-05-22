#pragma once
#include <cstdio>
#include <vector>
#include "Order.h"
#include "Point.h"
#include "Rider.h"
#include "algorithm.h"

enum ProgramStatus {
  GOOD,     //��������
  BREAK,    // �Ʋ�
  REVOKE,   //����ִ��
  FINISHED  //û���������͵Ķ���
};


//ģ���࣬���ڴ洢��������
//��ʼ���������ֵĳ�ʼλ��
//Example: 
//	Model m = Model({1,2})
class Model {
 public:
  //��ʼ��Model
  Model(Point init_position);

  //����½ӵĶ���
  void add_order(Order o);

  // ����һ����λʱ��
  // �ɵ����������1. ����ǰʱ��Ķ������������
  //							 2. ÿ��������ǰ�н�һ��
  void step();

  //�����ѽӵ��������еĶ���
  unsigned num_sending() const;

  //��������ɵĶ���
  unsigned num_finished() const;

  //���س�ʱ�Ķ���
  unsigned num_outdate() const;

  //�������е�Ǯ��
  unsigned money() const;

  //���ص�ǰʱ��
  unsigned now() const;

  //���ص�ǰ״̬
  ProgramStatus statu() const;

  //����ӵĶ���
  std::queue<Order> waiting_order;

  //����
  std::vector<Rider> riders;
 private:
  //�������Ƹ������
  void add_rider();

	//����Ƿ��Ʋ�������Ʋ�������__statu__
  void check_is_break();

	//����Ƿ񱻵���ִ��,����ǣ�����__statu__
  void check_is_revoke();

	//����Ƿ�û���������͵Ķ���������ǣ�����__statu__
  void check_is_finished();

  //���ֳ�ʼλ��
  Point init_position;

  //��ǰ״̬
  ProgramStatus __statu__;

  //��ǰʱ��
  unsigned int __time__;

};
