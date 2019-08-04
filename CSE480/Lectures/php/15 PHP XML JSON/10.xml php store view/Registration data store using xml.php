<!DOCTYPE html>
<html>
<head>
<style>
div.container {
    width: 100%;
    border: 1px solid gray;
}

header, footer {
    padding: 1em;
    color: white;
    background-color: black;
    clear: left;
    text-align: center;
}

nav {
    float: left;
    max-width: 160px;
    margin: 0;
    padding: 1em;
}

nav ul {
    list-style-type: none;
    padding: 0;
}
   
nav ul a {
    text-decoration: none;
}

article {
    margin-left: 170px;
    border-left: 1px solid gray;
    padding: 1em;
    overflow: hidden;
}
</style>
</head>
<body>
<?php
if(isset($_REQUEST['ok']))
{
$xml = new DOMDocument("1.0", "UTF-8");
$xml->load("info.xml");

$rootTag = $xml->getElementsByTagName("document")->item(0);

$dataTag = $xml->createElement("data");

$firstTag = $xml->createElement("first", $_REQUEST['first']);
$lastTag = $xml->createElement("last", $_REQUEST['last']);
$passwordTag = $xml->createElement("password", $_REQUEST['password']);

$dataTag->appendChild($firstTag);
$dataTag->appendChild($lastTag);
$dataTag->appendChild($passwordTag);

$rootTag->appendChild($dataTag);

$xml->save("info.xml");

}


?>

<div class="container">

<header>
  <h1>Registration Form</h1>
</header>
  
<nav>
  <ul>
    <li><a href="#">Registration Form</a></li>
    <li><a href="SimpleXML parse.php">View List</a></li>
  </ul>
</nav>

<article>
  <form action="" method="">
  <label for="firstname">First Name:</label>
<input type="text" id="firstname" name="first"> <br> <br>
 
<label for="lastname">Last Name:</label>
<input type="text" id="lastname" name="last"> <br> <br>
 
<br>
<label for="Password">Password:</label>
<input type="password" name="password" /> <br><br>

<input type="submit" name="ok" value="Submit">
 
</form>
</article>

<footer>Copyright &copy; East-West University, 2018. All Rights Reserved.</footer>

</div>

</body>
</html>