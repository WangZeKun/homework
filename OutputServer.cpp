#include "OutputServer.h"

OutputServer::OutputServer() {
  OutFile = std::ofstream("./output.txt");

  CONSOLE_CURSOR_INFO cci;
  cci.bVisible = 0;
  cci.dwSize = sizeof(cci);
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

OutputServer::~OutputServer() {}

void OutputServer::PrintToConsole(const Model &m) {
  gotoxy(0,0);
  int i, j, position[17][17] = {0};
  Point point;
  for (i = 0; i < 17; i += 2) {
    for (j = 0; j < 17; j += 2) {
      position[i][j] = 1;
    }
  }
  for (size_t i = 0; i < m.riders.size(); i++) {
    for (auto it = m.riders[i].received_orders.begin();
         it != m.riders[i].received_orders.end(); it++) {
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
      switch (position[i][j]) {
        case 0:
          std::wcout << L"  ";
          break;
        case 1:  //房子
          std::wcout << L"⌂ ";
          break;
        case 2:
          std::wcout << L"\033[01;34m⌂ \033[0m";  //餐馆
          break;
        case 3:
          std::wcout << L"\033[01;31m⌂ \033[0m";  //食客
          break;
        case 4:
          std::wcout << L'⛹';  //骑手
          break;
        default:;
      }
    }
    std::wcout << std::endl;
  }

  std::wcout << L"时间：" << m.now() << "        " << std::endl;
  std::wcout << L"钱：" << m.money() << "        " << std::endl;
  std::wcout << L"接单数：" << m.num_sending() + m.num_finished() + m.num_outdate() << "        "
             << std::endl;
  std::wcout << L"超时数：" << m.num_outdate() << "        " << std::endl;
  std::wcout << L"完成数：" << m.num_finished() << "        " << std::endl;
}

void OutputServer::PrintToFile(const Model &m) {
  OutFile << "时间：" << m.now() << std::endl;
  OutFile << "钱：" << m.money() << std::endl;
  OutFile << "接单数：" << m.num_sending() + m.num_finished() + m.num_outdate() << std::endl;
  OutFile << "超时数：" << m.num_outdate() << std::endl;
  OutFile << "完成数：" << m.num_finished() << std::endl;
  for (size_t i = 0; i < m.riders.size(); i++) {
    auto point = m.riders[i].get_position();
    OutFile << "骑手" << i << "位置：" << point.x << " " << point.y
            << std::endl;
  }
}

void OutputServer::gotoxy(int x, int y) {
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {x, y});
}
