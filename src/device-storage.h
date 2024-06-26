/* Copyright (C) 2018-2021 Open Information Security Foundation
 *
 * You can copy, redistribute or modify this Program under the terms of
 * the GNU General Public License version 2 as published by the Free
 * Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * version 2 along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */

/**
 * \file
 *
 * \author Eric Leblond <eric@regit.org>
 *
 * LiveDevice wrapper around storage api
 */

#ifndef SURICATA_DEVICE_STORAGE_H
#define SURICATA_DEVICE_STORAGE_H

#include "util-device.h"

typedef struct LiveDevStorageId_ {
    int id;
} LiveDevStorageId;

unsigned int LiveDevStorageSize(void);

void *LiveDevGetStorageById(LiveDevice *d, LiveDevStorageId id);
int LiveDevSetStorageById(LiveDevice *d, LiveDevStorageId id, void *ptr);

void LiveDevFreeStorage(LiveDevice *d);

LiveDevStorageId LiveDevStorageRegister(const char *name, const unsigned int size,
        void *(*Alloc)(unsigned int), void (*Free)(void *));

#endif /* SURICATA_DEVICE_STORAGE_H */
