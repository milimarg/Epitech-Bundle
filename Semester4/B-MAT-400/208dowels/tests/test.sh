#!/bin/bash

tested=0
done=0

got_error=0

while read line; do
  ../208dowels $line > log.txt
  ./208dowelsRef $line > logRef.txt

  sed -e 's/[[:space:]]//g' log.txt > logTruncated.txt
  sed -e 's/[[:space:]]//g' logRef.txt > logRefTruncated.txt

  tested=$((tested+1))

  diff logTruncated.txt logRefTruncated.txt
  if [[ $? -eq 0 ]]; then
    done=$((done+1))
  else
    got_error=1
  fi

done < ./tests.txt

ok_tests=$((tested-done))

if [[ got_error -eq 1 ]]; then
  echo -e "\n\n\n-----"
fi

echo "Total tests: $tested"
echo "$done OK"
echo "$ok_tests KO"
