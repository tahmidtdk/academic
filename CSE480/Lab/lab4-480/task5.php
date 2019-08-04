<?php 
	$n=10;
	$chk = false;
	for($i=1; $i<=10; $i++){
		if($i%2==1 && $chk){
			echo "_$i";
		}else if($chk){
			echo "-$i";
		}
		if(!$chk){
			echo "$i";
			$chk = true;
		}
	}
?>