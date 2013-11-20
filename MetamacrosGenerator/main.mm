//
//  main.c
//  MetamacrosGenerator
//
//  Created by Egor Chiglintsev on 19/11/13.
//  Copyright (c) 2013 Egor Chiglintsev.
//  Released under the MIT license.
//

#include <stdio.h>
#import <Foundation/Foundation.h>

#pragma mark -
#pragma mark constants

static const int kMinLimit = 20;


#pragma mark -
#pragma mark file header comment

void print_file_header(void)
{
    NSCalendar *calendar = [NSCalendar currentCalendar];
    NSDate     *now      = [NSDate date];
    
    NSDateComponents *components = [calendar components: NSYearCalendarUnit
                                               fromDate: now];
    
    printf("/**\n");
    printf(" * Macros for metaprogramming\n");
    printf(" * ExtendedC\n");
    printf(" *\n");
    printf(" * This file has been generated using\n");
    printf(" * MetamacrosGenerator software.\n");
    printf(" * Copyright (C) %d Egor Chiglintsev\n", (int)components.year);
    printf(" *\n");
    printf(" * Source code available at\n");
    printf(" *    https://github.com/wanderwaltz/MetamacroGenerator\n");
    printf(" *\n");
    printf(" * It is based on and is extending the metamacros.h\n");
    printf(" * file included in extobjc library which can be found\n");
    printf(" * at https://github.com/jspahrsummers/libextobjc\n");
    printf(" *\n");
    printf(" * Copyright (C) 2012 Justin Spahr-Summers\n");
    printf(" * Released under the MIT license\n");
    printf(" */\n");
    printf("\n\n");
}


#pragma mark -
#pragma mark #include guard defines

const char kIncludeGuardMacroName[] = "EXTC_METAMACROS_EXTENDED_H";


void print_include_guard_open(void)
{
    printf("#ifndef %s\n", kIncludeGuardMacroName);
    printf("#define %s\n\n", kIncludeGuardMacroName);
}


void print_include_guard_close(void)
{
    printf("#endif // #ifndef %s\n", kIncludeGuardMacroName);
}


#pragma mark -
#pragma mark miscellaneous

/// Prints hard separator
void ____(BOOL insertNewlinesAfter = NO)
{
    printf("///////////////////////////////////////////////////////////////////////////////////\n");
    
    if (insertNewlinesAfter) printf("\n\n");
}


void print_pragma_mark(const char *title)
{
    printf("#pragma mark -\n");
    printf("#pragma mark %s\n\n", title);
}


#pragma mark -
#pragma mark metamacro_exprify

void print_metamacro_exprify(void)
{
    ____();
    printf("/**\n");
    printf(" * Executes one or more expressions (which may have a void type, such as a call\n");
    printf(" * to a function that returns no value) and always returns true.\n");
    printf(" */\n");
    printf("#define metamacro_exprify(...) \\\n");
    printf("    ((__VA_ARGS__), true)\n");
    ____(YES);
}


#pragma mark -
#pragma mark metamacro_stringify

void print_interface_metamacro_stringify(void)
{
    ____();
    printf("/**\n");
    printf(" * Returns a string representation of VALUE after full macro expansion.\n");
    printf(" */\n");
    printf("#define metamacro_stringify(VALUE) \\\n");
    printf("    metamacro_stringify_(VALUE)\n");
    ____(YES);
}


void print_implementation_metamacro_stringify(void)
{
    ____();
    printf("#define metamacro_stringify_(VALUE) # VALUE\n");
    ____(YES);
}


#pragma mark -
#pragma mark metamacro_concat

void print_interface_metamacro_concat(void)
{
    ____();
    printf("/**\n");
    printf(" * Returns A and B concatenated after full macro expansion.\n");
    printf(" */\n");
    printf("#define metamacro_concat(A, B) \\\n");
    printf("    metamacro_concat_(A, B)\n");
    ____(YES);
}


void print_implementation_metamacro_concat(void)
{
    ____();
    printf("#define metamacro_concat_(A, B) A ## B\n");
    ____(YES);
}


#pragma mark -
#pragma mark metamacro_at

