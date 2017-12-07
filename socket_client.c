#include <arpa/inet.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  char fname[50], buffer[1025];
  int sockfd, n;
  struct sockaddr_in address;

  address.sin_family = AF_INET;
  address.sin_port = htons(15000);
  address.sin_addr.s_addr = inet_addr("127.0.0.1");

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  connect(sockfd, (struct sockaddr *)&address, sizeof(address));

  printf("Enter a filename: ");
  scanf("%s", fname);

  printf("Sending request... \n");
  send(sockfd, fname, sizeof(fname), 0); // send a message on a socket

  printf("Recieved response: \n");
  while ((n = recv(sockfd, buffer, sizeof(buffer), 0)) > 0)
    write(1, buffer, n);

  return 0;
}