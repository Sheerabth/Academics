<html>
<head><title> + "Register form" + "</title></head>
<body bgcolor = #f0f0f0>
<h1 align = center>Register Form</h1>
<form action = "GrossSalaryServlet" method = "POST" target = "_blank">
    <ul>
        <li style="padding-bottom:1em"><b>Net Salary: </b>
            <input type = "text" name = "netSalary">
        <li style="padding-bottom:1em"><b>Deduction: </b>
            <input type = "text" name = "deduction" />
            <br/>
            <input style="margin-top:1em" type = "submit" value = "Calculate Gross Salary" />
    </ul>
</form>
</body>
</html>