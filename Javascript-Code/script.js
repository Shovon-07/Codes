//___ String method ___//
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


//___ String to number ___//
var str = "shovon";
var strToNumber = Number(str);
console.log(`String to number = ${typeof(strToNumber)}`);


//___ Number to string ___//
var num = 123;
var numToString = num.toString();
console.log(`Number to String = ${typeof(numToString)}`);


//___ Array ___//
let fruits = ["Mango", "Apple", "Bananna"];
fruits.push("Lichi"); // Add item as last item
fruits.sort(); // Sorting array item
document.getElementById("DisplayArray").innerHTML = fruits;
console.log(`Access last element in array = ${fruits[fruits.length - 1]}`);
fruits.pop("Lichi"); // Remove item as last item
fruits[0] = "Goava"; // Change array item
console.log(`Change array item = ${fruits}`);
delete fruits[2]; // Delete array item
console.log(`Delete array item = ${fruits}`);


//___ ___//


//___ Object ___//
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