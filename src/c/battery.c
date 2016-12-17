//
// Copyright (C) 2016, Vinodh Kumar M. <GreenHex@gmail.com>
//

#include <pebble.h>
#include "battery.h"
#include "utils.h"

Layer *battery_layer = 0;
static BatteryChargeState charge_state;

static void batt_gauge_update_proc( BatteryChargeState state ) {
  charge_state = state;
  layer_mark_dirty( battery_layer );
}

static void battery_layer_update_proc( Layer *layer, GContext *ctx ) {
  GRect bounds = layer_get_bounds( layer );
  uint32_t batt_angle = TRIG_MAX_ANGLE * charge_state.charge_percent / 100;
  graphics_context_set_fill_color( ctx, PBL_IF_COLOR_ELSE( foreground_colour, GColorBlack ) );
  graphics_fill_radial( ctx, bounds, GOvalScaleModeFitCircle, 
                       BATT_GAUGE_EXT_RADIUS - BATT_GAUGE_INT_RADIUS, 0, batt_angle );
}

void battery_init( Layer* parent_layer ) {
  battery_layer = layer_create( BATT_GAUGE_RECT );
  layer_set_update_proc( battery_layer, battery_layer_update_proc );
  layer_add_child( parent_layer, battery_layer );
  layer_set_hidden( battery_layer, true );
  
  batt_gauge_update_proc( battery_state_service_peek() );
  battery_state_service_subscribe( batt_gauge_update_proc );
}

void battery_deinit( void ) {
  if ( battery_layer ) layer_destroy( battery_layer );
}