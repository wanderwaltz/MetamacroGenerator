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

void print_metamacro_exprify(const char *prefix)
{
    ____();
    printf("/**\n");
    printf(" * Executes one or more expressions (which may have a void type, such as a call\n");
    printf(" * to a function that returns no value) and always returns true.\n");
    printf(" */\n");
    printf("#define %smetamacro_exprify(...) \\\n", prefix);
    printf("    ((__VA_ARGS__), true)\n");
    ____(YES);
}


#pragma mark -
#pragma mark metamacro_stringify

void print_interface_metamacro_stringify(const char *prefix)
{
    ____();
    printf("/**\n");
    printf(" * Returns a string representation of VALUE after full macro expansion.\n");
    printf(" */\n");
    printf("#define %smetamacro_stringify(VALUE) \\\n", prefix);
    printf("    %smetamacro_stringify_(VALUE)\n", prefix);
    ____(YES);
}


void print_implementation_metamacro_stringify(const char *prefix)
{
    ____();
    printf("#define %smetamacro_stringify_(VALUE) # VALUE\n", prefix);
    ____(YES);
}


#pragma mark -
#pragma mark metamacro_concat

void print_interface_metamacro_concat(const char *prefix)
{
    ____();
    printf("/**\n");
    printf(" * Returns A and B concatenated after full macro expansion.\n");
    printf(" */\n");
    printf("#define %smetamacro_concat(A, B) \\\n", prefix);
    printf("    %smetamacro_concat_(A, B)\n", prefix);
    ____(YES);
}


void print_implementation_metamacro_concat(const char *prefix)
{
    ____();
    printf("#define %smetamacro_concat_(A, B) A ## B\n", prefix);
    ____(YES);
}


#pragma mark -
#pragma mark metamacro_at

void print_interface_metamacro_at(const char *prefix, int limit)
{
    ____();
    printf("/**\n");
    printf(" * Returns the Nth variadic argument (starting from zero). At least\n");
    printf(" * N + 1 variadic arguments must be given. N must be in [0..%d].\n", limit);
    printf(" */\n");
    printf("#define %smetamacro_at(N, ...) \\\n", prefix);
    printf("    %smetamacro_concat(%smetamacro_at, N)(__VA_ARGS__)\n", prefix, prefix);
    ____(YES);
}


void print_implementation_metamacro_at(const char *prefix, int limit)
{
    ____();
    printf("// %smetamacro_at expansions\n", prefix);
    
    for (int i = 0; i <= limit; ++i)
    {
        printf("#define %smetamacro_at%d(", prefix, i);
        
        for (int arg = 0; arg < i; ++arg)
        {
            printf("_%d, ", arg);
        }
        
        printf("...) %smetamacro_head(__VA_ARGS__)\n", prefix);
    }
    ____(YES);
}


#pragma mark -
#pragma mark metamacro_argcount

void print_interface_metamacro_argcount(const char *prefix, int limit)
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
    printf("#define %smetamacro_argcount(...) \\\n", prefix);
    printf("    %smetamacro_argcount_(X, ##__VA_ARGS__, ", prefix);
    for (int i = limit; i > 0; --i)
    {
        printf("%d, ", i);
    }
    printf("0)\n");
    ____(YES);
}


void print_implementation_metamacro_argcount(const char *prefix, int limit)
{
    ____();
    printf("#define %smetamacro_argcount_(", prefix);
    for (int i = 0; i <= limit; ++i)
    {
        printf("_%d, ", i);
    }
    printf("N, ...) N\n");
    ____(YES);
}


#pragma mark -
#pragma mark metamacro_head

void print_interface_metamacro_head(const char *prefix)
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
    printf("            %smetamacro_head(__VA_ARGS__)\n", prefix);
    printf("\n");
    printf(" * @endcode\n");
    printf(" */\n");
    printf("#define %smetamacro_head(...) \\\n", prefix);
    printf("    %smetamacro_head_(__VA_ARGS__, 0)\n", prefix);
    ____(YES);
}


