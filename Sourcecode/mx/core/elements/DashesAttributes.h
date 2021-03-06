// MusicXML Class Library v0.2
// Copyright (c) 2015 - 2016 by Matthew James Briggs

#pragma once

#include "mx/core/ForwardDeclare.h"
#include "mx/core/AttributesInterface.h"
#include "mx/core/Decimals.h"
#include "mx/core/Enums.h"
#include "mx/core/Integers.h"

#include <iosfwd>
#include <memory>
#include <vector>

namespace mx
{
    namespace core
    {

        MX_FORWARD_DECLARE_ATTRIBUTES( DashesAttributes )

        struct DashesAttributes : public AttributesInterface
        {
        public:
            DashesAttributes();
            virtual bool hasValues() const;
            virtual std::ostream& toStream( std::ostream& os ) const;
            StartStopContinue type;
            NumberLevel number;
            TenthsValue dashLength;
            TenthsValue spaceLength;
            TenthsValue defaultX;
            TenthsValue defaultY;
            TenthsValue relativeX;
            TenthsValue relativeY;
            const   bool hasType;
            bool hasNumber;
            bool hasDashLength;
            bool hasSpaceLength;
            bool hasDefaultX;
            bool hasDefaultY;
            bool hasRelativeX;
            bool hasRelativeY;

            bool fromXElement( std::ostream& message, xml::XElement& xelement );
        };
    }
}
