/***************************************************************************
 *                                                                         *
 *   Copyright (C) 2011 by Jean-Baptiste Mardelle (jb@kdenlive.org)        *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA          *
 ***************************************************************************/

#ifndef PROXYCLIPJOB
#define PROXYCLIPJOB

#include "abstractclipjob.h"

class QTemporaryFile;
class Bin;
class ProjectClip;

class ProxyJob : public AbstractClipJob
{
    Q_OBJECT

public:
    ProxyJob(ClipType cType, const QString &id, const QStringList& parameters, QTemporaryFile *playlist);
    virtual ~ ProxyJob();
    const QString destination() const;
    void startJob();
    stringMap cancelProperties();
    const QString statusMessage();
    void processLogInfo();
    static QList <ProjectClip *> filterClips(QList <ProjectClip *>clips);
    static QHash <ProjectClip *, AbstractClipJob *> prepareJob(Bin *bin, QList <ProjectClip *>clips);

private:
    QString m_dest;
    QString m_src;
    int m_exif;
    QString m_proxyParams;
    int m_renderWidth;
    int m_renderHeight;
    int m_jobDuration;
    bool m_isFfmpegJob;
    QTemporaryFile *m_playlist;
};

#endif
