let greeting = "Howdy ";
let name = "Molly";
let message = ", please check your order:";

let welcome = greeting + name + message;

let sign = "Montague House";
let tiles = sign.length;
let subTotal = tiles * 5;
let shipping = 7;
let grandTotal = subTotal + shipping;

let el = document.getElementById("greeting");
el.textContent = welcome;

let elSign = document.getElementById("userSign");
elSign.innerHTML = sign;

let elTiles = document.getElementById("tiles");
elTiles.textContent = tiles;

let elSubTotal = document.getElementById("subTotal");
elSubTotal.textContent = "$" + subTotal;

let elShipping = document.getElementById("shipping");
elShipping.textContent = "$" + shipping;

let elGrandTotal = document.getElementById("grandTotal");
elGrandTotal.textContent = "$" + grandTotal;
