function testVar() {
    var x = 1; // 'var' declaration
    if (true) {
        var x = 2; // Same 'x', because 'var' is function-scoped
        console.log("Inside if block (var):", x); // 2
    }
    console.log("Outside if block (var):", x); // 2
}

function testLet() {
    let y = 1; // 'let' declaration
    if (true) {
        let y = 2; // New 'y', because 'let' is block-scoped
        console.log("Inside if block (let):", y); // 2
    }
    console.log("Outside if block (let):", y); // 1
}

testVar();
testLet();
