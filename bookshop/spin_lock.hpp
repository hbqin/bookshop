
#ifndef SPIN_LOCK_HPP
#	define SPIN_LOCK_HPP

#include <atomic>

class SpinLock final
{
private:
	using this_type = SpinLock;
	using atomic_type = std::atomic_flag;

	atomic_type m_lock{false};

public:
	SpinLock() = default;
	~SpinLock() = default;

	SpinLock(const this_type&) = delete;
	SpinLock& operator=(const this_type&) = delete;

	void lock() noexcept;
	bool try_lock() noexcept;
	void unlock() noexcept;
};

class SpinLockGuard final 
{
private:
	using this_type = SpinLockGuard;
	using spin_lock_type = SpinLock;

	spin_lock_type& m_lock;
public:
	SpinLockGuard(spin_lock_type& lock) noexcept;
	~SpinLockGuard() noexcept;

	SpinLockGuard(const this_type&) = delete;
	SpinLockGuard& operator=(const this_type) = delete;
};

#endif
