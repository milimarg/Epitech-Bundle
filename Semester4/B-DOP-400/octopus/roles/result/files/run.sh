#!/bin/bash

while IFS= read -r line; do
    export "$line"
done < "./.env.result"

/usr/bin/node /opt/result/server.js
