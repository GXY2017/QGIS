/***************************************************************************
  qgscrashhandler.h - QgsCrashHandler

 ---------------------
 begin                : 23.4.2017
 copyright            : (C) 2017 by Nathan Woodrow
 email                : woodrow.nathan@gmail.com
 ***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
#ifndef QGSCRASHHANDLER_H
#define QGSCRASHHANDLER_H

#include "qgis.h"
#include "qgis_app.h"
#include "qgscrashreport.h"

#ifdef WIN32
#include <windows.h>
#include <dbghelp.h>
#endif

/**
 * Utility object to handle crashes in QGIS.
 */
class APP_EXPORT QgsCrashHandler
{

  public:
#ifdef Q_OS_WIN
    static LONG WINAPI handle( struct _EXCEPTION_POINTERS *ExceptionInfo );
#endif

    /**
     * Show the crash dialog.
     * @param stack The current stack of the crash point.
     */
    static void showCrashDialog( const QgsStackLines &stack );

    /**
     * Restart the application.
     * Restores project and arguments used when application was loaded.
     */
    static void restartApplication();

  private:

    /**
     * This class doesn't need to be created by anyone as is only used to handle
     * crashes in the application.
     */
    QgsCrashHandler() {}
};


#endif // QGSCRASHHANDLER_H