void print_interface_metamacro_at(int limit)
{
    ____();
    printf("/**\n");
    printf(" * Returns the Nth variadic argument (starting from zero). At least\n");
    printf(" * N + 1 variadic arguments must be given. N must be in [0..%d].\n", limit);
    printf(" */\n");
    printf("#define metamacro_at(N, ...) \\\n");
    printf("    metamacro_concat(metamacro_at, N)(__VA_ARGS__)\n");
    ____(YES);
}


void print_implementation_metamacro_at(int limit)
{
    ____();
    printf("// metamacro_at expansions\n");
    
    for (int i = 0; i <= limit; ++i)
    {
        printf("#define metamacro_at%d(", i);
        
        for (int arg = 0; arg < i; ++arg)
        {
            printf("_%d, ", arg);
        }
        
        printf("...) metamacro_head(__VA_ARGS__)\n");
    }
    ____(YES);
}


#pragma mark -
#pragma mark metamacro_argcount

void print_interface_metamacro_argcount(int limit)
{
    ____();
    printf("/**\n");
    printf(" * Returns the number of arguments (up to %d) provided to the macro. At\n", limit);
    printf(" * least one argument must be provided.\n");
    printf(" *\n");
    printf(" * This implementation is based on ##__VA_ARGS__ extension and properly processes\n");
    printf(" * the case with zero arguments provided.\n");
    printf(" *\n");
    printf(" * Based on http://stackoverflow.com/questions/11317474/macro-to-count-number-of-arguments\n");
    printf(" */\n");
    printf("#define metamacro_argcount(...) \\\n");
    printf("    metamacro_argcount_(X, ##__VA_ARGS__, ");
    for (int i = limit; i > 0; --i)
    {
        printf("%d, ", i);
    }
    printf("0)\n");
    ____(YES);
}


void print_implementation_metamacro_argcount(int limit)
{
    ____();
    printf("#define metamacro_argcount_(");
    for (int i = 0; i <= limit; ++i)
    {
        printf("_%d, ", i);
    }
    printf("N, ...) N\n");
    ____(YES);
}


#pragma mark -
#pragma mark metamacro_head

void print_interface_metamacro_head(void)
{
    ____();
    printf("/**\n");
    printf(" * Returns the first argument given. At least one argument must be provided.\n");
    printf(" *\n");
    printf(" * This is useful when implementing a variadic macro, where you may have only\n");
    printf(" * one variadic argument, but no way to retrieve it (for example, because \\c ...\n");
    printf(" * always needs to match at least one argument).\n");
    printf(" *\n");
    printf(" * @code\n");
    printf("\n");
    printf("        #define varmacro(...) \\\n");
    printf("            metamacro_head(__VA_ARGS__)\n");
    printf("\n");
    printf(" * @endcode\n");
    printf(" */\n");
    printf("#define metamacro_head(...) \\\n");
    printf("    metamacro_head_(__VA_ARGS__, 0)\n");
    ____(YES);
}


void print_implementation_metamacro_head(void)
{
    ____();
    printf("#define metamacro_head_(FIRST, ...) FIRST\n");
    ____(YES);
}


#pragma mark -
#pragma mark metamacro_tail

void print_interface_metamacro_tail(void)
{
    ____();
    printf("/**\n");
    printf(" * Returns every argument except the first. At least two arguments must be\n");
    printf(" * provided.\n");
    printf(" */\n");
    printf("#define metamacro_tail(...) \\\n");
    printf("    metamacro_tail_(__VA_ARGS__)\n");
    ____(YES);
}


void print_implementation_metamacro_tail(void)
{
    ____();
    printf("#define metamacro_tail_(FIRST, ...) __VA_ARGS__\n");
    ____(YES);
}


#pragma mark -
#pragma mark metamacro_take

void print_interface_metamacro_take(int limit)
{
    ____();
    printf("/**\n");
    printf(" * Returns the first N (up to %d) variadic arguments as a new argument list.\n", limit);
    printf(" * At least N variadic arguments must be provided.\n");
    printf(" */\n");
    printf("#define metamacro_take(N, ...) \\\n");
    printf("    metamacro_concat(metamacro_take, N)(__VA_ARGS__)\n");
    ____(YES);
}


