import processing.serial.*; // Import the serial library

Serial myPort;
String val;
float temperature = 0;
boolean rapidIncreaseDetected = false;
String portName;

void setup() {
  size(1000, 600);
  println(Serial.list());
  portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);
  myPort.bufferUntil('\n');
  textFont(createFont("Verdana", 35));
  textAlign(CENTER, CENTER); // Add this line to center the text
}

void draw() {
  if (rapidIncreaseDetected) {
    background(250, 155, 195);
    fill(255);
    text("Alert!! \n\n High Stress Levels. \n\n Guided breathing executed. \n\n Inhale as the lights turn on & exhale as they turn off.", width / 2, height / 2);
  } else {
    background(169, 229, 252);
    fill(255);
    text("Stress Levels: \n\n Normal", width / 2, height / 2);
  }
}

void serialEvent(Serial p) {
  val = p.readStringUntil('\n');
  if (val != null) {
    val = trim(val);
    println("Received: " + val);
    if (val.equals("ALERT")) {
      rapidIncreaseDetected = true;
      println("Rapid temperature increase detected!");
    } else {
      try {
        temperature = float(val);
        println("Converted temperature: " + temperature);
        rapidIncreaseDetected = false;
      } catch (Exception e) {
        println("Error converting to float: " + val);
      }
    }
  }
}
