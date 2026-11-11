const hotel = {
  name: "Park",
  roomRate: 240,
  discount: 15,
  offerPrice() {
    return this.roomRate * ((100 - this.discount) / 100);
  },
};

let hotelName = document.getElementById("hotelName");
let roomRate = document.getElementById("roomRate");
let specialRate = document.getElementById("specialRate");

hotelName.textContent = hotel.name;
roomRate.textContent = `$ ${hotel.roomRate.toFixed(2)}`;
specialRate.textContent = `$ ${hotel.offerPrice()}`;
