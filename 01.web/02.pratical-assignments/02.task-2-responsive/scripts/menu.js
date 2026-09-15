export function initMenu() {
  const menuButton = document.querySelector(".menu-toggle");
  const navigation = document.querySelector(".navigation");

  menuButton.setAttribute("aria-expanded", "false");

  menuButton.addEventListener("click", () => {
    const isOpen = navigation.classList.toggle("is-open");
    menuButton.setAttribute("aria-expanded", String(isOpen));
  });

  const links = document.querySelectorAll(".nav-item");
  const currentUrl = window.location.href.endsWith("/") ? window.location.href + "index.html" : window.location.href;

  links.forEach((link) => {
    if (link.href === currentUrl) {
      link.classList.add("active");
    }
  });

  const headerMenu = document.querySelector(".header-menu");

  document.addEventListener("click", (event) => {
    if (!headerMenu.contains(event.target)) {
      navigation.classList.remove("is-open");
      menuButton.setAttribute("aria-expanded", "false");
    }
  });
}
