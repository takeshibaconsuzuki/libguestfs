/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED BY 'src/generator.ml'.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009 Red Hat Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <rpc/types.h>
#include <rpc/xdr.h>
#include "daemon.h"
#include "../src/guest_protocol.h"
#include "actions.h"

static void mount_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mount_args args;
  const char *device;
  const char *mountpoint;

  if (!xdr_guestfs_mount_args (xdr_in, &args)) {
    reply_with_error ("mount: daemon failed to decode procedure arguments");
    return;
  }
  device = args.device;
  mountpoint = args.mountpoint;

  r = do_mount (device, mountpoint);
  if (r == -1)
    /* do_mount has already called reply_with_error, so just return */
    return;

  reply (NULL, NULL);
}

static void sync_stub (XDR *xdr_in)
{
  int r;

  r = do_sync ();
  if (r == -1)
    /* do_sync has already called reply_with_error, so just return */
    return;

  reply (NULL, NULL);
}

static void touch_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_touch_args args;
  const char *path;

  if (!xdr_guestfs_touch_args (xdr_in, &args)) {
    reply_with_error ("touch: daemon failed to decode procedure arguments");
    return;
  }
  path = args.path;

  r = do_touch (path);
  if (r == -1)
    /* do_touch has already called reply_with_error, so just return */
    return;

  reply (NULL, NULL);
}

