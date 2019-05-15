#include "OutputServer.h"

OutputServer::OutputServer() {}

OutputServer::~OutputServer() {}

OutputServer::PrintToConsole(const Model &m) {
  int i, j, position[17][17] = {0};
  Point point;
  for (i = 0; i < 17; i += 2) {
    for (j = 0; j < 17; j += 2) {
      positiong[i][j] = 1;
    }
  }
  for (size_t i = 0; i < m.riders.size(); i++) {
    for (auto it = m.riders[i].recived_orders.begin();
         it != m.riders[i].recived_orders.end(); it++) {
      position[(*it).from.x][(*it).from.y] = 2;
      position[(*it).to.x][(*it).to.y] = 3;
    }
    for (auto it = m.riders[i].sending_orders.begin();
         it != m.riders[i].sending_orders.end(); it++) {
      position[(*it).from.x][(*it).from.y] = 2;
      position[(*it).to.x][(*it).to.y] = 3;
    }
    position[m.riders[i].get_position().x][m.riders[i].get_position().y] = 4;
  }
  for (i = 0; i < 17; i++) {
    for (j = 0; j < 17; j++) {
      switch (potision[i][j]) {
        case 0:
          std::wcout << ' ';
          break;
        case 1:  //房子
          std::wcout << '⌂';
          break;
        case 2:
          std::wcout << '\033[01;34m⌂\033[0m';  //餐馆
          break;
        case 3:
          std::wcout << '\033[01;31m⌂\033[0m';  //食客
          break;
        case 4:
          std::wcout << '⛹';  //骑手
          break;
        default:;
      }
    }
  }