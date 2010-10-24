/************************************************************************
*
* Copyright 2010 Jakob Leben (jakob.leben@gmail.com)
*
* This file is part of SuperCollider Qt GUI.
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
************************************************************************/

#ifndef QC_LEVEL_INDICATOR_H
#define QC_LEVEL_INDICATOR_H

#include "../QcHelper.h"

#include <QWidget>

class QcLevelIndicator : public QWidget, public QcHelper
{
  Q_OBJECT
  Q_PROPERTY( float value READ dummyFloat WRITE setValue );
  Q_PROPERTY( float warning READ dummyFloat WRITE setWarning );
  Q_PROPERTY( float critical READ dummyFloat WRITE setCritical );
  Q_PROPERTY( float peak READ dummyFloat WRITE setPeak );
  Q_PROPERTY( bool drawPeak READ dummyBool WRITE setDrawPeak );
public:
  QcLevelIndicator()
  : _value( 0.f ), _warning(0.6), _critical(0.8),
    _peak( 0.f ), _drawPeak( false )
  {}
  void setValue( float f ) { _value = f; update(); }
  void setWarning( float f ) { _warning = f; update(); }
  void setCritical( float f ) { _critical = f; update(); }
  void setPeak( float f ) { _peak = f; update(); }
  void setDrawPeak( bool b ) { _drawPeak = b; update(); }
private:
  QSize sizeHint() const { return QSize( 15, 80 ); }
  void paintEvent( QPaintEvent *e );
  float _value;
  float _warning;
  float _critical;
  float _peak;
  bool _drawPeak;
};

#endif
