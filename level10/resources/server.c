#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int sock;				 // my socket
	struct sockaddr_in sin;	 // struct containing technical data

	sin.sin_addr.s_addr = inet_addr("127.0.0.1");  // server's address
	sin.sin_family = AF_INET;					   // socket family
	sin.sin_port = htons(6969);					   // port we're listening on

	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1) {
		perror("[SERVER] Error: socket");
		return 1;
	}

	// Bind the socket
	if (bind(sock, (struct sockaddr *)&sin, sizeof(sin)) == -1) {
		perror("[SERVER] Error: bind");
		return 1;
	}

	// Start listening
	if (listen(sock, 1) == -1) {
		perror("[SERVER] Error: listen");
		return 1;
	}

	printf("[SERVER] Listening on 127.0.0.1:6969...\n");

	struct sockaddr_in csin;
	int val;
	int sizeof_csin = sizeof(csin);

	while (1) {
		printf("[SERVER] Waiting for a client connection...\n");
		val = accept(sock, (struct sockaddr *)&csin, &sizeof_csin);

		if (val < 0) {
			perror("[SERVER] Accept failed");
			continue;
		}

		printf("[SERVER] Connected to client socket %d\n", val);

		// Simple echo server
		char buffer[1024];
		ssize_t bytes_received;

		// Read data from client
		while ((bytes_received = recv(val, buffer, sizeof(buffer), 0)) > 0) {
			buffer[bytes_received] = '\0';	// Null-terminate string
			printf("[SERVER] Received: %s", buffer);
		}

		if (bytes_received == 0) {
			printf("[SERVER] Client disconnected\n");
		} else if (bytes_received < 0) {
			perror("[SERVER] Error receiving data");
		}

		// Send response to client
		char response[] = "Hello, client!\n";
		send(val, response, sizeof(response), 0);

		// close(val); // Close the client connection
	}

	close(sock);  // Close the server socket
	return 0;
}
