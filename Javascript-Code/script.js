//___ String method ___//
/*
let txt = "Al Jubair Shovon";
let txt2 = " Cat";
console.log("String length = " + txt.length);
console.log("String slice = " + txt.slice(10,16)); // Parameter = 1st: start & 2nd: end
console.log("String substr = " + txt.substr(3,6)); // Parameter = 1st: start & 2nd: length
console.log("String replace = " + txt.replace("Jubair" , "Modon"));
console.log("String replace all = " + txt.replaceAll("o" , "@"));
console.log("String upper case = " + txt.toUpperCase());
console.log("String lower case = " + txt.toLowerCase());
console.log("String concat = " + txt.concat(" -->"+txt2)); // It join two string
console.log("String trim = " + txt.trim()); // It remove white space
console.log("String carAt = " + txt.charAt(10)); // It return specified charecter
console.log(`String Interpolation = ${txt} -->${txt2} `); // String Interpolation

if(txt.match("Shovon")) {
    console.log("String match = " + "Congratulation");
} else {
    console.log("String match = " + "Sorry");
}
*/

//___ String to number ___//
/*
var str = "shovon";
var strToNumber = Number(str);
console.log(`String to number = ${typeof(strToNumber)}`);
*/

//___ Number to string ___//
/*
var num = 123;
var numToString = num.toString();
console.log(`Number to String = ${typeof(numToString)}`);
*/


//___ Array ___//
/*
var fruits = ["Mango", "Apple", "Bananna"];

fruits.push("Lichi"); // Add item as last item
fruits.sort(); // Sorting array item
console.log(fruits);
// document.getElementById("DisplayArray").innerHTML = fruits;

console.log(`Access last element in array = ${fruits[fruits.length - 1]}`);

fruits.pop("Lichi"); // Remove item as last item

fruits[0] = "Goava"; // Change array item
console.log(`Change array item = ${fruits}`);

delete fruits[2]; // Delete array item
console.log(`Delete array item = ${fruits}`);

var fruits = ["Mango", "Apple", "Bananna"];
fruits.splice(1,0,"Lichi"); // It add 1 item in '1' no position
fruits.splice(0,1); // It remove 1 item from '0' no posotion
console.log(`Array splice = ${fruits}`);

let students = ['shovon','jubair','asik'];
let sliced = students.slice(1);
console.log(sliced);

var fruits = ["Mango", "Apple", "Bananna"];
fruits.shift();
console.log(`Shift array items = ${fruits}`); // It remove items from starting

var fruits = ["Mango", "Apple", "Bananna"];
fruits.unshift("Pineapple");
console.log(`Unshift array items = ${fruits}`);// It add items in starting

let boys = ['Shovon','Asik','Jony'];
let girls = ['Meghla','Alina'];
let marge = boys.concat(girls); // It's marge 2 or 3 array(array.concat(array,array))
console.log(marge);

// Loop in arrya (using for in loop)
let boys = ['Shovon','Asik','Jony'];
for(let x in boys) {
    document.write(boys[x] + "</br>");
}

// Loop in arrya (using for each loop)
let boys = ['Shovon','Asik','Jony'];
boys.forEach(keys => {
    document.write(keys + "</br>");
});
*/


//___ Object ___//
/*
const obj = {
    'FirstName' : "Al Jubair",
    'LastName' : " shovon",
    'age' : 21,
    // Method in object
    'FullName' : function() {
        return this.FirstName + this.LastName;
    }

};

console.log("Object = " + obj['FirstName']);
console.log("Object = " + obj.LastName);
console.log("Object = " + obj.FullName());
*/

//___ Convert object to text ___//
/*
let obj = {
    name : 'shovon',
    roll : 520157,
    dept : 'CMT',
};
let txt = "";
for(let x in obj) {
    txt += obj[x];
}
document.write(txt);
*/

//___ Convert object to array ___//
/*
let obj = {
    name : 'shovon',
    roll : 520157,
    dept : 'CMT',
};
let arrayList = Object.keys(obj);
console.log(arrayList);
*/


//___ Date Object ___//
/*
/*** 
 * Date sequence => Year, Month, Day, Hour, Minute, Second, Milisecond
***/
// let d = new Date();
// // document.write(d);
// d.getFullYear();
// d.getMonth();
// d.getDate();

/*** 
 * getMonth() methood return numaric value.
 * If we want to show months full text then follow this steps
***/
// const months = ["January","February","March","April","May","June","July","Augest","September","October","November","December"];
// document.write(months[d.getMonth()]);


//___ Math Object ___//
/*
let num = 1.9;
console.log(`Round = ${Math.round(num)}`); // It's return round value
console.log(`Ceil = ${Math.ceil(num)}`); // সবসময় উপরের সংখ্যা return করবে
console.log(`Floor = ${Math.floor(num)}`); // সবসময় নিচের সংখ্যা return করবে
console.log(`Power = ${Math.pow(2,3)}`); // It's return power => pow(number, power)
console.log(`Sqrt = ${Math.sqrt(49)}`); // It's return squre root
console.log(`Sign = ${Math.sign(0)}`); // যদি number positive হয় তাহলে 1 return করবে, negetive হলে-1, 0 হলে 0 return করবে
console.log(`Abs = ${Math.abs(-2)}`); // It's return absulute/positive number
console.log(`Max = ${Math.max(4,1,12,3)}`); // It;s return maximum number
console.log(`Min = ${Math.min(4,12,3,5)}`); // It's return minimum number
console.log(`Pi = ${Math.PI}`); // It's return pi value


//___ Random Number ___//
console.log(`Random = ${Math.random()}`); // It's return random number
console.log(`Random integer (1-9) = ${Math.floor(Math.random() * 10)}`); // It's return random integer number
console.log(`Random integer (1-10) = ${Math.floor(Math.random() * 10) + 1}`); // It's return random integer number 1-10
console.log(`Random integer (1-99) = ${Math.floor(Math.random() * 100)}`); // It's return random integer number 1-99
console.log(`Random integer (1-100) = ${Math.floor(Math.random() * 100) + 1}`); // It's return random integer number 1-100
console.log(`Random integer (1-9999) = ${Math.floor(Math.random() * 10000)}`); // It's return random integer number 1-9000
console.log(`Random integer (1-10000) = ${Math.floor(Math.random() * 10000) + 1}`); // It's return random integer number 1-9000
*/






//__________________ Problem solving __________________//

//___ How to print 1-6 random number (ludo game) ___//
/*
function getRandomIntNumber(min,max) {
    return Math.floor(Math.random() * (max - min + 1)) + min;
}
console.log(getRandomIntNumber(1,6));
*/


//___ How to find leep year ___//
/*
function getLeepYear(year) {
    if((year % 400 === 0) || ((year % 4 === 0) && (year % 100 !== 0))) {
        console.log(`${year} is leep year`);
    } else {
        console.log(`${year} is not leep year`);
    }
}
getLeepYear(2006);
*/