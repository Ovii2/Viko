let table = 3;
let i = 1;
let msg = "";

while (i < 11) {
  msg += `${i} + ${table} = ${i + table}`;
  msg += `&nbsp; ${i} * ${table} = ${i * table}<br>`;
  i++;
}

let el = document.getElementById("blackboard");
el.innerHTML = msg;
