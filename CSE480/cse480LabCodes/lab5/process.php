<html>
   
   <head>
      <style>
         .error {color: #FF0000;}
      </style>
   </head>
   
   <body>



      <?php
         // define variables and set to empty values
         $nameErr = $emailErr = $genderErr = $addressErr =$passwordErr =$bdayErr=$enrolErr="";
         $name = $email = $gender = $comment = $address = $password=$bday=$enrol="";
         
         if ($_SERVER["REQUEST_METHOD"] == "POST") {
            if (empty($_POST["name"])) {
               $nameErr = "Name is required";
            }else {
               $name = test_input($_POST["name"]);
            }
            if(empty($_POST["bday"])){
               $bdayErr="date of birth is requird";

            }else{
               $pday = new DateTime($_POST['bday']); // Your date of birth
               $today = new Datetime(date('m/d/y'));
               $diff = $today->diff($pday);

               if($diff->y<15){
                  $bdayErr="age must be greater then 15";
               }else{
                  $bday = test_input($_POST["bday"]);
            
               }

            }
            if (empty($_POST["password"])) {
               $nameErr = "Password is required";
            }else {
                  $dassword=$_POST["password"];
                  $uppercase = preg_match('@[A-Z]@', $dassword);
                  $lowercase = preg_match('@[a-z]@', $dassword);
                  $number    = preg_match('@[0-9]@', $dassword);
                  $specialChars = preg_match('@[^\w]@', $dassword);

                  if(!$uppercase || !$lowercase || !$number || !$specialChars || strlen($password) < 8) {
    echo 'Password should be at least 8 characters in length and should include at least one upper case letter, one number, and one special character.';
}else{
    $password = test_input($_POST["password"]);
}

            }
            
            if (empty($_POST["email"])) {
               $emailErr = "Email is required";
            }else {
               $email = test_input($_POST["email"]);
               
               // check if e-mail address is well-formed
               if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
                  $emailErr = "Invalid email format"; 
               }
            }
            
            if (empty($_POST["address"])) {
               $addressErr = "address is required";
            }else {
               $address= test_input($_POST["address"]);
            }
            
            if (empty($_POST["comment"])) {
               $comment = "";
            }else {
               $comment = test_input($_POST["comment"]);
            }
            
            if (empty($_POST["gender"])) {
               $genderErr = "Gender is required";
            }else {
               $gender = test_input($_POST["gender"]);
            }
         }


         $servername = "localhost";
         $username = "root";
         $password = "";
         $dbname = "demo";

// Create connection
$conn = new mysqli($servername, $username, $password,$dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}else{
   $sql = "INSERT INTO form (name, password, email,address,dob,gender,nocors)
VALUES ('$name','$password','$email','$address','$bday','$gender','$enrol')";

if ($conn->query($sql) === TRUE) {
    echo "New record created successfully";
} else {
    echo "Error: " . $sql . "<br>" . $conn->error;
}

$conn->close();

}

         
         function test_input($data) {
            $data = trim($data);
            $data = stripslashes($data);
            $data = htmlspecialchars($data);
            return $data;
         }
      ?>
     
      <h2>Absolute classes registration</h2>
     
      <p><span class = "error">* required field.</span></p>
     
      <form method = "post" action = "<?php 
         echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
         <table>
            <tr>
               <td>User Name:</td>
               <td><input type = "text" name = "name" maxlength="15" minlength="6">
                  <span class = "error">* <?php echo $nameErr;?></span>
               </td>
            </tr>

            <tr>
               <td>Password: </td>
               <td><input type = "Password" name = "password">
                  <span class = "error">* <?php echo $passwordErr;?></span>
               </td>
            </tr>
           
            <tr>
               <td>E-mail: </td>
               <td><input type = "text" name = "email">
                  <span class = "error">* <?php echo $emailErr;?></span>
               </td>
            </tr>
           
            <tr>
               <td>Address: </td>
               <td><input type = "text" name = "address">
                  <span class = "error">* <?php echo $addressErr;?></span>
               </td>
            </tr>
            <tr>
               <td>Date of Borth: </td>
               <td><input type="date" name="bday">
                  <span class = "error">* <?php echo $bdayErr;?></span>
               </td>
            </tr>
            <tr>
            
            <tr>
               <td>Gender:</td>
               <td>
                  <input type = "radio" name = "gender" value = "female">Female
                  <input type = "radio" name = "gender" value = "male">Male
                  <span class = "error">* <?php echo $genderErr;?></span>
               </td>
            </tr>
             <td>Number of Class Enroled</td>
               <td> <input type = "number" name = "enrol">
                  <span class = "error"><?php echo $enrolErr;?></span>
               </td>
            </tr>
				
            <td>
               <input type = "submit" name = "submit" value = "Submit"> 
            </td>
				
         </table>
			
      </form>
      
      <?php
         echo "<h2>Your given values are as:</h2>";
         echo $name;
         echo "<br>";
         
         echo $email;
         echo "<br>";
         echo $bday;
         echo "<br>";
         echo $password;
         echo "<br>";
         
          echo $address;
          echo "<br>";
         
         echo $gender;
      ?>
   
   </body>
</html>