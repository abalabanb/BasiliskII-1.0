/*
 *  xpram_amiga.cpp - XPRAM handling, AmigaOS specific stuff
 *
 *  Basilisk II (C) 1997-2001 Christian Bauer
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
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <proto/dos.h>

#include "sysdeps.h"
#include "xpram.h"


// XPRAM file name
extern char *XPRAM_FILE_NAME;

/*
 *  Load XPRAM from settings file
 */

void LoadXPRAM(const char *vmdir)
{
	BPTR fh;

	if (XPRAM_FILE_NAME)
	{
		fh = Open(XPRAM_FILE_NAME, MODE_OLDFILE);

		if (fh)
		{
			Read(fh, XPRAM, 256);
			Close(fh);
			fh = NULL;
		}
	}
}


/*
 *  Save XPRAM to settings file
 */

void SaveXPRAM(void)
{
	BPTR fh;

	if (XPRAM_FILE_NAME)
	{
		fh = Open(XPRAM_FILE_NAME, MODE_NEWFILE);

		if (fh)
		{
			Write(fh, XPRAM, 256);
			Close(fh);
			fh = NULL;
		}
	}
}


/*
 *  Delete PRAM file
 */

void ZapPRAM(void)
{
	if (XPRAM_FILE_NAME)
	{
		Delete(XPRAM_FILE_NAME);
	}
}