void print_implementation_metamacro_head(const char *prefix)
{
    ____();
    printf("#define %smetamacro_head_(FIRST, ...) FIRST\n", prefix);
    ____(YES);
}


#pragma mark -
#pragma mark metamacro_tail

void print_interface_metamacro_tail(const char *prefix)
{
    ____();
    printf("/**\n");
    printf(" * Returns every argument except the first. At least two arguments must be\n");
    printf(" * provided.\n");
    printf(" */\n");
    printf("#define %smetamacro_tail(...) \\\n", prefix);
    printf("    %smetamacro_tail_(__VA_ARGS__)\n", prefix);
    ____(YES);
}


void print_implementation_metamacro_tail(const char *prefix)
{
    ____();
    printf("#define %smetamacro_tail_(FIRST, ...) __VA_ARGS__\n", prefix);
    ____(YES);
}


#pragma mark -
#pragma mark metamacro_take

void print_interface_metamacro_take(const char *prefix, int limit)
{
    ____();
    printf("/**\n");
    printf(" * Returns the first N (up to %d) variadic arguments as a new argument list.\n", limit);
    printf(" * At least N variadic arguments must be provided.\n");
    printf(" */\n");
    printf("#define %smetamacro_take(N, ...) \\\n", prefix);
    printf("    %smetamacro_concat(%smetamacro_take, N)(__VA_ARGS__)\n", prefix, prefix);
    ____(YES);
}


void print_implementation_metamacro_take(const char *prefix, int limit)
{
    NSCParameterAssert(limit >= kMinLimit);
    ____();
    printf("// %smetamacro_take expansions\n", prefix);
    printf("#define %smetamacro_take0(...)\n", prefix);
    printf("#define %smetamacro_take1(...) %smetamacro_head(__VA_ARGS__)\n", prefix, prefix);
    for (int i = 2; i <= limit; ++i)
    {
        printf("#define %smetamacro_take%d(...) %smetamacro_head(__VA_ARGS__), ", prefix, i, prefix);
        printf("%smetamacro_take%d(%smetamacro_tail(__VA_ARGS__))\n", prefix, i-1, prefix);
    }
    ____(YES);
}


#pragma mark -
#pragma mark metamacro_drop

void print_interface_metamacro_drop(const char *prefix, int limit)
{
    ____();
    printf("/**\n");
    printf(" * Removes the first N (up to %d) variadic arguments from the given argument\n", limit);
    printf(" * list. At least N variadic arguments must be provided.\n");
    printf(" */\n");
    printf("#define %smetamacro_drop(N, ...) \\\n", prefix);
    printf("    %smetamacro_concat(%smetamacro_drop, N)(__VA_ARGS__)\n", prefix, prefix);
    ____(YES);
}


void print_implementation_metamacro_drop(const char *prefix, int limit)
{
    NSCParameterAssert(limit >= kMinLimit);
    ____();
    printf("// %smetamacro_drop expansions\n", prefix);
    printf("#define %smetamacro_drop0(...) __VA_ARGS__\n", prefix);
    printf("#define %smetamacro_drop1(...) %smetamacro_tail(__VA_ARGS__)\n", prefix, prefix);
    for (int i = 2; i <= limit; ++i)
    {
        printf("#define %smetamacro_drop%d(...) %smetamacro_drop%d(%smetamacro_tail(__VA_ARGS__))\n",
               prefix, i, prefix, i-1, prefix);
    }
    ____(YES);
}


#pragma mark -
#pragma mark metamacro_dec

void print_metamacro_dec(const char *prefix, int limit)
{
    NSCParameterAssert(limit >= kMinLimit);
    ____();
    printf("/**\n");
    printf(" * Decrements VAL, which must be a number between 0 and %d, inclusive.\n", limit);
    printf(" *\n");
    printf(" * This is primarily useful when dealing with indexes and counts in\n");
    printf(" * metaprogramming.\n");
    printf(" */\n");
    printf("#define %smetamacro_dec(VAL) \\\n", prefix);
    printf("    %smetamacro_at(VAL, ", prefix);
    
    for (int i = -1; i < limit-1; ++i)
    {
        printf("%d, ", i);
    }
    
    printf("%d)\n", limit-1);
    ____(YES);
}


