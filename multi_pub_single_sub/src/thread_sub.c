/*
 * Copyright (c) 2024 WATANABE Aoi
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(sub, LOG_LEVEL_INF);

#include <zephyr/kernel.h>
#include <zephyr/zbus/zbus.h>

#include "events/int_event.h"

static void thread_sub(void *p1, void *p2, void *p3);
static void zbus_lis_cb(const struct zbus_channel *chan);

ZBUS_CHAN_DECLARE(int_chan);

K_THREAD_DEFINE(sub_tid, 1024, thread_sub, NULL, NULL, NULL, 2, K_ESSENTIAL, 0);
ZBUS_LISTENER_DEFINE(sub_int_lis, zbus_lis_cb);

static void thread_sub(void *p1, void *p2, void *p3)
{
	ARG_UNUSED(p1);
	ARG_UNUSED(p2);
	ARG_UNUSED(p3);
	LOG_INF("Create thread [sub]");

	for (;;) {
		LOG_DBG("spin sub");
		k_sleep(K_SECONDS(2));
	}
}
static void zbus_lis_cb(const struct zbus_channel *chan)
{
	if (chan == &int_chan) {
		const struct int_evt *evt = zbus_chan_const_msg(chan);
		LOG_WRN("Subscribe [%d]", evt->data);
	}
}