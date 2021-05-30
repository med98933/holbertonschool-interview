#!/usr/bin/node
const request = require('request');
const URL = 'https://swapi-api.hbtn.io/api/films/' + process.argv[2];
const id = [];
request(URL, function (err, res, body) {
  if (err) console.log(err);
  else if (res.statusCode === 200) {
    const characters = JSON.parse(body).characters;
    for (let i = 0; i < characters.length; i++) {
      id.push({ URL: characters[i], name: '' });
      request(characters[i], function (error, resp, body2) {
        if (error) console.log(error);
        id[i].name = JSON.parse(body2).name;
        if (checkdata(id)) {
          for (let x = 0; x < id.length; x++) {
            console.log(id[x].name);
          }
        }
      });
    }
  }
});
function checkdata (id) {
  for (let i = 0; i < id.length; i++) {
    if (id[i].name === '') { return false; }
  }
  return true;
}
