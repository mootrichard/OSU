"use strict";
var express = require('express'),
    app = express(),
    handlebars = require('express-handlebars'),
    bodyParser = require('body-parser'),
    mysql = require('mysql');

var pool = mysql.createPool({
  host  : 'localhost',
  user  : 'student',
  password: 'default',
  database: 'student',
});

app.engine('hbs', handlebars({defaultLayout: 'main', extname:'.hbs', helpers: {dateFormat: require('handlebars-dateformat')}}));
app.set('view engine', 'hbs');
app.set('port', 8000);

app.use(express.static('public'));
app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());

app.get('/', function(req, res, next) {
  var context = {};
  pool.query('SELECT * FROM workouts', function(err, results){
    if(err){
      next(err);
      return;
    }
    context.results = results;
    res.render('home', context);
  });
});

app.post('/add-workout', function(req, res, next){
  var insertQuery = 'INSERT INTO workouts (name, reps, weight, date, lbs) values (';

  insertQuery = insertQuery.concat(
    "'" , req.body.name , "'" , ',' ,
    "'" , req.body.reps , "'" , ',' ,
    "'" , req.body.weight , "'" , ',' ,
    "'" , req.body.date , "'" , ',' ,
    "'" , req.body.units, "'" , ')');

  pool.query(insertQuery,function(err, result){
    if(err){
      next(err);
      return;
    }else{
      req.body.id = result.insertId;
      req.body.layout = false;
      req.body.units = parseInt(req.body.units);
      res.render('add', req.body);
    }
  });
});

app.delete('/delete-workout', function(req, res, next){
  if( req.body.id !== undefined){
    var deleteQuery = "DELETE FROM workouts WHERE id=";
    deleteQuery = deleteQuery.concat( req.body.id);
    pool.query(deleteQuery, function(err, results){
      if(err){
        next(err);
        return;
      } else{
        res.send(req.body.id);
      }
    })
  }
  else{
    res.send("Error: No ID provided");
  }
});

app.post('/update-workout', function(req, res, next){
  var updateQuery = 'UPDATE workouts SET ';

  updateQuery = updateQuery.concat(
    "name='" , req.body.name , "'" , ',' ,
    "reps='" , req.body.reps , "'" , ',' ,
    "weight='" , req.body.weight , "'" , ',' ,
    "date='" , req.body.date , "'" , ',' ,
    "lbs='" , req.body.units, "'" , ' WHERE id=', req.body.id);

    pool.query(updateQuery, function(err, results){
      if(err){
        next(err);
        return;
      } else{
        res.send(req.body);
      }
    })
});

app.get('/reset-table',function(req,res,next){
  var context = {};
  pool.query("DROP TABLE IF EXISTS workouts", function(err){
    var createString = "CREATE TABLE workouts("+
    "id INT PRIMARY KEY AUTO_INCREMENT,"+
    "name VARCHAR(255) NOT NULL,"+
    "reps INT,"+
    "weight INT,"+
    "date DATE,"+
    "lbs BOOLEAN)";
    pool.query(createString, function(err){
      context = {tableReset:"Table has been reset"};
      res.render('home',context);
    })
  });
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
