package com.example.stockmanagement;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class ProductDAO {
    public static void addProduct(Product product) throws ClassNotFoundException {
        String INSERT_PRODUCT_SQL = String.format("INSERT INTO product" +
                " (product_name, product_price, product_category) VALUES" +
                " ('%s', '%f', '%s')", product.getProductName(), product.getProductPrice(), product.getProductCategory());

        try (Connection connection = Database.getConnection();
             Statement statement = connection.createStatement();
        ) {
            statement.executeUpdate(INSERT_PRODUCT_SQL);
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public static List<Product> getProducts() throws ClassNotFoundException {
        String GET_PRODUCTS_SQL = "SELECT * FROM product";
        List<Product> productDetails = new ArrayList<>();
        try (Connection connection = Database.getConnection();
             Statement statement = connection.createStatement();
        ) {
            ResultSet result = statement.executeQuery(GET_PRODUCTS_SQL);
            while (result.next()) {
                Product product = new Product(result.getString("product_name"), result.getFloat("product_price"), result.getString("product_category"));
                product.setProductId(result.getInt("product_id"));
                productDetails.add(product);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return productDetails;
    }

    public static void deleteProduct(Integer productId) throws ClassNotFoundException {
        String DELETE_PRODUCT_SQL = String.format("DELETE FROM product WHERE product_id=%d", productId);
        try (Connection connection = Database.getConnection();
             Statement statement = connection.createStatement();
        ) {
            statement.executeQuery(DELETE_PRODUCT_SQL);
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
