// MusicXML Class Library v0.2
// Copyright (c) 2015 - 2016 by Matthew James Briggs

#pragma once

#include "mx/core/ForwardDeclare.h"
#include "mx/core/AttributesInterface.h"
#include "mx/core/Enums.h"

#include <iosfwd>
#include <memory>
#include <vector>

namespace mx
{
    namespace core
    {

        MX_FORWARD_DECLARE_ATTRIBUTES( SlashAttributes )

        struct SlashAttributes : public AttributesInterface
        {
        public:
            SlashAttributes();
            virtual bool hasValues() const;
            virtual std::ostream& toStream( std::ostream& os ) const;
            StartStop type;
            YesNo useDots;
            YesNo useStems;
            const 	bool hasType;
            bool hasUseDots;
            bool hasUseStems;

            bool fromXElement( std::ostream& message, xml::XElement& xelement );
        };
    }
}
