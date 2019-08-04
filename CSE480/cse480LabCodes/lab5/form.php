<!DOCTYPE HTML>  
<html>
<head>
<style>
.error {color: #FF0000;}

  .graybox {
    background-color: #f2f1e3;
    border: 1px solid #d3ceb4;
    padding: 10px;
  }
  .dbox {
    background-color:   #f7f9f9;
    padding: 10px;
  }

    .tab-border {
    text-align: center;
    border: 1px solid black;
  }
</style>
</head>
<body>  

<?php

// define variables and set to empty values
$name = $email = $gender = $comment =$gender= $website =$pass=$add= $d=$a=$n=$phone="";
$nameErr = $emailErr = $genderErr = $websiteErr =$passErr=$addErr=$dErr=$nErr= "";
$ck=0;
$Reg = '[a-z]{2,6}$/i';
$f=0;
$c=0;
if ($_SERVER["REQUEST_METHOD"] == "POST") {
  if (empty($_POST["name"])) {
    $nameErr = "Name is required";
  } else {
    $name = test_input($_POST["name"]);
    // check if name only contains letters and whitespace
    if (!preg_match("/^[a-zA-Z ]{6,15}$/i",$name)) {
      $nameErr = "Username must be 6-15 chars long"; 
  }
  else
  {
    $ck++;
  }
}
if (empty($_POST["phone"])) {
    $nErr = "number is required";
  } else {
    $phone = test_input($_POST["phone"]);
    if (!preg_match("/[0-9]+/", $phone)) {
         $nErr = "number of course enrolled should contain only integer";
          }
        
             else
  {
    $ck++;
  }
        }
        

  
  if (empty($_POST["email"])) {
    $emailErr = "Email is required";
  } else {
    $email = test_input($_POST["email"]);
    // check if e-mail address is well-formed
    if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
      $emailErr = "Invalid email format"; 
    }
     else
  {
    $ck++;
  }
  }

  if (empty($_POST["pass"])) {
    $passErr = "pass is required";
  } else {
    $pass = test_input($_POST["pass"]);
    if (!preg_match("/\d/", $pass)) {
         $passErr = "Password should contain at least one number";
          }
        else  if (!preg_match("/[A-Z]/", $pass)) {
            $passErr = "Password should contain at least one uppercase Letter";
          }
         else if (!preg_match("/[a-z]/", $pass)) {
            $passErr= "Password should contain at least one lowercase Letter";
          }
          else if(!preg_match("#[\\~\\!\\@\\#\\$\\%\\^\\&\\*\\(\\)\\_\\-\\+\\=\\{\\}\\[\\]\\|\\:\\;\\&lt;\\&gt;\\.\\?\\/\\\\\\\\]+#", $pass)){
        $passErr = "Password must have at least 1 Special Character";
    }
  
        else
  {
    $ck++;
  }
          
  }

  
  if (empty($_POST["gender"])) {
    $genderErr = "Gender is required";
  } else {
    $gender = test_input($_POST["gender"]);
    $ck++;
  }

  if (empty($_POST["add"])) {
    $addErr = "adress is required";
  } else {
    $add = test_input($_POST["add"]);
    $ck++;
  }




if (empty($_POST["dob"])) {
    $dobErr = "date is required";
  } else {
    $dob = $_POST["dob"];

 
//Create a DateTime object using the user's date of birth.
$dob = new DateTime($dob);
 
//We need to compare the user's date of birth with today's date.
$now = new DateTime();
 
//Calculate the time difference between the two dates.
$difference = $now->diff($dob);
 
//Get the difference in years, as we are looking for the user's age.
$age = $difference->y;
 
//Print it out.
if ($age<15)
{
  $dobErr = "sorry u can't enter because u r under 15 ";
}
 else
  {
    $ck++;
  }

}
}

function test_input($data) {
  $data = trim($data);
  $data = stripslashes($data);
  $data = htmlspecialchars($data);
  return $data;
}

if($ck==7)
{
  $name=$_POST['name'];
  $pass=$_POST['pass'];
  $email=$_POST['email'];
  $add=$_POST['add'];
  $dob=$_POST['dob'];
  $gender=$_POST['gender'];
  $phone=$_POST['phone'];
  $link = mysqli_connect("localhost", "root", "", "form");
 
// Check connection
if(!$link){
    die("ERROR: Could not connect. " . mysqli_connect_error());
}
 
// Attempt insert query execution
$sql = "INSERT INTO user (name, pass,email,add,dob,gender,phone ) VALUES ('$name', '$pass', '$email','$add','$dob','$gender','$phone')";
if(mysqli_query($link, $sql)){
    echo "Records inserted successfully.";
} else{
    echo "ERROR: Could not able to execute $sql. " . mysqli_error($link);
}
 
// Close connection
mysqli_close($link);
}


?>

<h2>PHP Form Validation Example</h2>
<p><span class="error">* required field</span></p>
<form method="post" action=" ">  
  Username: <input type="text" name="name" required>
  <span class="error">* <?php echo $nameErr;?></span>
  <br><br>
  Password: <input type="text" name="pass" required>
  <span class="error">* <?php echo $passErr;?></span>
  <br><br>
  Email: <input type="text" name="email" required>
  <span class="error">* <?php echo $emailErr;?></span>
  <br><br>
  Address: <input type="text" name="add" required>
  <span class="error">* <?php echo $addErr;?></span>
  <br><br>
  Date of Birth: <input type="date" name="dob"required>
  <span class="error">* <?php echo $dobErr;?></span>
  <br><br>
 
  Gender:
  <input type="radio" name="gender" <?php if (isset($gender) && $gender=="female") echo "checked";?> value="female" required>Female
  <input type="radio" name="gender" <?php if (isset($gender) && $gender=="male") echo "checked";?> value="male" required>Male
  <input type="radio" name="gender" <?php if (isset($gender) && $gender=="other") echo "checked";?> value="other" required>Other  
  <span class="error">* <?php echo $genderErr;?></span>
  <br><br>
  Phone: <input type="number" name="phone" >
  <span class="error" required> <?php echo $nErr;?></span>
  <br><br>

 <input type="submit" name="submit" value="Register" class="btn btn-primary">    
</form>


</body>
</html>