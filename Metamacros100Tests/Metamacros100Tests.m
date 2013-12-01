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
    XCTAssertEqual(y[99], 100, @"metamacro_take supports taking up to 100 arguments");
}


#pragma mark -
#pragma mark metamacro_drop tests

/// This case tests the ww_metamacro_drop's core functionality
- (void) test_ww_metamacro_drop
{
    int x[] = ww_metamacro_drop(6, first, six, arguments, will, be, ignored, { 1, 2, 3 });
    
    XCTAssertEqual(x[0], 1, @"ww_metamacro_drop drops the first N arguments of the arglist and returns the rest");
    XCTAssertEqual(x[1], 2, @"ww_metamacro_drop drops the first N arguments of the arglist and returns the rest");
    XCTAssertEqual(x[2], 3, @"ww_metamacro_drop drops the first N arguments of the arglist and returns the rest");
    
    int y[] = {ww_metamacro_drop(100,
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
                                 101, 102, 103, 104)};
    
    XCTAssertEqual(sizeof(y), sizeof(int) * 4, @"ww_metamacro_drop supports dropping up to 100 arguments");
    XCTAssertEqual(y[3], 104, @"ww_metamacro_drop supports dropping up to 100 arguments");
}


/// This case tests that ww_metamacro_drop has been properly aliased to the metamacro_drop
- (void) test_metamacro_drop
{
    int x[] = metamacro_drop(6, first, six, arguments, will, be, ignored, { 1, 2, 3 });
    
    XCTAssertEqual(x[0], 1, @"metamacro_drop drops the first N arguments of the arglist and returns the rest");
    XCTAssertEqual(x[1], 2, @"metamacro_drop drops the first N arguments of the arglist and returns the rest");
    XCTAssertEqual(x[2], 3, @"metamacro_drop drops the first N arguments of the arglist and returns the rest");
    
    int y[] = {metamacro_drop(100,
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
                                 101, 102, 103, 104)};
    
    XCTAssertEqual(sizeof(y), sizeof(int) * 4, @"metamacro_drop supports dropping up to 100 arguments");
    XCTAssertEqual(y[3], 104, @"metamacro_drop supports dropping up to 100 arguments");
}


#pragma mark -
#pragma mark metamacro_inc tests

