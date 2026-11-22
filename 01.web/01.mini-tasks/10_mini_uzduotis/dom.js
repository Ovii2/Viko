const noteInput = document.getElementById("noteInput");
const noteName = document.getElementById("noteName");
const recordButton = document.querySelector("[data-state]");

const writeLabel = () => {
  noteName.textContent = noteInput.value;
};

const record = (button) => {
  button.dataset.state = "stop";
  button.textContent = "stop";
};

const stop = (button) => {
  button.dataset.state = "record";
  button.textContent = "record";
};

const recorderControls = (e) => {
  e.preventDefault();

  switch (recordButton.dataset.state) {
    case "record":
      record(recordButton);
      break;
    case "stop":
      stop(recordButton);
      break;
    default:
      console.error(`Unknown state: ${recordButton.dataset.state}`);
      break;
  }
};

noteInput.addEventListener("input", writeLabel);
recordButton.addEventListener("click", recorderControls);
