#!/usr/bin/node

const https = require('https')

const consoleArg = process.argv.slice(2);

const options = {
  hostname: 'swapi-api.hbtn.io',
  port: 443,
  path: '/api/films/' + consoleArg[0] + '/',
  method: 'GET'
}


console.log('arg: ', consoleArg);

switch (consoleArg[0]) {
case 'insult':
    console.log(consoleArg[1], 'smells quite badly.');
    break;
case 'compliment':
    console.log(consoleArg[1], 'is really cool.');
    break;
default:
    console.log('Sorry, that is not something I know how to do.');
}

const req = https.request(options, res => {
  console.log(`statusCode: ${res.statusCode}`)

  res.on('data', d => {
    process.stdout.write(d);
  })
})


req.on('error', error => {
  console.error(error)
})

req.end()
