<!DOCTYPE html>
<html>
	<body>

		<script>
			if (window.XMLHttpRequest) {// code for IE7+, Firefox, Chrome, Opera, Safari
				xmlhttp = new XMLHttpRequest();
			} else {// code for IE6, IE5
				xmlhttp = new ActiveXObject("Microsoft.XMLHTTP");
			}
			xmlhttp.open("GET", "cd_catalog.xml", false);
			xmlhttp.send();
			xmlDoc = xmlhttp.responseXML;
			document.write("<table border='1'>");
			document.write("<tr><td>NAME</td><td>COUNTRY</td><td>COMPANY</td><td>PRICE</td><td>BIRTH</td></tr>");
			var x = xmlDoc.getElementsByTagName("INFO");
			for ( i = 0; i < x.length; i++) {
				document.write("<tr><td>");		
				document.write(x[i].getElementsByTagName("NAME")[0].childNodes[0].nodeValue);
				document.write("</td><td>");				
				document.write(x[i].getElementsByTagName("COUNTRY")[0].childNodes[0].nodeValue);
				document.write("</td><td>");				
				document.write(x[i].getElementsByTagName("COMPANY")[0].childNodes[0].nodeValue);
				document.write("</td><td>");				
				document.write(x[i].getElementsByTagName("PRICE")[0].childNodes[0].nodeValue);
				document.write("</td><td>");
				document.write(x[i].getElementsByTagName("BIRTH")[0].childNodes[0].nodeValue);
				document.write("</td></tr>");
			}
			document.write("</table>");
		</script>

	</body>
</html>
