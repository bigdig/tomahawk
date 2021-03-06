/* === This file is part of Tomahawk Player - <http://tomahawk-player.org> ===
 *
 *   Copyright 2013, Uwe L. Korn <uwelk@xhochy.com>
 *
 *   Tomahawk is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   Tomahawk is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Tomahawk. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef NETWORKACTIVITYWIDGET_P_H
#define NETWORKACTIVITYWIDGET_P_H

#include "NetworkActivityWidget.h"
#include "ui_NetworkActivityWidget.h"

class NetworkActivityWidgetPrivate
{
public:
    NetworkActivityWidgetPrivate( Tomahawk::Widgets::NetworkActivityWidget* q )
        : q_ptr ( q )
        , ui( new Ui::NetworkActivityWidget )
        , sortedProxy( 0 )
    {
    }
    Tomahawk::Widgets::NetworkActivityWidget* q_ptr;
    Q_DECLARE_PUBLIC ( Tomahawk::Widgets::NetworkActivityWidget )

private:
    QSharedPointer<Ui::NetworkActivityWidget> ui;
    Tomahawk::playlistinterface_ptr playlistInterface;
    QStandardItemModel* crumbModelLeft;
    QSortFilterProxyModel* sortedProxy;

    QPointer<PlaylistModel> weeklyChartsModel;
    QPointer<PlaylistModel> monthlyChartsModel;
    QPointer<PlaylistModel> yearlyChartsModel;
    QPointer<PlaylistModel> overallChartsModel;

    QPointer<PlaylistModel> trendingTracksModel;

    Tomahawk::Widgets::NetworkActivityWidget::ViewType activeView;
};

#endif // NETWORKACTIVITYWIDGET_P_H
