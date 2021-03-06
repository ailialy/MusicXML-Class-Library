// MusicXML Class Library v0.2
// Copyright (c) 2015 - 2016 by Matthew James Briggs

#include "mx/core/elements/Arpeggiate.h"
#include "mx/core/FromXElement.h"
#include <iostream>

namespace mx
{
    namespace core
    {
        Arpeggiate::Arpeggiate()
        :ElementInterface()
        ,myAttributes( std::make_shared<ArpeggiateAttributes>() )
        {}


        bool Arpeggiate::hasAttributes() const
        {
            return myAttributes->hasValues();
        }


        bool Arpeggiate::hasContents() const  { return false; }
        std::ostream& Arpeggiate::streamAttributes( std::ostream& os ) const
        {
            if ( myAttributes )
            {
                myAttributes->toStream( os );
            }
            return os;
        }


        std::ostream& Arpeggiate::streamName( std::ostream& os ) const  { os << "arpeggiate"; return os; }
        std::ostream& Arpeggiate::streamContents( std::ostream& os, const int indentLevel, bool& isOneLineOnly ) const
        {
            MX_UNUSED( indentLevel );
            isOneLineOnly = true;
            return os;
        }


        ArpeggiateAttributesPtr Arpeggiate::getAttributes() const
        {
            return myAttributes;
        }


        void Arpeggiate::setAttributes( const ArpeggiateAttributesPtr& value )
        {
            if ( value )
            {
                myAttributes = value;
            }
        }


        bool Arpeggiate::fromXElement( std::ostream& message, xml::XElement& xelement )
        {
            return myAttributes->fromXElement( message, xelement );
        }

    }
}
