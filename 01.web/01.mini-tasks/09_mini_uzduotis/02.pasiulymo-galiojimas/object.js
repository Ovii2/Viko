function Hotel(name, roomRate, discount) {
  this.name = name;
  this.roomRate = roomRate;
  this.discount = discount;
  this.offerPrice = function () {
    return this.roomRate * ((100 - this.discount) / 100);
  };
}

const hotelPark = new Hotel("Park", 240, 15);
const hotelCity = new Hotel("City", 180, 10);

const hotels = [hotelPark, hotelCity];

const hotelsHtml = hotels
  .map((hotel) => {
    return `
  <div class="hotelName">${hotel.name}</div>
  <div class="roomRate">${hotel.roomRate.toFixed(2)}</div>
  <div class="specialRate">${hotel.offerPrice().toFixed(2)}</div>
  `;
  })
  .join("");

const hotelsEl = document.querySelector(".hotels");

hotelsEl.innerHTML = hotelsHtml;

const DAYS_UNTIL_EXPIRY = 7;

const getExpiryDate = () => {
  const today = new Date();
  const expiryDate = new Date(today);
  expiryDate.setDate(today.getDate() + DAYS_UNTIL_EXPIRY);
  return expiryDate;
};

const formatExpiryMessage = (date) => {
  const dayName = date.toLocaleDateString("en-GB", { weekday: "long" });
  const fullDate = date.toLocaleDateString("en-GB", {
    day: "numeric",
    month: "long",
    year: "numeric",
  });

  return `Offer expires next ${dayName} (${fullDate})`;
};

const expiryMsg = formatExpiryMessage(getExpiryDate());
const offerEndsEl = document.getElementById("offerEnds");

offerEndsEl.textContent = expiryMsg;
document.title += ` ${expiryMsg}`;
