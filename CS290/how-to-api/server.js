var express = require('express'),
    app = express(),
    handlebars = require('express-handlebars'),
    bodyParser = require('body-parser'),
    brewerydb = require('brewerydb-node'),
    brewdb = new brewerydb('fa05b9dc34be20efb73fc21f7fbdcd5e');
    request = require('request');

app.engine('hbs', handlebars({defaultLayout: 'main', extname:'.hbs'}));
app.set('view engine', 'hbs');
app.set('port', 3000);

app.use(express.static('public'));
app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());

app.get('/', function(req,res){
  res.render('home');
});

app.get('/start', function(req, res){
  res.render('start');
})

app.get('/test-key', function(req, res){
  res.render('test-key');
})

app.get('/libraries', function(req,res){
  res.render('libraries');
});

app.get('/endpoints', function(req, res){
  res.render('endpoints');
});

app.get('/user-test', function(req,res){
  var userApiKey = req.query.apiKey;
  var userBrewerydb = req.query.apiKey.length > 0 ? new brewerydb('userApiKey'): new brewerydb('fa05b9dc34be20efb73fc21f7fbdcd5e');
  var userResponse = userBrewerydb.beer.find({name:"Sculpin IPA"}, function(err, data){
    res.send(data);
  })
});

app.use(function(req,res){
  res.type('text/plain');
  res.status(404);
  res.send('404 - Not Found');
});

app.use(function(err, req, res, next){
  console.error(err.stack);
  res.type('plain/text');
  res.status(500);
  res.send('500 - Server Error');
});

app.listen(app.get('port'), function(req, res) {
  console.log('Express started on http://localhost:' + app.get('port') + '; Press Ctrl+C to terminate.')
});
