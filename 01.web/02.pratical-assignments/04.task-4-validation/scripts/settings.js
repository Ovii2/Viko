import { toast } from "../components/toast/toast.js";

const lightThemeBtn = document.querySelector(".theme-light");
const darkThemeBtn = document.querySelector(".theme-dark");
const defaultThemeBtn = document.querySelector(".theme-default");

const saveBtn = document.querySelector(".save-button");
const resetBtn = document.querySelector(".reset-button");

const documentEl = document.documentElement;

lightThemeBtn.addEventListener("click", (e) => {
  documentEl.classList.remove("dark-theme");
});

darkThemeBtn.addEventListener("click", (e) => {
  documentEl.classList.add("dark-theme");
});

saveBtn.addEventListener("click", (e) => {
  if (documentEl.classList.contains("dark-theme")) {
    localStorage.setItem("theme", "dark");
  } else {
    localStorage.setItem("theme", "light");
  }
  toast();
});
