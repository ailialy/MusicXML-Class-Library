// MusicXML Class Library v0.2
// Copyright (c) 2015 - 2016 by Matthew James Briggs

#include "mxtest/control/CompileControl.h"
#ifdef MX_COMPILE_CORE_TESTS

#include "cpul/cpulTestHarness.h"
#include "mxtest/core/HelperFunctions.h"
#include "mx/core/Elements.h"

using namespace mx::core;
using namespace std;
using namespace MxTestHelpers;

TEST( Test01, Directive )
{
	Directive object;
	stringstream expected;
	streamLine( expected, 1, R"(<directive></directive>)", false );
	stringstream actual;
	// object.toStream( std::cout, 1 );
	object.toStream( actual, 1 );
	CHECK_EQUAL( expected.str(), actual.str() )
	CHECK( ! object.hasAttributes() )
	CHECK( object.hasContents() )
}
TEST( Test02, Directive )
{
	DirectivePtr object = makeDirective( XsString{ "Mork\nde\t\t\n\nbork" } );
    object->getAttributes()->hasLang = true;
    object->getAttributes()->hasFontFamily = true;
    object->getAttributes()->fontFamily = CommaSeparatedText{ "This Font,That Font" };
	stringstream expected;
	streamLine( expected, 1, "<directive font-family=\"This Font,That Font\" xml:lang=\"it\">Mork\nde\t\t\n\nbork</directive>", false );
	stringstream actual;
	// object->toStream( std::cout, 1 );
	object->toStream( actual, 1 );
	CHECK_EQUAL( expected.str(), actual.str() )
	CHECK( object->hasAttributes() )
	CHECK( object->hasContents() )
}

#endif
