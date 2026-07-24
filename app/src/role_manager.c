/*
 * Copyright (c) 2026 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#include <zephyr/kernel.h>
#include <zmk/role_manager.h>
#include <zmk/ble.h>
#include <zephyr/logging/log.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/conn.h>

LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

static enum zmk_unibody_mode current_mode = ZMK_UNIBODY_MODE_DONGLE;

#if IS_ENABLED(CONFIG_ZMK_BLE)
extern int update_advertising(void);
#endif
extern int zmk_split_peripheral_ble_set_enabled(bool en);

enum zmk_unibody_mode zmk_unibody_get_mode(void) {
    return current_mode;
}

void zmk_unibody_set_mode(enum zmk_unibody_mode mode) {
    if (current_mode == mode) {
        return;
    }

    LOG_INF("Switching keyboard mode to %s", mode == ZMK_UNIBODY_MODE_DONGLE ? "DONGLE" : "DIRECT");

    // Disconnect active connections to avoid hung keys
    if (current_mode == ZMK_UNIBODY_MODE_DIRECT) {
        // Disconnect direct BLE hosts
        for (int i = 0; i < ZMK_BLE_PROFILE_COUNT; i++) {
            zmk_ble_prof_disconnect(i);
        }
    } else if (current_mode == ZMK_UNIBODY_MODE_DONGLE) {
        // Disconnect from Dongle
        zmk_split_peripheral_ble_set_enabled(false);
    }

    current_mode = mode;

    // Reset advertising states
    if (mode == ZMK_UNIBODY_MODE_DONGLE) {
#if IS_ENABLED(CONFIG_ZMK_BLE)
        // Stop standard HOG advertising
        update_advertising();
#endif
        // Start split peripheral advertising
        zmk_split_peripheral_ble_set_enabled(true);
    } else {
        // Stop split peripheral advertising (already done during disconnect)
#if IS_ENABLED(CONFIG_ZMK_BLE)
        // Start standard HOG BLE advertising
        update_advertising();
#endif
    }
}

void zmk_unibody_toggle_mode(void) {
    if (current_mode == ZMK_UNIBODY_MODE_DONGLE) {
        zmk_unibody_set_mode(ZMK_UNIBODY_MODE_DIRECT);
    } else {
        zmk_unibody_set_mode(ZMK_UNIBODY_MODE_DONGLE);
    }
}
