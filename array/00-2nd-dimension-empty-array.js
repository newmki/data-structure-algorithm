const X = 10;
let array1 = new Array(X);
let array2 = [...array1];
let array3 = array2.map(() => []);
let array4 = [...Array(X)].map(() => []);
console.log(array1);
console.log(array2);
console.log(array3);
console.log(array4);
