/*
 * Copyright (c) 2024 WATANABE Aoi
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(pub, LOG_LEVEL_INF);

#include <zephyr/kernel.h>
#include <zephyr/zbus/zbus.h>

#include "events/int_event.h"

static void thread_pub(void *p1, void *p2, void *p3);

ZBUS_CHAN_DECLARE(int_chan);

static char name1[] = "pub1";
static char name2[] = "pub2";

static struct int_evt pub1 = {.data = 1};
static struct int_evt pub2 = {.data = 2};

K_THREAD_DEFINE(pub1_tid, 1024, thread_pub, name1, &pub1, NULL, 1, K_ESSENTIAL, 10);
K_THREAD_DEFINE(pub2_tid, 1024, thread_pub, name2, &pub2, NULL, 1, K_ESSENTIAL, 1000);

static void thread_pub(void *p1, void *p2, void *p3)
{
	const char *name = (char *)p1;
  const struct int_evt *evt = (struct int_evt *)p2;
  LOG_INF("Create thread [%s]", name);
	k_sleep(K_SECONDS(2));

	for (;;) {
		LOG_DBG("Spin [%s]", name);
		LOG_WRN("Publish [%s: %d]", name, evt->data);
    zbus_chan_pub(&int_chan,evt, K_FOREVER);
		k_sleep(K_SECONDS(2));
	}
}