#pragma once

#define TAPPING_TERM 190
#define QUICK_TAP_TERM 120

#define ENABLE_LED_MATRIX_SOLID_REACTIVE_MULTINEXUS
// #define RGB_MATRIX_SOLID_REACTIVE_GRADIENT_MODE
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS

#define RGB_MATRIX_DEFAULT_HUE 42
#define RGB_MATRIX_DEFAULT_SAT 210
#define RGB_MATRIX_DEFAULT_VAL 255

#ifdef HLC_CIRQUE_TRACKPAD // Only apply these settings to the right half

// Define the specific pins your Kyria rev3/rev4 uses
#    define CIRQUE_PINNACLE_ATTN_PIN GP2
#    define CIRQUE_PINNACLE_DR_PIN GP3

// The userspace already defines rotation, but being explicit here is safe
#    define POINTING_DEVICE_ROTATION_180

#endif
