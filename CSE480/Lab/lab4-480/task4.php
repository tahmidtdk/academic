<?php
	function selection_sort($data){
		for($i=0; $i<count($data)-1; $i++) {
			$min = $i;
			for($j=$i+1; $j<count($data); $j++) {
				if ($data[$j]>$data[$min]) {
					$min = $j;
				}
			}
		    $data = swap_positions($data, $i, $min);
		}
		return $data;
	}

	function swap_positions($data1, $left, $right) {
		$old = $data1[$right];
		$data1[$right] = $data1[$left];
		$data1[$left] = $old;
		return $data1;
	}

	$arr=array(78, 60, 62, 68, 71, 68, 73, 85, 66, 64, 76, 63, 75, 76, 73, 68, 62, 73, 72, 65, 74, 62, 62, 65, 64, 68, 73, 75, 79, 73);

	$dat = selection_sort($arr);

	for($i=0; $i<sizeof($dat); $i++){
		echo "$dat[$i] &nbsp;";
	}

?>