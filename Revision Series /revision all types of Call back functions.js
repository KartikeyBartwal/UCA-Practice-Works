// Anonymous Callback Function:
// Defined inline, useful for quick operations.
numArray1.forEach(function(value) {
    // Your code here
    console.log(`The value is: ${value}`);
});

console.log(`\n`);

// Named Callback Function:
// Defined separately, useful for reusability and clarity.
var namedFunction = function(value) {
    // Your code here
    console.log(`The value is: ${value}`);
};

numArray1.forEach(namedFunction);

console.log(`\n`);

// Arrow Function:
// Concise syntax, ideal for short callback functions.
numArray1.forEach(value => {
    // Your code here
    console.log(`The value is: ${value}`);
});

console.log(`\n`);

// Callback with Parameters:
// Allows access to index and array, providing more control.
numArray1.forEach(function(value, index, array) {
    // Your code here
    console.log(`Value: ${value}, Index: ${index}, Array Length: ${array.length}`);
});
