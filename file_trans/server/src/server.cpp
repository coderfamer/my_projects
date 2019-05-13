#include "server.h"

FileServer::FileServer()
{
	init_socket();
	bind_socket();
}

FileServer::~FileServer()
{
}



bool FileServer::init_socket()
{
	

	//memset(&serv_addr, 0, sizeof(serv_addr));
	bzero(&serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = port;
	serv_addr.sin_addr.s_addr = htons(INADDR_ANY);

	if ((serv_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		perror("Create socket failed!!");
		exit(1);
	}
	return true;
}

bool FileServer::bind_socket()
{
	int bd = bind(serv_fd, (const sockaddr *)&serv_fd, sizeof(serv_fd));
	if (bd == -1){
		perror("bind socket error");
		exit(1);
	}

	int listenfd = listen(serv_fd, 100);
	if (listenfd == -1){
		perror("listen socket error");
		exit(1);
	}
}

bool FileServer::do_recieve()
{
	struct sockaddr_in cli_addr;
	socklen_t addrlen = sizeof(cli_addr);
	int connfd;

	while (1) { 
		char filename[BUFFER_SIZE] = { 0 };

		connfd = accept(serv_fd, (struct sockaddr *)&cli_addr, &addrlen);
		if (connfd == -1){
			perror("connect error!!");
			exit(1);
		}
		close(serv_fd);

		if (recv(connfd, filename, BUFFER_SIZE, 0) == -1){
			perror("Can't receive filename");
			exit(1);
		}

		FILE *fp = fopen(filename, "wb");
		if (fp == NULL){
			perror("Can't open file");
			exit(1);
		}

		char 
	}
}



