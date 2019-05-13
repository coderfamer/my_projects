#include "queue.h"


template <typename T>
void Buffer<T>::add(T x)
{
	while (true) {
		std::unique_lock<std::mutex> locker(m_mtx);
		m_cond.wait(locker, [this](){
			return m_buffer.size() < m_size;
		});

		m_buffer.push_back(x);
		locker.unlock();
		m_cond.notify_all();

		return;
	}
}

//T remove();
template <typename T>
T Buffer<T>::remove()
{
	
}