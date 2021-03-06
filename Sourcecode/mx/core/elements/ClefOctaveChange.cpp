// MusicXML Class Library v0.2
// Copyright (c) 2015 - 2016 by Matthew James Briggs

#include "mx/core/elements/ClefOctaveChange.h"
#include "mx/core/FromXElement.h"
#include <iostream>

namespace mx
{
    namespace core
    {
        ClefOctaveChange::ClefOctaveChange()
        :myValue()
        {}


        ClefOctaveChange::ClefOctaveChange( const Integer& value )
        :myValue( value )
        {}


        bool ClefOctaveChange::hasAttributes() const
        {
            return false;
        }


        bool ClefOctaveChange::hasContents() const
        {
            return true;
        }


        std::ostream& ClefOctaveChange::streamAttributes( std::ostream& os ) const
        {
            return os;
        }


        std::ostream& ClefOctaveChange::streamName( std::ostream& os ) const
        {
            os << "clef-octave-change";
            return os;
        }


        std::ostream& ClefOctaveChange::streamContents( std::ostream& os, const int indentLevel, bool& isOneLineOnly  ) const
        {
            MX_UNUSED( indentLevel );
            isOneLineOnly = true;
            os << myValue;
            return os;
        }


        Integer ClefOctaveChange::getValue() const
        {
            return myValue;
        }


        void ClefOctaveChange::setValue( const Integer& value )
        {
            myValue = value;
        }


        bool ClefOctaveChange::fromXElement( std::ostream& message, xml::XElement& xelement )
        {
            MX_UNUSED( message );
            MX_UNUSED( xelement );
            myValue.parse( xelement.getValue() );
            return true;
        }

    }
}
