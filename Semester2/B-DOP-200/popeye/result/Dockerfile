FROM node:12.0.0-alpine

RUN mkdir /views/

COPY package.json /
COPY server.js /
COPY views/ /views/

RUN npm install

EXPOSE 80

CMD ["node", "/server.js"]
