
<?php 
	$chessboard_size = $_POST["size_board"];
?>


<!DOCTYPE html>
<html>
<head>
	<title>Chess board</title>
	<style>
		table.board_style {
		  margin: 80px auto;
		  background: black;
		  border: 1px solid #333;
		}

		td.board_style {
		  width: 70px;
		  height: 70px;
		}

		tr.board_style:nth-child(odd) td.board_style:nth-child(even),
		tr.board_style:nth-child(even) td.board_style:nth-child(odd) {
		  background: white;
		}
	</style>
</head>
<body>
	<table class="board_style">
		<?php 
			for($i=0; $i<$chessboard_size; $i++){
		?>
	  <tr class="board_style">
	  	<?php 
	  		for($j=0; $j<$chessboard_size; $j++){
	  	?>
	    <td class="board_style"></td>
	    <?php } ?>
	  </tr>
	  <?php } ?>
	</table>

</body>
</html>