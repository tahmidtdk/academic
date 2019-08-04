<?php 
	$letter1 = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890@$%*()_-+=';
	$letter2 = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ';
	$letter3 = '1234567890@$%*()_-+=';
	$letter4 = '@$%*()_-+=';

	$pass = ""; //remember to declare $pass as an array
    $length1 = strlen($letter1) - 1;
    $length2 = strlen($letter2) - 1;
    $length3 = strlen($letter3) - 1;
    $length4 = strlen($letter4) - 1;
	for ($i = 0; $i < 8; $i++) {
		if($i<2){
	        $n = rand(0, $length1);
	        $pass[$i] = $letter1[$n];
		}else if($i<4){
			$n = rand(0, $length2);
	        $pass[$i] = $letter2[$n];
		}else if($i<6){
			$n = rand(0, $length3);
	        $pass[$i] = $letter3[$n];
		}else{
			$n = rand(0, $length4);
	        $pass[$i] = $letter4[$n];
		}
    }
    str_shuffle($pass);
    echo "Password: $pass";
?>