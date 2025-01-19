#!/bin/bash

case $1 in
  "short")
    npm run dev
    ;;
  "create")
    (cd prisma && docker-compose up --detach) && sleep 2 && (npx prisma migrate dev --create-only) && npm run dev
    ;;
  *)
    (cd prisma && docker-compose up --detach) && sleep 2 && (npx prisma migrate dev --name init) && npm run dev
    ;;
esac
