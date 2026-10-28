export const validateName = (value) => {
  const min = 3;
  const max = 50;
  const name = value.trim();

  if (name === "") {
    return "Įveskite vardą.";
  }

  if (name.length < min || name.length > max) {
    return `Vardą turi sudaryti nuo ${min} iki ${max} simbolių.`;
  }

  return "";
};

export const validateEmail = (value) => {
  const email = value.trim();

  if (email === "") {
    return "Įveskite el.paštą.";
  }

  const emailPattern = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;

  if (!email.match(emailPattern)) {
    return "Įveskite tinkamą el. pašto adresą.";
  }

  return "";
};

export const validateTravelDate = (value) => {
  const date = value.trim();

  if (date === "") {
    return "Pasirinkite kelionės datą.";
  }

  const now = new Date();
  const year = now.getFullYear();
  const month = String(now.getMonth() + 1).padStart(2, "0");
  const day = String(now.getDate()).padStart(2, "0");
  const today = `${year}-${month}-${day}`;

  if (date < today) {
    return "Kelionės data negali būti praeityje.";
  }

  return "";
};

export const validateDestination = (value) => {
  const destination = value.trim();

  if (destination === "") {
    return "Pasirinkite kelionės kryptį.";
  }
};

export const validateTravelGroup = (value) => {
  if (!value) {
    return "Pasirinkite, kaip keliausite.";
  }

  return "";
};
