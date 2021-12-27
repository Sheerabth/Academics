/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package sem_6.dec.socket.noauth;

import java.net.*;
import java.io.*;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author 19pw33
 */
class Receiver implements Runnable {
    private DataInputStream in = null;
    private Socket socket = null;
    
    public Receiver(Socket socket) {
        this.socket = socket;
    }
    
    @Override
    public void run() {
        try {
            in = new DataInputStream(new BufferedInputStream(socket.getInputStream()));
            String line = "";
            
            while (!line.equals("EXIT") && socket.isConnected()) {
                try {
                    line = in.readUTF();
                    System.out.println("Message received from " + socket + ": " + line);
                }
                catch (IOException ex) {
                    break;
                    // Logger.getLogger(Receiver.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
            in.close();
        } catch (IOException ex) {
            Logger.getLogger(Receiver.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
}

public class Client {

    /**
     * @param args the command line arguments
     */
    
    private Socket socket = null;
    private DataInputStream consoleIn = null;
    private DataOutputStream out = null;
    
    public Client(String address, int port) {
        try {
            socket = new Socket(address, port);
            new Thread(new Receiver(socket)).start();
            System.out.println("Connected to: " + socket);
            
            consoleIn = new DataInputStream(System.in);
            out = new DataOutputStream(socket.getOutputStream());
        }
        catch (UnknownHostException ex) {
            Logger.getLogger(Client.class.getName()).log(Level.SEVERE, null, ex);
        }
        catch (IOException ex) {
            Logger.getLogger(Client.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        String line = "";
        while (!line.equals("EXIT")) {
            try {
                line = consoleIn.readLine();
                out.writeUTF(line);
            } 
            catch (IOException ex) {
                // Logger.getLogger(Client.class.getName()).log(Level.SEVERE, null, ex);
                break;
            }
        }
        try {
            consoleIn.close();
            out.close();
            socket.close();
        }
        catch (IOException ex) {
            Logger.getLogger(Client.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    public static void main(String[] args) {
        // TODO code application logic here
        Client client = new Client("127.0.0.1", 5000);
    }
    
}
