# Simple Calculator

[![MIT license](https://img.shields.io/badge/License-MIT-blue.svg)](https://github.com/ludehsar/SimpleCalculator/blob/master/LICENSE)

## Table of Contents

* [About the Project](#about-the-project)
* [Prerequisites](#prerequisites)
  * [Hardware Requirements](#hardware-requirements)
  * [Software Requirements](#software-requirements)
* [Installation](#installation)
* [Roadmap](#roadmap)
* [Contributing](#contributing)
* [License](#license)
* [Contacts](#contacts)

## About The Project

This is actually the final project for the course CSE 612 (Computer Interfacing and Microcontroller Lab) at Department of Computer Science and Engineering, University of Chittagong. In this presentation, we have been told to interface a simple calculator with atmega 8 microcontroller, a 4 * 4 keypad, and two 7 segment LED displays. The objective of this project is to learn how to program a microcontroller. In order to accomplish the result, we write a C program to control the software behaviour of the calculator. We also have a design file which is used for software simulation by the Proteus 8.6+ professional.

## Prerequisites

Before starting with this project, we need some softwares and some hardwares.

### Hardware Requirements

The hardwares required for this project are:

* AVR Programmer burner
* Atmega 8 microcontroller
* 4 * 4 small calculator keypad
* 7 segment display (qty: 2)
* Connecting wires
* Breadboard
* Power adapter

### Software Requirements

* Install avr-gcc, avr-libc, avrdude, gcc, make
* Install WinAVR for convenience
* Atmel Studio
* Proteus 8.6+ professional to run the simulation

## Installation

1. Clone the github repo.
```sh
git clone https://github.com/ludehsar/SimpleCalculator.git
```

2. Load the [hex file](https://github.com/ludehsar/SimpleCalculator/blob/master/SimpleCalculator/Release/SimpleCalculator.hex) of the code to the microcontroller using avr programmer burner.

3. Now, connect the keypad and 7 segment displays with the microcontroller according to the following figure:

<p align="center">
    <img src="https://github.com/ludehsar/SimpleCalculator/blob/master/images/screenshot.PNG" alt="the connections" />
</p>

**Note:** The pin configuration might not be accurate for the microcontroller. See [https://components101.com/microcontrollers/atmega8-avr](https://components101.com/microcontrollers/atmega8-avr) for pin configuration of the atmega 8 microcontroller. If the image is not clear, then, PB0-PB7 are connected with the calculator, PC0-PC5 are connected with the first 6 ports of the first 7 segment display, PD7 is connected with the 7-th ports of the first 7 segment display. PD0-PD6 are connected with ports **a-g** of the second 7 segment display. Don't forget to configure the vcc and the grounds. The 7 segment displays are common cathode, so the com ports will be connected to ground. For convenience, the pin configuration of the 7 segment displays can be found [here](https://components101.com/7-segment-display-pinout-working-datasheet).

4. Connect the power adapter and you are good to go.

5. In order to simulate the design file, open Proteus 8.6+ professional and open [Calculator.pdsprj](https://github.com/ludehsar/SimpleCalculator/blob/master/Design/Calculator.pdsprj). Then hit the play button.

## Roadmap

See the [open issues](https://github.com/ludehsar/SimpleCalculator/issues) for a list of proposed features (and known issues).

## Contributing

Contributions are what make the open source community such an amazing place to be learn, inspire, and create. Any contributions you make are **greatly appreciated**.

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## License

Distributed under the MIT License. See `LICENSE` for more information.

## Contacts

1. Md. Rashedul Alam Anik - mdraanik12@gmail.com
2. Sajib Kumar Das - sajibkumardas97@gmail.com
3. Monayam Reshad - reshadmrrr@gmail.com
4. Muhammad Shahriar Alam - shahriarcsecu33@gmail.com
5. Gazi Mohaimin Iqbal - mohaiminiqbal21@gmail.com

Project Link: [https://github.com/ludehsar/SimpleCalculator](https://github.com/ludehsar/SimpleCalculator)
