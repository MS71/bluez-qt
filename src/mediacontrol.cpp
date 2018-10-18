/*
 * BluezQt - Asynchronous Bluez wrapper library
 *
 * Copyright (C) 2015 David Rosca <nowrep@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) version 3, or any
 * later version accepted by the membership of KDE e.V. (or its
 * successor approved by the membership of KDE e.V.), which shall
 * act as a proxy defined in Section 6 of version 3 of the license.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#include "mediacontrol.h"
#include "mediacontrol_p.h"
#include "pendingcall.h"

namespace BluezQt
{
#if 0
static QString equalizerToString(MediaControl::Equalizer equalizer)
{
    switch (equalizer) {
    case MediaControl::EqualizerOn:
        return QStringLiteral("on");
    default:
        return QStringLiteral("off");
    }
}

static QString repeatToString(MediaControl::Repeat repeat)
{
    switch (repeat) {
    case MediaControl::RepeatSingleTrack:
        return QStringLiteral("singletrack");
    case MediaControl::RepeatAllTracks:
        return QStringLiteral("alltracks");
    case MediaControl::RepeatGroup:
        return QStringLiteral("group");
    default:
        return QStringLiteral("off");
    }
}

static QString shuffleToString(MediaControl::Shuffle shuffle)
{
    switch (shuffle) {
    case MediaControl::ShuffleAllTracks:
        return QStringLiteral("alltracks");
    case MediaControl::ShuffleGroup:
        return QStringLiteral("group");
    default:
        return QStringLiteral("off");
    }
}
#endif
MediaControl::MediaControl(const QString &path, const QVariantMap &properties)
    : QObject()
    , d(new MediaControlPrivate(path, properties))
{
}

MediaControl::~MediaControl()
{
    delete d;
}

MediaControlPtr MediaControl::toSharedPtr() const
{
    return d->q.toStrongRef();
}

#if 0
QString MediaControl::name() const
{
    return d->m_name;
}

MediaControl::Equalizer MediaControl::equalizer() const
{
    return d->m_equalizer;
}

PendingCall *MediaControl::setEqualizer(MediaControl::Equalizer equalizer)
{
    return new PendingCall(d->setDBusProperty(QStringLiteral("Equalizer"), equalizerToString(equalizer)),
                           PendingCall::ReturnVoid, this);
}

MediaControl::Repeat MediaControl::repeat() const
{
    return d->m_repeat;
}

PendingCall *MediaControl::setRepeat(MediaControl::Repeat repeat)
{
    return new PendingCall(d->setDBusProperty(QStringLiteral("Repeat"), repeatToString(repeat)),
                           PendingCall::ReturnVoid, this);
}

MediaControl::Shuffle MediaControl::shuffle() const
{
    return d->m_shuffle;
}

PendingCall *MediaControl::setShuffle(MediaControl::Shuffle shuffle)
{
    return new PendingCall(d->setDBusProperty(QStringLiteral("Shuffle"), shuffleToString(shuffle)),
                           PendingCall::ReturnVoid, this);
}

MediaControl::Status MediaControl::status() const
{
    return d->m_status;
}

MediaControlTrack MediaControl::track() const
{
    return d->m_track;
}

quint32 MediaControl::position() const
{
    return d->m_position;
}

PendingCall *MediaControl::play()
{
    return new PendingCall(d->m_bluezMediaControl->Play(), PendingCall::ReturnVoid, this);
}

PendingCall *MediaControl::pause()
{
    return new PendingCall(d->m_bluezMediaControl->Pause(), PendingCall::ReturnVoid, this);
}

PendingCall *MediaControl::stop()
{
    return new PendingCall(d->m_bluezMediaControl->Stop(), PendingCall::ReturnVoid, this);
}

PendingCall *MediaControl::next()
{
    return new PendingCall(d->m_bluezMediaControl->Next(), PendingCall::ReturnVoid, this);
}

PendingCall *MediaControl::previous()
{
    return new PendingCall(d->m_bluezMediaControl->Previous(), PendingCall::ReturnVoid, this);
}

PendingCall *MediaControl::fastForward()
{
    return new PendingCall(d->m_bluezMediaControl->FastForward(), PendingCall::ReturnVoid, this);
}

PendingCall *MediaControl::rewind()
{
    return new PendingCall(d->m_bluezMediaControl->Rewind(), PendingCall::ReturnVoid, this);
}
#endif

} // namespace BluezQt
