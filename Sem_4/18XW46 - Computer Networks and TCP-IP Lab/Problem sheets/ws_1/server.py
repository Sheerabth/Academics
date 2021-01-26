import socket

if __name__ == "__main__":
    host = "localhost"
    port = 6969
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.bind((host, port))
        s.listen()
        print("Listening to port 6969")
        conn, addr = s.accept()
        with conn:
            print("connected by ", addr)
            while True:
                data = conn.recv(1024)
                if not data:
                    break
                conn.sendall(data)