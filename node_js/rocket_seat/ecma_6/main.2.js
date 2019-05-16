function scopeTest(x) {
    let y = 2;
    console.log(x, y);

    var z = 7;
    const w = 9;

    if(x > 5) {
        let z = 3;
        let y = 4;
        console.log(x, y, z, w);
    }
    
    console.log(x, y, z, w);

    function nestedFunction(data) {
        console.log(data);
        console.log(x, y, z, w);
    }

    nestedFunction("foi");
}


scopeTest(10);

console.log(z)