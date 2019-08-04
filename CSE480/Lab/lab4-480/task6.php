<?php  
	$word =  $_POST["word"];
	
	$j = strlen($word)-1;
	$check= true;
	for($i=0; $i<(strlen($word)/2); $i++){
		if($word[$i]!=$word[$j]){
			$check = false;
			break;
		}
		$j--;
	}

	if($check)
		echo "Palindrome";
	else
		echo "Not Palindrome";

?>