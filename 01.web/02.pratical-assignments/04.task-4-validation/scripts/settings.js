import { toast } from "../components/toast/toast.js";

const lightThemeBtn = document.querySelector(".theme-light");
const darkThemeBtn = document.querySelector(".theme-dark");
const defaultThemeBtn = document.querySelector(".theme-default");

const saveBtn = document.querySelector(".save-button");
const resetBtn = document.querySelector(".reset-button");

const backgroundGreenBtn = document.querySelector(".background-green");
const backgroundCreamBtn = document.querySelector(".background-cream");
const backgroundBlueBtn = document.querySelector(".background-blue");
const backgroundGrayBtn = document.querySelector(".background-gray");

const fontGreenBtn = document.querySelector(".font-green");
const fontGrayBtn = document.querySelector(".font-gray");
const fontBlackBtn = document.querySelector(".font-black");

const fontGreenTxt = document.querySelector(".font-green-text");
const fontGrayTxt = document.querySelector(".font-gray-text");
const fontBlackTxt = document.querySelector(".font-black-text");

const documentEl = document.documentElement;

lightThemeBtn.addEventListener("click", (e) => {
  documentEl.classList.remove("dark-theme");
});

darkThemeBtn.addEventListener("click", (e) => {
  documentEl.classList.add("dark-theme");
  fontGreenTxt.textContent = "Šviesiai žalia";
  fontGrayTxt.textContent = "Šviesiai pilka";
  fontBlackTxt.textContent = "Balta";
});

backgroundGreenBtn.addEventListener("click", (e) => {
  documentEl.style.setProperty("--color-background", "var(--color-green-background)");
});

backgroundCreamBtn.addEventListener("click", (e) => {
  documentEl.style.setProperty("--color-background", "var(--color-cream-background)");
});

backgroundBlueBtn.addEventListener("click", (e) => {
  documentEl.style.setProperty("--color-background", "var(--color-blue-background)");
});

backgroundGrayBtn.addEventListener("click", (e) => {
  documentEl.style.setProperty("--color-background", "var(--color-gray-background)");
});

fontGreenBtn.addEventListener("click", (e) => {
  documentEl.style.setProperty("--color-text", "var(--color-primary)");
});

fontGrayBtn.addEventListener("click", (e) => {
  documentEl.style.setProperty("--color-text", "var(--color-font-gray)");
});

fontBlackBtn.addEventListener("click", (e) => {
  documentEl.style.setProperty("--color-text", "var(--color-font-black)");
});

saveBtn.addEventListener("click", (e) => {
  if (documentEl.classList.contains("dark-theme")) {
    localStorage.setItem("theme", "dark");
  } else {
    localStorage.setItem("theme", "light");
  }
  localStorage.setItem("backgroundColor", documentEl.style.getPropertyValue("--color-background"));
  localStorage.setItem("fontColor", documentEl.style.getPropertyValue("--color-text"));
  toast("Nustatymai išsaugoti");
});

resetBtn.addEventListener("click", () => {
  localStorage.clear();
  documentEl.classList.remove("dark-theme");
  documentEl.style.removeProperty("--color-background");
  documentEl.style.removeProperty("--color-text");
  toast("Nustatymai atkurti");
});