void print_implementation_metamacro_take(int limit)
{
    NSCParameterAssert(limit >= kMinLimit);
    ____();
    printf("// metamacro_take expansions\n");
    printf("#define metamacro_take0(...)\n");
    printf("#define metamacro_take1(...) metamacro_head(__VA_ARGS__)\n");
    for (int i = 2; i <= limit; ++i)
    {
        printf("#define metamacro_take%d(...) metamacro_head(__VA_ARGS__), ", i);
        printf("metamacro_take%d(metamacro_tail(__VA_ARGS__))\n", i-1);
    }
    ____(YES);
}


#pragma mark -
#pragma mark metamacro_drop

void print_interface_metamacro_drop(int limit)
{
    ____();
    printf("/**\n");
    printf(" * Removes the first N (up to %d) variadic arguments from the given argument\n", limit);
    printf(" * list. At least N variadic arguments must be provided.\n");
    printf(" */\n");
    printf("#define metamacro_drop(N, ...) \\\n");
    printf("    metamacro_concat(metamacro_drop, N)(__VA_ARGS__)\n");
    ____(YES);
}


void print_implementation_metamacro_drop(int limit)
{
    NSCParameterAssert(limit >= kMinLimit);
    ____();
    printf("// metamacro_drop expansions\n");
    printf("#define metamacro_drop0(...) __VA_ARGS__\n");
    printf("#define metamacro_drop1(...) metamacro_tail(__VA_ARGS__)\n");
    for (int i = 2; i <= limit; ++i)
    {
        printf("#define metamacro_drop%d(...) metamacro_drop%d(metamacro_tail(__VA_ARGS__))\n", i, i-1);
    }
    ____(YES);
}


#pragma mark -
#pragma mark metamacro_dec

void print_metamacro_dec(int limit)
{
    NSCParameterAssert(limit >= kMinLimit);
    ____();
    printf("/**\n");
    printf(" * Decrements VAL, which must be a number between 0 and %d, inclusive.\n", limit);
    printf(" *\n");
    printf(" * This is primarily useful when dealing with indexes and counts in\n");
    printf(" * metaprogramming.\n");
    printf(" */\n");
    printf("#define metamacro_dec(VAL) \\\n");
    printf("    metamacro_at(VAL, ");
    
    for (int i = -1; i < limit-1; ++i)
    {
        printf("%d, ", i);
    }
    
    printf("%d)\n", limit-1);
    ____(YES);
}


#pragma mark -
#pragma mark metamacro_inc

void print_metamacro_inc(int limit)
{
    ____();
    printf("/**\n");
    printf(" * Increments VAL, which must be a number between 0 and %d, inclusive.\n", limit);
    printf(" *\n");
    printf(" * This is primarily useful when dealing with indexes and counts in\n");
    printf(" * metaprogramming.\n");
    printf(" */\n");
    printf("#define metamacro_inc(VAL) \\\n");
    printf("    metamacro_at(VAL, ");
    
    for (int i = 1; i <= limit; ++i)
    {
        printf("%d, ", i);
    }
    
    printf("%d)\n", limit+1);
    ____(YES);
}


#pragma mark -
#pragma mark metamacro_is_even

void print_metamacro_is_even(int limit)
{
    ____();
    printf("/**\n");
    printf(" * Returns 1 if N is an even number, or 0 otherwise.\n");
    printf(" * N must be between 0 and %d, inclusive.\n", limit);
    printf(" *\n");
    printf(" * For the purposes of this test, zero is considered even.\n");
    printf(" */\n");
    printf("#define metamacro_is_even(N) \\\n");
    printf("metamacro_at(N, ");
    
    for (int i = 0; i < limit; ++i)
    {
        printf("%d, ", (i % 2) == 0);
    }
    
    printf("%d)\n", (limit % 2) == 0);
    ____(YES);
}


#pragma mark -
#pragma mark metamacro_not

void print_metamacro_not(void)
{
    ____();
    printf("/**\n");
    printf(" * Returns the logical NOT of B, which must be the number zero or one.\n");
    printf(" */\n");
    printf("#define metamacro_not(B) \\\n");
    printf("    metamacro_at(B, 1, 0)\n");
    ____(YES);
}


#pragma mark -
#pragma mark metamacro_foreach_cxt

void print_interface_metamacro_foreach_cxt_internal(int limit, const char *suffix)
{
    printf("#define metamacro_foreach_cxt%s(MACRO, SEP, CONTEXT, ...) \\\n", suffix);
    printf("    metamacro_concat(metamacro_foreach_cxt%s, metamacro_argcount(__VA_ARGS__))(MACRO, SEP, CONTEXT, __VA_ARGS__)\n", suffix);
}


