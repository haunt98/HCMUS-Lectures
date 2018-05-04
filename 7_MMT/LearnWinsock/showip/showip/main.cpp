#include <stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")

int main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("usage: showip www.example.com\n");
		return 0;
	}

	WSADATA var_WSADATA;
	int status;
	// Khoi tao Winsock phien ban 2.2
	status = WSAStartup(MAKEWORD(2, 2), &var_WSADATA);
	if (status != 0) {
		printf("WSAStartup() failed with error: %d\n", status);
		WSACleanup();
		return 1;
	}

	// Who am I
	char hostname[100];
	status = gethostname(hostname, 100);
	if (status != 0) {
		printf("gethostname() failed with error %d\n",
		       WSAGetLastError());
		WSACleanup();
		return 0;
	}
	printf("I am %s\n", hostname);

	// Create addrinfo object
	struct addrinfo *result, hints;
	memset(&hints, 0, sizeof(hints)); // make sure struct is empty
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	status = getaddrinfo(argv[1], NULL, &hints, &result);
	if (status != 0) {
		printf("getaddrinfo() failed with error: %d\n", status);
		WSACleanup();
		return 1;
	}

	// Show IP result hold
	struct addrinfo *p;
	for (p = result; p != NULL; p = p->ai_next) {
		if (p->ai_family == AF_INET) {
			char ip4_str[INET_ADDRSTRLEN];
			struct sockaddr_in *ipv4 =
			    (struct sockaddr_in *)p->ai_addr;
			void *addr = &(ipv4->sin_addr);
			inet_ntop(p->ai_family, addr, ip4_str, INET_ADDRSTRLEN);
			printf("IPv4 %s\n", ip4_str);
		} else {
			char ip6_str[INET6_ADDRSTRLEN];
			struct sockaddr_in6 *ipv6 =
			    (struct sockaddr_in6 *)p->ai_addr;
			void *addr = &(ipv6->sin6_addr);
			inet_ntop(p->ai_family, addr, ip6_str,
				  INET6_ADDRSTRLEN);
			printf("IPv6 %s\n", ip6_str);
		}
	}

	// Cleanup
	freeaddrinfo(result);
	WSACleanup();
	return 0;
}