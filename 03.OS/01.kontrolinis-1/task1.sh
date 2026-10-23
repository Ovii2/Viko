#!/bin/bash

failas=$1
katalogas=$2

if [ -z "$failas" ]; then
  echo "Įveskite failo pavadinimą:"
  read -r failas
fi

if [ -z "$katalogas" ]; then
  echo "Įveskite katalogo pavadinimą:"
  read -r katalogas
fi

if [ -f "$failas" ] || [ -d "$katalogas" ]; then
  rm "$failas"
  cd "$katalogas"
  touch "$failas"
  echo "Failas pavadinimu $failas sėkmingai sukurtas."
else
  echo "Failas arba katalogas nerastas."
fi
