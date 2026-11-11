const multiplicationOutputEl = document.querySelector(".multiplication-output");
const additionOutputEl = document.querySelector(".addition-output");

const arithmeticOperation = (operation, sign, number) => {
  if (sign !== "+" && sign !== "*") {
    console.error(`Unkown sign: ${sign}.`);
    return "";
  }
  let msg = `${operation} table of ${number}<br><br>`;
  for (let i = 1; i <= 10; i++) {
    switch (sign) {
      case "*":
        msg += `${i} ${sign} ${number} = ${i * number}<br>`;
        break;
      case "+":
        msg += `${i} ${sign} ${number} = ${i + number}<br>`;
        break;
    }
  }
  return msg;
};

multiplicationOutputEl.innerHTML = arithmeticOperation("Multiplication", "*", 3);
additionOutputEl.innerHTML = arithmeticOperation("Addition", "+", 3);
