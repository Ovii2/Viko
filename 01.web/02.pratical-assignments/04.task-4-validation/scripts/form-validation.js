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

  if (name.match(/\d/)) {
    return "Varde negali būti skaičių.";
  }

  return "";
};

export const validateEmail = (value) => {
  const email = value.trim();

  if (email === "") {
    return "Įveskite el.paštą.";
  }

  const emailPattern = /^\S+@\S+\.\S+$/;

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

  return "";
};

export const validateTravelGroup = (value) => {
  if (!value) {
    return "Pasirinkite, kaip keliausite.";
  }

  return "";
};

export const validateInterestsGroup = (value) => {
  if (!value) {
    return "Pasirinkite pomėgį.";
  }

  return "";
};

export const validateCompanionGroup = (value) => {
  if (!value) {
    return "Pasirinkite, su kuo keliaujate.";
  }

  return "";
};

export const validateFrequency = (value) => {
  const frequency = value.trim();

  if (frequency === "") {
    return "Pasirinkite kelionės dažnį.";
  }

  return "";
};
