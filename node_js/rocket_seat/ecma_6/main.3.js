const printLine = (data, data2) => console.log("---------------------- " + data, data2);


function teste1(data) {
    console.log(data);
}

teste1('data 1');


printLine("", "");


const myArray = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];

myArray.map(function(value) {
    console.log(value);
});


printLine("", "");


myArray.map((value, index) => {
    console.log(value, index);
});


printLine("", "");


myArray.map( (value, index) => console.log(value, index) );


printLine("", "");


myArray.map( value => console.log(value) );