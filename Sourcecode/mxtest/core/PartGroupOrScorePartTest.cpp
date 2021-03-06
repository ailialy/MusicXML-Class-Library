// MusicXML Class Library v0.2
// Copyright (c) 2015 - 2016 by Matthew James Briggs

#include "mxtest/control/CompileControl.h"
#ifdef MX_COMPILE_CORE_TESTS

#include "cpul/cpulTestHarness.h"
#include "mxtest/core/HelperFunctions.h"
#include "mxtest/core/PartGroupOrScorePartTest.h"
#include "mxtest/core/ScorePartTest.h"
#include "mxtest/core/PartGroupTest.h"

using namespace mx::core;
using namespace std;
using namespace MxTestHelpers;

TEST( Test01, PartGroupOrScorePart )
{
    variant v = variant::one;
	PartGroupOrScorePartPtr object = tgenPartGroupOrScorePart( v );
	stringstream expected;
	tgenPartGroupOrScorePartExpected( expected, 1, v );
	stringstream actual;
	// object->toStream( std::cout, 1 );
    bool isOneLineOnly = true;
	object->streamContents( actual, 1, isOneLineOnly );
	CHECK_EQUAL( expected.str(), actual.str() )
	CHECK( ! object->hasAttributes() )
	CHECK( ! object->hasContents() )
}
TEST( Test02, PartGroupOrScorePart )
{
    variant v = variant::two;
	PartGroupOrScorePartPtr object = tgenPartGroupOrScorePart( v );
	stringstream expected;
	tgenPartGroupOrScorePartExpected( expected, 1, v );
	stringstream actual;
	// object->toStream( std::cout, 1 );
    bool isOneLineOnly = true;
	object->streamContents( actual, 1, isOneLineOnly );
	CHECK_EQUAL( expected.str(), actual.str() )
	CHECK( ! object->hasAttributes() )
	CHECK( object->hasContents() )
}
TEST( Test03, PartGroupOrScorePart )
{
    variant v = variant::three;
	PartGroupOrScorePartPtr object = tgenPartGroupOrScorePart( v );
	stringstream expected;
	tgenPartGroupOrScorePartExpected( expected, 1, v );
	stringstream actual;
	// object->toStream( std::cout, 1 );
    bool isOneLineOnly = true;
	object->streamContents( actual, 1, isOneLineOnly );
	CHECK_EQUAL( expected.str(), actual.str() )
	CHECK( ! object->hasAttributes() )
	CHECK( object->hasContents() )
}

namespace MxTestHelpers
{
    PartGroupOrScorePartPtr tgenPartGroupOrScorePart( variant v )
    {
        PartGroupOrScorePartPtr o = makePartGroupOrScorePart();
        switch ( v )
        {
            case variant::one:
            {
                
            }
                break;
            case variant::two:
            {
                o->setChoice( PartGroupOrScorePart::Choice::scorePart );
                o->setScorePart( tgenScorePart( v ) );
            }
                break;
            case variant::three:
            {
                o->setChoice( PartGroupOrScorePart::Choice::partGroup );
                o->setPartGroup( tgenPartGroup( v ) );
            }
                break;
            default:
                break;
        }
        return o;
    }
    void tgenPartGroupOrScorePartExpected( std::ostream& os, int i, variant v )
    {
        
        switch ( v )
        {
            case variant::one:
            {
                tgenPartGroupExpected( os, i, v );
            }
                break;
            case variant::two:
            {
                tgenScorePartExpected( os, i, v );
            }
                break;
            case variant::three:
            {
                tgenPartGroupExpected( os, i, v );
            }
                break;
            default:
                break;
        }
    }
}

#endif
