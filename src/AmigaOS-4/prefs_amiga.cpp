/*
 *  prefs_amiga.cpp - Preferences handling, AmigaOS specifix stuff
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

#include <stdio.h>

#include "sysdeps.h"
#include "prefs.h"


// Platform-specific preferences items
prefs_desc platform_prefs_items[] = {
	{"sound", TYPE_STRING, false, "sound output mode description"},
	{"scsimemtype", TYPE_INT32, false, "SCSI buffer memory type"},
	{"lineskip", TYPE_INT32, false, "Skip scan lines"},
	{"windowdepth", TYPE_INT32, false, "Window depth" },
	{"use_p96_lock", TYPE_BOOLEAN, false, "Lock screen in fullscreen" },
	{"use_direct_video_32b", TYPE_BOOLEAN, false, "For some videocards" },
	{NULL, TYPE_END, false, NULL} // End of list
};


// Prefs file name
extern char *PREFS_FILE_NAME;
extern char *PREFS_FILE_NAME_ARC;

/*
 *  Load preferences from settings file
 */

void LoadPrefs(const char *vmdir)
{
	// Read preferences from settings file
	FILE *f = fopen(PREFS_FILE_NAME, "r");
	if (f != NULL) {

		// Prefs file found, load settings
		LoadPrefsFromStream(f);
		fclose(f);

	} else {

		// No prefs file, save defaults
		SavePrefs();
	}
}


/*
 *  Save preferences to settings file
 */

void SavePrefs(void)
{
	FILE *f;
	if ((f = fopen(PREFS_FILE_NAME, "w")) != NULL) {
		SavePrefsToStream(f);
		fclose(f);
	}
	if ((f = fopen(PREFS_FILE_NAME_ARC, "w")) != NULL) {
		SavePrefsToStream(f);
		fclose(f);
	}
}


/*
 *  Add defaults of platform-specific prefs items
 *  You may also override the defaults set in PrefsInit()
 */

void AddPlatformPrefsDefaults(void)
{
	PrefsReplaceString("extfs", "RAM:");
	PrefsAddInt32("scsimemtype", 0);
}
