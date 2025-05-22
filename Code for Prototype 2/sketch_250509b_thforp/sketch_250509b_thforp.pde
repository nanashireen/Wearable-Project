import processing.serial.*;

Serial myPort;
String serialData;

void setup() {
  size(400, 300);
  println(Serial.list());
  String portName = Serial.list()[0]; // Imports arduino
  myPort = new Serial(this, portName, 9600);
  myPort.bufferUntil('\n');
}

void draw() {
  background(150, 236, 255);
  
  if (myPort.available() > 0) {
    serialData = myPort.readStringUntil('\n');
    println("Received: " + serialData); //Prints recieved temperature
    if (serialData = "") {
      background()
  }
}
