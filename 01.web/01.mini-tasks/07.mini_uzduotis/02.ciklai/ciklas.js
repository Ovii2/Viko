let table = 3;
let i = 1;
let msg = "";

let addittionEl = document.querySelector(".addition");
let multiplicationEl = document.querySelector(".multiplication");

while (i < 11) {
  let addition = `${i} + ${table} = ${i + table}<br>`;
  addittionEl.innerHTML += addition;

  let multiplication = `${i} * ${table} = ${i * table}<br>`;
  multiplicationEl.innerHTML += multiplication;
  i++;
}

// let el = document.getElementById("blackboard");
// el.innerHTML = msg;