#pragma mark -
#pragma mark metamacro_inc

void print_metamacro_inc(const char *prefix, int limit)
{
    ____();
    printf("/**\n");
    printf(" * Increments VAL, which must be a number between 0 and %d, inclusive.\n", limit);
    printf(" *\n");
    printf(" * This is primarily useful when dealing with indexes and counts in\n");
    printf(" * metaprogramming.\n");
    printf(" */\n");
    printf("#define %smetamacro_inc(VAL) \\\n", prefix);
    printf("    %smetamacro_at(VAL, ", prefix);
    
    for (int i = 1; i <= limit; ++i)
    {
        printf("%d, ", i);
    }
    
    printf("%d)\n", limit+1);
    ____(YES);
}


#pragma mark -
#pragma mark metamacro_is_even

void print_metamacro_is_even(const char *prefix, int limit)
{
    ____();
    printf("/**\n");
    printf(" * Returns 1 if N is an even number, or 0 otherwise.\n");
    printf(" * N must be between 0 and %d, inclusive.\n", limit);
    printf(" *\n");
    printf(" * For the purposes of this test, zero is considered even.\n");
    printf(" */\n");
    printf("#define %smetamacro_is_even(N) \\\n", prefix);
    printf("%smetamacro_at(N, ", prefix);
    
    for (int i = 0; i < limit; ++i)
    {
        printf("%d, ", (i % 2) == 0);
    }
    
    printf("%d)\n", (limit % 2) == 0);
    ____(YES);
}


#pragma mark -
#pragma mark metamacro_not

void print_metamacro_not(const char *prefix)
{
    ____();
    printf("/**\n");
    printf(" * Returns the logical NOT of B, which must be the number zero or one.\n");
    printf(" */\n");
    printf("#define %smetamacro_not(B) \\\n", prefix);
    printf("    %smetamacro_at(B, 1, 0)\n", prefix);
    ____(YES);
}


#pragma mark -
#pragma mark metamacro_foreach_cxt

void print_interface_metamacro_foreach_cxt_internal(const char *prefix, int limit, const char *suffix)
{
    printf("#define %smetamacro_foreach_cxt%s(MACRO, SEP, CONTEXT, ...) \\\n", prefix, suffix);
    printf("    %smetamacro_concat(%smetamacro_foreach_cxt%s, %smetamacro_argcount(__VA_ARGS__))(MACRO, SEP, CONTEXT, __VA_ARGS__)\n", prefix, prefix, suffix, prefix);
}


void print_interface_metamacro_foreach_cxt(const char *prefix, int limit)
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
    print_interface_metamacro_foreach_cxt_internal(prefix, limit, "");
     ____(YES);
}


void print_interface_metamacro_foreach_cxt_recursive(const char *prefix, int limit)
{
    ____();
    printf("/**\n");
    printf(" * Identical to #%smetamacro_foreach_cxt. This can be used when the former would\n", prefix);
    printf(" * fail due to recursive macro expansion.\n");
    printf(" */\n");
    print_interface_metamacro_foreach_cxt_internal(prefix, limit, "_recursive");
    ____(YES);
}


