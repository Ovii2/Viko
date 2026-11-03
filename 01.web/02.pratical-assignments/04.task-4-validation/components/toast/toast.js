export const toast = () => {
  const toastContainer = document.createElement("div");
  toastContainer.classList.add("toast");

  toastContainer.innerHTML = `
    <div class="toast-content">
      <img src="../../assets/icons/check_circle.svg" alt="Atlikta" />
      <p class="text">Nustaymai išsaugoti</p>
    </div>
  `;

  document.body.append(toastContainer);
  setTimeout(() => {
    toastContainer.classList.add("toast-exit");

    toastContainer.addEventListener(
      "animationend",
      () => {
        toastContainer.remove();
      },
      { once: true },
    );
  }, 3000);
};
