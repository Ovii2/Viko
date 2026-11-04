const documentEl = document.documentElement;

const theme = localStorage.getItem("theme");
const backgroundColor = localStorage.getItem("backgroundColor");

switch (theme) {
  case "dark":
    documentEl.classList.add("dark-theme");
    break;
  case "light":
    documentEl.classList.remove("dark-theme");
    break;
  default:
    documentEl.classList.remove("dark-theme");
    break;
}

documentEl.style.setProperty("--color-background", backgroundColor);
