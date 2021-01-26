import socket

if __name__ == "__main__":

    host = '127.0.0.1'
    port = 6969

    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((host, port))
        s.sendall(b'Hello, world')
        data = s.recv(1024)

    print('Received', repr(data))
