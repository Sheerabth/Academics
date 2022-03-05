package com.example.serverinfo;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet(name = "ServerInfoServlet", value = "/")
public class ServerInfoServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html");

        PrintWriter out = response.getWriter();
        out.println(
                "<head><title>" + "Server Info" + "</title></head>\n" +
                        "<body bgcolor = \"#f0f0f0\">\n" +
                        "<h1 align = \"center\">" + "Server Info" + "</h1>\n" +
                        "<ul>\n" +
                        "  <li><b>Server Name: </b> "
                        + request.getServerName() + "\n" +
                        "  <li><b>Server Port: </b> "
                        + request.getServerPort() + "\n" +
                        "</ul>\n" +
                        "</body>" +
                    "</html>"
        );
    }
}
