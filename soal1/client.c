//Client
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#define PORT 8080
  
int main(int argc, char const *argv[]) {
    struct sockaddr_in address;
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
	char *hello = "Hello from client";
	char *command;
	char buffer[1024] = {0};

	char *registers = "register";
	char *login = "login";
	char *exit = "Exit";
	char *add = "add";
	char *download = "download";
	char *delete = "delete";
	char *see = "see";
	char *find = "find";

	FILE *register_id_fptr;
	FILE *register_password_fptr;
	FILE *login_id_fptr;
	FILE *login_password_fptr;
	char *register_id;
	char *register_password;
	char *login_id_password;
	char *login_id;
	char *login_password;

	char *add_filename;
	char *download_filename;
	char *delete_filename;
	char *see_filename;
	char *find_filename;
	char *publisher;
	char *publication_year;
	char *filepath;


    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }
  
    memset(&serv_addr, '0', sizeof(serv_addr));
  
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
      
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
  
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    //send(sock , hello , strlen(hello) , 0 );
    //printf("Hello message sent\n");
    //valread = read( sock , buffer, 1024);
    //printf("%s\n",buffer );
	while(1){
		printf("Register/Login?\n");
		scanf("%s", command);
		send(sock , command , strlen(command) , 0 );
		if(strcmp(command,registers)==0){
			//append ID
			printf("Input your ID:\n");	
			scanf("%s", register_id);
			send(sock , register_id , strlen(register_id) , 0 );

			//append Password
			printf("Input your Password:\n");	
			scanf("%s", register_password);	
			send(sock , register_password , strlen(register_password) , 0 );

		}
		else if(strcmp(command,login)==0){
			printf("Input your ID and Password with the format(id:password):\n");
			scanf("%s", login_id_password);
			send(sock , login_id_password , strlen(login_id_password) , 0 );

			//printf("Input your Password:\n");
			//scanf("%s", login_password);
			//send(sock , login_password , strlen(login_password) , 0 );


		}
		else if(strcmp(command,add)==0){
			printf("Please enter the filename (ex:TEMPfile.pdf): \n");
			printf("Please input this required information\n");
			printf("Publisher: \nPublication year: \nFilepath: \n");
			scanf("%s", filename);
			//send(sock , filename , strlen(filename) , 0 );
			scanf("%s %s %s", publisher,publication_year,filepath);
			//send(sock , publisher , strlen(publisher) , 0 );
			//send(sock , publication_year , strlen(publication_year) , 0 );
			//send(sock , filepath , strlen(filepath) , 0 );
		}
		else if(strcmp(command,download)==0){
			printf("Please enter the filename (ex:TEMPfile.pdf): \n");
			//scanf("%s", download_filename);
		}
		else if(strcmp(command,delete)==0){
			printf("Please enter the filename (ex:TEMPfile.pdf): \n");
			//scanf("%s", delete_filename);
		}
		else if(strcmp(command,see)==0){
			printf("Please enter the filename (ex:TEMPfile.pdf): \n");
			//scanf("%s", see_filename);
		}
		else if(strcmp(command,find)==0){
			printf("Please enter the filename (ex:TEMPfile.pdf): \n");
			//scanf("%s", find_filename);
		}
		valread = read (sock, buffer, 1024);
		printf("%s\n",buffer);
		memset(buffer,0,1024);  
	}

    return 0;
}
