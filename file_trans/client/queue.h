#include "common.h"

template <typename T>
class Buffer
{
public:
	Buffer() : m_size(1) {}
	Buffer(s) : m_size(s) {}

	void add(T x);
	T remove();
private:
	std::mutex m_mtx;	//互斥锁
	std::condition_variable m_cond;	//条件变量
	std::deque<T> m_buffer; //缓冲区内容
	unsigned int m_size;
};