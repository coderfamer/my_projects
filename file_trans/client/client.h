#include "common.h"
#include "client.h"
#include "queue.h"

template <typename T>
class FileClient
{

public:

private:
	Buffer<T> *m_buf;
	std::string m_id;
};