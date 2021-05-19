#!/usr/bin/node

const https = require('https')

const consoleArg = process.argv[2];

const options = {
  hostname: 'swapi-api.hbtn.io',
  port: 443,
  path: '/api/films/' + consoleArg + '/',
  method: 'GET'
}

console.log('arg: ', consoleArg);

const req = https.request(options, res => {
  console.log(`statusCode: ${res.statusCode}`)

  res.on('data', d => {
    process.stdout.write(d);
    const obj = JSON.parse(d, function (key, value) {
      if (key == "characters") {
	console.log(value)
	console.log(JSON.stringify(value));
      }
    })
    const characters = JSON.parse(d).characters;
    console.log(characters);

  })
})

req.on('error', error => {
  console.error(error)
})

req.end()
