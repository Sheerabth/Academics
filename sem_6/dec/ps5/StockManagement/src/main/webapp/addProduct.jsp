<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
         pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
<head>
    <meta charset="ISO-8859-1">
    <title>Insert title here</title>
</head>
<body>
<div align="center">
    <h1>Employee Register Form</h1>
    <form action = "AddProductServlet" method="post">
        <table style="width: 80%">
            <tr>
                <td>Enter Product Name</td>
                <td><input type="text" name="productName" /></td>
            </tr>
            <tr>
                <td>Enter Product Price</td>
                <td><input type="text" name="productPrice" /></td>
            </tr>
            <tr>
                <td>Enter Product Category</td>
                <td><input type="text" name="productCategory" /></td>
            </tr>
        </table>
        <input type="submit" value="Add Product" />
        <br />
        <a href="<%= request.getContextPath() %>/index.jsp">Return to Home Page</a>
    </form>
</div>
</body>
</html>