void print_interface_metamacro_foreach_cxt(int limit)
{
    ____();
    printf("/**\n");
    printf(" * For each consecutive variadic argument (up to %d), MACRO is passed the\n", limit);
    printf(" * zero-based index of the current argument, CONTEXT, and then the argument\n");
    printf(" * itself. The results of adjoining invocations of MACRO are then separated by\n");
    printf(" * SEP.\n");
    printf(" *\n");
    printf(" * Inspired by P99: http://p99.gforge.inria.fr\n");
    printf(" */\n");
    print_interface_metamacro_foreach_cxt_internal(limit, "");
     ____(YES);
}


void print_interface_metamacro_foreach_cxt_recursive(int limit)
{
    ____();
    printf("/**\n");
    printf(" * Identical to #metamacro_foreach_cxt. This can be used when the former would\n");
    printf(" * fail due to recursive macro expansion.\n");
    printf(" */\n");
    print_interface_metamacro_foreach_cxt_internal(limit, "_recursive");
    ____(YES);
}


void print_implementation_metamacro_foreach_cxt(int limit, const char *suffix)
{
    ____();
    printf("// metamacro_foreach_cxt expansions\n");
    printf("#define metamacro_foreach_cxt%s0(MACRO, SEP, CONTEXT)\n", suffix);
    printf("#define metamacro_foreach_cxt%s1(MACRO, SEP, CONTEXT, _0) MACRO(0, CONTEXT, _0)\n\n", suffix);
    
    for (int i = 2; i <= limit; ++i)
    {
        printf("#define metamacro_foreach_cxt%s%d(MACRO, SEP, CONTEXT, ", suffix, i);
        
        for (int arg = 0; arg < i-1; ++arg)
        {
            printf("_%d, ", arg);
        }
        
        printf("_%d) \\\n", i-1);
        
        
        printf("    metamacro_foreach_cxt%s%d(MACRO, SEP, CONTEXT, ", suffix, i-1);
        
        
        for (int arg = 0; arg < i-2; ++arg)
        {
            printf("_%d, ", arg);
        }
        
        printf("_%d) \\\n", i-2);
        
        printf("    SEP \\\n");
        printf("    MACRO(%d, CONTEXT, _%d)\n\n", i-1, i-1);
    }
    ____(YES);
}


#pragma mark -
#pragma mark metamacro_foreach

void print_interface_metamacro_foreach(void)
{
    ____();
    printf("/**\n");
    printf(" * Identical to #metamacro_foreach_cxt, except that no CONTEXT argument is\n");
    printf(" * given. Only the index and current argument will thus be passed to MACRO.\n");
    printf(" */\n");
    printf("#define metamacro_foreach(MACRO, SEP, ...) \\\n");
    printf("    metamacro_foreach_cxt(metamacro_foreach_iter, SEP, MACRO, __VA_ARGS__)\n");
    ____(YES);
}


void print_implementation_metamacro_foreach(void)
{
    ____();
    printf("#define metamacro_foreach_iter(INDEX, MACRO, ARG) MACRO(INDEX, ARG)\n");
    ____(YES);
}


#pragma mark -
#pragma mark metamacro_foreach_concat

void print_interface_metamacro_foreach_concat(int limit)
{
    ____();
    printf("/**\n");
    printf(" * In consecutive order, appends each variadic argument (up to %d) onto\n", limit);
    printf(" * BASE. The resulting concatenations are then separated by SEP.\n");
    printf(" *\n");
    printf(" * This is primarily useful to manipulate a list of macro invocations into instead\n");
    printf(" * invoking a different, possibly related macro.\n");
    printf(" */\n");
    printf("#define metamacro_foreach_concat(BASE, SEP, ...) \\\n");
    printf("    metamacro_foreach_cxt(metamacro_foreach_concat_iter, SEP, BASE, __VA_ARGS__)\n");
    ____(YES);
}


void print_implementation_metamacro_foreach_concat(void)
{
    ____();
    printf("// implemented from scratch so that metamacro_concat() doesn't end up nesting\n");
    printf("#define metamacro_foreach_concat_iter(INDEX, BASE, ARG) metamacro_foreach_concat_iter_(BASE, ARG)\n");
    printf("#define metamacro_foreach_concat_iter_(BASE, ARG) BASE ## ARG\n");
    ____(YES);
}


