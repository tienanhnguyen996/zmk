# Zephyr™ Mechanical Keyboard (ZMK) Firmware - Dynamic 2-Mode Hybrid Fork

> [!WARNING]
> **CRITICAL WARNING:** This fork contains highly experimental code that is **not suitable for general production use**. **Use this fork at your own risk.**

---

### Current Implementation State & Features

This fork implements a **Dynamic 2-Mode Hybrid Keyboard role** (`CONFIG_ZMK_UNIBODY_HYBRID`) designed for unibody keyboards using a USB-powered ZMK Dongle:

1. **Dongle Mode (Split Peripheral):** The unibody keyboard behaves as a split peripheral (Slave), sending raw matrix keypresses wirelessly to a USB Dongle (Central) plugged into the PC.
2. **Direct Mode (Standalone Keyboard):** The unibody keyboard behaves as a standard standalone Central keyboard, connecting directly to the host device via USB or Bluetooth.

A toggle key (`&unibody_toggle`) assigned on the Adjust Layer (Layer 3) switches between these two modes instantly.

#### **BLE Identity Separation (No Connection Hijacking):**
This fork resolves the BLE connection hijacking issue by utilizing Zephyr's multiple local identity support:
* **Identity 0 (Direct Mode):** Uses the hardware default BLE MAC address to pair and connect directly to host PCs.
* **Identity 1 (Dongle Mode):** Generates a deterministic static random BLE MAC address derived from the MCU's FICR (factory information configuration registers), toggling the address LSB to differentiate it.
This ensures your PC and the USB Dongle see the keyboard as two entirely distinct Bluetooth devices, preventing the PC from hijacking the connection when switching to Dongle mode.

#### **Dynamic Hybrid Mode Behavioral Details in Dongle Mode:**
* **Local Layer Tracking:** The keyboard (peripheral) runs keymap processing locally in `DONGLE` mode to maintain correct layer tracking. This is required so the peripheral can intercept and execute the mode switch behaviors (`&unibody_toggle`, `&unibody_dongle`, `&unibody_direct`) locally when they are pressed on a higher layer.
* **Global Stateful Behaviors (RGB & Power):** To prevent duplicate/conflicting executions, global stateful behaviors (such as `rgb_ug`, `ext_power`, and `backlight`) are bypassed locally on the peripheral when in `DONGLE` mode. They are evaluated on the central (Dongle) and executed on the peripheral only when commanded by the central over BLE.
* **Combos:** Local combo detection is bypassed on the peripheral in `DONGLE` mode. Combos are forwarded as raw key positions and fully evaluated on the central (Dongle).

---

[![Discord](https://img.shields.io/discord/719497620560543766)](https://zmk.dev/community/discord/invite)
[![Build](https://github.com/zmkfirmware/zmk/workflows/Build/badge.svg)](https://github.com/zmkfirmware/zmk/actions)
[![Contributor Covenant](https://img.shields.io/badge/Contributor%20Covenant-v2.0%20adopted-ff69b4.svg)](CODE_OF_CONDUCT.md)

[ZMK Firmware](https://zmk.dev/) is an open source ([MIT](LICENSE)) keyboard firmware built on the [Zephyr™ Project](https://www.zephyrproject.org/) Real Time Operating System (RTOS). ZMK's goal is to provide a modern, wireless, and powerful firmware free of licensing issues.

Check out the website to learn more: https://zmk.dev/.

You can also come join our [ZMK Discord Server](https://zmk.dev/community/discord/invite).

To review features, check out the [feature overview](https://zmk.dev/docs/). ZMK is under active development, and new features are listed with the [enhancement label](https://github.com/zmkfirmware/zmk/issues?q=is%3Aissue+is%3Aopen+label%3Aenhancement) in GitHub. Please feel free to add 👍 to the issue description of any requests to upvote the feature.
