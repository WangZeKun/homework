#include "RiderFactor.h"

std::tuple<std::queue<Point>, int> cal_solution(const Rider &r, const Order &new_order,const int time) {
  //初始化数据
  int sending_num = r.sending_orders.size();
  int received_num = r.received_orders.size() + 1;
  int n = sending_num  + received_num * 2;
  Point *P = new Point[n];
  int *last_time = new int[n];
  int **is_outdate = new int*[n];

  int **G = new int*[n];
  int **from = new int *[n];
  int **dp = new int *[n];
  for (size_t i = 0; i < n; i++) {
    last_time[i] = INT_MAX / 2;
    G[i] = new int[n];
    is_outdate[i] = new int[(long long)1 << n];
    from[i] = new int[(long long)1 << n];
    dp[i] = new int[(long long)1 << n];
    for (size_t j = 0; j < n; j++) {
      G[i][j] = INT_MAX / 2;
    }
    for (size_t j = 0; j < ((long long)1 << n); j++) {
      is_outdate[i][j] = 0;
      from[i][j] = -1;
      dp[i][j] = INT_MAX / 2;
    }
  }
  // std::fill(G, G + 20 * 20, INT_MAX);
  // std::fill(dp, dp + 20 * (1 << 20), INT_MAX);
  // std::fill(from, from + 20, -1);

  P[0] = new_order.from;
  P[1] = new_order.to;
  int index_from = 2;
  for (auto it_from = r.received_orders.begin();
       it_from != r.received_orders.end(); it_from++) {
    P[index_from] = (*it_from).from;
    P[index_from + 1] = (*it_from).to;
    last_time[index_from + 1] = (30 - time - (*it_from).time) * 2;
    index_from += 2;
  }
  for (auto it_from = r.sending_orders.begin();
       it_from != r.sending_orders.end(); it_from++) {
    P[index_from] = (*it_from).to;
    last_time[index_from] = (30 - (time - (*it_from).time)) * 2;
    index_from += 1;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      G[i][j] = G[j][i] = Point::get_dis(P[i], P[j]);
    }
    dp[i][1 << i] = Point::get_dis(r.get_position(), P[i]);
  }

  //列dp方程
  for (int S = 0; S < (1 << n); S++)
    for (int i = 0; i < n; ++i)
      if (S & (1 << i) && check(S, i, received_num))
        for (int j = 0; j < n; ++j)
          if (!(S & (1 << j)) && G[i][j] != INT_MAX / 2) {
            if (dp[j][S | (1 << j)] > dp[i][S] + G[i][j]) {
              if (dp[i][S] + G[i][j] > last_time[j] || is_outdate[i][S]) {
                if (dp[j][S | (1 << j)] == INT_MAX / 2 ||
                    is_outdate[j][S | (1 << j)] == 1) {
                  dp[j][S | (1 << j)] = dp[i][S] + G[i][j];
                  from[j][S | (1 << j)] = i;
                  is_outdate[j][S | (1 << j)] = 1;
                }
              } else {
                dp[j][S | (1 << j)] = dp[i][S] + G[i][j];
                from[j][S | (1 << j)] = i;
                is_outdate[j][S | (1 << j)] = 0;
              }
            }
          }

  int index = 0, all_cost = INT_MAX / 2, is_out = 1;
  std::queue<Point> path;
  for (int i = 0; i < n; i++) {
    if (dp[i][(1 << n) - 1] < all_cost &&
        !(is_outdate[i][(1 << n) - 1] == 1 && is_out == 0)) {
      index = i;
      is_out = is_outdate[i][(1 << n) - 1];
      all_cost = dp[i][(1 << n) - 1];
    } else if (is_outdate[i][(1 << n) - 1] == 0 && is_out == 1) {
      index = i;
      is_out = is_outdate[i][(1 << n) - 1];
      all_cost = dp[i][(1 << n) - 1];
    }
  }
  get_path(index, (1 << n) - 1, from, P, path);
  for (size_t i = 0; i < n; i++) {
    delete[] is_outdate[i];
    delete[] G[i];
    delete[] from[i];
    delete[] dp[i];
  }
  delete[] last_time;
  delete[] is_outdate;
  delete[] G;
  delete[] from;
  delete[] dp;
  return {path, all_cost};
}

bool check(int S, int i, int received_num) {
  if (i < 2 * received_num && i % 2 == 1 && !(S & (1 << (i - 1)))) return false;
  return true;
}

void get_path(int end, int S, int **from, Point P[], std::queue<Point> &path) {
  if (end != -1) {
    get_path(from[end][S], S ^ 1 << end, from, P, path);
    path.push(P[end]);
  }
}
