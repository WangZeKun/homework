#pragma once
#include <cstdio>
#include <vector>
#include "order.h"
#include "point.h"
#include "rider.h"
#include "algorithm.h"


//��¼���������״̬
enum ProgramStatus {
  GOOD,     //��������
  BREAK,    //�Ʋ�
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

  //����µĶ���
  void AddOrder(Order o);

  // ����һ����λʱ��
  // �ɵ����������1. ����ǰʱ��Ķ������������
  //							 2. ÿ��������ǰ�н�һ��
  void Step();

  //�����ѽӵ��������еĶ���
  unsigned num_sending() const;

  //��������ɵĶ���
  unsigned num_finished() const;

  //���س�ʱ�Ķ���
  unsigned num_outdate() const;

  //�������е�Ǯ��
  unsigned money() const;

  //���ص�ǰʱ��
  unsigned time() const;

  //���ص�ǰ״̬
  ProgramStatus statu() const;

  //����ӵĶ���
  std::queue<Order> waiting_order;

  //����
  std::vector<Rider> riders;
 private:
  //�������Ƹ������
  void AddRider();

	//����Ƿ��Ʋ�������Ʋ�������statu_
  void CheckIsBreak();

	//����Ƿ񱻵���ִ��,����ǣ�����statu_
  void CheckIsRevoke();

	//����Ƿ�û���������͵Ķ���������ǣ�����statu_
  void CheckIsFinished();

  //���ֳ�ʼλ��
  Point init_position_;

  //��ǰ״̬
  ProgramStatus statu_;

  //��ǰʱ��
  unsigned int time_;

};
