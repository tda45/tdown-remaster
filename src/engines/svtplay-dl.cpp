/*
 *
 *  Copyright (c) 2022
 *  name : Francis Banyikwa
 *  email: mhogomchungu@gmail.com
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "svtplay-dl.h"

#ifdef _MSC_VER
#pragma warning(disable : 4309) // Disable truncation of constant value warning
#endif
#include "../settings.h"
#include "../util.hpp"
#include "../utils/miscellaneous.hpp"
#include "../utility.h"

const char * svtplay_dl::testData()
{
	return R"R(DEBUG [1689598027.9425933] svtplay-dl/svtplay_dl/utils/getmedia.py/get_media: version: 4.24
DEBUG [1689598027.9450247] svtplay-dl/svtplay_dl/service/__init__.py/__init__: service: svtplay
DEBUG [1689598027.9451392] svtplay-dl/svtplay_dl/utils/http.py/request: HTTP getting 'https://www.svtplay.se/klipp/KZxpGB6/kriget-i-ukraina-har-besoker-svt-en-skyttegrav-i-zaporizjzja-regionen?id=KZxpGB6'
DEBUG [1689598027.9475543] $urllib3/connectionpool.py/_new_conn: Starting new HTTPS connection (1): www.svtplay.se:443
DEBUG [1689598031.6283054] $urllib3/connectionpool.py/_make_request: https://www.svtplay.se:443 "GET /klipp/KZxpGB6/kriget-i-ukraina-har-besoker-svt-en-skyttegrav-i-zaporizjzja-regionen?id=KZxpGB6 HTTP/1.1" 200 None
DEBUG [1689598034.2711911] svtplay-dl/svtplay_dl/utils/http.py/request: HTTP getting 'https://api.svt.se/video/KZxpGB6'
DEBUG [1689598034.2727182] $urllib3/connectionpool.py/_new_conn: Starting new HTTPS connection (1): api.svt.se:443
\ Log truncated for MSVC compatibility\
DEBUG [1689598043.7114809] svtplay-dl/svtplay_dl/utils/http.py/request: HTTP getting 'https://svt-vod-7c.akamaized.net/d0/world/20230710/4a34cbb5-b1e8-44e6-8cfc-132c25571ca8/hls-ts-lb-full.m3u8'
DEBUG [1689598043.713569] $urllib3/connectionpool.py/_new_conn: Starting new HTTPS connection (1): svt-vod-7c.akamaized.net:443
\ Log truncated for MSVC compatibility\
DEBUG [1689598049.9126453] svtplay-dl/svtplay_dl/utils/http.py/request: HTTP getting 'https://svt-vod-7c.akamaized.net/d0/world/20230710/4a34cbb5-b1e8-44e6-8cfc-132c25571ca8/hls-ts-full.m3u8'
\ Log truncated for MSVC compatibility\
DEBUG [1689598050.0271435] svtplay-dl/svtplay_dl/utils/http.py/request: HTTP getting 'https://svt-vod-7c.akamaized.net/d0/world/20230710/4a34cbb5-b1e8-44e6-8cfc-132c25571ca8/hls-ts-avc.m3u8'
\ Log truncated for MSVC compatibility\
DEBUG [1689598050.1256115] svtplay-dl/svtplay_dl/utils/http.py/request: HTTP getting 'https://svt-vod-7c.akamaized.net/d0/world/20230710/4a34cbb5-b1e8-44e6-8cfc-132c25571ca8/dash-full.mpd'
\ Log truncated for MSVC compatibility\
DEBUG [1689598050.234446] svtplay-dl/svtplay_dl/utils/http.py/request: HTTP getting 'https://svt-vod-7c.akamaized.net/d0/world/20230710/4a34cbb5-b1e8-44e6-8cfc-132c25571ca8/hls-cmaf-lb-full.m3u8'
\ Log truncated for MSVC compatibility\
DEBUG [1689598050.3272824] svtplay-dl/svtplay_dl/utils/http.py/request: HTTP getting 'https://svt-vod-7c.akamaized.net/d0/world/20230710/4a34cbb5-b1e8-44e6-8cfc-132c25571ca8/dash-lb-full.mpd'
\ Log truncated for MSVC compatibility\
DEBUG [1689598050.428062] svtplay-dl/svtplay_dl/utils/http.py/request: HTTP getting 'https://svt-vod-7c.akamaized.net/d0/world/20230710/4a34cbb5-b1e8-44e6-8cfc-132c25571ca8/dash-hbbtv-avc.mpd'
\ Log truncated for MSVC compatibility\
DEBUG [1689598050.5321388] svtplay-dl/svtplay_dl/utils/http.py/request: HTTP getting 'https://svt-vod-7c.akamaized.net/d0/world/20230710/4a34cbb5-b1e8-44e6-8cfc-132c25571ca8/dash-avc.mpd'
\ Log truncated for MSVC compatibility\
DEBUG [1689598050.642335] svtplay-dl/svtplay_dl/utils/http.py/request: HTTP getting 'https://svt-vod-7c.akamaized.net/d0/world/20230710/4a34cbb5-b1e8-44e6-8cfc-132c25571ca8/hls-ts-avc.m3u8'
\ Log truncated for MSVC compatibility\
DEBUG [1689598052.6228123] svtplay-dl/svtplay_dl/utils/http.py/request: HTTP getting 'https://svt-vod-7c.akamaized.net/d0/world/20230710/4a34cbb5-b1e8-44e6-8cfc-132c25571ca8/dash-avc.mpd'
\ Log truncated for MSVC compatibility\
DEBUG [1689598052.738594] svtplay-dl/svtplay_dl/utils/stream.py/format_prio: Format priority: ['h264', 'h264-51']
DEBUG [1689598052.73879] svtplay-dl/svtplay_dl/utils/stream.py/protocol_prio: Protocol priority scores (higher is better): {'dash': 3, 'hls': 2, 'http': 1}
DEBUG [1689598052.7391403] svtplay-dl/svtplay_dl/utils/http.py/request: HTTP getting 'https://svt-vod-7c.akamaized.net/d0/world/20230710/4a34cbb5-b1e8-44e6-8cfc-132c25571ca8/dash-full.mpd'
DEBUG [1689598052.7407427] $urllib3/connectionpool.py/_new_conn: Starting new HTTPS connection (1): svt-vod-7c.akamaized.net:443
\ Log truncated for MSVC compatibility\
INFO [1689598058.1682267] svtplay-dl/svtplay_dl/utils/output.py/find_dupes: Outfile: svt.nyheter.kriget.i.ukraina.har.besoker.svt.en.skyttegrav.i.zaporizjzja-regionen-77e0cd8-svtplay.mp4
INFO [1689598058.1692932] svtplay-dl/svtplay_dl/utils/getmedia.py/get_one_media: Selected to download dash, bitrate: 3884 format: h264

\ Log truncated for MSVC compatibility\
DEBUG [1689598058.175341] $urllib3/connectionpool.py/_new_conn: Starting new HTTPS connection (1): svt-vod-7c.akamaized.net:443
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

		"Log truncated for MSVC compatibility"
\ Log truncated for MSVC compatibility\

		"Log truncated for MSVC compatibility"
		"Log truncated for MSVC compatibility"

		"Log truncated for MSVC compatibility"
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

		"Log truncated for MSVC compatibility"
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\


\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

		"Log truncated for MSVC compatibility"
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

\ Log truncated for MSVC compatibility\
\ Log truncated for MSVC compatibility\

INFO [1689598170.796944] svtplay-dl/svtplay_dl/postprocess/__init__.py/merge: Merge audio and video into svt.nyheter.kriget.i.ukraina.har.besoker.svt.en.skyttegrav.i.zaporizjzja-regionen-77e0cd8-svtplay.mp4
INFO [1689598171.062669] svtplay-dl/svtplay_dl/postprocess/__init__.py/merge: Merging done, removing old files.
)R" ;
}

void svtplay_dl::init( settings&,Logger& logger,const engines::enginePaths& enginePath )
{
	auto m = enginePath.enginePath( "svtplay-dl.json" ) ;

	if( !QFile::exists( m ) ){

		QJsonObject mainObj ;

		utility::addJsonCmd json( mainObj ) ;

		json.add( { { "Generic" },{ { "amd64","svtplay-dl",{ "svtplay-dl" } },
					  { "aarch64","svtplay-dl",{ "svtplay-dl" } } } } ) ;
		json.done() ;

		mainObj.insert( "Version","1" ) ;

		mainObj.insert( "DownloadUrl","" ) ;

		mainObj.insert( "AutoUpdate",false ) ;

		mainObj.insert( "Name","svtplay-dl" ) ;

		mainObj.insert( "VersionArgument","--version" ) ;

		mainObj.insert( "VersionStringLine",0 ) ;

		mainObj.insert( "VersionStringPosition",1 ) ;

		mainObj.insert( "LikeYoutubeDl",false ) ;

		engines::file( m,logger ).write( mainObj ) ;
	}
}

svtplay_dl::svtplay_dl( const engines& engs,const engines::engine& engine,QJsonObject& ) :
	engines::engine::baseEngine( engs.Settings(),engine,engs.processEnvironment() ),
	m_processEnvironment( engines::engine::baseEngine::processEnvironment() )
{
	m_processEnvironment.insert( "PYTHONUNBUFFERED","true" ) ;
}

void svtplay_dl::updateOutPutChannel( QProcess::ProcessChannel& s ) const
{
	s = QProcess::ProcessChannel::StandardError ;
}

void svtplay_dl::updateDownLoadCmdOptions( const engines::engine::baseEngine::updateOpts& e,
					   bool s,
					   const QStringList& m )
{
	e.ourOptions.append( "--verbose" ) ;

	if( utility::platformisFlatPak() ){

		e.ourOptions.append( "--output" ) ;
		e.ourOptions.append( engines::engine::baseEngine::Settings().downloadFolder() ) ;
	}

	engines::engine::baseEngine::updateDownLoadCmdOptions( e,s,m ) ;
}

QStringList svtplay_dl::horizontalHeaderLabels() const
{
	auto m = engines::engine::baseEngine::horizontalHeaderLabels() ;

	m[ 1 ] = QObject::tr( "Method" ) ;

	return m ;
}

void svtplay_dl::setProxySetting( engines::engine::baseEngine::optionsEnvironment&,QStringList& e,const QString& s )
{
	e.append( "--proxy" ) ;
	e.append( s ) ;
}

static bool _add( std::vector< engines::engine::baseEngine::mediaInfo >& s,const QString& e )
{
	for( const auto& m : s ){

		if( m.id() == e ){

			return false ;
		}
	}

	return true ;
}

std::vector<engines::engine::baseEngine::mediaInfo> svtplay_dl::mediaProperties( Logger&,const QByteArray& e )
{
	auto mm = util::split( e,'\n',true ) ;

	while( true ){

		if( mm.size() == 0 ){

			return {} ;

		}else if( mm[ 0 ].startsWith( "INFO: " ) ){

			break ;
		}else{
			mm.removeAt( 0 ) ;
		}
	}

	std::vector< engines::engine::baseEngine::mediaInfo > s ;

	for( const auto& it : mm ){

		if( it.startsWith( "INFO: Quality:" ) ){

			continue ;
		}

		auto a = util::split( it,' ',true ) ;

		auto n = a.size() ;

		if( n > 4 ){

			a.takeAt( 0 ) ;
			auto format = a.takeAt( 0 ) ;

			if( _add( s,format ) ){

				auto method     = "Method: " + a.takeAt( 0 ) ;
				auto codec      = a.takeAt( 0 ) ;
				auto resolution = a.takeAt( 0 ) ;
				auto notes      = method + "\n" + a.join( ", " ) ;

				s.emplace_back( format,codec,resolution,"NA","0",notes,"","" ) ;
			}

		}else if( n == 3 ){

			a.takeAt( 0 ) ;

			auto format = a.takeAt( 0 ) ;

			if( _add( s,format ) ){

				auto method     = "Method: " + a.takeAt( 0 ) ;
				auto codec      = a.takeAt( 0 ) ;
				auto resolution = "N/A" ;
				auto notes      = method ;

				s.emplace_back( format,codec,resolution,"NA","0",notes,"","" ) ;
			}
		}
	}

	return s ;
}

const QProcessEnvironment& svtplay_dl::processEnvironment() const
{
	return m_processEnvironment ;
}

svtplay_dl::~svtplay_dl()
{
}

engines::engine::baseEngine::DataFilter svtplay_dl::Filter( int id )
{
	auto& s = engines::engine::baseEngine::Settings() ;
	const auto& engine = engines::engine::baseEngine::engine() ;

	return { util::types::type_identity< svtplay_dl::svtplay_dlFilter >(),s,engine,id } ;
}

QString svtplay_dl::updateTextOnCompleteDownlod( const QString& uiText,
						 const QString& bkText,
						 const QString& dopts,
						 const QString& tabName,
						 const engines::engine::baseEngine::finishedState& f )
{
	if( f.success() ){

		return engines::engine::baseEngine::updateTextOnCompleteDownlod( uiText,dopts,tabName,f ) ;

	}else if( f.cancelled() ){

		return engines::engine::baseEngine::updateTextOnCompleteDownlod( bkText,dopts,tabName,f ) ;
	}else{
		using functions = engines::engine::baseEngine ;

		if( uiText.startsWith( "ERROR:" ) ){

			auto s = uiText.mid( 6 ) ;
			auto m = engines::engine::baseEngine::updateTextOnCompleteDownlod( s,dopts,tabName,f ) ;

			return m + "\n" + bkText ;

		}else if( uiText.contains( "Temporary failure in name resolution" ) ){

			return functions::errorString( f,functions::errors::noNetwork,bkText ) ;

		}else if( uiText.contains( "Name or service not known" ) ){

			return functions::errorString( f,functions::errors::unknownUrl,bkText ) ;
		}else{
			auto m = engines::engine::baseEngine::processCompleteStateText( f ) ;
			return m + "\n" + bkText ;
		}
	}
}

svtplay_dl::svtplay_dlFilter::svtplay_dlFilter( settings&,const engines::engine& engine,int id ) :
	engines::engine::baseEngine::filter( engine,id ){
}

class svtplayFilter : public engines::engine::baseEngine::filterOutPut
{
public:
	svtplayFilter( const engines::engine& engine ) :
		m_engine( engine ),
		m_callables( svtplayFilter::meetCondition,svtplayFilter::skipCondition )
	{
	}
	engines::engine::baseEngine::filterOutPut::result
	formatOutput( const engines::engine::baseEngine::filterOutPut::args& args ) const override
	{
		const auto& l = args.locale ;
		auto& d = args.data ;
		const auto& m = args.outPut ;

		auto notMainLogger = !d.mainLogger() ;

		if( notMainLogger && d.svtData().fileName().isEmpty() ){

			d.toStringList().forEach( [ & ]( const QByteArray& s ){

				if( s.startsWith( "Outfile: " ) ){

					auto m = s.mid( 9 ) ;
					d.svtData().setFileName( m ) ;

					args.data.addFileName( m ) ;
				}
			} ) ;
		}

		if( m.startsWith( "DEBUG " ) ){

			if( notMainLogger && m.contains( " 200 " ) ){

				auto q = m.lastIndexOf( ' ' ) ;

				if( q != -1 ){

					auto mm = m.mid( q + 1 ) ;

					d.svtData().addToSize( mm.toLongLong() ) ;
				}
			}

			if( d.lastText().contains( "ETA" ) ){

				return { d.lastText(),m_engine,m_callables } ;
			}else{
				auto s = m.indexOf( "HTTP getting" ) ;

				if( s != -1 ){

					m_tmp = "Getting: " + m.mid( s + 12 ) ;
				}else{
					m_tmp.clear() ;
				}

				return { m_tmp,m_engine,m_callables } ;
			}

		}else if( m.startsWith( "INFO" ) ){

			auto s = m.indexOf( "Outfile:" ) ;

			if( s != -1 ){

				m_tmp = m.mid( s ) ;
			}else{
				s = m.indexOf( "Selected to download" ) ;

				if( s != -1 ){

					m_tmp = m.mid( s ) ;
				}else{
					m_tmp.clear() ;
				}
			}

			return { m_tmp,m_engine,m_callables } ;
		}

		auto e = m.indexOf( "ETA" ) ;

		auto a = m.mid( e ) ;

		auto aa = a.indexOf( "DEBUG" ) ;

		if( aa != -1 ){

			a = a.mid( 0,aa ) ;
		}

		auto b = m.indexOf( ']' ) ;

		auto c = m.mid( 0,b ) ;

		auto cc = c.indexOf( '[' ) ;

		auto dd = util::split( c.mid( cc + 1 ),'/' ) ;

		if( dd.size() == 2 ){

			auto x = dd[ 0 ].toDouble() ;
			auto y = dd[ 1 ].toDouble() ;

			auto z = x / y ;

			auto zz = QString::number( z * 100,'f',2 ) ;

			auto ss = "[" + dd[ 0 ] + "/" + dd[ 1 ] + "] (" + zz + "%), " + a ;

			m_tmp = ss.toUtf8() ;

			if( !d.mainLogger() ){

				auto ss = d.svtData().size() ;

				auto ll = l.formattedDataSize( ss ).toUtf8() ;

				auto mm = static_cast< qint64 >( ss / z ) ;

				auto lll = l.formattedDataSize( mm ).toUtf8() ;

				m_tmp = ll + "/~" + lll + ", " + m_tmp ;
			}

			if( x == y ){

				d.svtData().reset() ;
			}
		}else{
			m_tmp = "[00/00] (NA), " + a ;
		}

		return { m_tmp,m_engine,m_callables } ;
	}
	bool meetCondition( const engines::engine::baseEngine::filterOutPut::args& args ) const override
	{
		const auto& e = args.outPut ;

		if( svtplayFilter::meetCondition( e ) ){

			return true ;
		}else{
			return utils::misc::startsWithAny( e,"DEBUG","Getting:","INFO" ) ;
		}
	}
	const engines::engine& engine() const override
	{
		return m_engine ;
	}
private:
	static bool startsWithCondition( const QByteArray& e )
	{
		if( e.startsWith( '[' ) && e.size() > 1 ){

			auto m = e[ 1 ] ;

			return m >= '0' && m <= '9' ;

		}else if( e.startsWith( "\r[" ) && e.size() > 2 ){

			auto m = e[ 2 ] ;

			return m >= '0' && m <= '9' ;
		}else{
			return false ;
		}
	}
	static bool meetCondition( const QByteArray& e )
	{
		return svtplayFilter::startsWithCondition( e ) && e.contains( " ETA:" ) ;
	}
	static bool meetCondition( const engines::engine&,const QByteArray& e )
	{
		return e.contains( "] (" ) && e.contains( " ETA:" ) ;
	}
	static bool skipCondition( const engines::engine&,const QByteArray& )
	{
		return false ;
	}

	const engines::engine& m_engine ;
	mutable QByteArray m_tmp ;
	engines::engine::baseEngine::filterOutPut::result::callables m_callables ;
} ;

engines::engine::baseEngine::FilterOutPut svtplay_dl::filterOutput( int )
{
	const engines::engine& engine = engines::engine::baseEngine::engine() ;

	return { util::types::type_identity< svtplayFilter >(),engine } ;
}

QString svtplay_dl::updateCmdPath( const QString& e )
{
	const auto& name = engines::engine::baseEngine::engine().name() ;

	if( utility::platformIsWindows() ){

		return e + "/" + name + "/" + name + ".exe" ;
	}else{
		return e ;
	}
}

engines::metadata svtplay_dl::parseJsonDataFromGitHub( const QJsonDocument& doc )
{
	auto array = doc.array() ;

	if( array.size() ){

		QString fileName ;
		QString url ;

		if( utility::platformIsWindows() ){

			if( utility::CPU().x86_32() ){

				fileName = "svtplay-dl-win32.zip" ;

				url = "https://svtplay-dl.se/download/%1/svtplay-dl-win32.zip" ;
			}else{
				fileName = "svtplay-dl-amd64.zip" ;

				url = "https://svtplay-dl.se/download/%1/svtplay-dl-amd64.zip" ;
			}
		}else{
			fileName = "svtplay-dl" ;

			url = "https://svtplay-dl.se/download/%1/svtplay-dl" ;
		}

		QJsonObject obj ;

		auto name = array[ 0 ].toObject().value( "name" ).toString() ;

		obj.insert( "browser_download_url",url.arg( name ) ) ;
		obj.insert( "name",fileName ) ;
		obj.insert( "digest","" ) ;
		obj.insert( "size",0 ) ;

		return obj ;
	}else{
		return {} ;
	}
}

engines::engine::baseEngine::onlineVersion svtplay_dl::versionInfoFromGithub( const QByteArray& e )
{
	QJsonParseError err ;
	auto doc = QJsonDocument::fromJson( e,&err ) ;

	if( err.error == QJsonParseError::NoError ){

		auto s = doc.array() ;

		if( s.size() ){

			auto m = s[ 0 ].toObject().value( "name" ).toString() ;

			return { m,m } ;
		}
	}

	return { {},{} } ;
}

QString svtplay_dl::downloadUrl()
{
	return "https://api.github.com/repos/spaam/svtplay-dl/tags" ;
}

const QByteArray& svtplay_dl::svtplay_dlFilter::operator()( Logger::Data& s )
{
	if( s.doneDownloading() ){

		auto lines = s.toStringList() ;

		for( auto it = lines.rbegin() ; it != lines.rend() ; it++ ){

			const QByteArray& m = *it ;

			if( m.startsWith( "ERROR" ) ){

				auto e = m.indexOf( ':' ) ;

				if( e == -1 ){

					return m ;
				}else{
					m_tmp = "ERROR:" + m.mid( e + 1 ) ;

					return m_tmp ;
				}

			}else if( m.contains( "media already exists" ) ){

				m_tmp = "Media already exists" ;

				return m_tmp ;

			}else if( m.contains( "Temporary failure in name resolution" ) ){

				m_tmp = "Temporary failure in name resolution" ;

				return m_tmp ;

			}else if( m.contains( "Name or service not known" ) ){

				m_tmp = "Name or service not known" ;

				return m_tmp ;
			}
		}

		if( m_fileName.isEmpty() ){

			return m_tmp ;
		}else{
			s.addFileName( m_fileName ) ;

			return m_fileName ;
		}

	}else if( s.lastLineIsProgressLine() ){

		const auto& fileName = s.svtData().fileName() ;

		if( fileName.isEmpty() ){

			return s.lastText() ;
		}else{
			m_tmp = fileName + "\n" + s.lastText() ;

			return m_tmp ;
		}
	}else{
		const auto& m = s.lastText() ;

		if( m.isEmpty() ){

			s.reverseForEach( [ this ]( int,const QByteArray& e ){

				if( e.isEmpty() ){

					return false ;
				}else{
					m_tmp = this->lastText( e ) ;

					return true ;
				}
			} ) ;

			return m_tmp ;
		}else{
			return this->lastText( m ) ;
		}
	}
}

svtplay_dl::svtplay_dlFilter::~svtplay_dlFilter()
{
}

const QByteArray& svtplay_dl::svtplay_dlFilter::lastText( const QByteArray& m )
{
	if( m.startsWith( "WARNING" ) && m.contains( "already exists" ) ){

		auto a = m.indexOf( '(' ) ;
		auto b = m.lastIndexOf( ')' ) ;

		if( a != -1 && b != -1 && b > a ){

			m_tmp = "\"" + m.mid( a + 1,b - a - 1 ) + "\" already exists" ;
		}else{
			m_tmp = "media already exists" ;
		}

		return m_tmp ;

	}else if( m.contains( "Merge audio, video and subtitle into " ) ){

		auto e = m.indexOf( "Merge audio, video and subtitle into " ) ;

		if( e != -1 ){

			m_fileName = m.mid( e + 37 ) ;
		}

		return m_fileName ;

	}else if( m.contains( "Merge audio and video into " ) ){

		auto e = m.indexOf( "Merge audio and video into " ) ;

		if( e != -1 ){

			m_fileName = m.mid( e + 27 ) ;
		}

		return m_fileName ;

	}else if( m.contains( "INFO: " ) ){

		auto e = m.indexOf( "INFO: " ) ;

		if( e != -1 ){

			m_tmp = m.mid( e + 6 ) ;
		}

		return m_tmp ;

	}else if( m.startsWith( "ERROR" ) ){

		auto e = m.indexOf( ":" ) ;

		if( e != -1 ){

			m_tmp = m.mid( e + 1 ) ;
		}

		return m_tmp ;

	}else if( m.startsWith( "Getting: " ) ){

		m_tmp = QObject::tr( "Getting" ).toUtf8() + "\n" ;

		if( m.size() < 91 ){

			m_tmp += m ;

			m_tmp.replace( "Getting:  '","" ) ;
		}else{
			auto e = m ;

			e.replace( "Getting:  '","" ) ;

			m_tmp += e.mid( 0,40 ) + "..." ;

			m_tmp += e.mid( e.size() - 40 ) ;
		}

		if( m_tmp.endsWith( "'" ) ){

			m_tmp.truncate( m_tmp.size() - 1 ) ;
		}

		return m_tmp ;
	}else{
		return m_preProcessing.text() ;
	}
}
