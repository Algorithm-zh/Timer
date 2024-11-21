#include "Timer.h"
#include <chrono>

Timer::Timer(int repeat) : m_repeat(repeat), m_period(0) { m_time = now(); }
Timer::~Timer() {}

int64_t Timer::now() {
  // 获取当前时间戳
  auto now = std::chrono::system_clock::now();

  // 将时间转换为毫秒数
  auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
  return now_ms.time_since_epoch().count();
}

void Timer::on_timer() {
  if (!m_func || m_repeat == 0) {
    return;
  }
  m_func();
  m_time += m_period;
  if (m_repeat > 0) {
    m_repeat--;
  }
}
