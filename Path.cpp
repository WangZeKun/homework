#include "Path.h"


Path::Path(Point start, std::vector<Point> path):start(start),path(path),__dis__(-1) {}

Path::~Path() {}

int Path::dis() {
  if (__dis__ != -1) {
    return __dis__;  
	}
  int len = 0;
  for (size_t i = 0; i < path.size(); i++) {
    len += Point::get_dis(start, path[i]);
    start = path[i];
  }
  __dis__ = len;
  return len;
}

bool Path::check() {
  for (size_t i = 0; i < path.size(); i++) {
    if (path[i].type == FROM) {
      isSending.insert(path[i].order_id);
    } else {
      if (isSending.find(path[i].order_id) == isSending.end()) return false;
		}
  }
  return true;
}
