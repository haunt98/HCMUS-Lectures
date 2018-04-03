#include <WinSock2.h>
#include <stdio.h>
#include <ws2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")

#define MY_PORT "3030"
#define BUFLEN 512

int main(void)
{
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
	hints.ai_flags = AI_PASSIVE;

	// Get local address and port to be used by server
	status = getaddrinfo(NULL, MY_PORT, &hints, &result);
	if (status != 0) {
		printf("getaddrinfo() failed with error %d\n", status);
		WSACleanup();
		return 1;
	}

	// Loop through all the resuls
	SOCKET listen_SOCKET = INVALID_SOCKET;
	for (p_addrinfo = result; p_addrinfo != NULL;
	     p_addrinfo = p_addrinfo->ai_next) {
		listen_SOCKET =
		    socket(p_addrinfo->ai_family, p_addrinfo->ai_socktype,
			   p_addrinfo->ai_protocol);
		if (listen_SOCKET == INVALID_SOCKET) {
			continue;
		}
		status = bind(listen_SOCKET, p_addrinfo->ai_addr,
			      (int)p_addrinfo->ai_addrlen);
		if (status == SOCKET_ERROR) {
			closesocket(listen_SOCKET);
			continue;
		}
		break;
	}

	// done with result
	freeaddrinfo(result);

	// Listen on a socket
	status = listen(listen_SOCKET, SOMAXCONN);
	if (status == SOCKET_ERROR) {
		printf("listen() failed with error: %d\n", WSAGetLastError());
		closesocket(listen_SOCKET);
		WSACleanup();
		return 1;
	}

	// Accept on a socket
	SOCKET client_SOCKET = INVALID_SOCKET;
	client_SOCKET = accept(listen_SOCKET, NULL, NULL);
	if (client_SOCKET == INVALID_SOCKET) {
		printf("accept() failed with error %d\n", WSAGetLastError());
		closesocket(listen_SOCKET);
		WSACleanup();
		return 1;
	} else {
		printf("Client connected\n");
	}

	// done with listen_SOCKET
	closesocket(listen_SOCKET);

	// Chat
	char buf[BUFLEN];
	while (1) {
		status = recv(client_SOCKET, buf, BUFLEN, 0);
		if (status == SOCKET_ERROR) {
			printf("recv() error %d\n", WSAGetLastError());
			break;
		} else if (status == 0) {
			printf("Connection closed\n");
			break;
		} else {
			printf("Receive data: %s\n", buf);
		}
	}

	// Cleanup
	closesocket(client_SOCKET);
	WSACleanup();
	return 0;
}