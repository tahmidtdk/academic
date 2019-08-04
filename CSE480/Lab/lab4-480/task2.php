<?php 
	$row_size =  $_POST['row_size'];
	echo "$row_size<br>";
	for($i = 0; $i<$row_size; $i++){
		if($i<$row_size/2){
			for($j=0; $j<=$i && $j<=$row_size/2; $j++){
				echo "*";
				// echo "*";
			}echo "<br>";
		}else{
			for($j=0; $j<($i-$row_size/2); $j++){
				echo "&nbsp;";
				echo "&nbsp;";
			}
			for($j = 0; $j<($row_size-$i) && $j<$row_size/2; $j++){
				echo "*";
			}echo "<br>";
		}
	}
?>