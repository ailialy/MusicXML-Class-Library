// MusicXML Class Library v0.2
// Copyright (c) 2015 - 2016 by Matthew James Briggs

#pragma once

#include "mx/core/ForwardDeclare.h"
#include "mx/core/ElementInterface.h"
#include "mx/core/Decimals.h"

#include <iosfwd>
#include <memory>
#include <vector>

namespace mx
{
    namespace core
    {

        MX_FORWARD_DECLARE_ELEMENT( StaffSize )

        inline StaffSizePtr makeStaffSize() { return std::make_shared<StaffSize>(); }
		inline StaffSizePtr makeStaffSize( const NonNegativeDecimal& value ) { return std::make_shared<StaffSize>( value ); }
		inline StaffSizePtr makeStaffSize( NonNegativeDecimal&& value ) { return std::make_shared<StaffSize>( std::move( value ) ); }

        class StaffSize : public ElementInterface
        {
        public:
            StaffSize();
            StaffSize( const NonNegativeDecimal& value );

            virtual bool hasAttributes() const;
            virtual bool hasContents() const;
            virtual std::ostream& streamAttributes( std::ostream& os ) const;
            virtual std::ostream& streamName( std::ostream& os ) const;
            virtual std::ostream& streamContents( std::ostream& os, const int indentLevel, bool& isOneLineOnly ) const;
            NonNegativeDecimal getValue() const;
            void setValue( const NonNegativeDecimal& value );

            bool fromXElement( std::ostream& message, xml::XElement& xelement );

        private:
            NonNegativeDecimal myValue;
        };
    }
}
