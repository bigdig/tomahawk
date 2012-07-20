#include "DeclarativeCoverArtProvider.h"
#include "PlayableItem.h"
#include "playlist/PlayableProxyModel.h"
#include "Query.h"
#include "Album.h"
#include "Artist.h"

#include <QDeclarativeImageProvider>
#include <QModelIndex>
#include <QDebug>

namespace Tomahawk
{

DeclarativeCoverArtProvider::DeclarativeCoverArtProvider( PlayableProxyModel *model )
    : QDeclarativeImageProvider( QDeclarativeImageProvider::Pixmap )
    , m_model( model )
{

}

DeclarativeCoverArtProvider::~DeclarativeCoverArtProvider()
{
}

QPixmap DeclarativeCoverArtProvider::requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
{
    // We always can generate it in the requested size
    int width = requestedSize.width() > 0 ? requestedSize.width() : 230;
    int height = requestedSize.height() > 0 ? requestedSize.height() : 230;

    if( size )
        *size = QSize( width, height );

//    PlayableItem *item = m_model->itemFromIndex( id.toInt() );
//    if( item ) {
//        qDebug() << "item:" << item;
//        qDebug() << "item2:" << item->artistName() << item->name();
//        if ( !item->query().isNull() ) {
//            return item->query()->displayQuery()->cover( *size );
//        }
//    }

    tDebug() << "Getting by id:" << id;
    album_ptr album = Album::getByCoverId( id );
    if ( !album.isNull() )
    {
        tDebug() << "Returning album cover:" << album->cover( requestedSize ).isNull();
        return album->cover( requestedSize );
    }
    artist_ptr artist = Artist::getByUniqueId( id );
    if ( !artist.isNull() )
    {
        tDebug() << "Returning artist cover:" << artist->cover( requestedSize ).isNull();
        return artist->cover( requestedSize );
    }
/*    query_ptr query = Query::getByCoverId( id );
    if ( !query.isNull() ) {
        return query->cover( requestedSize );
    }*/

    // TODO: create default cover art image
    QPixmap pixmap( *size );
    pixmap.fill();

    return pixmap;
}

}