#pragma mark -
#pragma mark metamacro_for_cxt

void print_interface_metamacro_for_cxt(int limit)
{
    ____();
    printf("/**\n");
    printf(" * Iterates COUNT times, each time invoking MACRO with the current index\n");
    printf(" * (starting at zero) and CONTEXT. The results of adjoining invocations of MACRO\n");
    printf(" * are then separated by SEP.\n");
    printf(" *\n");
    printf(" * COUNT must be an integer between zero and %d, inclusive.\n", limit);
    printf(" */\n");
    printf("#define metamacro_for_cxt(COUNT, MACRO, SEP, CONTEXT) \\\n");
    printf("    metamacro_concat(metamacro_for_cxt, COUNT)(MACRO, SEP, CONTEXT)\n");
    ____(YES);
}


void print_implementation_metamacro_for_cxt(int limit)
{
    ____();
    printf("// metamacro_for_cxt expansions\n");
    printf("#define metamacro_for_cxt0(MACRO, SEP, CONTEXT)\n");
    printf("#define metamacro_for_cxt1(MACRO, SEP, CONTEXT) MACRO(0, CONTEXT)\n\n");
    
    for (int i = 2; i <= limit; ++i)
    {
        printf("#define metamacro_for_cxt%d(MACRO, SEP, CONTEXT) \\\n", i);
        printf("    metamacro_for_cxt%d(MACRO, SEP, CONTEXT) \\\n", i-1);
        printf("    SEP \\\n");
        printf("    MACRO(%d, CONTEXT)\n\n", i-1);
    }
    ____(YES);
}


#pragma mark -
#pragma mark metamacro_if_eq

void print_interface_metamacro_if_eq(int limit)
{
    ____();
    printf("/**\n");
    printf(" * If A is equal to B, the next argument list is expanded; otherwise, the\n");
    printf(" * argument list after that is expanded. A and B must be numbers between zero\n");
    printf(" * and %d, inclusive. Additionally, B must be greater than or equal to A.\n", limit);
    printf(" *\n");
    printf(" * @code\n");
    printf("\n");
    printf(" // expands to true\n");
    printf(" metamacro_if_eq(0, 0)(true)(false)\n");
    printf("\n");
    printf(" // expands to false\n");
    printf(" metamacro_if_eq(0, 1)(true)(false)\n");
    printf("\n");
    printf(" * @endcode\n");
    printf(" *\n");
    printf(" * This is primarily useful when dealing with indexes and counts in\n");
    printf(" * metaprogramming.\n");
    printf(" */\n");
    printf("#define metamacro_if_eq(A, B) \\\n");
    printf("    metamacro_concat(metamacro_if_eq, A)(B)\n");
    ____(YES);
}

void print_interface_metamacro_if_eq_recursive()
{
    ____();
    printf("/**\n");
    printf(" * Identical to #metamacro_if_eq. This can be used when the former would fail\n");
    printf(" * due to recursive macro expansion.\n");
    printf(" */\n");
    printf("#define metamacro_if_eq_recursive(A, B) \\\n");
    printf("    metamacro_concat(metamacro_if_eq_recursive, A)(B)\n");
    ____(YES);
}


void print_implementation_metamacro_if_eq(int limit, const char *suffix)
{
    ____();
    printf("// metamacro_if_eq%s expansions\n", suffix);
    printf("#define metamacro_if_eq%s0(VALUE) \\\n", suffix);
    printf("    metamacro_concat(metamacro_if_eq%s0_, VALUE)\n\n", suffix);
    
    printf("#define metamacro_if_eq%s0_0(...) __VA_ARGS__ metamacro_consume_\n", suffix);
    
    for (int i = 1; i <= limit; ++i)
    {
        printf("#define metamacro_if_eq%s0_%d(...) metamacro_expand_\n", suffix, i);
    }
    
    printf("\n");
    
    for (int i = 1; i <= limit; ++i)
    {
        printf("#define metamacro_if_eq%s%d(VALUE) metamacro_if_eq%s%d(metamacro_dec(VALUE))\n",
               suffix, i, suffix, i-1);
    }
    ____(YES);
}


