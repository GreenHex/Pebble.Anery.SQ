//
// Copyright (C) 2016, Vinodh Kumar M. <GreenHex@gmail.com>
//

#pragma once
#include <pebble.h>
#include "global.h"

extern Layer *date_layer;

void date_init( Layer *parent_layer );
void date_deinit( void );
