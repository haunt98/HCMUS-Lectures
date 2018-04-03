// CLIENT
#include <stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>

// linked Ws2_32.lib
#pragma comment(lib, "Ws2_32.lib")

#define DEFAULT_PORT "27015"
#define DEFAULT_BUFLEN 512

int main(int argc, char *argv[])
{
	// Validate the parameters
	if (argc != 2) {
		printf("usage: %s server-name\n", argv[0]);
		return 1;
	}

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

	/* address family	AF_INET6		IPv6
	 *					AF_INET			IPv4
	 * type				SOCK_STREAM		TCP
	 *					SOCK_DGRAM		UDP
	 * protocol			IPPROTO_TCP
	 *					IPPROTO_UDP
	 */
	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;

	// Resolve the server address and port
	iResult = getaddrinfo(argv[1], DEFAULT_PORT, &hints, &result);
	if (iResult != 0) {
		printf("getaddrinfo() failed with error: %d\n", iResult);
		WSACleanup();
		return 1;
	}
	// Create SOCKET object for Client to connect to Server
	SOCKET connect_SOCKET = INVALID_SOCKET;
	connect_SOCKET =
	    socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if (connect_SOCKET == INVALID_SOCKET) {
		printf("socket() failed with error: %ld\n", WSAGetLastError());
		freeaddrinfo(result);
		WSACleanup();
		return 1;
	}

	// Connect to server
	iResult =
	    connect(connect_SOCKET, result->ai_addr, (int)result->ai_addrlen);
	if (iResult == SOCKET_ERROR) {
		closesocket(connect_SOCKET);
		connect_SOCKET = INVALID_SOCKET;
	}

	// Should really try the next address returned by getaddrinfo
	// if the connect call failed
	// But for this simple example we just free the resources
	// returned by getaddrinfo and print an error message
	freeaddrinfo(result);

	if (connect_SOCKET == INVALID_SOCKET) {
		printf("Unable to connect to server!\n");
		WSACleanup();
		return 1;
	}

	// Sending and Receiving Data on the Client
	// use send and recv functions
	int recvbuflen = DEFAULT_BUFLEN;
	char recvbuf[DEFAULT_BUFLEN];
	char *sendbuf = "this is a test";

	// Send an initial buffer
	iResult = send(connect_SOCKET, sendbuf, (int)strlen(sendbuf), 0);
	if (iResult == SOCKET_ERROR) {
		printf("send() failed: %d\n", WSAGetLastError());
		closesocket(connect_SOCKET);
		WSACleanup();
		return 1;
	}
	printf("Bytes Sent: %ld\n", iResult);

	// Shutdown the connection for sending since no more data will be sent
	// the client can still use the ConnectSocket for receiving data
	//		SD_SEND
	//		SD_RECEIVE
	//		SD_BOTH
	iResult = shutdown(connect_SOCKET, SD_SEND);
	if (iResult == SOCKET_ERROR) {
		printf("shutdown() failed with error: %d\n", WSAGetLastError());
		closesocket(connect_SOCKET);
		WSACleanup();
		return 1;
	}

	// Receive data until the server closes the connection
	do {
		iResult = recv(connect_SOCKET, recvbuf, recvbuflen, 0);
		if (iResult > 0)
			printf("Bytes received: %d\n", iResult);
		else if (iResult == 0)
			printf("Connection closed\n");
		else
			printf("recv() failed with error: %d\n",
			       WSAGetLastError());
	} while (iResult > 0);

	// Cleanup
	closesocket(connect_SOCKET);
	WSACleanup();
	return 0;
}