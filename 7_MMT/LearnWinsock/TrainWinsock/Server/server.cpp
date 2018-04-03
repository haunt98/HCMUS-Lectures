// SERVER
#include <stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>

// linked Ws2_32.lib
#pragma comment(lib, "Ws2_32.lib")

#define DEFAULT_PORT "27015"
#define DEFAULT_BUFLEN 512

int main(void)
{
	WSADATA var_WSADATA;
	int iResult;

	// Khoi tao Winsock phien ban 2.2
	iResult = WSAStartup(MAKEWORD(2, 2), &var_WSADATA);
	if (iResult != 0) {
		printf("WSAStartup() failed with error: %d\n", iResult);
		WSACleanup();
		return 1;
	}
	// Declare addrinfo object
	struct addrinfo *result = NULL, hints;
	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	// Resolve the local address and port to be used by the server
	iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
	if (iResult != 0) {
		printf("getaddrinfo() failed with error: %d\n", iResult);
		WSACleanup();
		return 1;
	}

	// Create SOCKET object for Server to listen to Client
	SOCKET listen_SOCKET = INVALID_SOCKET;
	listen_SOCKET =
	    socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if (listen_SOCKET == INVALID_SOCKET) {
		printf("socket() failed with error: %ld\n", WSAGetLastError());
		freeaddrinfo(result);
		WSACleanup();
		return 1;
	}

	// Setup the TCP listening socket
	iResult = bind(listen_SOCKET, result->ai_addr, (int)result->ai_addrlen);
	if (iResult == SOCKET_ERROR) {
		printf("bind() failed with error: %d\n", WSAGetLastError());
		freeaddrinfo(result);
		closesocket(listen_SOCKET);
		WSACleanup();
		return 1;
	}

	// No longer need result
	freeaddrinfo(result);

	// Listen on a socket
	// SOMAXCONN maximum reasonable number of pending connections
	iResult = listen(listen_SOCKET, SOMAXCONN);
	if (iResult == SOCKET_ERROR) {
		printf("listen() failed with error: %ld\n", WSAGetLastError());
		closesocket(listen_SOCKET);
		WSACleanup();
		return 1;
	}

	// Accept a connection
	SOCKET client_SOCKET = INVALID_SOCKET;
	client_SOCKET = accept(listen_SOCKET, NULL, NULL);
	if (client_SOCKET == INVALID_SOCKET) {
		printf("accept() failed with error: %d\n", WSAGetLastError());
		closesocket(listen_SOCKET);
		WSACleanup();
		return 1;
	}
	// No longer need listen socket
	// now we have client_SOCKET
	closesocket(listen_SOCKET);

	// Receiving and Sending Data on the Server
	int recvbuflen = DEFAULT_BUFLEN;
	char recvbuf[DEFAULT_BUFLEN];
	int iSendResult;

	// Receive until the peer shuts down the connection
	do {
		iResult = recv(client_SOCKET, recvbuf, recvbuflen, 0);
		if (iResult > 0) {
			printf("Bytes received: %d\n", iResult);
			// Echo the buffer back to the sender
			iSendResult = send(client_SOCKET, recvbuf, iResult, 0);
			if (iSendResult == SOCKET_ERROR) {
				printf("send() failed with error: %d\n",
				       WSAGetLastError());
				closesocket(client_SOCKET);
				WSACleanup();
				return 1;
			}
			printf("Bytes sent: %d\n", iSendResult);
		} else if (iResult == 0)
			printf("Connection closing...\n");
		else {
			printf("recv() failed with error: %d\n",
			       WSAGetLastError());
			closesocket(client_SOCKET);
			WSACleanup();
			return 1;
		}
	} while (iResult > 0);

	// Shutdown the send data
	iResult = shutdown(client_SOCKET, SD_SEND);
	if (iResult == SOCKET_ERROR) {
		printf("shutdown failed: %d\n", WSAGetLastError());
		closesocket(client_SOCKET);
		WSACleanup();
		return 1;
	}

	// Cleanup
	closesocket(listen_SOCKET);
	WSACleanup();
	return 0;
}