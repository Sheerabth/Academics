package com.example.stockmanagement;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class Database {
    private static Connection connection = null;

    public static Connection getConnection() throws ClassNotFoundException, SQLException{
        Class.forName("org.postgresql.Driver");

//        if(connection == null)
        connection = DriverManager.getConnection("jdbc:postgresql://localhost:5432/stock_management", "test_user", "test_password");

        return connection;
    }
}
