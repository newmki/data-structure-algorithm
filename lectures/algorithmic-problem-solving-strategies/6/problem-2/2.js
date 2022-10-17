/** C++와 다르게 동작한다 */

function printPicked(picked) {
  console.log(picked);
}

function pick(n, picked, toPick) {
  if (toPick === 0) {
    return printPicked(picked);
  }

  const smallest = picked.length === 0 ? 0 : picked[picked.length - 1];
  for (let i = smallest; i < n; ++i) {
    picked.push(i);
    pick(n, picked, toPick - 1);
    picked.pop();
  }
}

let arr = Array();
pick(7, arr, 4);
