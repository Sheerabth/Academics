package com.example.stockmanagement;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;

@WebServlet(name = "AddProductServlet", value = "/AddProductServlet")
public class AddProductServlet extends HttpServlet {
    private static final long serialVersionID = 1L;

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        String productName = request.getParameter("productName");
        Float productPrice = Float.parseFloat(request.getParameter("productPrice"));
        String productCategory = request.getParameter("productCategory");

        Product product = new Product(productName, productPrice, productCategory);

        try {
            ProductDAO.addProduct(product);
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
        response.sendRedirect(request.getContextPath());
    }
}
