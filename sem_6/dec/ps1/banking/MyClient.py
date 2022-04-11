import socket


def MyClient(host, port):
    client_socket = socket.socket()
    client_socket.connect((host, port))

    client_socket.settimeout(2)
    while True:
        message = input()
        client_socket.send(message.encode())

        if message == "exit":
            try:
                client_socket.close()
            finally:
                break

        try:
            response = client_socket.recv(1024).decode()

        except TimeoutError:
            continue
        print(response)


MyClient("localhost", 9999)
