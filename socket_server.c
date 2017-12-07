#include <arpa/inet.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
  char fname[50], buffer[1025];
  int sockfd, new_socket, file, n;
  struct sockaddr_in address;

  address.sin_family = AF_INET;         // IPv4
  address.sin_port = htons(15000);      // Port
  address.sin_addr.s_addr = INADDR_ANY; //(Localhost)

  printf("Waiting for request... \n");

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  bind(sockfd, (struct sockaddr *)&address, sizeof(address));
  listen(sockfd, 3);

  new_socket = accept(sockfd, (struct sockaddr *)NULL, NULL);
  recv(new_socket, fname, sizeof(fname), 0);
  printf("Received request for: %s \n", fname);
  file = open(fname, O_RDONLY);
  if (file < 0)
    send(new_socket, "File not found. \n", 18, 0);
  else
    while ((n = read(file, buffer, sizeof(buffer))) > 0)
      send(new_socket, buffer, n, 0);
  printf("Response sent. \n");
  close(file);
  return 0;
}