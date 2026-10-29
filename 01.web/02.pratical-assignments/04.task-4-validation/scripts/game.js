const generateRandomNumber = () => Math.floor(Math.random() * 100) + 1;

let answer = generateRandomNumber();
// console.log(`Atsakymas : ${answer}`);

let min;
let max;

const updateRange = () => {
  min = Math.max(1, answer - 10);
  max = Math.min(100, answer + 10);
  rangeLimit.textContent = `${min} - ${max}`;
};

const attempts = [];

const attemptsCount = document.querySelector(".attempts-count");
const rangeLimit = document.querySelector(".range-limit");
const numberInput = document.querySelector(".number");
const guessBtn = document.querySelector(".guess-btn");
const giveupBtn = document.querySelector(".giveup-btn");
const newGameBtn = document.querySelector(".new-game-btn");
const guessResult = document.querySelector(".guess-result");
const historyBody = document.querySelector(".guess-history-table tbody");

attemptsCount.textContent = attempts.length;
updateRange();

const showInitialMessage = () => {
  guessResult.textContent = "Dar nespėjai!";
};

showInitialMessage();

guessBtn.addEventListener("click", () => {
  const guess = Number(numberInput.value);

  if (!Number.isInteger(guess) || guess < min || guess > max) {
    guessResult.textContent = `Įveskite sveiką skaičių nuo ${min} iki ${max}.`;
    return;
  }

  attempts.push(guess);
  attemptsCount.textContent = attempts.length;

  if (guess < answer) {
    guessResult.textContent = "Mano skaičius didesnis.";
  } else if (guess > answer) {
    guessResult.textContent = "Mano skaičius mažesnis.";
  } else {
    guessResult.textContent = "Atspėjai!";
    endGame();
  }

  const emptyHistory = historyBody.querySelector(".empty-history");

  if (emptyHistory) {
    emptyHistory.remove();
  }

  const row = historyBody.insertRow(0);

  row.insertCell().textContent = guess;
  row.insertCell().textContent = guess < answer ? "↑" : guess > answer ? "↓" : "✓";
  row.insertCell().textContent = guess < answer ? "Per mažas" : guess > answer ? "Per didelis" : "Atspėjai";
});

giveupBtn.addEventListener("click", () => {
  guessResult.textContent = `Atsakymas: ${answer}`;
  endGame();
});

newGameBtn.addEventListener("click", () => {
  restartGame();
});

const endGame = () => {
  guessBtn.disabled = true;
  giveupBtn.disabled = true;
  numberInput.disabled = true;
};

const restartGame = () => {
  historyBody.innerHTML = `
  <tr class="empty-history">
    <td colspan="3">Spėjimų nėra</td>
  </tr>
`;
  attempts.length = 0;
  attemptsCount.textContent = 0;
  numberInput.value = "";
  guessResult.textContent = "";
  answer = generateRandomNumber();
  updateRange();
  showInitialMessage();
  guessBtn.disabled = false;
  giveupBtn.disabled = false;
  numberInput.disabled = false;
};
