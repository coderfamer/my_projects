#include <iostream>
#include <arpa/inet.h>
#include <netdb.h>
#include <cstring>
#include <fcntl.h>
#include <netinet/in.h>
#include <pthread.h>
#include <cstdlib>
#include <unistd.h>
#include <cstdio>

#ifdef WIN32
#include <winsock2.h>
#include <windows.h>
#else
#include <sys/socket.h>
#endif


#define portnum 12345
#define FILE_SIZE 500
#define BUFFER_SIZE 4096
#define MAX_LINE 4096