'use strict'
var express = require('express');
var fs = require('fs');
var bodyParser = require('body-parser');
var app = express();
app.use(express.static(__dirname + '/public'));
app.use(bodyParser.json())
var idMapperService = require('./services/idMapperService.js')();

var routes = require('./routes/router.js')(app, idMapperService);
var midiSerialService;
idMapperService.getMappings().then(
  (data) => { midiSerialService = require("./services/midiSerialService.js")(data); },
  (err) => { process.exit(err); }
)
idMapperService.addListener(midiSerialService);
app.listen(3000, function () {
    console.log("Listening on port 3000");
});
