var SerialPort = require('serialport');
var port = new SerialPort('/dev/ttyACM0',{
  baudrate : 115200,
  parser: SerialPort.parsers.readline('\n')
});

var keypress = require('keypress');
keypress(process.stdin);

process.stdin.on('keypress', function (ch, key) {
  if (key && key.ctrl && key.name == 'c') {
    process.stdin.pause();
    process.exit();
  }
  else if (key && key.ctrl && key.name == 's') {
    msg = {
      function : 'setAll',
      red : 0,
      green : 20,
      blue : 20
    }
    port.write(JSON.stringify(msg), function(err){
      if (err) {
        return console.log('Error on write: ', err.message);
      }
      console.log({'Serial-OUT':JSON.stringify(msg)});
    });
  }
});

process.stdin.setRawMode(true);
process.stdin.resume();

port.on('open', function(){
  console.log("SerialPort open!")
});

port.on('data', function(data){
  console.log(JSON.parse(data))
});
