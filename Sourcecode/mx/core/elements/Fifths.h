// MusicXML Class Library v0.2
// Copyright (c) 2015 - 2016 by Matthew James Briggs

#pragma once

#include "mx/core/ForwardDeclare.h"
#include "mx/core/ElementInterface.h"
#include "mx/core/Integers.h"

#include <iosfwd>
#include <memory>
#include <vector>

namespace mx
{
    namespace core
    {

        MX_FORWARD_DECLARE_ELEMENT( Fifths )

        inline FifthsPtr makeFifths() { return std::make_shared<Fifths>(); }
		inline FifthsPtr makeFifths( const FifthsValue& value ) { return std::make_shared<Fifths>( value ); }
		inline FifthsPtr makeFifths( FifthsValue&& value ) { return std::make_shared<Fifths>( std::move( value ) ); }

        class Fifths : public ElementInterface
        {
        public:
            Fifths();
            Fifths( const FifthsValue& value );

            virtual bool hasAttributes() const;
            virtual bool hasContents() const;
            virtual std::ostream& streamAttributes( std::ostream& os ) const;
            virtual std::ostream& streamName( std::ostream& os ) const;
            virtual std::ostream& streamContents( std::ostream& os, const int indentLevel, bool& isOneLineOnly ) const;
            FifthsValue getValue() const;
            void setValue( const FifthsValue& value );

            bool fromXElement( std::ostream& message, xml::XElement& xelement );

        private:
            FifthsValue myValue;
        };
    }
}
