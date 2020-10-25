<?php
        $var;
        if(isset($_GET['sentence']))
        {
            $arr = str_split($_GET['sentence']);
            $var = $arr[0];
            for ($i=0; $i < count($arr); $i++)
            {
                if($arr[$i] == " ")
                {
                    array_splice($arr, $i, 1);
                }
            }
            $var = implode("",$arr);
        }
?>

<!DOCTYPE HTML>
<HTML>
	<head>
		<title>
			ws7_6
		</title>
	</head>
	<body>
        <h1>Enter a Sentence with spaces:</h1>
        <form>
            <input type = "text" name = "sentence" placeholder="Write a sentence "><br><br>
            <input type="submit">
        </form><br><br>

        <?php
         if(isset($_GET['sentence']))
        {
            echo "<p> The Sentence without spaces is <br>" . $var . "</p>";
        }
        ?>
	</body>
</html>
