// MusicXML Class Library v0.2
// Copyright (c) 2015 - 2016 by Matthew James Briggs

#include "mx/core/elements/Humming.h"
#include "mx/core/FromXElement.h"
#include <iostream>

namespace mx
{
    namespace core
    {
        Humming::Humming() : ElementInterface() {}


        bool Humming::hasAttributes() const { return false; }


        bool Humming::hasContents() const  { return false; }
        std::ostream& Humming::streamAttributes( std::ostream& os ) const { return os; }
        std::ostream& Humming::streamName( std::ostream& os ) const  { os << "humming"; return os; }
        std::ostream& Humming::streamContents( std::ostream& os, const int indentLevel, bool& isOneLineOnly ) const
        {
            MX_UNUSED( indentLevel );
            isOneLineOnly = true;
            return os;
        }


        bool Humming::fromXElement( std::ostream& message, xml::XElement& xelement )
        {
            MX_UNUSED( message );
            MX_UNUSED( xelement );
            return true;
        }

    }
}
