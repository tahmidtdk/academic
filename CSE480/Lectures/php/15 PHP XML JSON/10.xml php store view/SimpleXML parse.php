<?php


$xml2 = simplexml_load_file('info.xml')  or die("Error: Cannot create object");
	foreach($xml2->data as $datas) 
	{
        echo $datas->first. "<br>"; 
		echo $datas->last. "<br>"; 
		echo $datas->password. "<br><br><br>"; 
    }
?>




