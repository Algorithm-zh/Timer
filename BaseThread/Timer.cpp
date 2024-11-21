#include "Timer.h"
Timer::Timer(int repeat) : m_active(false), m_period(0), m_repeat(repeat) {}
Timer::~Timer() { stop(); }

void Timer::stop() { m_active.store(false); }
