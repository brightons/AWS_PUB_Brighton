# PLCnext AWS IoT Integration

This repository contains a PLCnext project for connecting a **Phoenix Contact AXC F 2152** controller to **AWS IoT** using **Function Block (FD) code**. The project is built with **PLCnext Engineer 2025.0** and utilizes the **IIoT Library 5.1.0**.

---

## Table of Contents

- [Overview](#overview)
- [Requirements](#requirements)
- [Installation](#installation)
- [Configuration](#configuration)
- [Usage](#usage)
- [Notes](#notes)


---

## Overview

This project demonstrates how to publish telemetry and device state data from a PLCnext controller to AWS IoT Core. The integration uses Phoenix Contact's IIoT library for seamless connectivity, leveraging MQTT protocols for data transmission.

Key features:

- Publish sensor and process data to AWS IoT Core
- Subscribe to device commands from AWS IoT
- Uses **Function Block (FD) programming**
- Compatible with **PLCnext Engineer 2025.0** and **IIoT Library 5.1.0**

---

## Requirements

- **PLC Hardware:** AXC F 2152
- **Firmware version:** 2025.0.3 (25.0.3.99)
- **Firmware:** Compatible with PLCnext Engineer 2025.0
- **Software:** PLCnext Engineer 2025.0
- **Libraries:** IIoT Library 5.1.0
- **AWS Account:** Access to AWS IoT Core

---

## Installation

1. Clone this repository:

```bash
git clone https://github.com/brightons/AWS_PUB_Brighton.git
cd AWS_PUB_Brighton
```

2. Open the project in **PLCnext Engineer 2025.0**.
3. Ensure that the IIoT Library 5.1.0 is installed in your PLCnext Engineer environment.
4. Compile the project and resolve any missing library dependencies.

---

## Configuration

1. Configure AWS IoT Core:
    - Create a Thing in AWS IoT Core.
    - Download the device certificate and private key.
    - Note the endpoint URL.

2. Configure PLCnext IIoT connection:
    - Add AWS IoT connection parameters in the project:
        - Endpoint URL
        - Thing name
        - Certificates and keys

3. Map PLC variables to MQTT topics using the IIoT function blocks.

---

## Usage

1. Deploy the compiled project to the **AXC F 2152** controller.
2. Start the PLC runtime.
3. Monitor the published topics in AWS IoT Core.
4. Use MQTT clients to send commands back to the PLC.

---

## Notes

- This project uses **Function Block (FD) code** for all AWS IoT interactions.
- Ensure your PLC firmware is up-to-date for compatibility with IIoT Library 5.1.0.
- Test the integration in a development environment before deploying to production.

---



