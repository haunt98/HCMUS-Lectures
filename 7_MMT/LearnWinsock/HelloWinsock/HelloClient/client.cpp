#include <WinSock2.h>
#include <stdio.h>
#include <string.h>
#include <ws2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")

#define MY_PORT "3030"
#define BUFLEN 512

int main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("usage: client hostname\n");
		exit(1);
	}

	int status;

	// Khoi tao winsock
	WSADATA var_WSADATA;
	status = WSAStartup(MAKEWORD(2, 2), &var_WSADATA);
	if (status != 0) {
		printf("WSAStartup failed with error %d\n", status);
		return 1;
	}

	// Tao addrinfo object
	addrinfo hints, *result, *p_addrinfo;
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	// Resolve server address and port
	status = getaddrinfo(argv[1], MY_PORT, &hints, &result);
	if (status != 0) {
		printf("getaddrinfo() failed with error %d\n", status);
		WSACleanup();
		return 1;
	}

	// Loop through all the resuls and connect the first
	SOCKET connect_SOCKET = INVALID_SOCKET;
	for (p_addrinfo = result; p_addrinfo != NULL;
	     p_addrinfo = p_addrinfo->ai_next) {
		connect_SOCKET =
		    socket(p_addrinfo->ai_family, p_addrinfo->ai_socktype,
			   p_addrinfo->ai_protocol);
		if (connect_SOCKET == INVALID_SOCKET) {
			continue;
		}
		status = connect(connect_SOCKET, p_addrinfo->ai_addr,
				 (int)p_addrinfo->ai_addrlen);
		if (status == SOCKET_ERROR) {
			closesocket(connect_SOCKET);
			continue;
		}
		break;
	}

	// done with result
	freeaddrinfo(result);

	// Chat
	char buf[BUFLEN];
	while (1) {
		printf("Enter send data: ");
		fgets(buf, BUFLEN, stdin);
		char *temp = NULL;
		strtok_s(buf, "\n", &temp);
		if (strcmp(buf, "exit") == 0) {
			printf("Close connection\n");
			break;
		}
		status = send(connect_SOCKET, buf, BUFLEN, 0);
		if (status == SOCKET_ERROR) {
			printf("send() error %d\n", WSAGetLastError());
			break;
		}
	}

	// Cleanup
	closesocket(connect_SOCKET);
	WSACleanup();
	return 0;
}