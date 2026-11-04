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

const documentEl = document.documentElement;

lightThemeBtn.addEventListener("click", (e) => {
  documentEl.classList.remove("dark-theme");
});

darkThemeBtn.addEventListener("click", (e) => {
  documentEl.classList.add("dark-theme");
});

backgroundGreenBtn.addEventListener("click", (e) => {
  documentEl.style.setProperty("--color-background", "var(--color-green-background)");
});

backgroundCreamBtn.addEventListener("click", () => {
  documentEl.style.setProperty("--color-background", "var(--color-cream-background)");
});

backgroundBlueBtn.addEventListener("click", (e) => {
  documentEl.style.setProperty("--color-background", "var(--color-blue-background)");
});

backgroundGrayBtn.addEventListener("click", (e) => {
  documentEl.style.setProperty("--color-background", "var(--color-gray-background)");
});

saveBtn.addEventListener("click", (e) => {
  if (documentEl.classList.contains("dark-theme")) {
    localStorage.setItem("theme", "dark");
  } else {
    localStorage.setItem("theme", "light");
  }
  localStorage.setItem("backgroundColor", documentEl.style.getPropertyValue("--color-background"));
  toast();
});
