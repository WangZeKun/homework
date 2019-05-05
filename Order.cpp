#include "Order.h"



Order::Order(const unsigned id):id(id),time(0) {}

Order::Order(const unsigned id, const Point restaurant, const Point diner,
             const unsigned time)
    : id(id), from(restaurant), to(diner), time(time), statu(MISS) {}

Order::~Order() {}

bool Order::operator==(const Order& o) const { return id == o.id; }
bool Order::operator<(const Order& o) const { return id < o.id; }

Order Order::operator=(Order& b) { return b; }

