/*
** Copyright (C) 2009-2015 Quadrant Information Security <quadrantsec.com>
** Copyright (C) 2009-2015 Champ Clark III <cclark@quadrantsec.com>
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License Version 2 as
** published by the Free Software Foundation.  You may not use, modify or
** distribute this program under any other version of the GNU General
** Public License.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/

/* sagan-credit.c
 *
 * Give credit where credit is due
 *
 */

#ifdef HAVE_CONFIG_H
#include "config.h"             /* From autoconf */
#endif

#include "sagan.h"
#include "version.h"

void Sagan_Credits(void)
{

    fprintf(stderr, "\n--[Sagan version %s | Credits]--------------------------------\n\n", VERSION);
    fprintf(stderr, "Champ Clark III (cclark@quadrantsec.com)\tLead developer.\n");
    fprintf(stderr, "Robert Nunley (rnunley@quadrantsec.com)\t\tRules/Ideas.\n");
    fprintf(stderr, "Brian Echeverry (becheverry@quadrantsec.com)\tRules.\n");
    fprintf(stderr, "Marcus Ranum\t\t\t\t\tsagan-plog.c code.\n");
    fprintf(stderr, "\"DrForbin\"\t\t\t\t\tPatches/testing/bug fixes.\n");
    fprintf(stderr, "Rainer Gerhards\t\t\t\t\tRsyslog/Liblognorm author.\n");
    fprintf(stderr, "Bruce M. Wink (bwink@quadrantsec.com)\t\tIdeas.\n");
    fprintf(stderr, "Daniel Koopmans\t\t\t\t\tBug reports & testing.\n");
    fprintf(stderr, "\"remydb\" (Github)\t\t\t\tBug reports & testing.\n");
    fprintf(stderr, "\"CyberTaoFlow\" (Github)\t\t\t\tBug reports & testing.\n");
    fprintf(stderr, "\"nix8\" (Github)\t\t\t\t\tBug reports & testing.\n");
    fprintf(stderr, "\"pitrpitr\" (Github)\t\t\t\tBug reports & testing.\n");
    fprintf(stderr, "\"ebayer\" (Github)\t\t\t\tBug reports & testing.\n");
    fprintf(stderr, "\"Juan Manuel (jmcabo - Github)\t\t\tBug reports & testing.\n");
    fprintf(stderr, "\"Stas Alekseev\" (salekseev - Github)\t\tSpec file for Redhat/Fedora.\n");
    fprintf(stderr, "\"Alice Kaerast\" (kaerast - Github\t\trsyslog example in 'extra'.\n");
    fprintf(stderr, "\"DigiAngel\" (Github)\t\t\t\t'content:!' idea.\n");
    fprintf(stderr, "Robert Bridge (RobbieAB - Github)\t\t'flowbit' idea.\n");
    fprintf(stderr, "Mathieu Parent (sathieu - Github)\t\tOld MySQL port fix.\n");
    fprintf(stderr, "Pierre Chifflier (chifflier - Githib)\t\tPatches/bug fixes/man page.\n");
    fprintf(stderr, "Pierre Chifflier \t\t\t\tDebian/Ubuntu packages.\n");
    fprintf(stderr, "\"miverson\" (Github)\t\t\t\tOSSEC converter/bug fixes.\n");
    fprintf(stderr, "\"ekse\" (Github)\t\t\t\t\tBug reports & testing.\n");
    fprintf(stderr, "\"mtgxx\" (Github)\t\t\t\tBug reports & testing.\n");
    fprintf(stderr, "\"powertoaster\" (Github)\t\t\t\tBug reports & testing.\n");
    fprintf(stderr, "Pawel Hajdan jr (Gentoo)\t\t\tGentoo ebuild.\n");
    fprintf(stderr, "James Lay\t\t\t\t\tRules.\n");
    fprintf(stderr, "Brad Doctor\t\t\t\t\tRules.\n");
    fprintf(stderr, "Sniffty Dugen\t\t\t\t\tRules.\n");
    fprintf(stderr, "Iman Khosravi\t\t\t\t\tRules.\n");
    fprintf(stderr, "Jon Schipp\t\t\t\t\tBug reports & testing.\n");
    fprintf(stderr, "Aleksey Chudov\t\t\t\t\t\"logrotate\" fix/suggestion.\n");

    fprintf(stderr, "\n");

}


