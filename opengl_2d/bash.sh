#!/bin/bash

file="main.cpp"  # Ім'я файлу, який потрібно коментувати/розкоментувати
line_number=93  # Номер рядка, який потрібно коментувати/розкоментувати
compile_command="make"

while true; do
  read -n1 key

  if [[ $key == "a" ]]; then
    sed -i "${line_number}s|^|//|" "$file"  # Коментуємо рядок за допомогою 'sed'
    $compile_command
  elif [[ $key == "r" ]]; then
    sed -i "${line_number}s|^//||" "$file"  # Розкоментовуємо рядок за допомогою 'sed'
    $compile_command
  fi

done

