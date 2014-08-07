/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the demonstration applications of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "stdafx.h"

#ifdef OPENGL_ONLY
#include <QtGui/QGuiApplication>
#define Application QGuiApplication
#else
#include <QtWidgets/QApplication>
#define Application QApplication
#endif

#include "Viewer.h"
#include "Scene.h"

#include <sofa/helper/system/FileRepository.h>

int main(int argc, char **argv)
{
    Application app(argc, argv);

    qmlRegisterType<Viewer>("Viewer", 1, 0, "Viewer");
	qmlRegisterType<Scene>("Scene", 1, 0, "Scene");

    QUrl mainScriptUrl = QUrl("qrc:///resource/Main.qml");

	QSurfaceFormat format;
	format.setMajorVersion(3);
	format.setMajorVersion(2);
	format.setProfile(QSurfaceFormat::OpenGLContextProfile::CompatibilityProfile);

    QQmlApplicationEngine engine(mainScriptUrl);
    QObject* topLevel = engine.rootObjects().value(0);
    QQuickWindow* window = qobject_cast<QQuickWindow *>(topLevel);
	//window->setFormat(format);
    if(0 == window)
    {
        qDebug() << "Your QML root object should be a window";
        return 1;
    }

    window->show();

    return app.exec();

//    // Example if you cannot use the blocking app.exec() function
//    QEventLoop eventLoop;

//    std::cout << "Start" << app.quitOnLastWindowClosed() << std::endl;
//    while(window->isVisible())
//    {
//        eventLoop.processEvents();
//    }
//    std::cout << "Exit" << std::endl;

//    return 0;
}
