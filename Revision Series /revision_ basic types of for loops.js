/*
TYPES OF LOOPS

TYPE 1: for

TYPE 2: for in 

TYPE 3: for of 

TYPE 4: forEach

Note: foes not support continue and break. But continue can be achieved through return map

*/


var numArray1 = [ 9 , 8 , 7 , 6 , 5 ];

// TYPE 1: for 
for( let i = 0; i < numArray1.length; i++ ) {
    
    console.log( ` The value is : ${numArray1[i]}`);
}

console.log( `\n\n`);


// TYPE 2: for in 

for( let i in numArray1 ) {
    
    console.log( `The value is ${numArray1[i]}`);
}

console.log( `\n\n`);


// TYPE 3: for of 

for( let num of numArray1 ) {
    
    console.log( `The value is ${num}`);
}











