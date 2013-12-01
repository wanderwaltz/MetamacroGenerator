//
//  Metamacros100Tests.m
//  Metamacros100Tests
//
//  Created by Egor Chiglintsev on 01.12.13.
//  Copyright (c) 2013 Egor Chiglintsev.
//  Released under the MIT license.
//
//  This file contains unit tests for the metamacros generator application.
//
//  Source code available at
//      https://github.com/wanderwaltz/MetamacroGenerator
//
//  Although we cannot actually test the app itself since it involves
//  generating code, but we can reasonably test its functionality by
//  testing the resulting macros which were created using this application.
//
//  For that purpose we're using the metamacros_100.h file which has been
//  generated using the following command:
//
//    ./MetamacrosGenerator -limit 100 -prefix ww_ > metamacros_100.h
//
//  Note that this metamacros_100.h has been generated with ww_ prefix,
//  so the 'proper' way of using these macros will be with this prefix.
//  But MetamacrosGenerator also provides aliases for the metamacros
//  without the prefix, and we'll have to actually write each test case
//  twice - for both prefixed and non-prefixed version so we could be
//  sure all the aliases are set up properly.

#import <XCTest/XCTest.h>
#import "metamacros_100.h"


#pragma mark -
#pragma mark TVSMetamacros100Tests interface

@interface Metamacros100Tests : XCTestCase
@end


#pragma mark -
#pragma mark Metamacros100Tests implementation

@implementation Metamacros100Tests

#pragma mark -
#pragma mark metamacro_exprify tests

/// This case tests the ww_metamacro_exprify's core functionality
- (void) test_ww_metamacro_exprify
{
    int  x     = 0;
    bool value = ww_metamacro_exprify(x += 1);
    
    XCTAssertEqual(x, 1, @"Expression should be executed as the result of ww_metamacro_exprify");
    XCTAssertTrue(value,  @"ww_metamacro_exprify always returns true");
}


/// This case tests that ww_metamacro_exprify has been properly aliased to the metamacro_exprify
- (void) test_metamacro_exprify
{
    int  x     = 0;
    bool value = metamacro_exprify(x += 1);
    
    XCTAssertEqual(x, 1, @"Expression should be executed as the result of metamacro_exprify");
    XCTAssertTrue(value,  @"metamacro_exprify always returns true");
}


#pragma mark -
#pragma mark metamacro_stringify tests

/// This case tests the ww_metamacro_stringify's core functionality
- (void) test_ww_metamacro_stringify
{
    NSString *string = @ww_metamacro_stringify(Argument stringified successfully);
    
    XCTAssertEqualObjects(string, @"Argument stringified successfully",
                          @"ww_metamacro_stringify should properly stringify its argument");
}


/// This case tests that ww_metamacro_stringify has been properly aliased to the metamacro_stringify
- (void) test_metamacro_stringify
{
    NSString *string = @metamacro_stringify(Argument stringified successfully);
    
    XCTAssertEqualObjects(string, @"Argument stringified successfully",
                          @"metamacro_stringify should properly stringify its argument");
}


#pragma mark -
#pragma mark metamacro_concat tests

/// This case tests the ww_metamacro_concat's core functionality
- (void) test_ww_metamacro_concat
{
    int x = 1;
    int ww_metamacro_concat(y_, concatenated) = 1;
    
    XCTAssertEqual(x, y_concatenated,
                   @"The fact that this test even compiles already prooves that the "
                   @"ww_metamacro_concat works as intended. Otherwise the variable name "
                   @"would be constructed errorneously.");
    
    
    ww_metamacro_concat(XCTAssert, True)(YES, @"This second example demonstrates another case "
                                        @"of using ww_metamacro_concat which is particularly useful "
                                        @"in metaprogramming: constructing other macro names. "
                                        @"In this case it will expand to XCTAssertTrue");
}


/// This case tests that ww_metamacro_concat has been properly aliased to the metamacro_concat
- (void) test_metamacro_concat
{
    int x = 1;
    int metamacro_concat(y_, concatenated) = 1;
    
    XCTAssertEqual(x, y_concatenated,
                   @"The fact that this test even compiles already prooves that the "
                   @"metamacro_concat works as intended. Otherwise the variable name "
                   @"would be constructed errorneously.");
    
    
    metamacro_concat(XCTAssert, True)(YES, @"This second example demonstrates another case "
                                      @"of using metamacro_concat which is particularly useful "
                                      @"in metaprogramming: constructing other macro names. "
                                      @"In this case it will expand to XCTAssertTrue");
}


