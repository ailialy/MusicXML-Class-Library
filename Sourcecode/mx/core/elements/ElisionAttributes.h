// MusicXML Class Library v0.2
// Copyright (c) 2015 - 2016 by Matthew James Briggs

#pragma once

#include "mx/core/ForwardDeclare.h"
#include "mx/core/AttributesInterface.h"
#include "mx/core/Decimals.h"
#include "mx/core/Enums.h"
#include "mx/core/Integers.h"
#include "mx/core/Strings.h"
#include "mx/core/FontSize.h"
#include "mx/core/NumberOrNormal.h"

#include <iosfwd>
#include <memory>
#include <vector>

namespace mx
{
    namespace core
    {

        MX_FORWARD_DECLARE_ATTRIBUTES( ElisionAttributes )

        struct ElisionAttributes : public AttributesInterface
        {
        public:
            ElisionAttributes();
            virtual bool hasValues() const;
            virtual std::ostream& toStream( std::ostream& os ) const;
            CommaSeparatedText fontFamily;
            FontStyle fontStyle;
            FontSize fontSize;
            FontWeight fontWeight;
            NumberOfLines underline;
            NumberOfLines overline;
            NumberOfLines lineThrough;
            RotationDegrees rotation;
            NumberOrNormal letterSpacing;
            XmlLang lang;
            bool hasFontFamily;
            bool hasFontStyle;
            bool hasFontSize;
            bool hasFontWeight;
            bool hasUnderline;
            bool hasOverline;
            bool hasLineThrough;
            bool hasRotation;
            bool hasLetterSpacing;
            bool hasLang;

            bool fromXElement( std::ostream& message, xml::XElement& xelement );
        };
    }
}
