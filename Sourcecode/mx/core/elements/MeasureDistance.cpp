// MusicXML Class Library v0.2
// Copyright (c) 2015 - 2016 by Matthew James Briggs

#include "mx/core/elements/MeasureDistance.h"
#include "mx/core/FromXElement.h"
#include <iostream>

namespace mx
{
    namespace core
    {
        MeasureDistance::MeasureDistance()
        :myValue()
        {}


        MeasureDistance::MeasureDistance( const TenthsValue& value )
        :myValue( value )
        {}


        bool MeasureDistance::hasAttributes() const
        {
            return false;
        }


        bool MeasureDistance::hasContents() const
        {
            return true;
        }


        std::ostream& MeasureDistance::streamAttributes( std::ostream& os ) const
        {
            return os;
        }


        std::ostream& MeasureDistance::streamName( std::ostream& os ) const
        {
            os << "measure-distance";
            return os;
        }


        std::ostream& MeasureDistance::streamContents( std::ostream& os, const int indentLevel, bool& isOneLineOnly  ) const
        {
            MX_UNUSED( indentLevel );
            isOneLineOnly = true;
            os << myValue;
            return os;
        }


        TenthsValue MeasureDistance::getValue() const
        {
            return myValue;
        }


        void MeasureDistance::setValue( const TenthsValue& value )
        {
            myValue = value;
        }


        bool MeasureDistance::fromXElement( std::ostream& message, xml::XElement& xelement )
        {
            MX_UNUSED( message );
            MX_UNUSED( xelement );
            myValue.parse( xelement.getValue() );
            return true;
        }

    }
}
