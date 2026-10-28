export const clearSearch = () => {
  const searchInput = document.querySelector(".search");
  const searchClearBtn = document.querySelector(".search-clear-btn");

  const updateClearButton = () => {
    searchClearBtn.hidden = searchInput.value.length < 1;
  };

  searchInput.addEventListener("input", updateClearButton);

  searchClearBtn.addEventListener("click", () => {
    searchInput.value = "";
    updateClearButton();
    searchInput.focus();
  });

  updateClearButton();
};
