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

const calculateOfferExpiration = () => {
  const date = new Date();
  const year = date.getFullYear;
  console.log(year);
};

calculateOfferExpiration();
