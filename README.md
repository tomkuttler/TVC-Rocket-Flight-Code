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
    - [PID Control Loop](#pid-control-loop)
    - [Parachute Ejection](#parachute-ejection)
- [Contributing](#contributing)
- [License](#license)

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

- `LAUNCH_PAD_IDLE`: The initialization state where the TVC system is initialized and the rocket is waiting for launch.
- `ASCENT`: The ascent state where the TVC system controls the orientation of the rocket during its powered ascent.
- `DESCENT`: The descent state where the TVC system is deactivated and the rocket is falling down.
- `LANDED`: The landed state where the rocket is waiting for recovery.

### PID Control Loop

The PID control loop is responsible for adjusting the orientation of the motor mount based on the current orientation of the rocket and the desired orientation. The TVC system uses two separate PID control loops, one for the orientation in the x-direction and one for the orientation in the y-direction.

Each PID control loop has three components:

- Proportional: The proportional component adjusts the orientation of the rocket based on the difference between the current orientation and the desired orientation.
- Integral: The integral component adjusts the orientation of the rocket based on the cumulative error between the current orientation and the desired orientation.
- Derivative: The derivative component adjusts the orientation of the rocket based on the rate of change of the error between the current orientation and the desired orientation.

By using two separate PID control loops, the TVC system is able to independently adjust the orientation of the rocket in both the x-direction and the y-direction, by using two servos which gimbal the motor mount.

### Parachute Ejection

While the TVC system controls the orientation of the rocket during ascent, a separate mechanical parachute ejection system is used to deploy the parachute. This system consists of springs and a servo that is triggered by a signal from the state machine when the rocket switches from the ascent state to the descent state. By ejecting the parachute during the switch from ascent to descent, the rocket is able to safely decelerate and return to the ground without sustaining damage.

## Contributing

If you would like to contribute to this project, please follow these steps:

1. Fork the repository to your own account.
2. Create a new branch with your changes.
3. Submit a pull request with your changes.

## License

This project is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License. You are free to use, copy, modify, distribute, and display the work, as well as make derivative works based on it, as long as you give attribution to the original author and share any derivative works under the same license. For more information about the license, please see the `LICENSE file.

<a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-sa/4.0/88x31.png" /></a><br />This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/">Creative Commons Attribution-ShareAlike 4.0 International License</a>.
