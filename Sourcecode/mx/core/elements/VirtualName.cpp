// MusicXML Class Library v0.2
// Copyright (c) 2015 - 2016 by Matthew James Briggs

#include "mx/core/elements/VirtualName.h"
#include "mx/core/FromXElement.h"
#include <iostream>

namespace mx
{
    namespace core
    {
        VirtualName::VirtualName()
        :myValue()
        {}


        VirtualName::VirtualName( const XsString& value )
        :myValue( value )
        {}


        bool VirtualName::hasAttributes() const
        {
            return false;
        }


        bool VirtualName::hasContents() const
        {
            return true;
        }


        std::ostream& VirtualName::streamAttributes( std::ostream& os ) const
        {
            return os;
        }


        std::ostream& VirtualName::streamName( std::ostream& os ) const
        {
            os << "virtual-name";
            return os;
        }


        std::ostream& VirtualName::streamContents( std::ostream& os, const int indentLevel, bool& isOneLineOnly  ) const
        {
            MX_UNUSED( indentLevel );
            isOneLineOnly = true;
            os << myValue;
            return os;
        }


        XsString VirtualName::getValue() const
        {
            return myValue;
        }


        void VirtualName::setValue( const XsString& value )
        {
            myValue = value;
        }


        bool VirtualName::fromXElement( std::ostream& message, xml::XElement& xelement )
        {
            MX_UNUSED( message );
            MX_UNUSED( xelement );
            myValue.setValue( xelement.getValue() );
            return true;
        }

    }
}
