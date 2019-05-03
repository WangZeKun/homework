#include "RiderFactor.h"

Solution cal_solution(Point start, Order new_order,
                      std::set<Order> received_order,
                      std::set<Order> sending_order) {
  //初始化数据
  received_order.insert(new_order);
  int sending_num = sending_order.size();
  int received_num = received_order.size();
  int n = sending_num * 2 + received_num;
  Point P[20];
  int from[20];
  int G[20][20];
  int dp[20][1 << 20];
  std::fill(G, G + 20 * 20, INT_MAX);
  std::fill(dp, dp + 20 * (1 << 20), INT_MAX);
  std::fill(from, from + 20, -1);

  int index_from = 0, index_to;
  for (auto it_from = received_order.begin(); it_from != received_order.end();
       it_from++) {
    index_to = 0;
    for (auto it_to = received_order.begin(); it_to != received_order.end();
         it_to++) {
      G[index_to][index_from] = G[index_from][index_to] =
          Point::get_dis((*it_from).from, (*it_to).to);
      G[index_to][index_from + 1] = G[index_from + 1][index_to] =
          Point::get_dis((*it_from).to, (*it_to).to);
      index_to++;
    }
    for (auto it_to = sending_order.begin(); it_to != sending_order.end();
         it_to++) {
      G[index_to][index_from] = G[index_from][index_to] =
          Point::get_dis((*it_from).from, (*it_to).to);
      G[index_to][index_from + 1] = G[index_from + 1][index_to] =
          Point::get_dis((*it_from).to, (*it_to).to);
      index_to++;
    }
    dp[index_from][1 << index_from] = 0;
    dp[index_from + 1][1 << (index_from + 1)] = 0;
    P[index_from] = (*it_from).from;
    P[index_from + 1] = (*it_from).to;
    index_from += 2;
  }
  for (auto it_from = sending_order.begin(); it_from != sending_order.end();
       it_from++) {
    index_to = 0;
    for (auto it_to = received_order.begin(); it_to != received_order.end();
         it_to++) {
      G[index_to][index_from] = G[index_from][index_to] =
          Point::get_dis((*it_from).from, (*it_to).to);
      G[index_to][index_from + 1] = G[index_from + 1][index_to] =
          Point::get_dis((*it_from).to, (*it_to).to);
      index_to++;
    }
    for (auto it_to = sending_order.begin(); it_to != sending_order.end();
         it_to++) {
      G[index_to][index_from] = G[index_from][index_to] =
          Point::get_dis((*it_from).from, (*it_to).to);
      G[index_to][index_from + 1] = G[index_from + 1][index_to] =
          Point::get_dis((*it_from).to, (*it_to).to);
      index_to++;
    }
    dp[index_from][1 << index_from] = 0;
    dp[index_from + 1][1 << (index_from + 1)] = 0;
    P[index_from] = (*it_from).from;
    P[index_from + 1] = (*it_from).to;
    index_from += 2;
  }

  //列dp方程
  for (int S = 0; S < (1 << n); S++)
    for (int i = 0; i < n; ++i)
      if (S & (1 << i) && check(S, i, received_num))
        for (int j = 0; j < n; ++j)
          if (!(S & (1 << j)) && G[i][j] != INT_MAX &&
              dp[j][S | (i << j)] > dp[i][S] + G[i][j]) {
            dp[j][S | (1 << j)] = dp[i][S] + G[i][j];
            from[j] = i;
          }

  Solution s;
  int index = 0;
  s.all_cost = INT_MAX;
  for (int i = 0; i < n; i++) {
    if (dp[i][1 << n - 1] < s.all_cost) {
      index = i;
      s.all_cost = dp[i][1 << n - 1];
    }
  }
  get_path(index, from, P, s.path);
  return s;
}

bool check(int S, int i, int received_num) {
  if (i < 2 * received_num && i % 2 == 1 && !S & (1 << i)) return false;
  return true;
}

void get_path(int end, int from[], Point P[], std::queue<Point> &path) {
  if (end != -1) {
    get_path(from[end], from, P, path);
    path.push(P[end]);
  }
