<!DOCTYPE html>
<html>
<body>

<?php
$cars = array("Volvo", "BMW", "Toyota"); 
echo "I like " . $cars[0] . ", " . $cars[1] . " and " . $cars[2] . ".";

// echo $cars[4]   Undefined offset: 4

?>

<?php
//assign adsense code to a variable
$googleadsensecode = '
<script type="text/javascript">
google_ad_client = "ca-pub-7536501212525209";
google_ad_slot = "8606657376"
google_ad_width = 350;
google_ad_height = 600;
</script>
<!– AD NAME –><script type='text/javascript'
src=”http://pagead2.googlesyndication.com/pagead/show_ads.js”>
</script>';
//now we will get output in HTML form
echo $googleadsensecode;
?>

</body>
</html>