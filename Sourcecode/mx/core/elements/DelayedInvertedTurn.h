// MusicXML Class Library v0.3.0
// Copyright (c) 2015 - 2016 by Matthew James Briggs

#pragma once

#include "mx/core/ForwardDeclare.h"
#include "mx/core/ElementInterface.h"
#include "mx/core/elements/DelayedInvertedTurnAttributes.h"

#include <iosfwd>
#include <memory>
#include <vector>

namespace mx
{
    namespace core
    {

        MX_FORWARD_DECLARE_ATTRIBUTES( DelayedInvertedTurnAttributes )
        MX_FORWARD_DECLARE_ELEMENT( DelayedInvertedTurn )

        inline DelayedInvertedTurnPtr makeDelayedInvertedTurn() { return std::make_shared<DelayedInvertedTurn>(); }

        class DelayedInvertedTurn : public ElementInterface
        {
        public:
            DelayedInvertedTurn();

            virtual bool hasAttributes() const;
            virtual bool hasContents() const;
            virtual std::ostream& streamAttributes( std::ostream& os ) const;
            virtual std::ostream& streamName( std::ostream& os ) const;
            virtual std::ostream& streamContents( std::ostream& os, const int indentLevel, bool& isOneLineOnly ) const;
            DelayedInvertedTurnAttributesPtr getAttributes() const;
            void setAttributes( const DelayedInvertedTurnAttributesPtr& attributes );

            bool fromXElement( std::ostream& message, xml::XElement& xelement );

        private:
            DelayedInvertedTurnAttributesPtr myAttributes;
        };
    }
}