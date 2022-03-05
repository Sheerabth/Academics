package com.example.servlet;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet(name = "RegisterServlet", value = "/RegisterServlet")
public class RegisterServlet extends HttpServlet {

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
        response.setContentType("text/html");

        PrintWriter out = response.getWriter();
        out.println(
                "<html>" +
                "<head><title>" + "Form Validation" + "</title></head>\n" +
                    "<body bgcolor = \"#f0f0f0\">\n" +
                        "<h1 align = \"center\">" + "Form Validation" + "</h1>\n" +
                        "<ul>\n" +
                        "  <li><b>First Name: </b> "
                        + request.getParameter("firstName") + "\n" +
                        "  <li><b>Last Name: </b> "
                        + request.getParameter("lastName") + "\n" +
                        "  <li><b>Age: </b> "
                        + request.getParameter("age") + "\n" +
                        "</ul>\n" +
                    "</body>" +
                "</html>"
        );
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doGet(request, response);
    }

}
