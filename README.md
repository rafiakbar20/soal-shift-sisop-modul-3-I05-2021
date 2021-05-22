# soal-shift-sisop-modul-3-I05-2021
Repository for Shift 3 Lab Work

# SOAL 1
Keverk is a famous ambitious person in his colleagues. Before he became the head of
department in HTMC, he has done a project which tells him to make a book server
database. This project is required, so that it could be used by the app owner and is
expected from the users.
In this project, Keverk is asked to:

# A.)
When a client is connected to the server, there are two main options. They are
register and login. If the user has chosen the register option, the client will prompt
an id and password to be sent to the server. Users can also login to the server.
Login is successful if the id and the password sent to the server matched with
one of the accounts listed on the server application. This system can accepts
multiple connections at once. A connection is counted when a client application is
connected to the server. If there are 2 connections or more then we must wait for
the first client to exit the application to be able to login and use the application.
Keverk wanted the file that stores the id and password named account.txt with
the following format:

# account.txt
```
id:password
id2:password2
```

# B.)
The system has a database on a file named files.tsv. The content of the file is
the file path on the server, publisher, and the year of publication. For every
insertion and removal of a file in the folder FILES on the server, the file files.tsv
will be affected. Folder FILES are made, automatically when the server is started

# C.)
Not only that, Keverk is asked to make a feature such that clients are able to
insert new files to the server. FILES directory have a structure as follows :

Direktori FILES

```
File1.extension
File2.extension
```

First, the client send input to the server with the structure as follows:
Client command example :

```
add
```

Client Console Output:

```
Publisher:
Publication year:
Filepath:
```

Then, we can fill the book’s data (please note that Filepath is the path to the file
that will be sent to the server). Then the client will send the file to the server via
socket. When a file is received at the server, a new row containing new data of
the book is then added to the files.tsv.

# D.)
Clients can also download files that exist in the FILES folder in the server, then
the system must send the following file to the client. Server must check from
files.tsv to check if the file requested is valid. If it’s not valid, the system sends an
error message back to the client. If valid, the following file is then sent to the
client in the client folder.

Client command example

```
download TEMPfile.pdf
```

# E.)
After that, the client can also delete file that is stored on the server. But keverk is
afraid that the file that is going to be deleted is an important file, so instead of
deleting the file, the program just changes its name to ‘old-FileName.extension’.
When the filename is changed, the row of the file in files.tsv will be deleted.

Client command example:

```
delete TEMPfile.pdf
```

# F.)
Clients can see all the contents of files.tsv by calling the see command. Output
of the command will follow this format.

Client command example :

```
see
```

Client Console Output:

```
Name:
Publisher:
Publication year:
File extension :
Filepath :
Name:
Publisher:
Publication Year:
File extension:
Filepath :
```

# G.)
The client application can also do search by using the find command and a
string. It will output the same format as number 6.

Client command example:

```
find TEMP
```

# H.)
Keverk is cautious on insertion and removal of files on the server, so he made a
log file for the server named running.log. The content of the log file is following
this format

running.log
```
Tambah : File1.extension (id:pass)
Hapus : File2.extension (id:pass)
```

But keverk has not yet understood the client and server system. Help Keverk to finish
this project!

Note:
- It is not allowed to use system() dan execv(). Please do the task fully using
thread and socket programming.
- To download and upload, please use any text file with extension. The content of
the file can be anything. (Please don’t use an empty file) and the accepted
requirement is trial with the minimum of 5 data.

Directory Structure:
```
├── Client
│ ├── client.c
│ ├── File2.extension
│ └── File1.extension
└── Server
  ├── account.txt
  ├── files.tsv
  ├── server.c
  ├── running.log
  └── FILES
    ├── File2.extension
    └── File1.extension
```

# SOLUTION

Here are the libraries used to solve this problem:

#include <stdio.h> = for standard input-output

#include <sys/socket.h> = to run socket

#include <stdlib.h> = for general functions

#include <netinet/in.h> = for internet domain addresses

#include <string.h> = to perform string manipulation, for example strcmp ()

#include <errno.h> = to give additional errors to the system

#include <unistd.h> = to fork a system call ()

#include <arpa/inet.h> = for internet operations

#include <sys/types.h> = for data types

#include <sys/stat.h> = for data returned by the stat() function

```
#define PORT 8080
#define SIZE 1024
```
Define server port and SIZE for later usse

# A.)

Source Code

*Server
```

```

*Client
```

```

Explanation

Screenshot

# B.)

Source Code

*Server
```

```

*Client
```

```

Explanation

Screenshot

# C.)

Source Code

*Server
```

```

*Client
```

```

Explanation

Screenshot

# D.)

Source Code

*Server
```

```

*Client
```

```

Explanation

Screenshot

# E.)

Source Code

*Server
```

```

*Client
```

```

Explanation

Screenshot

# F.)

Source Code

*Server
```

```

*Client
```

```

Explanation

Screenshot

# G.)

Source Code

*Server
```

```

*Client
```

```

Explanation

Screenshot

# H.)

Source Code

*Server
```

```

*Client
```

```

Explanation

Screenshot

Problems


