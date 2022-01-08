<div align="center">

# TVC-Rocket-Flight-Code

![Arduino](https://img.shields.io/badge/-Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white)
![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)

This repository contains the source code for a software implementation of thrust vector control (TVC) for model rockets. The software consists of a state machine and PID control loops to adjust the orientation of the rocket during its powered ascent.

</div>

## Table of contents

- [Installation](#installation)
- [Usage](#usage)
- [Features](#features)
    - [State Machine](#state-machine)

## Installation

To use this software, you will need a Teensy 4.1 board and the Arduino IDE with the Teensy Loader Application. Follow these steps to install the software:

1. Clone the repository to your local machine.
2. Open the `TVC-Flight-Code.ino` file in the Arduino IDE.
3. Upload the code to your Teensy.

## Usage

To use the TVC system with this software, you'll need a flight controller and a motor mount which can be rotated with two servos. The parameters in the `Rocket.h` and `StateMachine.h` file need to be adjusted for your specific rocket. After evaluating the correct parameters upload the code to the Teensy. Do not forget to power on the flight controller before launching the rocket. The Software automatically detects the launch and the TVC system will automatically adjust the orientation of the rocket during its powered ascent based on the PID control loop. Note that it's important to follow all safety guidelines when testing or launching your rocket, and to always conduct tests in a safe and legal manner.

## Features

### State Machine

The state machine is controlling the model rocket based on the current state of the flight. The state machine has four states:

`LAUNCH_PAD_IDLE`: The initialization state where the TVC system is initialized and the rocket is waiting for launch.\
`ASCENT`: The ascent state where the TVC system controls the orientation of the rocket during its powered ascent.\
`DESCENT`: The descent state where the TVC system is deactivated and the rocket is falling down.\
`LANDED`: The landed state where the rocket is waiting for recovery.
