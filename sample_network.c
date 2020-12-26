#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>

int main(int argc, char **argv) {
  int sockfd;
  struct sockaddr_in client_addr;

  /* コマンド引数がひとつであることを確認 */
  if (argc != 3) {
    fprintf(stderr, "usage: %s <machine-name> <port>\n", argv[0]);
    exit(1);
  }

  /* ソケットを作成 */
  if ((sockfd = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
    perror("client: socket");
    exit(1);
  }

  /* client_addr構造体に接続するサーバのアドレス・ポート番号を指定 */
  bzero((char *)&client_addr, sizeof(client_addr));
  client_addr.sin_family = PF_INET;
  client_addr.sin_addr.s_addr = inet_addr(argv[1]);
  client_addr.sin_port = htons(atoi(argv[2]));

  /* ソケットをサーバーに接続 */
  if (connect(sockfd, (struct sockaddr *)&client_addr,
	      sizeof(client_addr)) < 0) {
    perror("client: connect");
    close(sockfd);
    exit(1);
  }

  /* ソケットをクローズ */
  close(sockfd);

  return 0;
}
