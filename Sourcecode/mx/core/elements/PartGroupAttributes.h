// MusicXML Class Library v0.2
// Copyright (c) 2015 - 2016 by Matthew James Briggs

#pragma once

#include "mx/core/ForwardDeclare.h"
#include "mx/core/AttributesInterface.h"
#include "mx/core/Enums.h"
#include "mx/core/Strings.h"

#include <iosfwd>
#include <memory>
#include <vector>

namespace mx
{
    namespace core
    {

        MX_FORWARD_DECLARE_ATTRIBUTES( PartGroupAttributes )

        struct PartGroupAttributes : public AttributesInterface
        {
        public:
            PartGroupAttributes();
            virtual bool hasValues() const;
            virtual std::ostream& toStream( std::ostream& os ) const;
            StartStop type;
            XsToken number;
            const 	bool hasType;
            bool hasNumber;

            bool fromXElement( std::ostream& message, xml::XElement& xelement );
        };
    }
}
