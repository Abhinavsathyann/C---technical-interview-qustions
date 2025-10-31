// Note: works only on systems with networking support (e.g., Linux).
// Compile server: g++ server.cpp -o server
// Compile client: g++ client.cpp -o client

// server.cpp
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
using namespace std;

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1, addrlen = sizeof(address);
    char buffer[1024] = {0};
    string msg;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);
    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 3);
    cout << "Server waiting for connection...\n";
    new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
    cout << "Client connected.\n";
    while (true) {
        memset(buffer, 0, sizeof(buffer));
        read(new_socket, buffer, 1024);
        cout << "Client: " << buffer << endl;
        cout << "You: "; getline(cin, msg);
        send(new_socket, msg.c_str(), msg.size(), 0);
        if (msg == "exit") break;
    }
    close(server_fd);
}

// client.cpp
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
using namespace std;

int main() {
    int sock = 0; struct sockaddr_in serv_addr;
    char buffer[1024] = {0};
    string msg;
    sock = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);
    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    while (true) {
        cout << "You: "; getline(cin, msg);
        send(sock, msg.c_str(), msg.size(), 0);
        if (msg == "exit") break;
        memset(buffer, 0, sizeof(buffer));
        read(sock, buffer, 1024);
        cout << "Server: " << buffer << endl;
    }
    close(sock);
}
