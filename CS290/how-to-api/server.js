var express = require('express'),
    app = express(),
    handlebars = require('express-handlebars'),
    bodyParser = require('body-parser'),
    brewerydb = require('brewerydb-node');

app.engine('hbs', handlebars({defaultLayout: 'main', extname:'.hbs'}));
app.set('view engine', 'hbs');
app.set('port', 3000);

app.use(express.static('public'));
app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());

app.get('/', function(req,res){
  res.render('home');
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
