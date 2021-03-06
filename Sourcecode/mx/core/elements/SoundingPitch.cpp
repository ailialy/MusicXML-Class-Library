// MusicXML Class Library v0.2
// Copyright (c) 2015 - 2016 by Matthew James Briggs

#include "mx/core/elements/SoundingPitch.h"
#include "mx/core/FromXElement.h"
#include <iostream>

namespace mx
{
    namespace core
    {
        SoundingPitch::SoundingPitch() : ElementInterface() {}


        bool SoundingPitch::hasAttributes() const { return false; }


        bool SoundingPitch::hasContents() const  { return false; }
        std::ostream& SoundingPitch::streamAttributes( std::ostream& os ) const { return os; }
        std::ostream& SoundingPitch::streamName( std::ostream& os ) const  { os << "sounding-pitch"; return os; }
        std::ostream& SoundingPitch::streamContents( std::ostream& os, const int indentLevel, bool& isOneLineOnly ) const
        {
            MX_UNUSED( indentLevel );
            isOneLineOnly = true;
            return os;
        }


        bool SoundingPitch::fromXElement( std::ostream& message, xml::XElement& xelement )
        {
            MX_UNUSED( message );
            MX_UNUSED( xelement );
            return true;
        }

    }
}
