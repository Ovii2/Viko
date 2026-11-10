const ideaInput = document.querySelector(".idea");
const ideaCounter = document.querySelector(".idea-counter");

ideaInput.addEventListener("input", () => {
  ideaCounter.textContent = `${ideaInput.value.length}/${ideaInput.maxLength}`;
});
