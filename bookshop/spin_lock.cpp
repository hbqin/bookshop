
#include<thread>
#include "spin_lock.hpp"

void SpinLock::lock() noexcept
{
	for (;;) {
		if (!m_lock.test_and_set()) {
			return;
		}
		std::this_thread::yield();
	}
}

bool SpinLock::try_lock() noexcept
{
	return !m_lock.test_and_set();
}

void SpinLock::unlock() noexcept
{
	m_lock.clear();
}

SpinLockGuard::SpinLockGuard(spin_lock_type& lock) noexcept : m_lock(lock)
{
	m_lock.lock();
}

SpinLockGuard::~SpinLockGuard() noexcept
{
	m_lock.unlock();
}
