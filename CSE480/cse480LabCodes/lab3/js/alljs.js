// task1
function leapyear_cheaker() {
 	 var year = prompt("Enter The year:");
 	 var leap_year = false;
	if(year%100==0){
		if(year%400==0){
			leap_year=true;
		}
	}else{
		if(year%4==0){
			leap_year=true;
		}
	}

	if (leap_year) {
		document.getElementById("task1_txt").innerHTML = "Leap year";
	}else{
		document.getElementById("task1_txt").innerHTML = "Not Leap year";
	}
}

// task2
function guess_game(){
	var ran_num = Math.floor(Math.random() * 10);
	var inp_num = prompt("Guess a number:");
	if(ran_num==inp_num){
		document.getElementById("task2_txt").innerHTML = "Good Work";
	}else{
		document.getElementById("task2_txt").innerHTML = "Not Matched";
	}
}

// task3
function addition(){
		var num1 = document.getElementById('num1').value;
		var num2 = document.getElementById('num2').value;

		document.getElementById("task3_txt").innerHTML = "Result is:"+num1*num2;
	}
	
function divition(){
	var num1 = document.getElementById('num1').value;
	var num2 = document.getElementById('num2').value;
	document.getElementById("task4_txt").innerHTML = "Leargest Number:"+ Math.max(Math.max(num1, num2), num3);
}

// task4

function largenumber(){
	var num1 = document.getElementById('number1').value;
	var num2 = document.getElementById('number2').value;
	var num3 = document.getElementById('number3').value;

	document.getElementById("task4_txt").innerHTML = "Leargest Number:"+ Math.max(Math.max(num1, num2), num3);
}

function numberToHour(){
	var num = prompt("Enter number: ");

	var hour = Math.round(num/60);
	var min = num -(hour * 60);

	document.getElementById("task5_txt").innerHTML = ""+hour+" hours and "+min +" minutes";
}