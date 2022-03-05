package com.example.webinfo;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Date;
import java.util.Objects;

@WebServlet(name = "WebInfoServlet", value = "/")
public class WebInfoServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        Date date = new java.util.Date();
        Cookie[] cookies = request.getCookies();
        Cookie visitCookie = null;

        if(cookies != null) {
            for (Cookie cookie : cookies) {
                if (Objects.equals(cookie.getName(), "visitCount")) {
                    visitCookie = cookie;
                    break;
                }
            }
        }

        if(visitCookie == null)
            visitCookie = new Cookie("visitCount", String.valueOf(1));
        else {
            int visitCount = Integer.parseInt(visitCookie.getValue());
            visitCookie.setValue(String.valueOf(visitCount + 1));
        }
        response.addCookie(visitCookie);


        response.setContentType("text/html");

        PrintWriter out = response.getWriter();
        out.println(
                "<html>" +
                    "<head><title>" + "Website History" + "</title></head>\n" +
                    "<body bgcolor = \"#f0f0f0\">\n" +
                        "<h1 align = \"center\">" + "Form Validation" + "</h1>\n" +
                        "<ul>\n" +
                        "  <li><b>Current Date: </b> "
                        + date + "\n" +
                        "  <li><b>VisitedCount: </b> "
                        + visitCookie.getValue() + "\n" +
                        "</ul>\n" +
                    "</body>" +
                "</html>"
        );
    }
}
