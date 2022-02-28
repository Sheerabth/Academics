import socket
import threading

account =  dict()

def withdraw(address, amount):
    if account[address] < amount:
        return -1
    
    account[address] = account[address] - amount

    return account[address]

def deposit(address, amount):
    account[address] = account[address] + amount

    return account[address]

def ClientHandler(lock, conn, address):
    print("Connection from: ", address)
    while True:
        data = conn.recv(1024).decode()
        action = data.split()
        message = ""
        if len(action) > 0:
            if action[0] == "deposit":
                lock.acquire()
                amount = float(action[1])
                response = deposit(address, amount)
                message = "Remaining Credit: " + str(response)
                lock.release()

            elif action[0] == "withdraw":
                lock.acquire()
                amount = float(action[1])
                response = withdraw(address, amount)
                if response == -1:
                    message = "Not enough credit"
                else:
                    message = "Remaining Credit: " + str(response)
                lock.release()
            
            elif action[0] == "exit":
                print("Disconnected: ", address)
                conn.close()
                break
        
            conn.send(message.encode())

def MyServer(host, port):
    server_socket = socket.socket()
    server_socket.bind((host, port))
    lock = threading.Lock()

    while True:
        try:
            server_socket.listen(2)
            conn, address = server_socket.accept()
            if address not in account:
                account[address] = 1000

            threading.Thread(target=ClientHandler, args=(lock, conn, address)).start()

        except KeyboardInterrupt:
            break

MyServer("localhost", 9999)