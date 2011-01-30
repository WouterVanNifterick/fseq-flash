/* main_Praat.c
 *
 * Copyright (C) 1992-2010 Paul Boersma
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

/*
 * pb 2010/11/30
 */

#include "praat.h"
#include "praat_version.h"

static void logo (Graphics g) {
	Graphics_setWindow (g, 0, 1, 0.00, 0.80);
	Graphics_setTextAlignment (g, Graphics_CENTRE, Graphics_HALF);
	Graphics_setFont (g, kGraphics_font_TIMES);
	Graphics_setFontSize (g, 45);
	Graphics_setColour (g, Graphics_MAROON);
	Graphics_text (g, 0.385, 0.66, L"P");
	Graphics_text (g, 0.448, 0.66, L"\\s{R}");
	Graphics_text (g, 0.510, 0.66, L"\\s{A}");
	Graphics_text (g, 0.575, 0.66, L"\\s{A}");
	Graphics_text (g, 0.628, 0.66, L"\\s{T}");
	Graphics_setFontSize (g, 15);
	Graphics_text (g, 0.5, 0.55, L"%%doing phonetics by computer");
	#define xstr(s) str(s)
	#define str(s) #s
	Graphics_text (g, 0.5, 0.45, L"version " xstr(PRAAT_VERSION_STR));
	Graphics_setColour (g, Graphics_BLACK);
	Graphics_setFontSize (g, 14);
	Graphics_text (g, 0.5, 0.33, L"www.praat.org");
	Graphics_setFont (g, kGraphics_font_HELVETICA);
	Graphics_setFontSize (g, 10);
	Graphics_text (g, 0.5, 0.16, L"Copyright \\co 1992-" xstr(PRAAT_YEAR) " by Paul Boersma and David Weenink");
}

static wchar_t testScript1 [] = L""
	"demo Text... 0.5 centre 0.5 half Hello world\n"
	"demoWaitForInput ( )\n"
;

static wchar_t testScript2 [] = L""
	"Create Sound from formula... test mono 0.0 1.0 44100 1/2 * sin(2*pi*377*x) + randomGauss(0,0.1)\n"
	"Play\n"
	"Remove\n"
	"echo Finished\n"
;

int main (int argc, char *argv []) {
	praat_setLogo (130, 80, logo);
	//praat_setStandAloneScriptText (testScript2);
	praat_init ("Praat", argc, argv);
	INCLUDE_LIBRARY (praat_uvafon_init)
	INCLUDE_LIBRARY (praat_contrib_Ola_KNN_init)
	praat_run ();
	return 0;
}

/* End of file main_Praat.c */