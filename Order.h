#include<cstdio>
#include<vector>

#ifndef ORDER_H
#define ORDER_H

enum OrderStatus {
  MISS,      //δ�ӵ�
  RECEIVED,  //�ѽӵ�
  SENDING,   //��������
  END,       //�ѽ���
};

class Order {
 public:
  const int id;
  const std::pair<unsigned int,unsigned int> restaurant;
  const std::pair<unsigned int,unsigned int> diner;
  const int time;
  OrderStatus statu;

  Order(const unsigned int id, const std::pair<unsigned int, unsigned int> restaurant,
        const std::pair<unsigned int, unsigned int> diner, const unsigned int time);
  ~Order();

 private:
};
#endif  // !ORDER_H
