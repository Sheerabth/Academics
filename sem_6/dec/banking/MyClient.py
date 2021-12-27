from ctypes import resize
from socket import socket

def MyClient(host, port):
    client_socket = socket.socket()
    client_socket.connect((host, port))

    while True:
        message = input()

        client_socket.send(message.encode())
        if message == exit:
            try:
                client_socket.close()
            except:
                break

        response = client_socket.recv(1024).decode()
        print(response)

if '__name__' == '__main__':
    MyClient("localhost", 9999)
