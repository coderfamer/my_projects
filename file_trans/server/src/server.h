#include "common.h"

class FileServer
{
public:
	FileServer() : port(123456);
	bool init_socket();
	bool bind_socket();
	bool do_recieve();
	~FileServer();
protected:
private:
	struct sockaddr_in serv_addr;
	int port;
	int serv_fd;
};