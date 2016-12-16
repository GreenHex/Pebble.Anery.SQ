//
// Copyright (C) 2016, Vinodh Kumar M. <GreenHex@gmail.com>
//

#pragma once
#include <pebble.h>

// #define DEBUG
// #define REVERSE
#define ALWAYS_SHOW_SECONDS false
// #define ALLOW_TIMELINE_QV

#define CLOCK_DIAL_SIZE_W 128
#define CLOCK_DIAL_SIZE_H CLOCK_DIAL_SIZE_W
#define CLOCK_DIAL_POS_Y ( ( PBL_DISPLAY_WIDTH - CLOCK_DIAL_SIZE_W ) / 2 )
#define CLOCK_DIAL_POS_X CLOCK_DIAL_POS_Y

#define CLOCK_DIAL_RECT ( GRect( CLOCK_DIAL_POS_X, CLOCK_DIAL_POS_Y, CLOCK_DIAL_SIZE_W, CLOCK_DIAL_SIZE_H ) )
#define CLOCK_TICK_EDGE_OFFSET 3 /* make it an odd number */
#define CLOCK_CORNER_RADIUS 2

#if PBL_DISPLAY_WIDTH == 200

#define SEC_HAND_LENGTH 74
#define SEC_HAND_TAIL_LENGTH 28
#define SEC_HAND_TIP_LENGTH 16
#define SEC_HAND_WIDTH 1
#define SEC_CENTER_DOT_RADIUS 5

#else

#define SEC_HAND_LENGTH 58
#define SEC_HAND_TAIL_LENGTH 23
#define SEC_HAND_TIP_LENGTH 12
#define SEC_HAND_WIDTH 1
#define SEC_CENTER_DOT_RADIUS 4

#endif

#define DATE_WINDOW_SIZE_W 34
#define DATE_WINDOW_SIZE_H 26
#define DATE_WINDOW_POS_X ( CLOCK_DIAL_SIZE_W - DATE_WINDOW_SIZE_W - DATE_LEFT_GAP )
#define DATE_WINDOW_POS_Y ( CLOCK_DIAL_SIZE_H/2 - DATE_WINDOW_SIZE_H/2 )
#define DATE_WINDOW_OUTLINE_THK 3
#define DATE_LEFT_GAP 3 /* make it same as CLOCK_TICK_EDGE_OFFSET */

#define DATE_TXT_VERT_ADJ 4

#define DATE_WINDOW_BOUNDS ( GRect( 0, 0, DATE_WINDOW_SIZE_W, DATE_WINDOW_SIZE_H ) )
#define DATE_WINDOW_FRAME ( GRect ( DATE_WINDOW_POS_X, DATE_WINDOW_POS_Y, DATE_WINDOW_SIZE_W, DATE_WINDOW_SIZE_H ) )

#if PBL_DISPLAY_WIDTH == 200

#define BATT_GAUGE_SIZE_W 45
#define BATT_GAUGE_SIZE_H 51
#define BATT_HAND_LENGTH 33
#define BATT_GAUGE_DOT_RADIUS 3

#else

#define BATT_GAUGE_SIZE_W 35
#define BATT_GAUGE_SIZE_H 33
#define BATT_HAND_LENGTH 23
#define BATT_GAUGE_DOT_RADIUS 3

#endif

#define BATT_GAUGE_RIGHT_GAP 3
#define BATTERY_GAUGE_POS_X ( BATT_GAUGE_RIGHT_GAP )
#define BATTERY_GAUGE_POS_Y ( CLOCK_DIAL_SIZE_H/2 - BATT_GAUGE_SIZE_H/2 )
#define BATTERY_GAUGE_FRAME ( GRect ( BATTERY_GAUGE_POS_X, BATTERY_GAUGE_POS_Y, BATT_GAUGE_SIZE_W, BATT_GAUGE_SIZE_H ) )

#define BATTERY_GAUGE_PIVOT ( GPoint( BATT_GAUGE_SIZE_W - BATT_GAUGE_RIGHT_GAP - 1, BATT_GAUGE_SIZE_H/2 ) )
#define BATTERY_GAUGE_MAX_ANGLE_DEG 20
#define BATTERY_GAUGE_TICK_POS_X ( -BATT_GAUGE_SIZE_W )
#define BATTERY_GAUGE_TICK_POS_Y ( BATT_GAUGE_SIZE_H / 2 )
#define BATTERY_GAUGE_TICK_POS ( GPoint( -BATTERY_GAUGE_TICK_POS_X, BATTERY_GAUGE_TICK_POS_Y ) )

#ifdef REVERSE

#define BACKGROUND_COLOUR GColorWhite
#define TICKS_COLOUR GColorBlack
#define HAND_COLOUR GColorBlack
#define HAND_HIGHLIGHT_COLOUR GColorDarkGray
#define HAND_OUTLINE_COLOUR GColorLightGray
/*
#define HAND_COLOUR GColorCobaltBlue
#define HAND_HIGHLIGHT_COLOUR GColorPictonBlue
#define HAND_OUTLINE_COLOUR GColorBlack
*/
#define BATTERY_GAUGE_POINTER_FILL_COLOUR PBL_IF_COLOR_ELSE( GColorLightGray, GColorBlack )
#define BATTERY_GAUGE_POINTER_OUTLINE_COLOUR BACKGROUND_COLOUR

#define COLOUR_BG_BITMAP_BG     BACKGROUND_COLOUR
#define COLOUR_DOT              TICKS_COLOUR
#define COLOUR_DOT_OUTLINE      BACKGROUND_COLOUR
#define COLOUR_SEC_HAND         TICKS_COLOUR /* GColorWhite */
#define COLOUR_SEC_HAND_TIP     PBL_IF_COLOR_ELSE( GColorRed /* GColorDarkCandyAppleRed */, GColorWhite )

#else

#define BACKGROUND_COLOUR PBL_IF_COLOR_ELSE( GColorBlack, GColorBlack )
#define TICKS_COLOUR PBL_IF_COLOR_ELSE( GColorWhite, GColorWhite )
#define HAND_COLOUR GColorLightGray
#define HAND_HIGHLIGHT_COLOUR GColorWhite
#define HAND_OUTLINE_COLOUR BACKGROUND_COLOUR
/*
#define HAND_COLOUR GColorCobaltBlue
#define HAND_HIGHLIGHT_COLOUR GColorPictonBlue
#define HAND_OUTLINE_COLOUR GColorBlack
*/
#define BATTERY_GAUGE_POINTER_FILL_COLOUR PBL_IF_COLOR_ELSE( GColorLightGray, GColorWhite )
#define BATTERY_GAUGE_POINTER_OUTLINE_COLOUR PBL_IF_COLOR_ELSE( GColorBlack, GColorBlack )

#define COLOUR_BG_BITMAP_BG     BACKGROUND_COLOUR
#define COLOUR_DOT              TICKS_COLOUR
#define COLOUR_DOT_OUTLINE      BACKGROUND_COLOUR
#define COLOUR_SEC_HAND         TICKS_COLOUR /* GColorWhite */
#define COLOUR_SEC_HAND_TIP     PBL_IF_COLOR_ELSE( GColorRed /* GColorDarkCandyAppleRed */, GColorWhite )

#endif

#define SHOW_SECONDS_TIMER_TIMEOUT_MS ( 5 * 1000 )

extern tm tm_time;
