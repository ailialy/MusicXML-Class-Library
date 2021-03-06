// MusicXML Class Library v0.2
// Copyright (c) 2015 - 2016 by Matthew James Briggs

#include "mxtest/control/CompileControl.h"
#ifdef MX_COMPILE_CORE_TESTS

#include "cpul/cpulTestHarness.h"
#include "mxtest/core/HelperFunctions.h"
#include "mxtest/core/DisplayStepOctaveGroupTest.h"
#include "mxtest/core/SystemMarginsTest.h"
#include "mxtest/core/SystemDividersTest.h"

using namespace mx::core;
using namespace std;
using namespace MxTestHelpers;

TEST( Test01, DisplayStepOctaveGroup )
{
    variant v = variant::one;
	DisplayStepOctaveGroupPtr object = tgenDisplayStepOctaveGroup( v );
	stringstream expected;
	tgenDisplayStepOctaveGroupExpected( expected, 1, v );
	stringstream actual;
	// object->toStream( std::cout, 1 );
    bool isOneLineOnly = false;
	object->streamContents( actual, 1, isOneLineOnly );
	CHECK_EQUAL( expected.str(), actual.str() )
	CHECK( ! object->hasAttributes() )
	CHECK( object->hasContents() )
}
TEST( Test02, DisplayStepOctaveGroup )
{
    variant v = variant::two;
	DisplayStepOctaveGroupPtr object = tgenDisplayStepOctaveGroup( v );
	stringstream expected;
	tgenDisplayStepOctaveGroupExpected( expected, 1, v );
	stringstream actual;
	// object->toStream( std::cout, 1 );
    bool isOneLineOnly = false;
	object->streamContents( actual, 1, isOneLineOnly );
	CHECK_EQUAL( expected.str(), actual.str() )
	CHECK( ! object->hasAttributes() )
	CHECK( object->hasContents() )
}
TEST( Test03, DisplayStepOctaveGroup )
{
    variant v = variant::three;
	DisplayStepOctaveGroupPtr object = tgenDisplayStepOctaveGroup( v );
	stringstream expected;
	tgenDisplayStepOctaveGroupExpected( expected, 1, v );
	stringstream actual;
	// object->toStream( std::cout, 1 );
    bool isOneLineOnly = false;
	object->streamContents( actual, 1, isOneLineOnly );
	CHECK_EQUAL( expected.str(), actual.str() )
	CHECK( ! object->hasAttributes() )
	CHECK( object->hasContents() )
}

namespace MxTestHelpers
{
    DisplayStepOctaveGroupPtr tgenDisplayStepOctaveGroup( variant v )
    {
        DisplayStepOctaveGroupPtr o = makeDisplayStepOctaveGroup();
        switch ( v )
        {
            case variant::one:
            {
                
            }
                break;
            case variant::two:
            {
                o->getDisplayOctave()->setValue( OctaveValue( 7 ) );
                o->getDisplayStep()->setValue( StepEnum::g );
            }
                break;
            case variant::three:
            {
                o->getDisplayOctave()->setValue( OctaveValue( 5 ) );
                o->getDisplayStep()->setValue( StepEnum::b );
            }
                break;
            default:
                break;
        }
        return o;
    }
    void tgenDisplayStepOctaveGroupExpected( std::ostream& os, int i, variant v )
    {
        
        switch ( v )
        {
            case variant::one:
            {
                streamLine( os, i, R"(<display-step>A</display-step>)" );
                streamLine( os, i, R"(<display-octave>0</display-octave>)", false );
            }
                break;
            case variant::two:
            {
                streamLine( os, i, R"(<display-step>G</display-step>)" );
                streamLine( os, i, R"(<display-octave>7</display-octave>)", false );
            }
                break;
            case variant::three:
            {
                streamLine( os, i, R"(<display-step>B</display-step>)" );
                streamLine( os, i, R"(<display-octave>5</display-octave>)", false );
            }
                break;
            default:
                break;
        }
    }
}

#endif
