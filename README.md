# ESP32-S3 AI-Powered Voice Assistant



![Project Status](https://img.shields.io/badge/Status-Active-success)
![License](https://img.shields.io/badge/License-MIT-blue)
![ESP-IDF](https://img.shields.io/badge/ESP--IDF-v5.4+-green)
![Platform](https://img.shields.io/badge/Platform-ESP32--S3-orange)

*A fully custom, open-source AI voice assistant powered by ESP32-S3 and Xiaozhi AI framework*


</div>

---

## 📋 Overview

This project is a complete DIY AI voice assistant built around the ESP32-S3 microcontroller. It combines custom PCB design, advanced audio processing, and cloud-based AI to create a device that rivals commercial smart speakers in functionality while remaining fully open-source and customizable.

Unlike simple voice-controlled devices, this assistant leverages the **Xiaozhi AI framework** to provide natural language understanding through large language models (LLMs) like Qwen, DeepSeek, and GPT. The system uses a hybrid architecture: lightweight tasks run locally on the ESP32-S3, while computationally intensive AI processing happens on cloud servers.

### Key Highlights

- ✨ **Natural Conversation**: Powered by modern LLMs for intelligent, context-aware responses
- 🎙️ **Dual-Microphone Array**: Advanced audio capture with beamforming and echo cancellation
- 🔋 **Battery Powered**: Complete power management with USB-C charging and portable operation
- 💡 **WS2812B LED Ring**: Visual feedback with customizable animations
- 🏠 **Smart Home Ready**: Integration with Home Assistant and other platforms
- 🔧 **Fully Customizable**: Open hardware and software for endless possibilities
- 📱 **Web-Based Control**: Easy configuration through Xiaozhi console
- 🌐 **Multi-Language**: Support for multiple languages depending on AI model

---

## 🎯 Features

### Hardware Features
- **ESP32-S3-WROOM-1-N16R8** (Dual-core, 16MB Flash, 8MB PSRAM)
- **Dual ICS-43434 MEMS Microphones** for superior audio capture
- **MAX98357A I²S Amplifier** driving 3W speaker
- **BQ24250 Li-Ion Charger** with USB-C power delivery
- **MAX20402 Buck-Boost Regulator** for stable 3.3V output
- **WS2812B RGB LED Ring** for visual status indication
- **Optional OLED Display** header for screen integration
- **Compact PCB Design** (2-layer, professionally fabricated)
- **Custom 3D-Printed Enclosure** optimized for acoustics

### Software Features
- **Wake Word Detection** using Espressif's WakeNet
- **Audio Front-End (AFE)** with noise reduction and echo cancellation
- **WebSocket Communication** for low-latency server connection
- **Multiple AI Models** (Qwen, DeepSeek, GPT-4, and more)
- **Conversation History** and context awareness
- **Voice Profile Support** for personalized responses
- **Smart Home Integration** via Xiaozhi skill marketplace
- **OTA Updates** for firmware upgrades
- **Battery Monitoring** with low-battery alerts

---

## 🛠️ Hardware

### Bill of Materials (BOM)

| Component | Part Number | Quantity | Notes |
|-----------|------------|----------|-------|
| Microcontroller | ESP32-S3-WROOM-1-N16R8 | 1 | Main processor |
| Microphones | TDK InvenSense ICS-43434 | 2 | Digital MEMS |
| Audio Amplifier | MAX98357AETE+ | 1 | Class-D I²S |
| Battery Charger | BQ24250RGER | 1 | Li-Ion charging IC |
| DC-DC Converter | MAX20402ATGA/+ | 1 | Buck-boost regulator |
| RGB LEDs | WS2812B-5050 | 8-12 | Addressable LEDs |
| USB-C Connector | USB4105-GF-A | 1 | Power & programming |
| Speaker | 3W 4Ω Cavity Speaker | 1 | Audio output |
| Battery | Li-Ion/LiPo 3.7V | 1 | 2000-3000mAh recommended |
| Capacitors | Various (0603/0805) | ~25 | See full BOM |
| Resistors | Various (0603) | ~15 | See full BOM |
| Switches | 6x6mm Tactile | 2 | Reset & Boot |
| TVS Diode | USBLC6-2SC6 | 1 | USB ESD protection |

**📥 Full BOM with part numbers**: [Download BOM.csv](hardware/BOM.csv)

### PCB Design

The custom PCB is a 2-layer design measuring approximately 80x60mm with careful attention to:
- Signal integrity for I²S audio
- Power distribution with minimal noise
- Thermal management for power ICs
- Acoustic isolation between microphones and speaker


### 3D Enclosure

The enclosure is designed for FDM 3D printing with features for:
- Acoustic optimization (speaker grille, microphone ports)
- LED light diffusion ring
- USB-C and button access
- Battery compartment
- Ventilation slots

**🖨️ 3D Files**:
- `enclosure/base.stl` - Bottom tray
- `enclosure/top.stl` - Top cover
- `enclosure/led-ring.stl` - LED diffuser
- `enclosure/assembly.step` - Full assembly (STEP format)

**Printing Recommendations**:
- Material: PLA or PETG
- Layer Height: 0.2mm
- Infill: 20%
- Supports: Required for speaker grille

---

## 🚀 Getting Started

### Prerequisites

**Hardware Tools**:
- Soldering iron and supplies
- Multimeter for testing
- USB-C cable (data capable)
- 3D printer (optional, for enclosure)

**Software Requirements**:
- [Visual Studio Code](https://code.visualstudio.com/)
- [ESP-IDF Extension for VS Code](https://marketplace.visualstudio.com/items?itemName=espressif.esp-idf-extension)
- ESP-IDF v5.4 or newer
- Git

### Step 1: Hardware Assembly

1. **Order PCB**: Upload `hardware/gerbers/gerbers.zip` to JLCPCB, PCBWay, or ALLPCB
2. **Source Components**: Use the BOM to order parts from DigiKey, Mouser, or LCSC
3. **Assemble PCB**: Follow the [assembly guide](docs/ASSEMBLY.md) for soldering instructions
4. **3D Print Enclosure**: Print the STL files and assemble

**Detailed Assembly Guide**: [docs/ASSEMBLY.md](docs/ASSEMBLY.md)


### Step 2: WiFi Configuration

On first boot, the device creates a WiFi access point:

1. Connect to WiFi network: `Xioazhi`
2. Navigate to `http://192.168.4.1`
3. Enter your WiFi credentials
4. Device will restart and connect to your network

**Alternative**: Configure WiFi via `idf.py menuconfig` before flashing

### Step 3: Xiaozhi Cloud Setup

1. Create account at [xiaozhi.me](https://xiaozhi.me)
2. Navigate to [Console → Agents](https://xiaozhi.me/console/agents)
3. Click "Add Device" to generate Device ID and Pairing Code
4. Device will auto-pair on first cloud connection
5. Customize AI personality, voice, and skills through console

**Detailed Setup Guide**: [docs/SETUP.md](docs/SETUP.md)

### Step 4: Test Your Assistant

1. Say the wake word: **"Hey Wanda"**
2. Wait for LED confirmation (blue pulse)
3. Speak your question or command
4. Assistant responds through speaker
5. LED returns to idle state

---

## 📚 Documentation

- **[Assembly Guide](docs/ASSEMBLY.md)** - Step-by-step hardware assembly
- **[Setup Guide](docs/SETUP.md)** - Firmware configuration and first boot
- **[Firmware Guide](docs/FIRMWARE.md)** - Building and customizing firmware
- **[Xiaozhi Integration](docs/XIAOZHI.md)** - Cloud service setup and features
- **[Hardware Design](docs/HARDWARE.md)** - PCB design decisions and modifications
- **[Troubleshooting](docs/TROUBLESHOOTING.md)** - Common issues and solutions
- **[FAQ](docs/FAQ.md)** - Frequently asked questions
- **[API Reference](docs/API.md)** - Firmware API documentation

---


## 🤝 Contributing

Contributions are welcome! Here's how you can help:

### Reporting Bugs
- Use GitHub Issues with detailed reproduction steps
- Include serial monitor logs
- Specify hardware revision and firmware version

### Feature Requests
- Open a GitHub Issue with [Feature Request] tag
- Describe use case and benefits
- Discuss implementation approach

### Pull Requests
1. Fork the repository
2. Create feature branch (`git checkout -b feature/amazing-feature`)
3. Commit changes (`git commit -m 'Add amazing feature'`)
4. Push to branch (`git push origin feature/amazing-feature`)
5. Open Pull Request

**Contribution Guidelines**: [CONTRIBUTING.md](CONTRIBUTING.md)

---

## 📊 Project Status

- [x] PCB Design and fabrication
- [x] Firmware core functionality
- [x] Xiaozhi cloud integration
- [x] Basic voice interaction
- [x] 3D enclosure design
- [ ] Multi-device mesh networking
- [ ] Offline mode with local LLM
- [ ] Custom wake word training tools
- [ ] Mobile app for configuration
- [ ] Additional language packs


---

## 🔗 Related Projects

- [Xiaozhi ESP32](https://github.com/78/xiaozhi-esp32) - Official Xiaozhi firmware
- [ESP-IDF](https://github.com/espressif/esp-idf) - Espressif IoT Development Framework
- [WakeNet](https://github.com/espressif/esp-sr) - Espressif speech recognition
- [Home Assistant](https://www.home-assistant.io/) - Smart home integration

---

## 📄 License

This project is licensed under the MIT License - see [LICENSE](LICENSE) for details.

### Third-Party Licenses
- ESP-IDF: Apache 2.0
- Xiaozhi Framework: MIT
- Component datasheets: Respective manufacturers

---

## 🙏 Acknowledgments

- **Espressif Systems** for the amazing ESP32-S3 platform and development tools
- **Xiaozhi Team** for creating and maintaining the AI framework
- **Open-source community** for countless libraries and examples
- **PCB manufacturers** (JLCPCB, PCBWay) for affordable prototyping
- **Everyone** who contributed feedback, testing, and improvements

---



**Xiaozhi Community**:
- Forum: [xiaozhi.me/community](https://xiaozhi.me/community)
- Documentation: [docs.xiaozhi.me](https://docs.xiaozhi.me)



<div align="center">

**Built with ❤️ by makers, for makers**

[Documentation](docs/) • [Hardware Files](hardware/) • [Firmware](firmware/) • [Community](https://github.com/yourusername/esp32s3-voice-assistant/discussions)

</div>
