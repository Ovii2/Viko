const documentEl = document.documentElement;

const theme = localStorage.getItem("theme");
const backgroundColor = localStorage.getItem("backgroundColor");
const fontColor = localStorage.getItem("fontColor");
const fontSize = localStorage.getItem("fontSize");

const addDarkTheme = () => {
  documentEl.classList.add("dark-theme");
  fontGreenTxt.textContent = "Šviesiai žalia";
  fontGrayTxt.textContent = "Šviesiai pilka";
  fontBlackTxt.textContent = "Balta";
};

const removeDarkTheme = () => {
  documentEl.classList.remove("dark-theme");
  fontGreenTxt.textContent = "Tamsiai žalia";
  fontGrayTxt.textContent = "Tamsiai pilka";
  fontBlackTxt.textContent = "Juoda";
};

switch (theme) {
  case "dark":
    documentEl.classList.add("dark-theme");
    break;
  case "light":
    documentEl.classList.remove("dark-theme");
    break;
  default:
    window.matchMedia("(prefers-color-scheme: dark)").matches ? addDarkTheme() : removeDarkTheme();
    break;
}

documentEl.style.setProperty("--color-background", backgroundColor);
documentEl.style.setProperty("--color-text", fontColor);
documentEl.style.setProperty("--font-size", fontSize);
