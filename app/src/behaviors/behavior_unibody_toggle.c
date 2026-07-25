/*
 * Copyright (c) 2026 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#define DT_DRV_COMPAT zmk_behavior_unibody_toggle

#include <zephyr/device.h>
#include <drivers/behavior.h>
#include <zephyr/logging/log.h>

#include <zmk/behavior.h>
#include <zmk/role_manager.h>

LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

#if DT_HAS_COMPAT_STATUS_OKAY(DT_DRV_COMPAT)

static int on_keymap_binding_pressed(struct zmk_behavior_binding *binding,
                                     struct zmk_behavior_binding_event event) {
    zmk_unibody_toggle_mode();
    return ZMK_BEHAVIOR_OPAQUE;
}

static int on_keymap_binding_released(struct zmk_behavior_binding *binding,
                                       struct zmk_behavior_binding_event event) {
    return ZMK_BEHAVIOR_OPAQUE;
}

static const struct behavior_driver_api behavior_unibody_toggle_driver_api = {
    .binding_pressed = on_keymap_binding_pressed,
    .binding_released = on_keymap_binding_released,
#if IS_ENABLED(CONFIG_ZMK_BEHAVIOR_METADATA)
    .get_parameter_metadata = zmk_behavior_get_empty_param_metadata,
#endif
};

BEHAVIOR_DT_INST_DEFINE(0, NULL, NULL, NULL, NULL, POST_KERNEL, CONFIG_KERNEL_INIT_PRIORITY_DEFAULT,
                        &behavior_unibody_toggle_driver_api);

#endif /* DT_HAS_COMPAT_STATUS_OKAY(DT_DRV_COMPAT) */


/* Dongle Behavior */
#undef DT_DRV_COMPAT
#define DT_DRV_COMPAT zmk_behavior_unibody_dongle

#if DT_HAS_COMPAT_STATUS_OKAY(DT_DRV_COMPAT)

static int on_dongle_pressed(struct zmk_behavior_binding *binding,
                             struct zmk_behavior_binding_event event) {
    zmk_unibody_set_mode(ZMK_UNIBODY_MODE_DONGLE);
    return ZMK_BEHAVIOR_OPAQUE;
}

static const struct behavior_driver_api behavior_unibody_dongle_driver_api = {
    .binding_pressed = on_dongle_pressed,
    .binding_released = on_keymap_binding_released,
#if IS_ENABLED(CONFIG_ZMK_BEHAVIOR_METADATA)
    .get_parameter_metadata = zmk_behavior_get_empty_param_metadata,
#endif
};

BEHAVIOR_DT_INST_DEFINE(0, NULL, NULL, NULL, NULL, POST_KERNEL, CONFIG_KERNEL_INIT_PRIORITY_DEFAULT,
                        &behavior_unibody_dongle_driver_api);

#endif /* DT_HAS_COMPAT_STATUS_OKAY(DT_DRV_COMPAT) */


/* Direct Behavior */
#undef DT_DRV_COMPAT
#define DT_DRV_COMPAT zmk_behavior_unibody_direct

#if DT_HAS_COMPAT_STATUS_OKAY(DT_DRV_COMPAT)

static int on_direct_pressed(struct zmk_behavior_binding *binding,
                             struct zmk_behavior_binding_event event) {
    zmk_unibody_set_mode(ZMK_UNIBODY_MODE_DIRECT);
    return ZMK_BEHAVIOR_OPAQUE;
}

static const struct behavior_driver_api behavior_unibody_direct_driver_api = {
    .binding_pressed = on_direct_pressed,
    .binding_released = on_keymap_binding_released,
#if IS_ENABLED(CONFIG_ZMK_BEHAVIOR_METADATA)
    .get_parameter_metadata = zmk_behavior_get_empty_param_metadata,
#endif
};

BEHAVIOR_DT_INST_DEFINE(0, NULL, NULL, NULL, NULL, POST_KERNEL, CONFIG_KERNEL_INIT_PRIORITY_DEFAULT,
                        &behavior_unibody_direct_driver_api);

#endif /* DT_HAS_COMPAT_STATUS_OKAY(DT_DRV_COMPAT) */
