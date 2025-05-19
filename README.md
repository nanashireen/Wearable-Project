# Wearable-Project by Nana-Shireen Nduka, Neha Ippili and Aqdas Muhammad Shaban


Our project's goal is a wearable wristband that monitors the wearer's stress levels. This wristband measures the wearer's heart rate (EKG), sweat levels, and skin temperature and then uses these results to determine stress levels. This data will also be accessible within our app. It will also notify users when their stress levels are too high using haptics and a visual alarm, as well as show them breathing exercises to assist lower stress. Our device will be aimed towards young people, particularly those pursuing higher education.​

# Running Instructions

This project uses an **Arduino sketch** to control a microcontroller and a **Processing 5 sketch** to run a visual or interactive program on your computer.

---

## Requirements

Please install the following software before running the project:

1. **Arduino IDE**  
    Download: [https://www.arduino.cc/en/software](https://www.arduino.cc/en/software)
    
2. **Processing 5**  
    Download: [https://processing.org/download](https://processing.org/download)
    
---
## How to Run the Project

### 1. Clone or Download the Repository

```bash
git clone https://github.com/nanashireen/Wearable-Project.git
cd Wearable-Project
```

Or click **Code > Download ZIP**, then extract it.

---

### 2. Upload the Arduino Sketch

1. Open **Arduino IDE**.
    
2. Open the file:  
    `sketch_may11atestingfinal.ino`
    
3. Connect your Arduino board via USB.
    
4. In Arduino IDE:
    
    - Go to **Tools > Board** and select your board (e.g., Arduino Uno).
        
    - Go to **Tools > Port** and select the correct port.
        
5. Click the **Upload** button to upload the code to your board.
    

---

### 3. Run the Processing Script

1. Open **Processing 5**.
    
2. Open the file:  
    `sketch_250511bptoatesing.pde`
    
3. If needed, update the serial port index in the code:
    
    ```java
    println(Serial.list());
    ```
    
    Use the correct index from the list for your Arduino port.
    
4. Click the **Run** button (▶️) in Processing.

## Technologies Used

**![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXfYpRtsWlCeISXwjtqa_gdwAeGKyqEfI1ldbZQqoOZjblZnz3luh9tNqW9uH3_Sa87pxNLY1jF__hN1gAGY7cG2Agt6UJT0mwxJN4F1TkWejHruV1nDPhOuy1QsP7mhuKUVXBSypg?key=LuLp10UAkWDNsdIaLGqUHfbe)**

- 1x Arduino Uno
- 1x USB to MIDI cable
- 13x wires
- 14x alligator clips
- 7x 1.00 kΩ resistors
- 1x Temperature and Humidity sensor

## Prototype images

**![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXcpMyAV8cLYrHM2Unyx9GJI9KcPkJNdSLGvsHApyubw3kgcIdeEM54slGwCxZ2PD3e1t4I1pQVUi-6KUtLOBVBXiOLvN4ivr_M7mFO12dGTnwNl63BvSKFn3hvkVqr2h9DZ16UE?key=LuLp10UAkWDNsdIaLGqUHfbe)**

**![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXcM2kF7lkLiQtDDjJeg9cPFnfQvzsdnFOd2YpTfeo9Chhy4BlAGCo0RI84IB1yzX33XKxswLVa1mQPgpe6-RPRunkSW4dOybAFXBFtt_kBW4DJcTwGd8qwNc85FC26siEqZHzipSw?key=LuLp10UAkWDNsdIaLGqUHfbe)**

## Demo Video

- Video: [Click Me](https://youtube.com/shorts/ir2oypSS8c8)
