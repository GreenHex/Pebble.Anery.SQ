//
// Copyright (C) 2016, Vinodh Kumar M. <GreenHex@gmail.com>
//

#pragma once
#include <pebble.h>

// #define DEBUG
// #define ALWAYS_SHOW_SECONDS
// #define ALLOW_TIMELINE_QV
#define SHOW_SECONDS_TIMER_TIMEOUT_MS ( 8 * 1000 )
// #define RANDOMIZE_CLOCKFACE_COLOURS

#define CLOCK_DIAL_SIZE_W 124 /* 126 */
#define CLOCK_DIAL_SIZE_H ( CLOCK_DIAL_SIZE_W - 4 ) /* 118 */
#define CLOCK_DIAL_POS_X ( ( PBL_DISPLAY_WIDTH - CLOCK_DIAL_SIZE_W ) / 2 )
#define CLOCK_DIAL_POS_Y CLOCK_DIAL_POS_X
#define CLOCK_DIAL_RECT ( GRect( CLOCK_DIAL_POS_X, CLOCK_DIAL_POS_Y, CLOCK_DIAL_SIZE_W, CLOCK_DIAL_SIZE_H ) )
#define CLOCK_TICK_EDGE_OFFSET 3 /* make it an odd number */
#define CLOCK_CORNER_RADIUS 2

#define HOUR_HAND_LENGTH 32
#define HOUR_HAND_WIDTH 11
#define HOUR_CENTER_DOT_RADIUS 10
#define MIN_HAND_LENGTH 50
#define MIN_HAND_WIDTH 7
#define MIN_CENTER_DOT_RADIUS ( HOUR_CENTER_DOT_RADIUS - 3 )
#define SEC_HAND_LENGTH 52
#define SEC_HAND_TAIL_LENGTH 18
#define SEC_HAND_TIP_LENGTH 12
#define SEC_HAND_WIDTH 1
#define SEC_CENTER_DOT_RADIUS ( HOUR_CENTER_DOT_RADIUS - 6 )

#define BATT_GAUGE_INT_RADIUS 12
#define BATT_GAUGE_EXT_RADIUS 16
#define BATT_GAUGE_SIZE_W ( ( BATT_GAUGE_EXT_RADIUS * 2 ) + 1 )
#define BATT_GAUGE_SIZE_H BATT_GAUGE_SIZE_W 
#define BATT_GAUGE_POS_X ( ( CLOCK_DIAL_SIZE_W / 2 ) - ( BATT_GAUGE_SIZE_W / 2 ) )
#define BATT_GAUGE_POS_Y ( ( CLOCK_DIAL_SIZE_H / 2 ) - ( BATT_GAUGE_SIZE_H / 2 ) )
#define BATT_GAUGE_RECT ( GRect ( BATT_GAUGE_POS_X, BATT_GAUGE_POS_Y, BATT_GAUGE_SIZE_W, BATT_GAUGE_SIZE_H ) )

#define STATUS_WINDOW_SIZE_W CLOCK_DIAL_SIZE_W
#define STATUS_WINDOW_SIZE_H ( PBL_DISPLAY_HEIGHT - CLOCK_DIAL_SIZE_H - ( CLOCK_DIAL_POS_Y * 2 ) )
#define STATUS_WINDOW_POS_X CLOCK_DIAL_POS_X
#define STATUS_WINDOW_POS_Y ( CLOCK_DIAL_SIZE_H + CLOCK_DIAL_POS_Y )
#define STATUS_WINDOW_RECT ( GRect ( STATUS_WINDOW_POS_X, STATUS_WINDOW_POS_Y, STATUS_WINDOW_SIZE_W, STATUS_WINDOW_SIZE_H ) )
#define STATUS_TEXT_HOR_ADJ 0
#define STATUS_TEXT_VER_ADJ 2

#define FOREGROUND_COLOUR PBL_IF_COLOR_ELSE( GColorBlack, GColorBlack )
#define BACKGROUND_COLOUR PBL_IF_COLOR_ELSE( GColorWhite, GColorWhite )

extern tm tm_time;
extern GColor foreground_colour;
extern GColor background_colour;
