const strings = ["Rokas", "Vainas", "Albertas", "Narimantas", "Lukas"];

const blackboard = document.querySelector("#blackboard");

const longestName = (strings) => {
  let longest = strings[0];
  for (let i = 0; i < strings.length; i++) {
    if (strings[i].length > longest.length) {
      longest = strings[i];
    }
  }
  return longest;
};

const name = `Ilgiausias vardas: ${longestName(strings)}`;
blackboard.innerHTML = name;
