#include "BaseTime/TimerManager.h"
#include <iostream>
void foo() { std::cout << "foo" << std::endl; }
void bar(const std::string &name) { std::cout << "bar:" << name << std::endl; }
int main(int argc, char *argv[]) {

  // Timer t1(2);
  // t1.start(1000, foo);
  // Timer t2(4);
  // t2.start(1000, bar, "你好");
  // std::getchar();

  TimerManager mgr;
  mgr.schedule(1000, foo);
  mgr.schedule(1200, bar, "hello");
  while (true) {
    mgr.update();
  }
  return 0;
}
