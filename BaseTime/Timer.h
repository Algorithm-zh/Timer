#pragma once

#include <functional>
class Timer {

public:
  friend class TimerManager;
  Timer(int repeat = -1);
  ~Timer();
  template <typename F, typename... Args>
  void callback(int milliseconds, F &&func, Args &&...args);
  void on_timer();

private:
  static int64_t now();

private:
  int64_t m_time; // 定时器触发的时间点，单位毫秒
  std::function<void()> m_func;
  int m_period;
  int m_repeat;
};

template <typename F, typename... Args>
void Timer::callback(int milliseconds, F &&func, Args &&...args) {
  m_period = milliseconds;
  m_func = std::bind(std::forward<F>(func), std::forward<Args>(args)...);
}
