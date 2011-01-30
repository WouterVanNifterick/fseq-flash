#ifndef _Sound_to_SPINET_h_
#define _Sound_to_SPINET_h_
/* Sound_to_SPINET.h
 *
 * Copyright (C) 1993-2002 David Weenink
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

/*
 djmw 19970408
 djmw 20020813 GPL header
*/

#ifndef _SPINET_h_
	#include "SPINET.h"
#endif

#ifndef _Sound_extensions_h_
	#include "Sound_extensions.h"
#endif

SPINET Sound_to_SPINET (Sound me, double timeStep, double windowDuration,
	double minimumFrequencyHz, double maximumFrequencyHz, long nFilters,
	double excitationErbProportion, double inhibitionErbProportion);

#endif /* _Sound_to_SPINET_h_ */