export const modal = (title, data) => {
  const dialog = document.createElement("dialog");
  dialog.classList.add("modal");

  dialog.innerHTML = `
    <img class="check-icon" src="${new URL("../../assets/icons/check_circle.svg", import.meta.url)}" alt="Atlikta">
    <h2 class="title"></h2>
    <div class="modal-data"></div>
    <form method="dialog">
      <button class="modal-btn" type="submit">Uždaryti</button>
    </form>
  `;

  dialog.querySelector(".title").textContent = title;
  dialog.querySelector(".modal-data").textContent = data;

  dialog.addEventListener("close", () => {
    dialog.remove();
  });

  document.body.append(dialog);
  dialog.showModal();
};
