// MusicXML Class Library v0.2
// Copyright (c) 2015 - 2016 by Matthew James Briggs

#pragma once
#include "mx/utility/Throw.h"

#define MX_THROW_XNULL MX_THROW( "The internal object is null. This probably means that XDoc has gone out of scope causing all of its children to be destroyed." );
