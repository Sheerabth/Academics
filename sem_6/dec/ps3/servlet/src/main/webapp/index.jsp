<html>
<head><title> + "Register form" + "</title></head>
<body bgcolor = #f0f0f0>
<h1 align = center>Register Form</h1>
<form action = "RegisterServlet" method = "POST" target = "_blank">
    <ul>
        <li style="padding-bottom:1em"><b>First Name: </b>
            <input type = "text" name = "firstName">
        <li style="padding-bottom:1em"><b>Last Name: </b>
            <input type = "text" name = "lastName" />
        <li style="padding-bottom:1em"><b>Age: </b>
            <input type = "text" name = "age">
            <br/>
            <input style="margin-top:1em" type = "submit" value = "Submit" />
    </ul>
</form>
</body>
</html>