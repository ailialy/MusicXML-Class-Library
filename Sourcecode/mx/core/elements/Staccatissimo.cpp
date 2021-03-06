// MusicXML Class Library v0.2
// Copyright (c) 2015 - 2016 by Matthew James Briggs

#include "mx/core/elements/Staccatissimo.h"
#include "mx/core/FromXElement.h"
#include <iostream>

namespace mx
{
    namespace core
    {
        Staccatissimo::Staccatissimo()
        :ElementInterface()
        ,myAttributes( std::make_shared<EmptyPlacementAttributes>() )
        {}


        bool Staccatissimo::hasAttributes() const
        {
            return myAttributes->hasValues();
        }


        bool Staccatissimo::hasContents() const  { return false; }
        std::ostream& Staccatissimo::streamAttributes( std::ostream& os ) const
        {
            if ( myAttributes )
            {
                myAttributes->toStream( os );
            }
            return os;
        }


        std::ostream& Staccatissimo::streamName( std::ostream& os ) const  { os << "staccatissimo"; return os; }
        std::ostream& Staccatissimo::streamContents( std::ostream& os, const int indentLevel, bool& isOneLineOnly ) const
        {
            MX_UNUSED( indentLevel );
            isOneLineOnly = true;
            return os;
        }


        EmptyPlacementAttributesPtr Staccatissimo::getAttributes() const
        {
            return myAttributes;
        }


        void Staccatissimo::setAttributes( const EmptyPlacementAttributesPtr& value )
        {
            if ( value )
            {
                myAttributes = value;
            }
        }


        bool Staccatissimo::fromXElement( std::ostream& message, xml::XElement& xelement )
        {
            return myAttributes->fromXElement( message, xelement );
        }

    }
}
