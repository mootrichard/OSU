function weatherReq(){
  var req = new XMLHttpRequest(),
      appID = "APPID=5dcaafafdf3ebfd527a59c9e15f6947e",
      zipCode = document.getElementById('zip').value,
      url = "http://api.openweathermap.org/data/2.5/forecast/city?zip=" + zipCode + "&" + appID;
  if(zipCode.length != 5){
    document.getElementById('current-weather').appendChild(document.createTextNode('Invalid Zip Code'));
  }
  else{
    req.open("GET", url, true);
    req.send();
  }
  req.onreadystatechange = function(){
    if(req.readyState == 4 && req.status == 200){
      console.log(JSON.parse(req.response));
      document.getElementById('current-weather').appendChild(document.createTextNode(req.response))
    }
  }
}
