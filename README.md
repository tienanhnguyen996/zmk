# Zephyr™ Mechanical Keyboard (ZMK) Firmware - Dynamic 2-Mode Hybrid Fork

> [!WARNING]
> **DISCLAIMER:** This fork contains highly experimental, **UNTESTED** code. It is **100% vibe code** written to explore dynamic Central/Peripheral role switching. Use at your own risk!

---

### What is this fork for?

This fork implements a **Dynamic 2-Mode Hybrid Keyboard role** (`CONFIG_ZMK_UNIBODY_HYBRID`) designed for unibody keyboards using a USB-powered ZMK Dongle:
1. **Dongle Mode (Split Peripheral):** The unibody keyboard behaves as a split peripheral (Slave), sending raw matrix keypresses wirelessly to a USB Dongle (Central) plugged into the PC.
2. **Direct Mode (Standalone Keyboard):** The unibody keyboard behaves as a standard standalone Central keyboard, connecting directly to the host device via USB or Bluetooth.

A single GPIO direct keyscan key (e.g. shorting D0 to GND on a Seeed Studio XIAO BLE) is intercepted locally on the keyboard to toggle between these two modes instantly, changing the BLE advertising profiles on the fly.

---

[![Discord](https://img.shields.io/discord/719497620560543766)](https://zmk.dev/community/discord/invite)
[![Build](https://github.com/zmkfirmware/zmk/workflows/Build/badge.svg)](https://github.com/zmkfirmware/zmk/actions)
[![Contributor Covenant](https://img.shields.io/badge/Contributor%20Covenant-v2.0%20adopted-ff69b4.svg)](CODE_OF_CONDUCT.md)

[ZMK Firmware](https://zmk.dev/) is an open source ([MIT](LICENSE)) keyboard firmware built on the [Zephyr™ Project](https://www.zephyrproject.org/) Real Time Operating System (RTOS). ZMK's goal is to provide a modern, wireless, and powerful firmware free of licensing issues.

Check out the website to learn more: https://zmk.dev/.

You can also come join our [ZMK Discord Server](https://zmk.dev/community/discord/invite).

To review features, check out the [feature overview](https://zmk.dev/docs/). ZMK is under active development, and new features are listed with the [enhancement label](https://github.com/zmkfirmware/zmk/issues?q=is%3Aissue+is%3Aopen+label%3Aenhancement) in GitHub. Please feel free to add 👍 to the issue description of any requests to upvote the feature.
