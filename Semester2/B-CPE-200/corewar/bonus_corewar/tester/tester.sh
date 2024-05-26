#!/bin/bash

asm_path="../../asm/asm"
intra_asm_path="../../corewar_binaries/asm/asm"

RED="\e[0;31m"
GREEN="\e[0;32m"
RESET="\e[0m"

TESTS_PASSED=0
TESTS_TOTAL=0

clear

echo -e "COREWAR\n" | lolcat
for file in $(/bin/ls -p "../../Players/Assembly/" | grep -v "/"); do
  filename=$(echo $file | grep -Eo ".*[^.][^s]")
  $asm_path "../../Players/Assembly/$file" &> /dev/null
  mv ../../Players/Assembly/*.cor ../../Players/Compiled/
  $intra_asm_path "../../Players/Assembly/$file"
  mv ./*.cor ../../Players/Compiled/intra
  cmp "../../Players/Compiled/$filename""cor" "../../Players/Compiled/intra/$filename""cor" &> /dev/null
  if [[ $? -eq 0 ]]; then
    echo -e "$GREEN$file$RESET"
    TESTS_PASSED=$((TESTS_PASSED+1))
  else
    echo -e "$RED$file$RESET";
  fi
  TESTS_TOTAL=$((TESTS_TOTAL+1))
done

echo "TESTS PASSED: $TESTS_PASSED / $TESTS_TOTAL"
