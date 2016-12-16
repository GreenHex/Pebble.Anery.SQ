//
// Copyright (C) 2016, Vinodh Kumar M. <GreenHex@gmail.com>
//

#pragma once
#include <pebble.h>
#include "global.h"

#if PBL_DISPLAY_WIDTH == 200

static GPathInfo BATT_GAUGE_TICK = {
  2, (GPoint[]) {
    { BATTERY_GAUGE_TICK_POS_X + 5, 0 },
    { BATTERY_GAUGE_TICK_POS_X, 0 }
  }
};

#else

static GPathInfo BATT_GAUGE_TICK = {
  2, (GPoint[]) {
    { BATTERY_GAUGE_TICK_POS_X + 3, 0 },
    { BATTERY_GAUGE_TICK_POS_X, 0 }
  }
};

#endif

typedef struct {
  GContext *ctx;
  uint32_t batt_angle;
  GPoint center_pt;
  GPath *s_hand;
  GColor hand_colour;
  GColor hand_outline_colour;
  uint16_t dot_radius;
  BatteryChargeState charge_state;
} BATTERY_HAND_DRAW_PARAMS;

extern Layer *battery_layer;

void battery_init( Layer *parent_layer );
void battery_deinit( void );
