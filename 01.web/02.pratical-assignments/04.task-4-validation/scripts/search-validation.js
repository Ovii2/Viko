export const validateSearch = (value) => {
  const search = value.trim();

  if (search === "") {
    return "Įveskite paieškos frazę.";
  }

  return "";
};