#pragma mark -
#pragma mark metamacro_head tests

/// This case tests the ww_metamacro_head's core functionality
- (void) test_ww_metamacro_head
{
    int x = ww_metamacro_head(1, other, macro arguments, should be, ignored, and you,
                              can write here anything: #32423$@#$@#$@$!!@ sdfs zxxxg);
    
    XCTAssertEqual(x, 1, @"ww_metamacro_head should ignore all arguments besides the first");
    
    int y = ww_metamacro_head(2);
    
    XCTAssertEqual(y, 2, @"ww_metamacro_head works when at least one argument is provided");
}


/// This case tests that ww_metamacro_head has been properly aliased to the metamacro_head
- (void) test_metamacro_head
{
    int x = metamacro_head(1, other, macro arguments, should be, ignored, and you,
                           can write here anything: #32423$@#$@#$@$!!@ sdfs zxxxg);
    
    XCTAssertEqual(x, 1, @"metamacro_head should ignore all arguments besides the first");
    
    int y = metamacro_head(2);
    
    XCTAssertEqual(y, 2, @"metamacro_head works when at least one argument is provided");
}


#pragma mark -
#pragma mark metamacro_tail tests

/// This case tests the ww_metamacro_tail's core functionality
- (void) test_ww_metamacro_tail
{
    int x[] = ww_metamacro_tail(all arguments besides the first are returned, { 1, 2, 3 }; );
    
    XCTAssertEqual(x[0], 1, @"ww_metamacro_tail should expand the argument list without the first arg.");
    XCTAssertEqual(x[1], 2, @"ww_metamacro_tail should expand the argument list without the first arg.");
    XCTAssertEqual(x[2], 3, @"ww_metamacro_tail should expand the argument list without the first arg.");
    
    int y = ww_metamacro_tail(@#$%^&*, 2);
    
    XCTAssertEqual(y, 2, @"ww_metamacro_tail works when at least two arguments are provided");
}


/// This case tests that ww_metamacro_tail has been properly aliased to the metamacro_tail
- (void) test_metamacro_tail
{
    int x[] = metamacro_tail(all arguments besides the first are returned, { 1, 2, 3 }; );
    
    XCTAssertEqual(x[0], 1, @"metamacro_tail should expand the argument list without the first arg.");
    XCTAssertEqual(x[1], 2, @"metamacro_tail should expand the argument list without the first arg.");
    XCTAssertEqual(x[2], 3, @"metamacro_tail should expand the argument list without the first arg.");
    
    int y = metamacro_tail(@#$%^&*, 2);
    
    XCTAssertEqual(y, 2, @"metamacro_tail works when at least two arguments are provided");
}


#pragma mark -
#pragma mark metamacro_at tests

/// This case tests the ww_metamacro_at's core functionality
- (void) test_ww_metamacro_at
{
    int x = ww_metamacro_at(1,
                            1, 2, 3); // select arg with index 1 from arglist 1,2,3 -> should expand to 2.
    
    XCTAssertEqual(x, 2, @"ww_metamacto_at expands to the Nth argument of the args list starting from 0");
    
    int a100 = 12345;
    
    // The whole thing with the a0..a100 is introduced here just to make
    // sure we can actually work with other things than just numbers.
    int y = ww_metamacro_at(100,
                             a0,
                             a1,  a2,  a3,  a4,  a5,  a6,  a7,  a8,  a9,  a10,
                            a11, a12, a13, a14, a15, a16, a17, a18, a19,  a20,
                            a21, a22, a23, a24, a25, a26, ---, a28, a29,  a30,
                            a31, ###, a33, a34, a35, a36, a37, a38, a39,  a40,
                            a41, a42, a43, $$$, a45, a46, a47, a48, a49,  a50,
                            a51, a52, a53, a54, a55, a56, a57, a58, a59,  a60,
                            a61, a62, a63, a64, a65, a66, a67, !!!, a69,  a70,
                            a71, a72, a73, a74, a75, a76, a77, a78, a79,  a80,
                            a81, a82, a83, a84, a85, a86, a87, a88, a89,  ***,
                            a91, a92, a93, a94, a95, a96, a97, a98, a99, a100);
    
    XCTAssertEqual(y, a100, @"ww_metamacro_at supports up to 100 arguments.");
}


/// This case tests that ww_metamacro_at has been properly aliased to the metamacro_at
- (void) test_metamacro_at
{
    int x = metamacro_at(1,
                         1, 2, 3); // select arg with index 1 from arglist 1,2,3 -> should expand to 2.
    
    XCTAssertEqual(x, 2, @"metamacto_at expands to the Nth argument of the args list starting from 0");
    
    int a100 = 12345;
    
    // The whole thing with the a0..a100 is introduced here just to make
    // sure we can actually work with other things than just numbers.
    int y = metamacro_at(100,
                         a0,
                         a1,  a2,  a3,  a4,  a5,  a6,  a7,  a8,  a9,  a10,
                         a11, a12, a13, a14, a15, a16, a17, a18, a19,  a20,
                         a21, a22, a23, a24, a25, a26, ---, a28, a29,  a30,
                         a31, ###, a33, a34, a35, a36, a37, a38, a39,  a40,
                         a41, a42, a43, $$$, a45, a46, a47, a48, a49,  a50,
                         a51, a52, a53, a54, a55, a56, a57, a58, a59,  a60,
                         a61, a62, a63, a64, a65, a66, a67, !!!, a69,  a70,
                         a71, a72, a73, a74, a75, a76, a77, a78, a79,  a80,
                         a81, a82, a83, a84, a85, a86, a87, a88, a89,  ***,
                         a91, a92, a93, a94, a95, a96, a97, a98, a99, a100);
    
    XCTAssertEqual(y, a100, @"metamacro_at supports up to 100 arguments.");
}


#pragma mark -
#pragma mark metamacro_argcount tests

/// This case tests the ww_metamacro_argcount's core functionality
- (void) test_ww_metamacro_argcount
{
    int x = ww_metamacro_argcount(there, are, four, arguments);
    
    XCTAssertEqual(x, 4, @"ww_metamacro_argcount returns the number of arguments which were passed to it");
    
    int y = ww_metamacro_argcount();
    
    XCTAssertEqual(y, 0, @"ww_metamacro_argcount properly handles the case of zero arguments provided");
    
    int z = ww_metamacro_argcount( 1,  2,  3,  4,  5,  6,  7,  8,  9,  10,
                                  11, 12, 13, 14, 15, 16, 17, 18, 19,  20,
                                  21, 22, 23, 24, 25, 26, 27, 28, 29,  30,
                                  31, 32, 33, 34, 35, 36, 37, 38, 39,  40,
                                  41, 42, 43, 44, 45, 46, 47, 48, 49,  50,
                                  51, 52, 53, 54, 55, 56, 57, 58, 59,  60,
                                  61, 62, 63, 64, 65, 66, 67, 68, 69,  70,
                                  71, 72, 73, 74, 75, 76, 77, 78, 79,  80,
                                  81, 82, 83, 84, 85, 86, 87, 88, 89,  90,
                                  91, 92, 93, 94, 95, 96, 97, 98, 99, 100);
    
    XCTAssertEqual(z, 100, @"ww_metamacro_argcount supports up to 100 arguments");
}


/// This case tests that ww_metamacro_argcount has been properly aliased to the metamacro_argcount
- (void) test_metamacro_argcount
{
    int x = metamacro_argcount(there, are, four, arguments);
    
    XCTAssertEqual(x, 4, @"metamacro_argcount returns the number of arguments which were passed to it");
    
    int y = metamacro_argcount();
    
    XCTAssertEqual(y, 0, @"metamacro_argcount properly handles the case of zero arguments provided");
    
    int z = metamacro_argcount( 1,  2,  3,  4,  5,  6,  7,  8,  9,  10,
                               11, 12, 13, 14, 15, 16, 17, 18, 19,  20,
                               21, 22, 23, 24, 25, 26, 27, 28, 29,  30,
                               31, 32, 33, 34, 35, 36, 37, 38, 39,  40,
                               41, 42, 43, 44, 45, 46, 47, 48, 49,  50,
                               51, 52, 53, 54, 55, 56, 57, 58, 59,  60,
                               61, 62, 63, 64, 65, 66, 67, 68, 69,  70,
                               71, 72, 73, 74, 75, 76, 77, 78, 79,  80,
                               81, 82, 83, 84, 85, 86, 87, 88, 89,  90,
                               91, 92, 93, 94, 95, 96, 97, 98, 99, 100);
    
    XCTAssertEqual(z, 100, @"metamacro_argcount supports up to 100 arguments");
}


#pragma mark -
#pragma mark metamacro_take tests

/// This case tests the ww_metamacro_take's core functionality
- (void) test_ww_metamacro_take
{
    int x[] = ww_metamacro_take(3, { 1, 2, 3 }, other, arguments, will, be, ignored);
    
    XCTAssertEqual(x[0], 1, @"ww_metamacro_take returns the first N arguments of the arglist as a new arglist");
    XCTAssertEqual(x[1], 2, @"ww_metamacro_take returns the first N arguments of the arglist as a new arglist");
    XCTAssertEqual(x[2], 3, @"ww_metamacro_take returns the first N arguments of the arglist as a new arglist");
    
    int y[] = {ww_metamacro_take(100,
                                   1,  2,  3,  4,  5,  6,  7,  8,  9,  10,
                                  11, 12, 13, 14, 15, 16, 17, 18, 19,  20,
                                  21, 22, 23, 24, 25, 26, 27, 28, 29,  30,
                                  31, 32, 33, 34, 35, 36, 37, 38, 39,  40,
                                  41, 42, 43, 44, 45, 46, 47, 48, 49,  50,
                                  51, 52, 53, 54, 55, 56, 57, 58, 59,  60,
                                  61, 62, 63, 64, 65, 66, 67, 68, 69,  70,
                                  71, 72, 73, 74, 75, 76, 77, 78, 79,  80,
                                  81, 82, 83, 84, 85, 86, 87, 88, 89,  90,
                                  91, 92, 93, 94, 95, 96, 97, 98, 99, 100,
                                 other, arguments, will, be, ignored)};
    
    XCTAssertEqual(sizeof(y), sizeof(int) * 100, @"ww_metamacro_take supports taking up to 100 arguments");
    XCTAssertEqual(y[99], 100, @"ww_metamacro_take supports taking up to 100 arguments");
}


/// This case tests that ww_metamacro_take has been properly aliased to the metamacro_take
- (void) test_metamacro_take
{
    int x[] = metamacro_take(3, { 1, 2, 3 }, other, arguments, will, be, ignored);
    
    XCTAssertEqual(x[0], 1, @"metamacro_take returns the first N arguments of the arglist as a new arglist");
    XCTAssertEqual(x[1], 2, @"metamacro_take returns the first N arguments of the arglist as a new arglist");
    XCTAssertEqual(x[2], 3, @"metamacro_take returns the first N arguments of the arglist as a new arglist");
    
    int y[] = {metamacro_take(100,
                                1,  2,  3,  4,  5,  6,  7,  8,  9,  10,
                               11, 12, 13, 14, 15, 16, 17, 18, 19,  20,
                               21, 22, 23, 24, 25, 26, 27, 28, 29,  30,
                               31, 32, 33, 34, 35, 36, 37, 38, 39,  40,
                               41, 42, 43, 44, 45, 46, 47, 48, 49,  50,
                               51, 52, 53, 54, 55, 56, 57, 58, 59,  60,
                               61, 62, 63, 64, 65, 66, 67, 68, 69,  70,
                               71, 72, 73, 74, 75, 76, 77, 78, 79,  80,
                               81, 82, 83, 84, 85, 86, 87, 88, 89,  90,
                               91, 92, 93, 94, 95, 96, 97, 98, 99, 100,
                            other, arguments, will, be, ignored)};
    
    XCTAssertEqual(sizeof(y), sizeof(int) * 100, @"metamacro_take supports taking up to 100 arguments");
}

@end
