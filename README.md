# 🎸 CatFuzz - Audio Plugin

<div align="center">

![JUCE](https://img.shields.io/badge/Framework-JUCE-blue)
![macOS](https://img.shields.io/badge/Platform-macOS-lightgrey)
![Audio Plugin](https://img.shields.io/badge/Plugin-Fuzz_Effect-orange)

*A fuzz pedal inspired by Big Muff and Fuzz Face with interactive feline interface*

</div>

## 🎛️ Features

- **Hybrid Algorithm**: Combines Fuzz Face (smooth) and Big Muff (aggressive) characteristics
- **Visual Interface**: Animated cat that reacts to fuzz parameter
- **3 Controls**: Fuzz, Tone, Volume
- **Formats**: VST3, AU (Audio Unit)

## 📸 Screenshots

<div align="center">

### Low Fuzz Setting (Calm Cat)
![Low Fuzz](screenshots/Captura 1.png)

### Mid Fuzz Setting (Neutral Cat)
![Mid Fuzz](screenshots/Captura 2.png)

### High Fuzz Setting (Angry Cat)  
![High Fuzz](screenshots/Captura 3.png)

</div>

## 🎚️ Controls

| Parameter | Range | Description |
|-----------|-------|-------------|
| **Fuzz** | 0.0 - 1.0 | Main distortion control + cat animation |
| **Tone** | 0.0 - 1.0 | Tone filter (dark to bright) |
| **Volume** | 0.0 - 1.0 | Output level |

## 🛠️ Development

### Technologies
- **JUCE Framework** 8.0.10
- **C++17**
- **Xcode** (main IDE)

## 🚀 Installation

1. **Clone repository**:
   ```bash
   git clone https://github.com/davidsignals/CatFuzz.git