/// This case tests the ww_metamacro_inc's core functionality
- (void) test_ww_metamacro_inc
{
    // We have to test each value individually since macros are expanded at
    // compile time so we cannot make a for loop or something like that here.
    // (we actually have macros for making loops below, but they have to be
    // also tested prior to using them here)
    XCTAssertEqual(ww_metamacro_inc(0), 1, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    
    XCTAssertEqual(ww_metamacro_inc( 1),  2, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc( 2),  3, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc( 3),  4, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc( 4),  5, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc( 5),  6, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc( 6),  7, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc( 7),  8, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc( 8),  9, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc( 9), 10, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(10), 11, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    
    XCTAssertEqual(ww_metamacro_inc(11), 12, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(12), 13, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(13), 14, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(14), 15, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(15), 16, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(16), 17, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(17), 18, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(18), 19, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(19), 20, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(20), 21, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    
    XCTAssertEqual(ww_metamacro_inc(21), 22, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(22), 23, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(23), 24, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(24), 25, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(25), 26, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(26), 27, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(27), 28, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(28), 29, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(29), 30, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(30), 31, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    
    XCTAssertEqual(ww_metamacro_inc(31), 32, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(32), 33, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(33), 34, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(34), 35, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(35), 36, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(36), 37, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(37), 38, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(38), 39, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(39), 40, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(40), 41, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    
    XCTAssertEqual(ww_metamacro_inc(41), 42, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(42), 43, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(43), 44, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(44), 45, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(45), 46, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(46), 47, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(47), 48, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(48), 49, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(49), 50, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(50), 51, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    
    XCTAssertEqual(ww_metamacro_inc(51), 52, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(52), 53, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(53), 54, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(54), 55, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(55), 56, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(56), 57, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(57), 58, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(58), 59, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(59), 60, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(60), 61, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    
    XCTAssertEqual(ww_metamacro_inc(61), 62, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(62), 63, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(63), 64, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(64), 65, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(65), 66, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(66), 67, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(67), 68, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(68), 69, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(69), 70, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(70), 71, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    
    XCTAssertEqual(ww_metamacro_inc(71), 72, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(72), 73, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(73), 74, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(74), 75, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(75), 76, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(76), 77, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(77), 78, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(78), 79, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(79), 80, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(80), 81, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    
    XCTAssertEqual(ww_metamacro_inc(81), 82, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(82), 83, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(83), 84, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(84), 85, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(85), 86, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(86), 87, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(87), 88, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(88), 89, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(89), 90, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(90), 91, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    
    XCTAssertEqual(ww_metamacro_inc( 91),  92, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc( 92),  93, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc( 93),  94, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc( 94),  95, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc( 95),  96, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc( 96),  97, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc( 97),  98, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc( 98),  99, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc( 99), 100, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(ww_metamacro_inc(100), 101, @"ww_metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
}


/// This case tests that ww_metamacro_inc has been properly aliased to the metamacro_inc
- (void) test_metamacro_inc
{
    // We have to test each value individually since macros are expanded at
    // compile time so we cannot make a for loop or something like that here.
    // (we actually have macros for making loops below, but they have to be
    // also tested prior to using them here)
    XCTAssertEqual(metamacro_inc(0), 1, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    
    XCTAssertEqual(metamacro_inc( 1),  2, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc( 2),  3, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc( 3),  4, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc( 4),  5, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc( 5),  6, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc( 6),  7, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc( 7),  8, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc( 8),  9, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc( 9), 10, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(10), 11, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    
    XCTAssertEqual(metamacro_inc(11), 12, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(12), 13, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(13), 14, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(14), 15, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(15), 16, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(16), 17, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(17), 18, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(18), 19, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(19), 20, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(20), 21, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    
    XCTAssertEqual(metamacro_inc(21), 22, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(22), 23, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(23), 24, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(24), 25, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(25), 26, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(26), 27, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(27), 28, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(28), 29, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(29), 30, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(30), 31, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    
    XCTAssertEqual(metamacro_inc(31), 32, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(32), 33, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(33), 34, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(34), 35, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(35), 36, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(36), 37, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(37), 38, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(38), 39, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(39), 40, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(40), 41, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    
    XCTAssertEqual(metamacro_inc(41), 42, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(42), 43, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(43), 44, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(44), 45, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(45), 46, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(46), 47, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(47), 48, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(48), 49, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(49), 50, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(50), 51, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    
    XCTAssertEqual(metamacro_inc(51), 52, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(52), 53, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(53), 54, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(54), 55, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(55), 56, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(56), 57, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(57), 58, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(58), 59, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(59), 60, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(60), 61, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    
    XCTAssertEqual(metamacro_inc(61), 62, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(62), 63, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(63), 64, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(64), 65, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(65), 66, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(66), 67, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(67), 68, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(68), 69, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(69), 70, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(70), 71, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    
    XCTAssertEqual(metamacro_inc(71), 72, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(72), 73, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(73), 74, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(74), 75, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(75), 76, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(76), 77, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(77), 78, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(78), 79, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(79), 80, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(80), 81, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    
    XCTAssertEqual(metamacro_inc(81), 82, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(82), 83, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(83), 84, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(84), 85, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(85), 86, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(86), 87, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(87), 88, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(88), 89, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(89), 90, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(90), 91, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    
    XCTAssertEqual(metamacro_inc( 91),  92, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc( 92),  93, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc( 93),  94, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc( 94),  95, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc( 95),  96, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc( 96),  97, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc( 97),  98, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc( 98),  99, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc( 99), 100, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
    XCTAssertEqual(metamacro_inc(100), 101, @"metamacro_inc increases its arg by 1 (should be in [0 .. 100])");
}


#pragma mark -
#pragma mark metamacro_dec tests

/// This case tests the ww_metamacro_inc's core functionality
- (void) test_ww_metamacro_dec
{
    // We have to test each value individually since macros are expanded at
    // compile time so we cannot make a for loop or something like that here.
    // (we actually have macros for making loops below, but they have to be
    // also tested prior to using them here)
    XCTAssertEqual(ww_metamacro_dec(0), -1, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    
    XCTAssertEqual(ww_metamacro_dec( 1), 0, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec( 2), 1, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec( 3), 2, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec( 4), 3, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec( 5), 4, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec( 6), 5, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec( 7), 6, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec( 8), 7, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec( 9), 8, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(10), 9, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    
    XCTAssertEqual(ww_metamacro_dec(11), 10, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(12), 11, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(13), 12, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(14), 13, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(15), 14, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(16), 15, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(17), 16, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(18), 17, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(19), 18, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(20), 19, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    
    XCTAssertEqual(ww_metamacro_dec(21), 20, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(22), 21, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(23), 22, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(24), 23, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(25), 24, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(26), 25, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(27), 26, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(28), 27, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(29), 28, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(30), 29, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    
    XCTAssertEqual(ww_metamacro_dec(31), 30, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(32), 31, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(33), 32, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(34), 33, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(35), 34, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(36), 35, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(37), 36, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(38), 37, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(39), 38, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(40), 39, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    
    XCTAssertEqual(ww_metamacro_dec(41), 40, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(42), 41, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(43), 42, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(44), 43, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(45), 44, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(46), 45, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(47), 46, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(48), 47, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(49), 48, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(50), 49, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    
    XCTAssertEqual(ww_metamacro_dec(51), 50, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(52), 51, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(53), 52, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(54), 53, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(55), 54, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(56), 55, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(57), 56, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(58), 57, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(59), 58, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(60), 59, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    
    XCTAssertEqual(ww_metamacro_dec(61), 60, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(62), 61, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(63), 62, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(64), 63, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(65), 64, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(66), 65, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(67), 66, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(68), 67, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(69), 68, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(70), 69, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    
    XCTAssertEqual(ww_metamacro_dec(71), 70, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(72), 71, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(73), 72, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(74), 73, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(75), 74, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(76), 75, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(77), 76, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(78), 77, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(79), 78, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(80), 79, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    
    XCTAssertEqual(ww_metamacro_dec(81), 80, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(82), 81, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(83), 82, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(84), 83, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(85), 84, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(86), 85, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(87), 86, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(88), 87, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(89), 88, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(90), 89, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    
    XCTAssertEqual(ww_metamacro_dec( 91), 90, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec( 92), 91, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec( 93), 92, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec( 94), 93, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec( 95), 94, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec( 96), 95, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec( 97), 96, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec( 98), 97, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec( 99), 98, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(ww_metamacro_dec(100), 99, @"ww_metamacro_dec decreases its arg by 1 (should be in [0..100])");
}


/// This case tests that ww_metamacro_dec has been properly aliased to the metamacro_dec
- (void) test_metamacro_dec
{
    // We have to test each value individually since macros are expanded at
    // compile time so we cannot make a for loop or something like that here.
    // (we actually have macros for making loops below, but they have to be
    // also tested prior to using them here)
    XCTAssertEqual(metamacro_dec(0), -1, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    
    XCTAssertEqual(metamacro_dec( 1), 0, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec( 2), 1, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec( 3), 2, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec( 4), 3, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec( 5), 4, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec( 6), 5, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec( 7), 6, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec( 8), 7, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec( 9), 8, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(10), 9, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    
    XCTAssertEqual(metamacro_dec(11), 10, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(12), 11, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(13), 12, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(14), 13, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(15), 14, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(16), 15, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(17), 16, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(18), 17, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(19), 18, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(20), 19, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    
    XCTAssertEqual(metamacro_dec(21), 20, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(22), 21, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(23), 22, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(24), 23, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(25), 24, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(26), 25, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(27), 26, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(28), 27, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(29), 28, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(30), 29, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    
    XCTAssertEqual(metamacro_dec(31), 30, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(32), 31, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(33), 32, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(34), 33, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(35), 34, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(36), 35, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(37), 36, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(38), 37, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(39), 38, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(40), 39, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    
    XCTAssertEqual(metamacro_dec(41), 40, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(42), 41, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(43), 42, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(44), 43, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(45), 44, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(46), 45, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(47), 46, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(48), 47, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(49), 48, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(50), 49, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    
    XCTAssertEqual(metamacro_dec(51), 50, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(52), 51, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(53), 52, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(54), 53, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(55), 54, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(56), 55, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(57), 56, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(58), 57, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(59), 58, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(60), 59, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    
    XCTAssertEqual(metamacro_dec(61), 60, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(62), 61, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(63), 62, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(64), 63, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(65), 64, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(66), 65, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(67), 66, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(68), 67, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(69), 68, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(70), 69, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    
    XCTAssertEqual(metamacro_dec(71), 70, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(72), 71, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(73), 72, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(74), 73, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(75), 74, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(76), 75, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(77), 76, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(78), 77, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(79), 78, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(80), 79, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    
    XCTAssertEqual(metamacro_dec(81), 80, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(82), 81, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(83), 82, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(84), 83, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(85), 84, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(86), 85, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(87), 86, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(88), 87, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(89), 88, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(90), 89, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    
    XCTAssertEqual(metamacro_dec( 91), 90, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec( 92), 91, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec( 93), 92, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec( 94), 93, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec( 95), 94, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec( 96), 95, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec( 97), 96, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec( 98), 97, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec( 99), 98, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
    XCTAssertEqual(metamacro_dec(100), 99, @"metamacro_dec decreases its arg by 1 (should be in [0..100])");
}


@end
