/*
 *  file.h - Filesystem related interfaces
 *
 *  Copyright (C) 2001 Ethan Benson
 *
 *  parse_device_path()
 *
 *  Copyright (C) 2001 Colin Walters
 *
 *  Copyright (C) 1999 Benjamin Herrenschmidt
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

#ifndef FILE_H
#define FILE_H

#include "types.h"
#include "stddef.h"
#include "prom.h"

struct boot_file_t;
#include "fs.h"

#define FILE_MAX_PATH		1024

struct boot_fspec_t {
	char*	dev;		/* OF device path */
	int	part;		/* Partition number or -1 */
	char*	file;		/* File path */
};

struct boot_file_t {

	/* File access methods */
        const struct fs_t *fs;

	/* Filesystem private (to be broken once we have a
	 * better malloc'ator)
	 */

	int		device_kind;
	ihandle		of_device;
	ino_t		inode;
	__u64           pos;
	unsigned char*	buffer;
	__u64   	len;
//	unsigned int	dev_blk_size;
//	unsigned int	part_start;
//	unsigned int	part_count;
};

extern int
open_file(const struct boot_fspec_t*	spec,
	  struct boot_file_t*		file);

extern int
parse_device_path(char *imagepath, char *defdevice, int defpart,
		  char *deffile, struct boot_fspec_t *result);


#endif