#pragma mark -
#pragma mark help message

void print_help_message(void)
{
    printf("---------------------------------------------------------------------\n");
    printf("MetamacroGenerator\n");
    printf("A command-line tool which allows generating metamacros.h\n");
    printf("similar to the one included in extobjc library with variable\n");
    printf("limit on arguments count.\n\n");
    printf("See https://github.com/jspahrsummers/libextobjc for more info.\n");
    printf("Source code available at\n");
    printf("    https://github.com/wanderwaltz/MetamacroGenerator\n");
    printf("\n");
    printf("Usage:\n");
    printf("./MetamacroGenerator -limit 25 > output.h\n\n");
    printf("Prints the generated metamacros.h into stdout. Default limit\n");
    printf("value is 20 as per original metamacros.h from extobjc.\n");
    printf("Limit cannot be set to less than %d.\n", kMinLimit);
    printf("---------------------------------------------------------------------\n");
}


#pragma mark -
#pragma mark main

int main(int argc, const char * argv[])
{
    int limit = 20;
    
    // Parse the command line arguments to find the -limit parameter
    for (int i = 1; i < argc; ++i)
    {
        const char *argName = argv[i];
        
        if (strcmp(argName, "-limit") == 0)
        {
            // -limit parameter found, we should have one more arg
            if (i+1 < argc)
            {
                const char *limitText = argv[i+1];
                
                limit = atoi(limitText);
                
                // fail if limit is less than some arbitrary selected value
                if (limit < kMinLimit)
                {
                    print_help_message();
                    return 0;
                }
                else
                {
                    // increase the arg index since we've already
                    // processed the next one.
                    ++i;
                }
            }
            else
            {
                print_help_message();
                return 0;
            }
        }
        else
        {
            print_help_message();
        }
    }
    
    
    // To make sure out asserts in the print functions do not fail.
    if (limit < kMinLimit) limit = kMinLimit;
    
    NSCParameterAssert(limit >= kMinLimit);
    
    print_file_header        ();
    print_include_guard_open ();
    
    ///////////// Interfaces /////////////
    print_pragma_mark("'Interface' part, use these macros for your metaprogramming");
    
    print_metamacro_exprify                              ();
    print_interface_metamacro_stringify                  ();
    print_interface_metamacro_concat                     ();
    print_interface_metamacro_head                       ();
    print_interface_metamacro_tail                       ();
    print_interface_metamacro_at                    (limit);
    print_interface_metamacro_argcount              (limit);
    print_interface_metamacro_take                  (limit);
    print_interface_metamacro_drop                  (limit);
    print_metamacro_inc                             (limit);
    print_metamacro_dec                             (limit);
    print_metamacro_is_even                         (limit);
    print_metamacro_not                                  ();
    print_interface_metamacro_foreach_cxt           (limit);
    print_interface_metamacro_foreach_cxt_recursive (limit);
    print_interface_metamacro_foreach                    ();
    print_interface_metamacro_foreach_concat        (limit);
    print_interface_metamacro_for_cxt               (limit);
    print_interface_metamacro_if_eq                 (limit);
    print_interface_metamacro_if_eq_recursive            ();
    
    ///////////// Implementations /////////////
    print_pragma_mark("'Implementation' part, do not write code which depends on any lines below");
    
    print_implementation_metamacro_stringify           ();
    print_implementation_metamacro_concat              ();
    print_implementation_metamacro_head                ();
    print_implementation_metamacro_tail                ();
    print_implementation_metamacro_at             (limit);
    print_implementation_metamacro_argcount       (limit);
    print_implementation_metamacro_take           (limit);
    print_implementation_metamacro_drop           (limit);
    print_implementation_metamacro_foreach_cxt    (limit, "");           // metamacro_foreach_cxt
    print_implementation_metamacro_foreach_cxt    (limit, "_recursive"); // maramacro_foreach_cxt_recursive
    print_implementation_metamacro_foreach             ();
    print_implementation_metamacro_foreach_concat      ();
    print_implementation_metamacro_for_cxt        (limit);
    print_implementation_metamacro_if_eq          (limit, "");           // metamacro_if_eq
    print_implementation_metamacro_if_eq          (limit, "_recursive"); // metamacro_if_eq_recursive
    
    print_include_guard_close();
    
    return 0;
}