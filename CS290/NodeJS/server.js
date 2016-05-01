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

app.get('/session',function(req,res,next){
  var context = {};
  //If there is no session, go to the main page.
  if(!req.session.name){
    res.render('newSession', context);
    return;
  }
  context.name = req.session.name;
  context.toDoCount = req.session.toDo.length || 0;
  context.toDo = req.session.toDo || [];
  console.log(context.toDo);
  res.render('toDo',context);
});

app.post('/session',function(req,res){
  var context = {};

  if(req.body['New List']){
    req.session.name = req.body.name;
    req.session.toDo = [];
    req.session.curId = 0;
  }

  //If there is no session, go to the main page.
  if(!req.session.name){
    res.render('newSession', context);
    return;
  }

  if(req.body['Add Item']){
    req.session.toDo.push({"name":req.body.name, "id":req.session.curId});
    req.session.curId++;
  }

  if(req.body['Done']){
    req.session.toDo = req.session.toDo.filter(function(e){
      return e.id != req.body.id;
    })
  }

  context.name = req.session.name;
  context.toDoCount = req.session.toDo.length;
  context.toDo = req.session.toDo;
  console.log(context.toDo);
  res.render('toDo',context);
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
