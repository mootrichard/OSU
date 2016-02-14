// Author: Richard Moot
// Date: February 14, 2016
// Description: Utilizing AJAX to do GET and POST requests to API's

function weatherReq(){
  var req = new XMLHttpRequest(),
      appID = "&APPID=5dcaafafdf3ebfd527a59c9e15f6947e",
      zipCode = document.getElementById('zip').value,
      units = "&units=imperial",
      url = "http://api.openweathermap.org/data/2.5/forecast/city?zip=" + zipCode + units +  appID,
      resp;
  document.getElementById('city').innerText = "";
  document.getElementById('city').style.color = 'black';
  document.getElementById('temperature').innerText = "";
  if(zipCode.length != 5){
    document.getElementById('city').appendChild(document.createTextNode('Invalid Zip Code'));
    document.getElementById('city').style.color = 'red';
  }
  else{
    req.open("GET", url, true);
    req.send();
  }
  req.onreadystatechange = function(){
    if(req.readyState == 4 && req.status == 200){
      resp = JSON.parse(req.response);
      console.log(resp);
      document.getElementById('city').innerText = resp.city.name;
      document.getElementById('temperature').innerText = "Current temprature: " + resp.list[0].main.temp + "\xB0 F";
      document.getElementById('clouds').innerText = "Description: " + resp.list[0].weather[0].description;
    }
  }
}

function httpPost(){
  var req = new XMLHttpRequest(),
      sendData = {},
      url = 'http://httpbin.org/post';
  sendData = {
    firstName: document.getElementById('firstName').value,
    lastName: document.getElementById('lastName').value,
    email: document.getElementById('email').value
  };
  req.open('POST', url, true);
  req.setRequestHeader("Content-Type", "application/json");
  req.send(JSON.stringify(sendData));
  req.onreadystatechange = function(){
    if(req.readyState == 4 && req.status == 200){
      var resp = JSON.parse(req.response),
          firstNode = document.createElement('p'),
          lastNode = document.createElement('p'),
          emailNode = document.createElement('p');

      for (var prop in resp.json){
        var newNode = document.createElement('p');
        newNode.innerText = prop + ": " + resp.json[prop];
        document.getElementById('http-post-results').appendChild(newNode);
      }
      console.log(resp);
    }
  }
}
