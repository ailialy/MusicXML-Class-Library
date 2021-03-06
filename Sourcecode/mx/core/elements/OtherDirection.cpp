// MusicXML Class Library v0.2
// Copyright (c) 2015 - 2016 by Matthew James Briggs

#include "mx/core/elements/OtherDirection.h"
#include "mx/core/FromXElement.h"
#include <iostream>

namespace mx
{
    namespace core
    {
        OtherDirection::OtherDirection()
        :myValue()
        ,myAttributes( std::make_shared<OtherDirectionAttributes>() )
        {}


        OtherDirection::OtherDirection( const XsString& value )
        :myValue( value )
        ,myAttributes( std::make_shared<OtherDirectionAttributes>() )
        {}


        bool OtherDirection::hasAttributes() const
        {
            return myAttributes->hasValues();
        }


        bool OtherDirection::hasContents() const
        {
            return true;
        }


        std::ostream& OtherDirection::streamAttributes( std::ostream& os ) const
        {
            if ( myAttributes )
            {
                myAttributes->toStream( os );
            }
            return os;
        }


        std::ostream& OtherDirection::streamName( std::ostream& os ) const
        {
            os << "other-direction";
            return os;
        }


        std::ostream& OtherDirection::streamContents( std::ostream& os, const int indentLevel, bool& isOneLineOnly  ) const
        {
            MX_UNUSED( indentLevel );
            isOneLineOnly = true;
            os << myValue;
            return os;
        }


        OtherDirectionAttributesPtr OtherDirection::getAttributes() const
        {
            return myAttributes;
        }


        void OtherDirection::setAttributes( const OtherDirectionAttributesPtr& value )
        {
            if ( value )
            {
                myAttributes = value;
            }
        }


        XsString OtherDirection::getValue() const
        {
            return myValue;
        }


        void OtherDirection::setValue( const XsString& value )
        {
            myValue = value;
        }


        bool OtherDirection::fromXElement( std::ostream& message, xml::XElement& xelement )
        {
            bool isSuccess = true;
            isSuccess &= myAttributes->fromXElement( message, xelement );
            myValue.setValue( xelement.getValue() );
            MX_RETURN_IS_SUCCESS;
        }

    }
}
