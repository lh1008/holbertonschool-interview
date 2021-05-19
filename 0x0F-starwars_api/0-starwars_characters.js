#!/usr/bin/node

const request = require('request');

const consoleArg = process.argv.slice(2);

const options = `https://swapi-api.hbtn.io/api/films/${consoleArg}`;

request(options, async (error, response, data) => {
  if (!error) {
    const characters = JSON.parse(data).characters;
    for (const id in characters) {
      await new Promise((resolve, reject) => {
        request(characters[id], (error, response, data) => {
          if (!error) {
            console.log(JSON.parse(data).name);
            resolve();
          }
        });
      });
    }
  }
});
