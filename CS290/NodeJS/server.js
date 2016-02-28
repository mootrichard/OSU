var express = require('express'),
    app = express(),
    handlebars = require('express-handlebars'),
    bodyParser = require('body-parser'),
    session = require('express-session');

app.engine('handlebars', handlebars({defaultLayout: 'main'}));
app.set('view engine', 'handlebars');
app.set('port', 3000);

app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());
app.use(session({secret:'thisIsAsecret'}));

app.get('/', function(req, res) {
  if(req.originalUrl === '/'){
    res.render('home', {title: "No Request made yet", data: {none: "No query has been requested"}});
  }
  else {
    res.render('home', {title: "GET Request", data: req.query});
  }
  //console.log(req);
});

app.post('/', function(req, res){
  res.render('home', {title:"POST Request", data: req.body});
});

function genContext(){
  var stuffToDisplay = {};
  stuffToDisplay.time = (new Date(Date.now())).toLocaleTimeString('en-US');
  return stuffToDisplay;
}

app.get('/time',function(req,res){
  res.render('time', genContext());
});

app.get('/count', function(req, res) {
  var context = {};
  context.count = req.session.count || 0;
  req.session.count = context.count + 1;
  res.render('count', context);
})

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
