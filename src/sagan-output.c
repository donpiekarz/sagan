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

/* sagan-output.c
*
* This becomes a threaded operation.  This handles all I/O intensive output plugins
*/
#ifdef HAVE_CONFIG_H
#include "config.h"             /* From autoconf */
#endif

#include <stdio.h>
#include <pthread.h>

#include "sagan.h"
#include "sagan-output.h"
#include "sagan-rules.h"
#include "sagan-config.h"

#include "output-plugins/sagan-snortsam.h"
#include "output-plugins/sagan-unified2.h"
#include "output-plugins/sagan-alert.h"
#include "output-plugins/sagan-external.h"
#include "output-plugins/sagan-syslog.h"

struct _SaganCounters *counters;
struct _Rule_Struct *rulestruct;
struct _SaganConfig *config;

sbool nonthread_alert_lock=0;

pthread_mutex_t SaganOutputNonThreadMutex=PTHREAD_MUTEX_INITIALIZER;

void Sagan_Output( _SaganEvent *Event )
{

    /* Single threaded operations */

    if ( nonthread_alert_lock == 0 )
        {

            pthread_mutex_lock(&SaganOutputNonThreadMutex);
            nonthread_alert_lock = 1;

            Sagan_Alert_File(Event);

#if defined(HAVE_DNET_H) || defined(HAVE_DUMBNET_H)
            if ( config->sagan_unified2_flag )
                {
                    Sagan_Unified2( Event );
                    Sagan_Unified2LogPacketAlert( Event );
                }
#endif

            nonthread_alert_lock = 0;
            pthread_mutex_unlock(&SaganOutputNonThreadMutex);
        }

    /* Are any "External" output formats enabled? */

    /****************************************************************************/
    /* Syslog output                                                            */
    /****************************************************************************/

#ifdef WITH_SYSLOG

    if ( config->sagan_syslog_flag )
        {
            Sagan_Alert_Syslog( Event );
        }

#endif

    /****************************************************************************/
    /* Snortsam Support	                                                        */
    /****************************************************************************/

    /* If we have a snortsam server && the rule requires snortsam..... */

#ifdef WITH_SNORTSAM

    if ( config->sagan_fwsam_flag && rulestruct[Event->found].fwsam_src_or_dst ) Sagan_FWSam( Event );

#endif

    /****************************************************************************/
    /* SMTP/Email support (libesmtp)                                            */
    /****************************************************************************/

#ifdef HAVE_LIBESMTP
    if ( config->sagan_esmtp_flag ) Sagan_ESMTP_Thread( Event );
#endif

    /****************************************************************************/
    /* External program support                                                 */
    /****************************************************************************/

    if ( config->sagan_ext_flag ) Sagan_Ext_Thread( Event );

}

