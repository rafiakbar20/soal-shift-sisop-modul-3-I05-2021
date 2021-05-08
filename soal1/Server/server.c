//Server
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
//#include <boost/filesystem.hpp>

#define PORT 8080
int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread, valread_2, valread_3;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Hello from server";
	char *tambah = "tambah";
	char *kurang = "kurang";
	char *cek = "cek";
	char *registrasi_berhasil = "Registrasi_berhasil";
	char *login_berhasil = "Login berhasil";
	char *pesan_cek= "Jumlah angka sekarang adalah";
	char *pesan_null = "command tidak sesuai";
	char *value;
	int var = 5;
	char *exit_2 = "Exit";

	FILE *register_id_fptr;
	FILE *register_password_fptr;
	FILE *login_fptr;
	FILE *login_id_fptr;
	FILE *login_password_fptr;

	char *registers = "register";
	char *login = "login";
	char *add = "add";
	char *download = "download";
	char *delete = "delete";
	char *see = "see";
	char *find = "find";

	char *register_id;
	char *register_password;
	char *login_id;
	char *login_password;
	char *hold;
	char *hold_2;

	char *add_filename;
	char *download_filename;
	char *delete_filename;
	char *see_filename;
	char *find_filename;
	char *publisher;
	char *publication_year;
	char *filepath;

      
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
      
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
      
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

//listen()
//while (1) {
//    newsockfd = accept();
//    pid = fork();
//    if (pid == 0) { // client process
//        close(sockfd);
//        // do some process - read and write
//        exit(0);
//    } else { // parent process
//        close(newsockfd);
//    }
//}

    //valread = read( new_socket , buffer, 1024);
    //printf("%s\n",buffer );
    //send(new_socket , hello , strlen(hello) , 0 );
    //printf("Hello message sent\n");
	while(1){
		//boost::filesystem::create_directories("/home/alvancho/Documents/IO5/Shift_3/Soal_1/Server");
		//boost::filesystem::path p("/home/alvancho/Documents/IO5/Shift_3/Soal_1/Server");
		//boost::filesystem::create_directory(p);
		valread = read (new_socket , buffer, 1024);
		//printf("test");
		if(strcmp(buffer,registers)==0){
			valread_2 = read (new_socket , buffer, 1024);
			register_id_fptr = fopen("/home/alvancho/Documents/IO5/Shift_3/Soal_1/Server/account.txt","a");
			fprintf(register_id_fptr,"%s:",buffer);
			fclose(register_id_fptr);

			valread_3 = read (new_socket , buffer, 1024);
			register_password_fptr = fopen("/home/alvancho/Documents/IO5/Shift_3/Soal_1/Server/account.txt","a");
			fprintf(register_password_fptr,"%s\n",buffer);
			fclose(register_password_fptr);

			send(new_socket , registrasi_berhasil , strlen(registrasi_berhasil) , 0 );
		}
		else if(strcmp(buffer,login)==0){
			valread_2 = read (new_socket , buffer, 1024);
			register_id_fptr = fopen("/home/alvancho/Documents/IO5/Shift_3/Soal_1/Server/account.txt","r");
			rewind(login_fptr);
			while(buffer!=hold){
				fscanf(login_fptr,"%[^\n]:",hold);
				fseek(login_fptr, strlen(buffer)+1, SEEK_SET );
			}
			fclose(login_fptr);

			//valread_3 = read (new_socket , buffer, 1024);
			//register_password_fptr = fopen("/home/alvancho/Documents/IO5/Shift_3/Soal_1/Server/account.txt","a");
			//rewind(register_password_fptr);
			//fscanf(register_password_fptr,"%s\n",hold_2;
			//fclose(register_password_fptr);

			send(new_socket , login_berhasil , strlen(login_berhasil) , 0 );
		}
		else if(strcmp(buffer,download)==0){
			//printf("Please enter the filename (ex:TEMPfile.pdf): \n");
			//scanf("%s", find_filename);
		}
		else if(strcmp(buffer,delete)==0){
			//printf("Please enter the filename (ex:TEMPfile.pdf): \n");
			//scanf("%s", find_filename);
		}
		else if(strcmp(buffer,see)==0){
			//printf("Please enter the filename (ex:TEMPfile.pdf): \n");
			//scanf("%s", find_filename);
		}
		else if(strcmp(buffer,find)==0){
			//printf("Please enter the filename (ex:TEMPfile.pdf): \n");
			//scanf("%s", find_filename);
		}
//		else if(strcmp(buffer,cek)==0){
//			sprintf(value, "%d", var);
//			send(new_socket , value , strlen(value) , 0 );
//			printf("%s",value);
//		}
//		else{
//			send(new_socket , pesan_null , strlen(pesan_null) , 0 );
//		}
		memset(buffer,0,1024);
	}
    return 0;
}
