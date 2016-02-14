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
      url = 'http://google.com';
}
