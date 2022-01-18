#pragma once

#include <QObject>

//Qt::AlignLeft 0x0001 Aligns with the left edge.
//Qt::AlignRight 0x0002 Aligns with the right edge.
//Qt::AlignHCenter 0x0004 Centers horizontally in the available space.
//Qt::AlignJustify 0x0008 Justifies the text in the available space.

//!
//! \brief The MUFormAlign enum
//!
enum MUFormAlign{
      faStart = Qt::AlignLeft
    , faCenter = Qt::AlignHCenter
    , faEnd = Qt::AlignRight
    , faJustify = Qt::AlignJustify
};


enum MUFormCompatibleValues{
      cvNone=1
    , cvQS  =2/*QML Style Sheets*/
    , cvQSS =4/*Qt Style Sheets*/
    , cvCSS =8/*Cascading Style Sheets*/
};

//!
//! \brief The MUFormOutPutStyle enum
//!
enum MUFormOutPutStyle{
    opsRowObject=1, opsRowArray=2, opsSimpleVariant=4
};

//!
//! \brief The MUFormFilterStyle enum
//!
enum MUFormFilterStyle{
    fsAutoDectect=1
};

enum MUFormWindowType{
    dftNormalForm=0,
    dftAddressForm=1,
    dftReportForm=1
};

enum DTOFormLayout{
    dflVerticalControls=0,
    dflHorizontalControls=0
};
