#!/bin/bash

echo "Įveskite pirmą skaičių nuo 1 iki 9:"
read -r num1

if [ "$num1" -lt 1 ] || [ "$num1" -gt 9 ]; then
  echo "Pirmas skaičius turi būti nuo 1 iki 9."
  exit 1
fi

echo "Įveskite antrą skaičių nuo 1 iki 9:"
read -r num2

if [ "$num2" -lt 1 ] || [ "$num2" -gt 9 ]; then
  echo "Antras skaičius turi būti nuo 1 iki 9."
  exit 1
fi

liekana=$((num1 % num2))

echo "Pirmas skaičius: $num1" >rezultatas.txt
echo "Antras skaičius: $num2" >>rezultatas.txt
echo "Liekana: $liekana" >>rezultatas.txt

if [ "$liekana" -eq 0 ]; then
  echo "$num1 % $num2 = $liekana"
fi
