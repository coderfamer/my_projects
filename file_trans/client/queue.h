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
	std::mutex m_mtx;	//������
	std::condition_variable m_cond;	//��������
	std::deque<T> m_buffer; //����������
	unsigned int m_size;
};