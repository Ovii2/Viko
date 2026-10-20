export function initMenu() {
  const menuButton = document.querySelector(".menu-toggle");
  const navigation = document.querySelector(".navigation");

  menuButton.setAttribute("aria-expanded", "false");

  menuButton.addEventListener("click", () => {
    const isOpen = navigation.classList.toggle("is-open");
    menuButton.setAttribute("aria-expanded", String(isOpen));
  });

  const headerMenu = document.querySelector(".header-menu");

  document.addEventListener("click", (event) => {
    if (!headerMenu.contains(event.target)) {
      navigation.classList.remove("is-open");
      menuButton.setAttribute("aria-expanded", "false");
    }
  });
}
