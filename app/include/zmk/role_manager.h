/*
 * Copyright (c) 2026 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

enum zmk_unibody_mode {
    ZMK_UNIBODY_MODE_DONGLE, // Acts as a split peripheral to the Dongle
    ZMK_UNIBODY_MODE_DIRECT, // Acts as a standalone USB/BLE keyboard
};

/**
 * Gets the current active mode of the unibody keyboard.
 */
enum zmk_unibody_mode zmk_unibody_get_mode(void);

/**
 * Sets the active mode of the unibody keyboard.
 */
void zmk_unibody_set_mode(enum zmk_unibody_mode mode);

/**
 * Toggles the keyboard mode between Dongle Mode and Direct Mode.
 */
void zmk_unibody_toggle_mode(void);
