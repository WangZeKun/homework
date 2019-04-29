#include<cstdio>
#include<vector>

#ifndef ORDER_H
#define ORDER_H

enum OrderStatus {
  MISS,      //未接单
  RECEIVED,  //已接单
  SENDING,   //正在派送
  END,       //已结束
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
