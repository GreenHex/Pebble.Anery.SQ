#include <pebble.h>
#include "status.h"

extern tm tm_time;

static Layer* status_layer = 0;
static TextLayer *status_text_layer = 0;

static void status_layer_update_proc( Layer *layer, GContext *ctx ) {
  GRect bounds = layer_get_bounds( layer );
  graphics_context_set_fill_color( ctx, GColorBlack );
  graphics_fill_rect( ctx, bounds, CLOCK_CORNER_RADIUS, GCornersBottom );  
}

// #define DATE_STRING "%a, %e-%b-%Y"
#define DATE_STRING "%a, %b %e"

static void status_text_layer_update_proc( Layer *layer, GContext *ctx ) {
  char date_str[] = "AAA, DD-MMM-YYYY";
  GRect date_window_bounds = layer_get_bounds( layer );
  date_window_bounds.origin.y -= 2;
  graphics_context_set_text_color( ctx, GColorWhite );
  strftime( date_str, sizeof( date_str ), DATE_STRING, &tm_time );
  graphics_draw_text( ctx, date_str, fonts_get_system_font( FONT_KEY_ROBOTO_CONDENSED_21 ), date_window_bounds,
                     GTextOverflowModeTrailingEllipsis, GTextAlignmentCenter, NULL );
}

void status_init( Layer *parent_layer ) {
  status_layer = layer_create( STATUS_WINDOW_RECT );
  layer_set_update_proc( status_layer, status_layer_update_proc );
  layer_add_child( parent_layer, status_layer );
  
  status_text_layer = text_layer_create( layer_get_bounds( status_layer ) );
  layer_set_update_proc( text_layer_get_layer( status_text_layer ), status_text_layer_update_proc );
  layer_add_child( status_layer, text_layer_get_layer( status_text_layer ) );
}

void status_deinit( void ) {
  if ( status_text_layer ) text_layer_destroy( status_text_layer );
  if ( status_layer ) layer_destroy( status_layer );
}