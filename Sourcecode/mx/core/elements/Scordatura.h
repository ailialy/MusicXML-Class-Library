// MusicXML Class Library v0.2
// Copyright (c) 2015 - 2016 by Matthew James Briggs

#pragma once

#include "mx/core/ForwardDeclare.h"
#include "mx/core/ElementInterface.h"

#include <iosfwd>
#include <memory>
#include <vector>

namespace mx
{
    namespace core
    {

        MX_FORWARD_DECLARE_ELEMENT( Accord )
        MX_FORWARD_DECLARE_ELEMENT( Scordatura )

        inline ScordaturaPtr makeScordatura() { return std::make_shared<Scordatura>(); }

        class Scordatura : public ElementInterface
        {
        public:
            Scordatura();

            virtual bool hasAttributes() const;
            virtual std::ostream& streamAttributes( std::ostream& os ) const;
            virtual std::ostream& streamName( std::ostream& os ) const;
            virtual bool hasContents() const;
            virtual std::ostream& streamContents( std::ostream& os, const int indentLevel, bool& isOneLineOnly ) const;

            /* _________ Accord minOccurs = 1, maxOccurs = unbounded _________ */
            const AccordSet& getAccordSet() const;
            void addAccord( const AccordPtr& value );
            void removeAccord( const AccordSetIterConst& value );
            void clearAccordSet();
            AccordPtr getAccord( const AccordSetIterConst& setIterator ) const;

            bool fromXElement( std::ostream& message, xml::XElement& xelement );

        private:
            AccordSet myAccordSet;
        };
    }
}
