# PresenceSwitch

## Overview

PresenceSwitch is a smart power outlet system designed to intelligently manage power based on user presence. By detecting whether you're home or away, the socket automatically turns devices on or off, optimizing energy consumption and providing convenience.

## Features

## Getting Started

### Prerequisites

Before you begin, ensure you have met the following requirements:

- Hardware: A compatible device running ETS2.
Software:
- ESP-IDF (for ESP32 development)
- Dependencies as mentioned in the requirements.txt (ESP-IDF).

## Installation

### Clone the repository:

bash
Copy code
git clone [PresenceSwitch](https://github.com/dscabello/PresenceSwitch).git
cd PresenceSwitch

Set up the [ESP-IDF](https://github.com/espressif/esp-idf) environment: Follow the official ESP-IDF Getting Started guide to set up the development environment.

### Build the project:
```
bash
Copy code
idf.py build
```

### Flash the firmware to your ESP32:
```
bash
Copy code
idf.py -p <PORT> flash
```

### Monitor the output:
```
bash
Copy code
idf.py monitor
```

### Usage

Launch the ETS2 Controller Box on your device.
Connect it to your ETS2 game using the configured network settings.
Customize the dashboard according to your preferences.

### Contributing
We welcome contributions! To contribute, please fork the repository, create a new branch, and submit a pull request with your changes.

Fork the project.
Create your feature branch:
bash
Copy code
git checkout -b feature/AmazingFeature
Commit your changes:
bash
Copy code
git commit -m 'Add some amazing feature'
Push to the branch:
bash
Copy code
git push origin feature/AmazingFeature
Open a pull request.

## Folder Contents

## License

- Attribution-NonCommercial-ShareAlike 4.0 International [LICENSE](https://github.com/dscabello/PresenceSwitch/blob/main/LICENSE)