void print_implementation_metamacro_foreach_cxt(const char *prefix, int limit, const char *suffix)
{
    ____();
    printf("// %smetamacro_foreach_cxt expansions\n", prefix);
    printf("#define %smetamacro_foreach_cxt%s0(MACRO, SEP, CONTEXT)\n", prefix, suffix);
    printf("#define %smetamacro_foreach_cxt%s1(MACRO, SEP, CONTEXT, _0) MACRO(0, CONTEXT, _0)\n\n", prefix, suffix);
    
    for (int i = 2; i <= limit; ++i)
    {
        printf("#define %smetamacro_foreach_cxt%s%d(MACRO, SEP, CONTEXT, ", prefix, suffix, i);
        
        for (int arg = 0; arg < i-1; ++arg)
        {
            printf("_%d, ", arg);
        }
        
        printf("_%d) \\\n", i-1);
        
        
        printf("    %smetamacro_foreach_cxt%s%d(MACRO, SEP, CONTEXT, ", prefix, suffix, i-1);
        
        
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

void print_interface_metamacro_foreach(const char *prefix)
{
    ____();
    printf("/**\n");
    printf(" * Identical to #%smetamacro_foreach_cxt, except that no CONTEXT argument is\n", prefix);
    printf(" * given. Only the index and current argument will thus be passed to MACRO.\n");
    printf(" */\n");
    printf("#define %smetamacro_foreach(MACRO, SEP, ...) \\\n", prefix);
    printf("    %smetamacro_foreach_cxt(%smetamacro_foreach_iter, SEP, MACRO, __VA_ARGS__)\n", prefix, prefix);
    ____(YES);
}


void print_implementation_metamacro_foreach(const char *prefix)
{
    ____();
    printf("#define %smetamacro_foreach_iter(INDEX, MACRO, ARG) MACRO(INDEX, ARG)\n", prefix);
    ____(YES);
}


#pragma mark -
#pragma mark metamacro_foreach_concat

void print_interface_metamacro_foreach_concat(const char *prefix, int limit)
{
    ____();
    printf("/**\n");
    printf(" * In consecutive order, appends each variadic argument (up to %d) onto\n", limit);
    printf(" * BASE. The resulting concatenations are then separated by SEP.\n");
    printf(" *\n");
    printf(" * This is primarily useful to manipulate a list of macro invocations into instead\n");
    printf(" * invoking a different, possibly related macro.\n");
    printf(" */\n");
    printf("#define %smetamacro_foreach_concat(BASE, SEP, ...) \\\n", prefix);
    printf("    %smetamacro_foreach_cxt(%smetamacro_foreach_concat_iter, SEP, BASE, __VA_ARGS__)\n", prefix, prefix);
    ____(YES);
}


void print_implementation_metamacro_foreach_concat(const char *prefix)
{
    ____();
    printf("// implemented from scratch so that %smetamacro_concat() doesn't end up nesting\n", prefix);
    printf("#define %smetamacro_foreach_concat_iter(INDEX, BASE, ARG) %smetamacro_foreach_concat_iter_(BASE, ARG)\n", prefix, prefix);
    printf("#define %smetamacro_foreach_concat_iter_(BASE, ARG) BASE ## ARG\n", prefix);
    ____(YES);
}


#pragma mark -
#pragma mark metamacro_for_cxt

void print_interface_metamacro_for_cxt(const char *prefix, int limit)
{
    ____();
    printf("/**\n");
    printf(" * Iterates COUNT times, each time invoking MACRO with the current index\n");
    printf(" * (starting at zero) and CONTEXT. The results of adjoining invocations of MACRO\n");
    printf(" * are then separated by SEP.\n");
    printf(" *\n");
    printf(" * COUNT must be an integer between zero and %d, inclusive.\n", limit);
    printf(" */\n");
    printf("#define %smetamacro_for_cxt(COUNT, MACRO, SEP, CONTEXT) \\\n", prefix);
    printf("    %smetamacro_concat(%smetamacro_for_cxt, COUNT)(MACRO, SEP, CONTEXT)\n", prefix, prefix);
    ____(YES);
}


void print_implementation_metamacro_for_cxt(const char *prefix, int limit)
{
    ____();
    printf("// %smetamacro_for_cxt expansions\n", prefix);
    printf("#define %smetamacro_for_cxt0(MACRO, SEP, CONTEXT)\n", prefix);
    printf("#define %smetamacro_for_cxt1(MACRO, SEP, CONTEXT) MACRO(0, CONTEXT)\n\n", prefix);
    
    for (int i = 2; i <= limit; ++i)
    {
        printf("#define %smetamacro_for_cxt%d(MACRO, SEP, CONTEXT) \\\n", prefix, i);
        printf("    %smetamacro_for_cxt%d(MACRO, SEP, CONTEXT) \\\n", prefix, i-1);
        printf("    SEP \\\n");
        printf("    MACRO(%d, CONTEXT)\n\n", i-1);
    }
    ____(YES);
}


#pragma mark -
#pragma mark metamacro_if_eq

void print_interface_metamacro_if_eq(const char *prefix, int limit)
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
    printf(" %smetamacro_if_eq(0, 0)(true)(false)\n", prefix);
    printf("\n");
    printf(" // expands to false\n");
    printf(" %smetamacro_if_eq(0, 1)(true)(false)\n", prefix);
    printf("\n");
    printf(" * @endcode\n");
    printf(" *\n");
    printf(" * This is primarily useful when dealing with indexes and counts in\n");
    printf(" * metaprogramming.\n");
    printf(" */\n");
    printf("#define %smetamacro_if_eq(A, B) \\\n", prefix);
    printf("    %smetamacro_concat(%smetamacro_if_eq, A)(B)\n", prefix, prefix);
    ____(YES);
}

void print_interface_metamacro_if_eq_recursive(const char *prefix)
{
    ____();
    printf("/**\n");
    printf(" * Identical to #%smetamacro_if_eq. This can be used when the former would fail\n", prefix);
    printf(" * due to recursive macro expansion.\n");
    printf(" */\n");
    printf("#define %smetamacro_if_eq_recursive(A, B) \\\n", prefix);
    printf("    %smetamacro_concat(%smetamacro_if_eq_recursive, A)(B)\n", prefix, prefix);
    ____(YES);
}


void print_implementation_metamacro_if_eq(const char *prefix, int limit, const char *suffix)
{
    ____();
    printf("// %smetamacro_if_eq%s expansions\n", prefix, suffix);
    printf("#define %smetamacro_if_eq%s0(VALUE) \\\n", prefix, suffix);
    printf("    %smetamacro_concat(%smetamacro_if_eq%s0_, VALUE)\n\n", prefix, prefix, suffix);
    
    printf("#define %smetamacro_if_eq%s0_0(...) __VA_ARGS__ %smetamacro_consume_\n", prefix, suffix, prefix);
    
    for (int i = 1; i <= limit; ++i)
    {
        printf("#define %smetamacro_if_eq%s0_%d(...) %smetamacro_expand_\n", prefix, suffix, i, prefix);
    }
    
    printf("\n");
    
    for (int i = 1; i <= limit; ++i)
    {
        printf("#define %smetamacro_if_eq%s%d(VALUE) %smetamacro_if_eq%s%d(%smetamacro_dec(VALUE))\n",
               prefix, suffix, i, prefix, suffix, i-1, prefix);
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
#pragma mark ovrriding default metamacros

void print_override_default_metamacros(const char *prefix)
{
    ____();
    printf("/**\n");
    printf(" * By default we override names of the default extobjc metamacros\n");
    printf(" * with our own implementation. By doing that you could use this\n");
    printf(" * file without changing the extobjc library distribution and won't\n");
    printf(" * get macro redefinition warnings.\n");
    printf(" *\n");
    printf(" * You can also disable this overrides so macros defined in this\n");
    printf(" * file will form a completely separate set from the extobjc ones.\n");
    printf(" *\n");
    printf(" * (This section of the file is generated only if the prefix option\n");
    printf(" * for generated extended metamacros is set to a nonempty value)\n");
    printf(" */\n");
    ____();
    printf("\n");
    printf("#ifndef SHOULD_OVERRIDE_EXTOBJC_METAMACROS\n");
    printf("    #define SHOULD_OVERRIDE_EXTOBJC_METAMACROS 1\n");
    printf("#endif\n");
    printf("\n");
    printf("#if SHOULD_OVERRIDE_EXTOBJC_METAMACROS\n");
    printf("\n");
    printf("    #ifdef metamacro_exprify\n");
    printf("        #undef metamacro_exprify\n");
    printf("    #endif\n");
    printf("\n");
    printf("    #define metamacro_exprify %smetamacro_exprify\n", prefix);
    printf("\n");
    printf("\n");
    printf("    #ifdef metamacro_stringify\n");
    printf("        #undef metamacro_stringify\n");
    printf("    #endif\n");
    printf("\n");
    printf("    #define metamacro_stringify %smetamacro_stringify\n", prefix);
    printf("\n");
    printf("\n");
    printf("    #ifdef metamacro_concat\n");
    printf("        #undef metamacro_concat\n");
    printf("    #endif\n");
    printf("\n");
    printf("    #define metamacro_concat %smetamacro_concat\n", prefix);
    printf("\n");
    printf("\n");
    printf("    #ifdef metamacro_head\n");
    printf("        #undef metamacro_head\n");
    printf("    #endif\n");
    printf("\n");
    printf("    #define metamacro_head %smetamacro_head\n", prefix);
    printf("\n");
    printf("\n");
    printf("    #ifdef metamacro_tail\n");
    printf("        #undef metamacro_tail\n");
    printf("    #endif\n");
    printf("\n");
    printf("    #define metamacro_tail %smetamacro_tail\n", prefix);
    printf("\n");
    printf("\n");
    printf("    #ifdef metamacro_at\n");
    printf("        #undef metamacro_at\n");
    printf("    #endif\n");
    printf("\n");
    printf("    #define metamacro_at %smetamacro_at\n", prefix);
    printf("\n");
    printf("\n");
    printf("    #ifdef metamacro_argcount\n");
    printf("        #undef metamacro_argcount\n");
    printf("    #endif\n");
    printf("\n");
    printf("    #define metamacro_argcount %smetamacro_argcount\n", prefix);
    printf("\n");
    printf("\n");
    printf("    #ifdef metamacro_take\n");
    printf("        #undef metamacro_take\n");
    printf("    #endif\n");
    printf("\n");
    printf("    #define metamacro_take %smetamacro_take\n", prefix);
    printf("\n");
    printf("\n");
    printf("    #ifdef metamacro_drop\n");
    printf("        #undef metamacro_drop\n");
    printf("    #endif\n");
    printf("\n");
    printf("    #define metamacro_drop %smetamacro_drop\n", prefix);
    printf("\n");
    printf("\n");
    printf("    #ifdef metamacro_inc\n");
    printf("        #undef metamacro_inc\n");
    printf("    #endif\n");
    printf("\n");
    printf("    #define metamacro_inc %smetamacro_inc\n", prefix);
    printf("\n");
    printf("\n");
    printf("    #ifdef metamacro_dec\n");
    printf("        #undef metamacro_dec\n");
    printf("    #endif\n");
    printf("\n");
    printf("    #define metamacro_dec %smetamacro_dec\n", prefix);
    printf("\n");
    printf("\n");
    printf("    #ifdef metamacro_is_even\n");
    printf("        #undef metamacro_is_even\n");
    printf("    #endif\n");
    printf("\n");
    printf("    #define metamacro_is_even %smetamacro_is_even\n", prefix);
    printf("\n");
    printf("\n");
    printf("    #ifdef metamacro_not\n");
    printf("        #undef metamacro_not\n");
    printf("    #endif\n");
    printf("\n");
    printf("    #define metamacro_not %smetamacro_not\n", prefix);
    printf("\n");
    printf("\n");
    printf("    #ifdef metamacro_foreach_cxt\n");
    printf("        #undef metamacro_foreach_cxt\n");
    printf("    #endif\n");
    printf("\n");
    printf("    #define metamacro_foreach_cxt %smetamacro_foreach_cxt\n", prefix);
    printf("\n");
    printf("\n");
    printf("    #ifdef metamacro_foreach_cxt_recursive\n");
    printf("        #undef metamacro_foreach_cxt_recursive\n");
    printf("    #endif\n");
    printf("\n");
    printf("    #define metamacro_foreach_cxt_recursive %smetamacro_foreach_cxt_recursive\n", prefix);
    printf("\n");
    printf("\n");
    printf("    #ifdef metamacro_foreach\n");
    printf("        #undef metamacro_foreach\n");
    printf("    #endif\n");
    printf("\n");
    printf("    #define metamacro_foreach %smetamacro_foreach\n", prefix);
    printf("\n");
    printf("\n");
    printf("    #ifdef metamacro_foreach_concat\n");
    printf("        #undef metamacro_foreach_concat\n");
    printf("    #endif\n");
    printf("\n");
    printf("    #define metamacro_foreach_concat %smetamacro_foreach_concat\n", prefix);
    printf("\n");
    printf("\n");
    printf("    #ifdef metamacro_for_cxt\n");
    printf("        #undef metamacro_for_cxt\n");
    printf("    #endif\n");
    printf("\n");
    printf("    #define metamacro_for_cxt %smetamacro_for_cxt\n", prefix);
    printf("\n");
    printf("\n");
    printf("    #ifdef metamacro_if_eq\n");
    printf("        #undef metamacro_if_eq\n");
    printf("    #endif\n");
    printf("\n");
    printf("    #define metamacro_if_eq %smetamacro_if_eq\n", prefix);
    printf("\n");
    printf("\n");
    printf("    #ifdef metamacro_if_eq_recursive\n");
    printf("        #undef metamacro_if_eq_recursive\n");
    printf("    #endif\n");
    printf("\n");
    printf("    #define metamacro_if_eq_recursive %smetamacro_if_eq_recursive\n", prefix);
    printf("\n");
    printf("#endif\n");
    ____(YES);
}



#pragma mark -
#pragma mark main

int main(int argc, const char * argv[])
{
    int limit          = 20;
    const char *prefix = "";
    
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
        else if (strcmp(argName, "-prefix") == 0)
        {
            // -prefix parameter found
            if (i+1 < argc)
            {
                prefix = argv[i+1];
                // increase the arg index since we've already
                // processed the next one.
                ++i;
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
    
    if (strlen(prefix) > 0)
    {
        print_override_default_metamacros(prefix);
    }
    
    print_metamacro_exprify                         (prefix);
    print_interface_metamacro_stringify             (prefix);
    print_interface_metamacro_concat                (prefix);
    print_interface_metamacro_head                  (prefix);
    print_interface_metamacro_tail                  (prefix);
    print_interface_metamacro_at                    (prefix, limit);
    print_interface_metamacro_argcount              (prefix, limit);
    print_interface_metamacro_take                  (prefix, limit);
    print_interface_metamacro_drop                  (prefix, limit);
    print_metamacro_inc                             (prefix, limit);
    print_metamacro_dec                             (prefix, limit);
    print_metamacro_is_even                         (prefix, limit);
    print_metamacro_not                             (prefix);
    print_interface_metamacro_foreach_cxt           (prefix, limit);
    print_interface_metamacro_foreach_cxt_recursive (prefix, limit);
    print_interface_metamacro_foreach               (prefix);
    print_interface_metamacro_foreach_concat        (prefix, limit);
    print_interface_metamacro_for_cxt               (prefix, limit);
    print_interface_metamacro_if_eq                 (prefix, limit);
    print_interface_metamacro_if_eq_recursive       (prefix);
    
    ///////////// Implementations /////////////
    print_pragma_mark("'Implementation' part, do not write code which depends on any lines below");
    
    print_implementation_metamacro_stringify      (prefix);
    print_implementation_metamacro_concat         (prefix);
    print_implementation_metamacro_head           (prefix);
    print_implementation_metamacro_tail           (prefix);
    print_implementation_metamacro_at             (prefix, limit);
    print_implementation_metamacro_argcount       (prefix, limit);
    print_implementation_metamacro_take           (prefix, limit);
    print_implementation_metamacro_drop           (prefix, limit);
    print_implementation_metamacro_foreach_cxt    (prefix, limit, "");           // metamacro_foreach_cxt
    print_implementation_metamacro_foreach_cxt    (prefix, limit, "_recursive"); // maramacro_foreach_cxt_recursive
    print_implementation_metamacro_foreach        (prefix);
    print_implementation_metamacro_foreach_concat (prefix);
    print_implementation_metamacro_for_cxt        (prefix, limit);
    print_implementation_metamacro_if_eq          (prefix, limit, "");           // metamacro_if_eq
    print_implementation_metamacro_if_eq          (prefix, limit, "_recursive"); // metamacro_if_eq_recursive
    
    print_include_guard_close();
    
    return 0;
}