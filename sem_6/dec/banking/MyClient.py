import socket

def MyClient(host, port):
    client_socket = socket.socket()
    client_socket.connect((host, port))

    while True:
        message = input()
        client_socket.send(message.encode())

        if message == "exit":
            try:
                client_socket.close()
            finally:
                break
        
        response = client_socket.recv(1024).decode()
        print(response)

MyClient("localhost", 9999)
