const listEl = document.getElementsByTagName("ul")[0];
const heading = document.querySelector("h2");

const newListEl = (name) => {
  const li = document.createElement("li");
  li.textContent = name;
  return li;
};

const kaleEl = newListEl("kale");
const creamEl = newListEl("cream");

listEl.prepend(kaleEl);
listEl.append(creamEl);

const liEl = document.querySelectorAll("li");

liEl.forEach((li) => {
  li.classList.add("cool");
});

const totalItems = () => {
  const span = document.createElement("span");
  span.textContent += liEl.length;
  return span;
};

heading.append(totalItems());
