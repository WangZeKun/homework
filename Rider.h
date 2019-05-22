#pragma once
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <set>
#include "order.h"
#include "point.h"

//������
//�����������ֵĶ�������Ϣ
class Rider {
 public:
  //���캯��
  //�������ֵĳ�ʼλ��
  Rider(Point position);
  ~Rider();

  //�������� һ��λʱ��
  //	1. ����
  //  2. �������һ���ط������¼,���¶�����
  void Step(unsigned time);

  // ���һ������
  void AddOrder(Order r);

  //�������ֵ��ܻ��Ѻ�·��
  void ChangePath(std::queue<Point> path, int all_cost);

  //�������ֵ�λ����Ϣ
  Point position() const;

  //���طǷ�������ʱ�䳬��60��������
  int illegal_orders() const;

  //���س�ʱ������ʱ�䳬��30��������
  int outdate_orders() const;

  //��������ɶ�����
  int finished_orders() const;

	//�����ѽӵ�����
	std::set<Order> received_orders() const;

	//���������ж���
	std::set<Order> sending_orders() const;

	//�����ܻ���
	int all_cost() const;

 private:
  //����·��
  std::queue<Point> path_;

  //����λ��
  Point position_;

  //�Ƿ�������ʱ�䳬��60��������
  int illegal_orders_;

  //��ʱ������ʱ�䳬��30��������
  int outdate_orders_;

  //����ɶ�����
  int finished_orders_;

  //������ʱ��
  int all_cost_;

  //�ѽӵ�����
  std::set<Order> received_orders_;

  //�����ж���
  std::set<Order> sending_orders_;
};
