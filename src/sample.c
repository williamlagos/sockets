#include "utils.h"
#include "sockets.h"
#include "structs.h"

int main(int argc, char** argv)
{
	/*Header* head;
	SOCKET socket;
	char* buffer = (char*) malloc(256);
	IPV4_Address address,client_address;
	if(argc < 3) error("Uso: client hostname porta\n");
	socket = create_socket(IPV4,TCP,DEFAULT);
	address = ipv4_address(argv[1],atoi(argv[2]));
	client_address = ipv4_address("",atoi(argv[2]));
	bind_socket(socket,(Address*)&client_address);
	
	buffer = read_input(256);
	connect_socket(socket,(Address*)&address);
	write(socket,buffer,255);
	read(socket,buffer,255);
	printf("Recebido:%s",buffer);

	head = (Header*) malloc(sizeof(Header));
	send_socket(&socket,(Address*)&address,(Header*)head);
	recv_socket(&socket,(Address*)&address,(Header*)head,256);
	printf("Recebido: %c\n",head->opcode);
	close(socket);*/

	SOCKET socket,newsocket;
	void* buffer;
	Header* head;
	IPV4_Address address;
	if(argc < 2) error("Uso: server porta\n");
	socket = create_socket(IPV4,TCP,DEFAULT);
	address = ipv4_address("",atoi(argv[1]));
	bind_socket(socket,(Address*)&address);
	buffer = (void*) malloc(256);
	/*while(1){
		recv_socket(&socket,(Address*)&address,buffer,256);
		head = (Header*) buffer;
		printf("Mensagem lida: %c\n",head->opcode);
		send_socket(&socket,(Address*)&address,buffer);
	}*/
	newsocket = listen_socket(
	socket,(struct sockaddr*)&address);
	read(newsocket,buffer,255);
	write(newsocket,buffer,255);
	close(newsocket);
	close(socket);
	return 0;
}
