package com.example.salary;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet(name = "GrossSalaryServlet", value = "/GrossSalaryServlet")
public class GrossSalaryServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html");

        Integer netSalary = Integer.valueOf(request.getParameter("netSalary"));
        Integer deduction = Integer.valueOf(request.getParameter("deduction"));
        int grossSalary = netSalary - deduction;

        response.setContentType("text/html");

        PrintWriter out = response.getWriter();
        out.println(
                "<head><title>" + "Gross Salary" + "</title></head>\n" +
                    "<body bgcolor = \"#f0f0f0\">\n" +
                        "<h1 align = \"center\">" + "Gross Salary" + "</h1>\n" +
                        "<ul>\n" +
                        "  <li><b>Net Salary: </b> "
                        + netSalary + "\n" +
                        "  <li><b>Deduction: </b> "
                        + deduction + "\n" +
                        "  <li><b>Gross Salary: </b> "
                        + grossSalary + "\n" +
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
