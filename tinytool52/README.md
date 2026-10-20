![Target Badge](https://img.shields.io/badge/AT89S52%20%20-%20Intem%20MCS51%20Architecture?style=flat&label=MCU&color=orange
)
![Target badge](https://img.shields.io/badge/AT89S51%20%20-%20Intem%20MCS51%20Architecture?style=flat&label=MCU&color=purple
)
![Drivers](https://img.shields.io/badge/37%20Drivers%20-%20Bare%20metal%20drivers?style=flat&label=Features&labelColor=grey&color=green
)
![Software](https://img.shields.io/badge/Standard%20Software%20Libraries%20-%20Partial%20STL%20Imlimentation?style=flat&label=Features&labelColor=grey&color=blue
)
# **tinytool52**
**tinytool52** &mdash; is a complete **bare metal driver suite** for modern day **Intel MCS51** **(8051/8052)** clones. It features a minimal implimentation of the **C Standard Library** with headers like **ttl52int.h** , **ttl52bool.h**, **ttl52matrix.h** and bare metal driver for **37+ Sensors** , **UART Serial** , **Software PWM** , **Software DAC & ADC** , and **more!**

# **Software Libraries**
- ttl52int.h &mdash; Standard Integers for 8052/8051
- ttl52bool.h &mdash; Boolean variables for 8052/8051
- ttl52fxp.h &mdash; Fixed Point data types as a float alternative for 8052/8051
- ttl52matrix.h &mdash; Functions for working with matrices 8052/8051
- ttl52dstring.h &mdash; String libraries for 8051/8052
- ttl52def.h &mdash; **NULL**,**size_t** and **offsetof()** implimentation for 8051/8052 

More libraries may be added as per requirement.

# **Bare Metal Drivers**

- Three Pin Relay
- Three Pin LED Module
- Dual Color LED
- Four Pin RGB Module
- Four Pin SMD RGB 
- Three pin Tracking Sensor
- Four Pin Avoidance Sensor
- Four Pin Small Sound Sensor
- Four Pin Big Sound Sensor
- Four Pin Flame Sensor
- Four Pin Linear Hall Sensor
- Four Pin touch Sensor
- Four Pin Digital Temperature Sensor
- Active Buzzer Driver (Times/Ticks)
- Passive Buzzer Driver (Frequency Based)
- Four Pin Reed Switch
- Three Pin Mini Reed
- Heartbeat Sensor
- 7-Color Flasher
- Laser Emiter 
- Shock Sensor
- Three Pin Push Button Module
- Rotatory Encoders
- Humidity Sensors
- Anaglog Temp & Hall Sensors
- TR Emission Driver
- IR Reciever Driver
- Tap Module
- Joystick Driver

More hardware drivers will be added as per requirement.

# **Project Timeline**

- **0 &mdash; 3 Months** : Complete Software Library with Stable Releases
- **3 &mdash; 9 Months** : Subset of Hardware Drivers

Please stay updated on the release structure for keeping track with stable drivers & different hardware configurations. Updates to the timeline will be made after some drivers are made and I can accurately guess the approximate time needed.

# **Project Information & Support**

**tinytool52** primarily targets the **SDCC (Small Device C Compiler)** and the pre compiled ***.lib** releases will not work for **Keil C51** , Ports may be possible if there is enough demand However, I personally do not like Keil C51 and its proprietary lock in mechanisms.

Each release will consist of a driver library (*xyz.lib*) file and its headers (*xyz.h*) with a quick start guide covering all the functions , their arguments , usage and a guide to link the library in your project. 

Linking Guides will also be published on this **Repository**.

# **Other Documentation**

[Sensor Documentation]()  
[Supported MCU Targets](assets/targets.md)  
[8051 Releases]()  
[8052 Releases]()  
[Software Libraries]()  
[Hardware Drivers]()  

# **Credits & Licensing**

**tinytool52** is completely designed and developed by **Baibhav Bhattacharya** (BaibhavPenguin on **GitHub**) , the **tinytool52** drivers are completely **free** & **open-source** for anyone to use and modify  
The **Software** , **Drivers** or **Libraries** under the **tinytool52** project come with absolutely **NO WARRANTY**.  

*Copyright 2026 Baibhav Bhattacharya* &mdash; [Apache License , version 2.0](LICENSE)