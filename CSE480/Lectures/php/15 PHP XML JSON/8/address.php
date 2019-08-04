<!DOCTYPE html>
<html>
<head>
<title>HTML Page</title>
<!--<meta charset="UTF-8">-->
</head>

<body>

<h1>Hello world!</h1>

<h2>My First XML Integration in HTML</h2>
	
<div>
<B> To: </b> <span id="to"></span><br>
<B> From: </b> <span id="from"></span><br>
<B> Heading: </b> <span id="heading"></span><br>
<B> Message: </b> <span id="message"></span><br>

</div>

  <script>
    var xmlhttp, xmlDoc;
	xmlhttp = new XMLHttpRequest();                  // built in XML Parser
	xmlhttp.open("GET", "address.xml", false);
	xmlhttp.send();
	
	xmlDoc = xmlhttp.responseXML;                      // The responseXML property returns the response as an XML DOM object.
	document.getElementById("to").innerHTML = xmlDoc.getElementsByTagName("to")[0].childNodes[0].nodeValue;
	document.getElementById("from").innerHTML = xmlDoc.getElementsByTagName("from")[0].childNodes[0].nodeValue;
	document.getElementById("heading").innerHTML = xmlDoc.getElementsByTagName("heading")[0].childNodes[0].nodeValue;
	document.getElementById("message").innerHTML = xmlDoc.getElementsByTagName("body")[0].childNodes[0].nodeValue;
	
  </script>
	
</body>
</html>

