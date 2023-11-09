# Button Checker for WIO Terminal

The **Button Checker for WIO Terminal** is a simple Arduino-based project that makes use of Seeed's WIO Terminal, equipped with built-in buttons and an LCD screen, to monitor the state of these buttons in real-time. This project serves as a practical example of button state monitoring and basic user interface development on the WIO Terminal.

## Features

- Monitors the state of WIO Terminal's built-in buttons.
- Displays the status of each button (ON/OFF) on the WIO Terminal's built-in LCD screen.
- Utilizes Free Fonts for text rendering on the screen.
- Provides a foundation for creating user interface elements on the WIO Terminal.

## Hardware Requirements

- **WIO Terminal**: You will need a Seeed WIO Terminal, which comes with built-in buttons and a color LCD screen.

## Software Requirements

- **Arduino IDE**: Install the Arduino Integrated Development Environment to upload and run the code on your WIO Terminal.

## Installation

1. **Install Arduino IDE**: If you don't already have it, download and install the Arduino IDE from the [official Arduino website](https://www.arduino.cc/en/software).

2. **Include Libraries as Headers**:
   - The necessary libraries, "Free_fonts.h" and "Tft_eSPI.h," are included in the code as headers. No separate installation is required.

3. **Upload the Code**:
   - Open the provided Arduino code in the Arduino IDE.
   - Select the correct board (WIO Terminal) and port.
   - Click the "Upload" button to upload the code to your WIO Terminal.

## Usage

1. After uploading the code, your WIO Terminal will display the initial state of its built-in buttons.

2. The built-in buttons on the WIO Terminal are continuously monitored for state changes.

3. The button states are displayed on the built-in LCD screen in real-time.

4. Buttons are represented with labels such as "A button," "B button," and so on.

5. Button presses are displayed as "ON" in green, while button releases are shown as "OFF" in red.

6. The button states are continuously monitored in the `loop()` function.

7. The serial monitor is used for debugging and displays the button states.

## Customization

- You can customize the button labels and appearance by modifying the `tekst` array in the code.

## Compatibility

This code is specifically designed for the Seeed WIO Terminal hardware platform and is not intended for use with other devices.

## Troubleshooting

- If you encounter any issues, check the wiring of your WIO Terminal, and ensure that the libraries are correctly included as headers in your Arduino project.

- Refer to the documentation for your WIO Terminal for more detailed information.

## Acknowledgments

This project utilizes the "TFT_eSPI" library for controlling the TFT display and the "Free_fonts.h" header for text rendering. Special thanks to the Arduino community for their contributions.

**Note**: This README provides an overview of the project and basic usage instructions. Refer to the specific documentation for your WIO Terminal for more detailed information.

Enjoy using the WIO Terminal's built-in buttons and display functionality for your projects!
