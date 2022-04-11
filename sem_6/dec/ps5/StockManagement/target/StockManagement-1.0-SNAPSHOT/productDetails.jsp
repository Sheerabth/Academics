<%@ page import="java.util.List" %>
<%@ page import="com.example.stockmanagement.Product" %>
<%@ page import="com.example.stockmanagement.ProductDAO" %>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
         pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
<head>
    <meta charset="ISO-8859-1">
    <title>Insert title here</title>
</head>
<body>
<h1 style="text-align: center">Product Details</h1>
<%
    List<Product> productDetails = null;
    try {
        productDetails = ProductDAO.getProducts();
    } catch (ClassNotFoundException e) {
        e.printStackTrace();
    }

    assert productDetails != null;
%>
<table border="1" style="width: 80%; margin-left: auto; margin-right: auto; ">
    <thead>
        <tr>
            <th>Product ID</th>
            <th>Product Name</th>
            <th>Product Price</th>
            <th>Product Category</th>
            <th>Delete</th>
        </tr>
    </thead>
    <tbody>
        <%
            for (Product product : productDetails) {
        %>
        <tr>
            <td><%= product.getProductId() %></td>
            <td><%= product.getProductName() %></td>
            <td><%= product.getProductPrice() %></td>
            <td><%= product.getProductCategory() %></td>
            <td><a href="<%=String.format("%s/DeleteProductServlet?productId=%d", request.getContextPath(), product.getProductId())%>">delete</a></td>
        </tr>
        <%
            }
        %>
    </tbody>
</table>
<br />
<a href=<%= request.getContextPath()%> >Return to home page</a>
</body>
</html>
