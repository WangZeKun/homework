#include "Order.h"



Order::Order(const unsigned int id, const std::pair<unsigned int, unsigned int> restaurant,
             const std::pair<unsigned int, unsigned int> diner, const unsigned int time)
    : id(id), restaurant(restaurant), diner(diner), time(time), statu(MISS) {}

Order::~Order() {}
