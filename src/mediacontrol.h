/*
 * BluezQt - Asynchronous BlueZ wrapper library
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

#ifndef BLUEZQT_MEDIACONTROL_H
#define BLUEZQT_MEDIACONTROL_H

#include <QObject>

#include "types.h"
//#include "mediacontroltrack.h"
#include "bluezqt_export.h"

namespace BluezQt
{

class PendingCall;

/**
 * @class BluezQt::MediaControl mediacontrol.h <BluezQt/MediaControl>
 *
 * Media player.
 *
 * This class represents a media player interface.
 */
class BLUEZQT_EXPORT MediaControl : public QObject
{
    Q_OBJECT
    //Q_PROPERTY(QString name READ name NOTIFY nameChanged)
    //Q_PROPERTY(Status status READ status NOTIFY statusChanged)

public:
    /**
     * Destroys a MediaControl object.
     */
    ~MediaControl();

    /**
     * Returns a shared pointer from this.
     *
     * @return MediaControlPtr
     */
    MediaControlPtr toSharedPtr() const;

#if 0
    /**
     * Returns the name of the player.
     *
     * @return name of player
     */
    QString name() const;

    /**
     * Returns the status of the player.
     *
     * @return status of player
     */
    Status status() const;
#endif

public Q_SLOTS:
#if 0
    /**
     * Resumes playback.
     *
     * Possible errors: PendingCall::NotSupported, PendingCall::Failed
     *
     * @return void pending call
     */
    PendingCall *play();

    /**
     * Pauses playback.
     *
     * Possible errors: PendingCall::NotSupported, PendingCall::Failed
     *
     * @return void pending call
     */
    PendingCall *pause();

    /**
     * Stops playback.
     *
     * Possible errors: PendingCall::NotSupported, PendingCall::Failed
     *
     * @return void pending call
     */
    PendingCall *stop();

    /**
     * Switch to next track.
     *
     * Possible errors: PendingCall::NotSupported, PendingCall::Failed
     *
     * @return void pending call
     */
    PendingCall *next();

    /**
     * Switch to previous track.
     *
     * Possible errors: PendingCall::NotSupported, PendingCall::Failed
     *
     * @return void pending call
     */
    PendingCall *previous();

    /**
     * Fast forwards playback.
     *
     * Possible errors: PendingCall::NotSupported, PendingCall::Failed
     *
     * @return void pending call
     */
    PendingCall *fastForward();

    /**
     * Rewinds playback.
     *
     * Possible errors: PendingCall::NotSupported, PendingCall::Failed
     *
     * @return void pending call
     */
    PendingCall *rewind();

Q_SIGNALS:
    /**
     * Indicates that player's name have changed.
     */
    void nameChanged(const QString &name);

    /**
     * Indicates that player's equalizer state have changed.
     */
    void equalizerChanged(Equalizer equalizer);

    /**
     * Indicates that player's repeat state have changed.
     */
    void repeatChanged(Repeat repeat);

    /**
     * Indicates that player's shuffle state have changed.
     */
    void shuffleChanged(Shuffle shuffle);

    /**
     * Indicates that player's status have changed.
     */
    void statusChanged(Status status);

    /**
     * Indicates that player's current track have changed.
     */
    void trackChanged(MediaControlTrack track);

    /**
     * Indicates that player's playback position have changed.
     */
    void positionChanged(quint32 position);
#endif

private:
    explicit MediaControl(const QString &path, const QVariantMap &properties);

    class MediaControlPrivate *const d;

    friend class MediaControlPrivate;
    friend class DevicePrivate;
};

} // namespace BluezQt

#endif // BLUEZQT_MEDIACONTROL_H
