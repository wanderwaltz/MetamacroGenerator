//
//  main.c
//  MetamacrosGenerator
//
//  Created by Egor Chiglintsev on 19/11/13.
//  Copyright (c) 2013 Sibers. All rights reserved.
//

#include <stdio.h>
#import <Foundation/Foundation.h>

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
    NSCParameterAssert(limit >= 20);
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
    NSCParameterAssert(limit >= 20);
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
#pragma mark main

int main(int argc, const char * argv[])
{
    int limit = 20;
    
    NSCParameterAssert(limit >= 20);
    
    print_file_header();
    print_include_guard_open();
    
    ///////////// Interfaces /////////////
    print_pragma_mark("'Interface' part, use these macros for your metaprogramming");
    
    print_metamacro_exprify();
    print_interface_metamacro_stringify();
    print_interface_metamacro_concat();
    print_interface_metamacro_head();
    print_interface_metamacro_tail();
    print_interface_metamacro_at(limit);
    print_interface_metamacro_argcount(limit);
    print_interface_metamacro_take(limit);
    print_interface_metamacro_drop(limit);
    
    ///////////// Implementations /////////////
    print_pragma_mark("'Implementation' part, do not write code which depends on any lines below");
    
    print_implementation_metamacro_stringify();
    print_implementation_metamacro_concat();
    print_implementation_metamacro_head();
    print_implementation_metamacro_tail();
    print_implementation_metamacro_at(limit);
    print_implementation_metamacro_argcount(limit);
    print_implementation_metamacro_take(limit);
    print_implementation_metamacro_drop(limit);
    
    print_include_guard_close();
    
    return 0;
}