/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package sem_6.dec.socket.noauth;

import java.net.*;
import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author 19pw33
 */

class ClientList {
    public static List<Socket> clientList = new ArrayList<>();
}

class ClientHandler implements Runnable {
    private DataInputStream in = null;
    private Socket socket = null;
    
    public ClientHandler(Socket socket) {
        this.socket = socket;
    }
    
    @Override
    public void run() {
        try {
            for(Socket clientSocket: ClientList.clientList) {
                if (!clientSocket.equals(this.socket)) {
                    DataOutputStream out = new DataOutputStream(clientSocket.getOutputStream());
                    out.writeUTF(socket + " has joined the chat");
                }
//                          out.close();
            }
            in = new DataInputStream(new BufferedInputStream(socket.getInputStream()));
            String line = "";
            
            while (!line.equals("EXIT")) {
                try {
                    line = in.readUTF();
                    if (line.equals("EXIT")) {
                        ClientList.clientList.remove(socket);
                        break;
                    }
                    System.out.println("Message sent by " + socket + ": " + line);
                    for(Socket clientSocket: ClientList.clientList) {
                        if (!clientSocket.equals(this.socket)) {
                            DataOutputStream out = new DataOutputStream(clientSocket.getOutputStream());
                            out.writeUTF(line);
                        }
//                          out.close();
                    }
                }
                catch (IOException ex) {
                    break;
                    // Logger.getLogger(Server.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
            System.out.println("Closing connection with " + socket);
            in.close();
            socket.close();
        } catch (IOException ex) {
            Logger.getLogger(Server.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}

public class Server {
    
    private Socket socket = null;
    private ServerSocket server = null;
    
    public Server(int port) {
        try {
            server = new ServerSocket(port);
            System.out.println("Server started at port " + port);
            try {
                while (true) {
                    socket = server.accept();
                    ClientList.clientList.add(socket);
                    System.out.println(socket + " has connected");
                    new Thread(new ClientHandler(socket)).start();
                    Thread.sleep(0);
                }
            }
            catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                e.printStackTrace();
            }
            server.close();
        }
        catch (IOException ex) {
            Logger.getLogger(Server.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Server server = new Server(5000);
    }
    
}
