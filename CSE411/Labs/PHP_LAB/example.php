<?php
    require 'connection.php';

	$sql = "SELECT * FROM info";
    $result = mysqli_query($connection, $sql);
    $resultCheck = mysqli_num_rows($result);
	
	echo "Row found: ".$resultCheck." in total";

    echo "<table border='1'>";
    echo "<tr><td> Studnet ID </td> <td> Studnet Name </td> </tr>";

    while($row = mysqli_fetch_assoc($result)){

    echo "<tr> <td> ".$row['id']."</td> <td>". $row['name']."</td>";

    }

    echo "</table>";
?>