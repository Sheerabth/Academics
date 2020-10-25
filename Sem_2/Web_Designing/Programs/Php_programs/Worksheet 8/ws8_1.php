<?php

	$valid = true;
	if(isset($_POST['first']))
	{
		$conn= mysqli_connect("localhost", "ranga", "qwerty", "ws8_1");
		if(!$conn)
		{
			echo "Connectoin Failed:" . mysqli_connect_error() ;
		}
		else
		{
			$sql= "INSERT INTO address (first, last, street, city, state, zipcode, t_number) VALUES ('$_POST[first]','$_POST[last]','$_POST[street]', '$_POST[city]', '$_POST[state]', '$_POST[zipcode]','$_POST[phone]')";
			if (mysqli_query($conn, $sql))
			{
				echo "New record created successfully";
			}
			else
			{
				echo "Error: " . $sql. "<br>" . mysqli_error($conn);
			}
			mysqli_close($conn);
		}
	}
	if (isset($_POST['search'])) {
		$conn= mysqli_connect("localhost", "ranga", "qwerty", "ws8_1");
		if(!$conn)
		{
			echo "Connectoin Failed:" . mysqli_connect_error() ;
		}
		else {
			$retval = $conn->query("SELECT * FROM address");
			$table = [];
			while($row = mysqli_fetch_assoc($retval))
			{
				array_push($table, $row);
			}
			echo json_encode($table);
		}

	}

?>
