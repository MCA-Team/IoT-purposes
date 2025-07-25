# IoT-purposes
IoT blueprints for future projects


## Overview
The aim of this project is the creation of a project's blueprint

---
## Prerequisites
For running and tweaking this project locally, you need to have the following tools installed on your device:
- **Docker**: to create and deploy services containers
- **Docker-compose**: to manage/orchestrate all the linked services containers
- **Arduino IDE**: For micro-controllers programming
- **Git**: for the project's repository pulling

---
## Setting up the environment
After satisfying the above requirements, you can proceed with the following steps:

**Step 1**: Clone the project's repository

In this Project, we will use a `Wemos D1 R1` device (with a WiFi chip) which is an ESP8266 based device. So we have to use ESP8266 boards manager component.

**Step 2**: Launch Aruino IDE. Enter the following URL into the `File > Preferences > Additional Boards Manager URLs` field of the Arduino IDE (You can add multiple URLs, separating them with commas):
```
https://arduino.esp8266.com/stable/package_esp8266com_index.json
```
Then, open Boards Manager from `Tools > Board > Boards Manager` menu and install `esp8266` platform (and don't forget to select your Wemos D1 R1 board from `Tools > Board > ESP8266 > LOLIN (WEMOS) D1 R1` menu after installation).

**Step 2**: Run the docker linked services: 
```bash
$ docker-compose up --detach 
```

---
## Troubleshooting
> Manage `Arduino IDE` installation by clicking the link bellow:
> <br/>
> [Download Arduino IDE](https://docs.arduino.cc/software/ide-v2/tutorials/getting-started/ide-v2-downloading-and-installing/?_gl=1*boqrg4*_up*MQ..*_ga*MTM2MTcwOTIyMi4xNzUzNDUzMjM4*_ga_NEXN8H46L5*czE3NTM0NTMyMzckbzEkZzAkdDE3NTM0NTMyMzckajYwJGwwJGgxMzY3MzM0MjIw)

> Once you connect your device to your computer, make sure the port is recognized in Arduino IDE (you can see something like `/dev/ttyUSB0` on Ubuntu for example)

> To activate the serial monitor in Arduino IDE, `Ctrl + Shift + M` 