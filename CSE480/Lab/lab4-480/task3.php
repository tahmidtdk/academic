<?php  
	$temperatures = array(78, 60, 62, 68, 71, 68, 73, 85, 66, 64, 76, 63, 75, 76, 73, 68, 62, 73, 72, 65, 74, 62, 62, 65, 64, 68, 73, 75, 79, 73);
	$sum=0;
	$max=0;
	$min=99999;
	for($i=0; $i<sizeof($temperatures); $i++){
		$sum+=$temperatures[$i];
		if($temperatures[$i]>$max)
			$max=$temperatures[$i];
		if($temperatures[$i]<$min)
			$min = $temperatures[$i];
	}

	$avg = $sum/sizeof($temperatures);

	$sum=0;
	for($i=0; $i<sizeof($temperatures); $i++){
		$sum+=(($temperatures[$i]-$avg)*($temperatures[$i]-$avg));
	}
	$upper = $sum/sizeof($temperatures);
	$standard_dev = sqrt($upper);
	

	echo "Average Temperature: $avg <br>";
	echo "Standard Deviation is: $standard_dev <br>";
	echo "Lowest Temperature: $min <br>";
	echo "Highest Temperature: $max <br>";
?>