# Zephyr™ Mechanical Keyboard (ZMK) Firmware - Dynamic 2-Mode Hybrid Fork

> [!WARNING]
> **CRITICAL WARNING:** This fork contains highly experimental code that is **not suitable for general production use**. 
> Due to sharing a single BLE local identity (MAC address) for both Direct (host PC) and Dongle modes, host PCs may auto-reconnect and hijack the Bluetooth link when switching back to Dongle mode. **Use this fork at your own risk.**

---

### Current Implementation State & Limitations

This fork implements a **Dynamic 2-Mode Hybrid Keyboard role** (`CONFIG_ZMK_UNIBODY_HYBRID`) designed for unibody keyboards using a USB-powered ZMK Dongle:

1. **Dongle Mode (Split Peripheral):** The unibody keyboard behaves as a split peripheral (Slave), sending raw matrix keypresses wirelessly to a USB Dongle (Central) plugged into the PC.
2. **Direct Mode (Standalone Keyboard):** The unibody keyboard behaves as a standard standalone Central keyboard, connecting directly to the host device via USB or Bluetooth.

A toggle key (`&unibody_toggle`) assigned on the Adjust Layer (Layer 3) switches between these two modes instantly.

#### **Known Limitation (Connection Hijack):**
* **The issue:** The split connection and your PC connections share the same MAC address (Identity 0). When switching to Dongle mode, the host PC may auto-reconnect, taking over the BLE slot and blocking the Dongle.
* **The workaround:** You must manually disable Bluetooth on your PC (or disconnect the keyboard from your PC's Bluetooth menu) when switching to Dongle mode to allow the Dongle to connect.

---

[![Discord](https://img.shields.io/discord/719497620560543766)](https://zmk.dev/community/discord/invite)
[![Build](https://github.com/zmkfirmware/zmk/workflows/Build/badge.svg)](https://github.com/zmkfirmware/zmk/actions)
[![Contributor Covenant](https://img.shields.io/badge/Contributor%20Covenant-v2.0%20adopted-ff69b4.svg)](CODE_OF_CONDUCT.md)

[ZMK Firmware](https://zmk.dev/) is an open source ([MIT](LICENSE)) keyboard firmware built on the [Zephyr™ Project](https://www.zephyrproject.org/) Real Time Operating System (RTOS). ZMK's goal is to provide a modern, wireless, and powerful firmware free of licensing issues.

Check out the website to learn more: https://zmk.dev/.

You can also come join our [ZMK Discord Server](https://zmk.dev/community/discord/invite).

To review features, check out the [feature overview](https://zmk.dev/docs/). ZMK is under active development, and new features are listed with the [enhancement label](https://github.com/zmkfirmware/zmk/issues?q=is%3Aissue+is%3Aopen+label%3Aenhancement) in GitHub. Please feel free to add 👍 to the issue description of any requests to upvote the feature.
