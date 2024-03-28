/*
 * Copyright (c) 2024 WATANABE Aoi
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "int_event.h"
#include <zephyr/zbus/zbus.h>

ZBUS_CHAN_DEFINE(
    int_chan, struct int_evt, NULL, NULL,
    ZBUS_OBSERVERS(sub_int_lis),
    ZBUS_MSG_INIT());