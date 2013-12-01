/**
 * Macros for metaprogramming
 * ExtendedC
 *
 * This file has been generated using
 * MetamacrosGenerator software.
 * Copyright (C) 2013 Egor Chiglintsev
 *
 * Source code available at
 *    https://github.com/wanderwaltz/MetamacroGenerator
 *
 * It is based on and is extending the metamacros.h
 * file included in extobjc library which can be found
 * at https://github.com/jspahrsummers/libextobjc
 *
 * Copyright (C) 2012 Justin Spahr-Summers
 * Released under the MIT license
 */


#ifndef EXTC_METAMACROS_EXTENDED_H
#define EXTC_METAMACROS_EXTENDED_H

#pragma mark -
#pragma mark 'Interface' part, use these macros for your metaprogramming

///////////////////////////////////////////////////////////////////////////////////
/**
 * By default we override names of the default extobjc metamacros
 * with our own implementation. By doing that you could use this
 * file without changing the extobjc library distribution and won't
 * get macro redefinition warnings.
 *
 * You can also disable this overrides so macros defined in this
 * file will form a completely separate set from the extobjc ones.
 *
 * (This section of the file is generated only if the prefix option
 * for generated extended metamacros is set to a nonempty value)
 */
///////////////////////////////////////////////////////////////////////////////////

#ifndef SHOULD_OVERRIDE_EXTOBJC_METAMACROS
    #define SHOULD_OVERRIDE_EXTOBJC_METAMACROS 1
#endif

#if SHOULD_OVERRIDE_EXTOBJC_METAMACROS

    #ifdef metamacro_exprify
        #undef metamacro_exprify
    #endif

    #define metamacro_exprify ww_metamacro_exprify


    #ifdef metamacro_stringify
        #undef metamacro_stringify
    #endif

    #define metamacro_stringify ww_metamacro_stringify


    #ifdef metamacro_concat
        #undef metamacro_concat
    #endif

    #define metamacro_concat ww_metamacro_concat


    #ifdef metamacro_head
        #undef metamacro_head
    #endif

    #define metamacro_head ww_metamacro_head


    #ifdef metamacro_tail
        #undef metamacro_tail
    #endif

    #define metamacro_tail ww_metamacro_tail


    #ifdef metamacro_at
        #undef metamacro_at
    #endif

    #define metamacro_at ww_metamacro_at


    #ifdef metamacro_argcount
        #undef metamacro_argcount
    #endif

    #define metamacro_argcount ww_metamacro_argcount


    #ifdef metamacro_take
        #undef metamacro_take
    #endif

    #define metamacro_take ww_metamacro_take


    #ifdef metamacro_drop
        #undef metamacro_drop
    #endif

    #define metamacro_drop ww_metamacro_drop


    #ifdef metamacro_inc
        #undef metamacro_inc
    #endif

    #define metamacro_inc ww_metamacro_inc


    #ifdef metamacro_dec
        #undef metamacro_dec
    #endif

    #define metamacro_dec ww_metamacro_dec


    #ifdef metamacro_is_even
        #undef metamacro_is_even
    #endif

    #define metamacro_is_even ww_metamacro_is_even


    #ifdef metamacro_not
        #undef metamacro_not
    #endif

    #define metamacro_not ww_metamacro_not


    #ifdef metamacro_foreach_cxt
        #undef metamacro_foreach_cxt
    #endif

    #define metamacro_foreach_cxt ww_metamacro_foreach_cxt


    #ifdef metamacro_foreach_cxt_recursive
        #undef metamacro_foreach_cxt_recursive
    #endif

    #define metamacro_foreach_cxt_recursive ww_metamacro_foreach_cxt_recursive


    #ifdef metamacro_foreach
        #undef metamacro_foreach
    #endif

    #define metamacro_foreach ww_metamacro_foreach


    #ifdef metamacro_foreach_concat
        #undef metamacro_foreach_concat
    #endif

    #define metamacro_foreach_concat ww_metamacro_foreach_concat


    #ifdef metamacro_for_cxt
        #undef metamacro_for_cxt
    #endif

    #define metamacro_for_cxt ww_metamacro_for_cxt


    #ifdef metamacro_if_eq
        #undef metamacro_if_eq
    #endif

    #define metamacro_if_eq ww_metamacro_if_eq


    #ifdef metamacro_if_eq_recursive
        #undef metamacro_if_eq_recursive
    #endif

    #define metamacro_if_eq_recursive ww_metamacro_if_eq_recursive

#endif
///////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////
/**
 * Executes one or more expressions (which may have a void type, such as a call
 * to a function that returns no value) and always returns true.
 */
#define ww_metamacro_exprify(...) \
    ((__VA_ARGS__), true)
///////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////
/**
 * Returns a string representation of VALUE after full macro expansion.
 */
#define ww_metamacro_stringify(VALUE) \
    ww_metamacro_stringify_(VALUE)
///////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////
/**
 * Returns A and B concatenated after full macro expansion.
 */
#define ww_metamacro_concat(A, B) \
    ww_metamacro_concat_(A, B)
///////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////
/**
 * Returns the first argument given. At least one argument must be provided.
 *
 * This is useful when implementing a variadic macro, where you may have only
 * one variadic argument, but no way to retrieve it (for example, because \c ...
 * always needs to match at least one argument).
 *
 * @code

        #define varmacro(...) \
            ww_metamacro_head(__VA_ARGS__)

 * @endcode
 */
#define ww_metamacro_head(...) \
    ww_metamacro_head_(__VA_ARGS__, 0)
///////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////
/**
 * Returns every argument except the first. At least two arguments must be
 * provided.
 */
#define ww_metamacro_tail(...) \
    ww_metamacro_tail_(__VA_ARGS__)
///////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////
/**
 * Returns the Nth variadic argument (starting from zero). At least
 * N + 1 variadic arguments must be given. N must be in [0..100].
 */
#define ww_metamacro_at(N, ...) \
    ww_metamacro_concat(ww_metamacro_at, N)(__VA_ARGS__)
///////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////
/**
 * Returns the number of arguments (up to 100) provided to the macro. At
 * least one argument must be provided.
 *
 * This implementation is based on ##__VA_ARGS__ extension and properly processes
 * the case with zero arguments provided.
 *
 * Based on http://stackoverflow.com/questions/11317474/macro-to-count-number-of-arguments
 */
#define ww_metamacro_argcount(...) \
    ww_metamacro_argcount_(X, ##__VA_ARGS__, 100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
///////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////
/**
 * Returns the first N (up to 100) variadic arguments as a new argument list.
 * At least N variadic arguments must be provided.
 */
#define ww_metamacro_take(N, ...) \
    ww_metamacro_concat(ww_metamacro_take, N)(__VA_ARGS__)
///////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////
/**
 * Removes the first N (up to 100) variadic arguments from the given argument
 * list. At least N variadic arguments must be provided.
 */
#define ww_metamacro_drop(N, ...) \
    ww_metamacro_concat(ww_metamacro_drop, N)(__VA_ARGS__)
///////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////
/**
 * Increments VAL, which must be a number between 0 and 100, inclusive.
 *
 * This is primarily useful when dealing with indexes and counts in
 * metaprogramming.
 */
#define ww_metamacro_inc(VAL) \
    ww_metamacro_at(VAL, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101)
///////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////
/**
 * Decrements VAL, which must be a number between 0 and 100, inclusive.
 *
 * This is primarily useful when dealing with indexes and counts in
 * metaprogramming.
 */
#define ww_metamacro_dec(VAL) \
    ww_metamacro_at(VAL, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99)
///////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////
/**
 * Returns 1 if N is an even number, or 0 otherwise.
 * N must be between 0 and 100, inclusive.
 *
 * For the purposes of this test, zero is considered even.
 */
#define ww_metamacro_is_even(N) \
ww_metamacro_at(N, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1)
///////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////
/**
 * Returns the logical NOT of B, which must be the number zero or one.
 */
#define ww_metamacro_not(B) \
    ww_metamacro_at(B, 1, 0)
///////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////
/**
 * For each consecutive variadic argument (up to 100), MACRO is passed the
 * zero-based index of the current argument, CONTEXT, and then the argument
 * itself. The results of adjoining invocations of MACRO are then separated by
 * SEP.
 *
 * Inspired by P99: http://p99.gforge.inria.fr
 */
#define ww_metamacro_foreach_cxt(MACRO, SEP, CONTEXT, ...) \
    ww_metamacro_concat(ww_metamacro_foreach_cxt, ww_metamacro_argcount(__VA_ARGS__))(MACRO, SEP, CONTEXT, __VA_ARGS__)
///////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////
/**
 * Identical to #ww_metamacro_foreach_cxt. This can be used when the former would
 * fail due to recursive macro expansion.
 */
#define ww_metamacro_foreach_cxt_recursive(MACRO, SEP, CONTEXT, ...) \
    ww_metamacro_concat(ww_metamacro_foreach_cxt_recursive, ww_metamacro_argcount(__VA_ARGS__))(MACRO, SEP, CONTEXT, __VA_ARGS__)
///////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////
/**
 * Identical to #ww_metamacro_foreach_cxt, except that no CONTEXT argument is
 * given. Only the index and current argument will thus be passed to MACRO.
 */
#define ww_metamacro_foreach(MACRO, SEP, ...) \
    ww_metamacro_foreach_cxt(ww_metamacro_foreach_iter, SEP, MACRO, __VA_ARGS__)
///////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////
/**
 * In consecutive order, appends each variadic argument (up to 100) onto
 * BASE. The resulting concatenations are then separated by SEP.
 *
 * This is primarily useful to manipulate a list of macro invocations into instead
 * invoking a different, possibly related macro.
 */
#define ww_metamacro_foreach_concat(BASE, SEP, ...) \
    ww_metamacro_foreach_cxt(ww_metamacro_foreach_concat_iter, SEP, BASE, __VA_ARGS__)
///////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////
/**
 * Iterates COUNT times, each time invoking MACRO with the current index
 * (starting at zero) and CONTEXT. The results of adjoining invocations of MACRO
 * are then separated by SEP.
 *
 * COUNT must be an integer between zero and 100, inclusive.
 */
#define ww_metamacro_for_cxt(COUNT, MACRO, SEP, CONTEXT) \
    ww_metamacro_concat(ww_metamacro_for_cxt, COUNT)(MACRO, SEP, CONTEXT)
///////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////
/**
 * If A is equal to B, the next argument list is expanded; otherwise, the
 * argument list after that is expanded. A and B must be numbers between zero
 * and 100, inclusive. Additionally, B must be greater than or equal to A.
 *
 * @code

 // expands to true
 ww_metamacro_if_eq(0, 0)(true)(false)

 // expands to false
 ww_metamacro_if_eq(0, 1)(true)(false)

 * @endcode
 *
 * This is primarily useful when dealing with indexes and counts in
 * metaprogramming.
 */
#define ww_metamacro_if_eq(A, B) \
    ww_metamacro_concat(ww_metamacro_if_eq, A)(B)
///////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////
/**
 * Identical to #ww_metamacro_if_eq. This can be used when the former would fail
 * due to recursive macro expansion.
 */
#define ww_metamacro_if_eq_recursive(A, B) \
    ww_metamacro_concat(ww_metamacro_if_eq_recursive, A)(B)
///////////////////////////////////////////////////////////////////////////////////


#pragma mark -
#pragma mark 'Implementation' part, do not write code which depends on any lines below

///////////////////////////////////////////////////////////////////////////////////
#define ww_metamacro_stringify_(VALUE) # VALUE
///////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////
#define ww_metamacro_concat_(A, B) A ## B
///////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////
#define ww_metamacro_head_(FIRST, ...) FIRST
///////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////
#define ww_metamacro_tail_(FIRST, ...) __VA_ARGS__
///////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////
// ww_metamacro_at expansions
#define ww_metamacro_at0(...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at1(_0, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at2(_0, _1, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at3(_0, _1, _2, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at4(_0, _1, _2, _3, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at5(_0, _1, _2, _3, _4, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at6(_0, _1, _2, _3, _4, _5, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at7(_0, _1, _2, _3, _4, _5, _6, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at8(_0, _1, _2, _3, _4, _5, _6, _7, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at9(_0, _1, _2, _3, _4, _5, _6, _7, _8, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at10(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at11(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at12(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at13(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at14(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at15(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at16(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at17(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at18(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at19(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at20(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at21(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at22(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at23(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at24(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at25(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at26(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at27(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at28(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at29(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at30(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at31(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at32(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at33(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at34(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at35(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at36(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at37(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at38(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at39(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at40(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at41(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at42(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at43(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at44(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at45(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at46(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at47(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at48(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at49(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at50(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at51(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at52(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at53(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at54(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at55(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at56(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at57(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at58(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at59(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at60(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at61(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at62(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at63(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at64(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at65(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at66(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at67(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at68(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at69(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at70(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at71(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at72(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at73(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at74(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at75(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at76(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at77(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at78(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at79(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at80(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at81(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at82(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at83(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at84(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at85(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at86(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at87(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at88(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at89(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at90(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at91(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at92(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at93(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at94(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at95(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at96(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at97(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95, _96, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at98(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95, _96, _97, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at99(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95, _96, _97, _98, ...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_at100(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95, _96, _97, _98, _99, ...) ww_metamacro_head(__VA_ARGS__)
///////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////
#define ww_metamacro_argcount_(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95, _96, _97, _98, _99, _100, N, ...) N
///////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////
// ww_metamacro_take expansions
#define ww_metamacro_take0(...)
#define ww_metamacro_take1(...) ww_metamacro_head(__VA_ARGS__)
#define ww_metamacro_take2(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take1(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take3(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take2(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take4(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take3(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take5(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take4(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take6(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take5(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take7(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take6(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take8(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take7(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take9(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take8(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take10(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take9(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take11(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take10(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take12(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take11(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take13(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take12(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take14(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take13(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take15(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take14(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take16(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take15(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take17(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take16(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take18(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take17(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take19(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take18(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take20(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take19(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take21(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take20(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take22(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take21(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take23(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take22(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take24(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take23(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take25(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take24(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take26(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take25(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take27(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take26(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take28(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take27(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take29(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take28(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take30(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take29(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take31(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take30(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take32(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take31(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take33(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take32(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take34(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take33(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take35(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take34(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take36(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take35(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take37(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take36(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take38(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take37(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take39(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take38(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take40(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take39(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take41(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take40(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take42(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take41(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take43(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take42(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take44(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take43(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take45(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take44(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take46(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take45(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take47(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take46(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take48(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take47(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take49(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take48(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take50(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take49(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take51(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take50(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take52(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take51(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take53(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take52(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take54(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take53(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take55(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take54(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take56(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take55(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take57(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take56(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take58(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take57(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take59(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take58(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take60(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take59(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take61(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take60(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take62(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take61(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take63(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take62(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take64(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take63(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take65(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take64(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take66(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take65(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take67(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take66(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take68(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take67(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take69(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take68(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take70(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take69(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take71(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take70(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take72(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take71(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take73(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take72(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take74(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take73(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take75(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take74(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take76(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take75(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take77(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take76(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take78(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take77(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take79(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take78(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take80(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take79(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take81(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take80(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take82(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take81(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take83(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take82(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take84(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take83(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take85(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take84(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take86(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take85(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take87(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take86(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take88(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take87(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take89(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take88(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take90(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take89(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take91(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take90(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take92(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take91(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take93(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take92(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take94(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take93(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take95(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take94(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take96(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take95(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take97(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take96(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take98(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take97(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take99(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take98(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_take100(...) ww_metamacro_head(__VA_ARGS__), ww_metamacro_take99(ww_metamacro_tail(__VA_ARGS__))
///////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////
// ww_metamacro_drop expansions
#define ww_metamacro_drop0(...) __VA_ARGS__
#define ww_metamacro_drop1(...) ww_metamacro_tail(__VA_ARGS__)
#define ww_metamacro_drop2(...) ww_metamacro_drop1(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop3(...) ww_metamacro_drop2(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop4(...) ww_metamacro_drop3(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop5(...) ww_metamacro_drop4(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop6(...) ww_metamacro_drop5(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop7(...) ww_metamacro_drop6(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop8(...) ww_metamacro_drop7(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop9(...) ww_metamacro_drop8(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop10(...) ww_metamacro_drop9(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop11(...) ww_metamacro_drop10(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop12(...) ww_metamacro_drop11(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop13(...) ww_metamacro_drop12(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop14(...) ww_metamacro_drop13(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop15(...) ww_metamacro_drop14(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop16(...) ww_metamacro_drop15(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop17(...) ww_metamacro_drop16(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop18(...) ww_metamacro_drop17(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop19(...) ww_metamacro_drop18(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop20(...) ww_metamacro_drop19(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop21(...) ww_metamacro_drop20(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop22(...) ww_metamacro_drop21(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop23(...) ww_metamacro_drop22(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop24(...) ww_metamacro_drop23(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop25(...) ww_metamacro_drop24(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop26(...) ww_metamacro_drop25(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop27(...) ww_metamacro_drop26(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop28(...) ww_metamacro_drop27(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop29(...) ww_metamacro_drop28(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop30(...) ww_metamacro_drop29(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop31(...) ww_metamacro_drop30(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop32(...) ww_metamacro_drop31(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop33(...) ww_metamacro_drop32(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop34(...) ww_metamacro_drop33(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop35(...) ww_metamacro_drop34(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop36(...) ww_metamacro_drop35(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop37(...) ww_metamacro_drop36(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop38(...) ww_metamacro_drop37(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop39(...) ww_metamacro_drop38(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop40(...) ww_metamacro_drop39(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop41(...) ww_metamacro_drop40(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop42(...) ww_metamacro_drop41(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop43(...) ww_metamacro_drop42(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop44(...) ww_metamacro_drop43(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop45(...) ww_metamacro_drop44(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop46(...) ww_metamacro_drop45(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop47(...) ww_metamacro_drop46(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop48(...) ww_metamacro_drop47(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop49(...) ww_metamacro_drop48(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop50(...) ww_metamacro_drop49(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop51(...) ww_metamacro_drop50(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop52(...) ww_metamacro_drop51(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop53(...) ww_metamacro_drop52(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop54(...) ww_metamacro_drop53(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop55(...) ww_metamacro_drop54(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop56(...) ww_metamacro_drop55(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop57(...) ww_metamacro_drop56(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop58(...) ww_metamacro_drop57(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop59(...) ww_metamacro_drop58(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop60(...) ww_metamacro_drop59(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop61(...) ww_metamacro_drop60(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop62(...) ww_metamacro_drop61(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop63(...) ww_metamacro_drop62(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop64(...) ww_metamacro_drop63(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop65(...) ww_metamacro_drop64(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop66(...) ww_metamacro_drop65(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop67(...) ww_metamacro_drop66(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop68(...) ww_metamacro_drop67(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop69(...) ww_metamacro_drop68(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop70(...) ww_metamacro_drop69(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop71(...) ww_metamacro_drop70(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop72(...) ww_metamacro_drop71(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop73(...) ww_metamacro_drop72(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop74(...) ww_metamacro_drop73(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop75(...) ww_metamacro_drop74(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop76(...) ww_metamacro_drop75(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop77(...) ww_metamacro_drop76(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop78(...) ww_metamacro_drop77(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop79(...) ww_metamacro_drop78(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop80(...) ww_metamacro_drop79(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop81(...) ww_metamacro_drop80(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop82(...) ww_metamacro_drop81(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop83(...) ww_metamacro_drop82(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop84(...) ww_metamacro_drop83(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop85(...) ww_metamacro_drop84(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop86(...) ww_metamacro_drop85(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop87(...) ww_metamacro_drop86(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop88(...) ww_metamacro_drop87(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop89(...) ww_metamacro_drop88(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop90(...) ww_metamacro_drop89(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop91(...) ww_metamacro_drop90(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop92(...) ww_metamacro_drop91(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop93(...) ww_metamacro_drop92(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop94(...) ww_metamacro_drop93(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop95(...) ww_metamacro_drop94(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop96(...) ww_metamacro_drop95(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop97(...) ww_metamacro_drop96(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop98(...) ww_metamacro_drop97(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop99(...) ww_metamacro_drop98(ww_metamacro_tail(__VA_ARGS__))
#define ww_metamacro_drop100(...) ww_metamacro_drop99(ww_metamacro_tail(__VA_ARGS__))
///////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////
// ww_metamacro_foreach_cxt expansions
#define ww_metamacro_foreach_cxt0(MACRO, SEP, CONTEXT)
#define ww_metamacro_foreach_cxt1(MACRO, SEP, CONTEXT, _0) MACRO(0, CONTEXT, _0)

#define ww_metamacro_foreach_cxt2(MACRO, SEP, CONTEXT, _0, _1) \
    ww_metamacro_foreach_cxt1(MACRO, SEP, CONTEXT, _0) \
    SEP \
    MACRO(1, CONTEXT, _1)

#define ww_metamacro_foreach_cxt3(MACRO, SEP, CONTEXT, _0, _1, _2) \
    ww_metamacro_foreach_cxt2(MACRO, SEP, CONTEXT, _0, _1) \
    SEP \
    MACRO(2, CONTEXT, _2)

#define ww_metamacro_foreach_cxt4(MACRO, SEP, CONTEXT, _0, _1, _2, _3) \
    ww_metamacro_foreach_cxt3(MACRO, SEP, CONTEXT, _0, _1, _2) \
    SEP \
    MACRO(3, CONTEXT, _3)

#define ww_metamacro_foreach_cxt5(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4) \
    ww_metamacro_foreach_cxt4(MACRO, SEP, CONTEXT, _0, _1, _2, _3) \
    SEP \
    MACRO(4, CONTEXT, _4)

#define ww_metamacro_foreach_cxt6(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5) \
    ww_metamacro_foreach_cxt5(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4) \
    SEP \
    MACRO(5, CONTEXT, _5)

#define ww_metamacro_foreach_cxt7(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6) \
    ww_metamacro_foreach_cxt6(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5) \
    SEP \
    MACRO(6, CONTEXT, _6)

#define ww_metamacro_foreach_cxt8(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7) \
    ww_metamacro_foreach_cxt7(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6) \
    SEP \
    MACRO(7, CONTEXT, _7)

#define ww_metamacro_foreach_cxt9(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8) \
    ww_metamacro_foreach_cxt8(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7) \
    SEP \
    MACRO(8, CONTEXT, _8)

#define ww_metamacro_foreach_cxt10(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9) \
    ww_metamacro_foreach_cxt9(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8) \
    SEP \
    MACRO(9, CONTEXT, _9)

#define ww_metamacro_foreach_cxt11(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10) \
    ww_metamacro_foreach_cxt10(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9) \
    SEP \
    MACRO(10, CONTEXT, _10)

#define ww_metamacro_foreach_cxt12(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11) \
    ww_metamacro_foreach_cxt11(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10) \
    SEP \
    MACRO(11, CONTEXT, _11)

#define ww_metamacro_foreach_cxt13(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12) \
    ww_metamacro_foreach_cxt12(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11) \
    SEP \
    MACRO(12, CONTEXT, _12)

#define ww_metamacro_foreach_cxt14(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13) \
    ww_metamacro_foreach_cxt13(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12) \
    SEP \
    MACRO(13, CONTEXT, _13)

#define ww_metamacro_foreach_cxt15(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14) \
    ww_metamacro_foreach_cxt14(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13) \
    SEP \
    MACRO(14, CONTEXT, _14)

#define ww_metamacro_foreach_cxt16(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15) \
    ww_metamacro_foreach_cxt15(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14) \
    SEP \
    MACRO(15, CONTEXT, _15)

#define ww_metamacro_foreach_cxt17(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16) \
    ww_metamacro_foreach_cxt16(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15) \
    SEP \
    MACRO(16, CONTEXT, _16)

#define ww_metamacro_foreach_cxt18(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17) \
    ww_metamacro_foreach_cxt17(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16) \
    SEP \
    MACRO(17, CONTEXT, _17)

#define ww_metamacro_foreach_cxt19(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18) \
    ww_metamacro_foreach_cxt18(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17) \
    SEP \
    MACRO(18, CONTEXT, _18)

#define ww_metamacro_foreach_cxt20(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19) \
    ww_metamacro_foreach_cxt19(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18) \
    SEP \
    MACRO(19, CONTEXT, _19)

#define ww_metamacro_foreach_cxt21(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20) \
    ww_metamacro_foreach_cxt20(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19) \
    SEP \
    MACRO(20, CONTEXT, _20)

#define ww_metamacro_foreach_cxt22(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21) \
    ww_metamacro_foreach_cxt21(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20) \
    SEP \
    MACRO(21, CONTEXT, _21)

#define ww_metamacro_foreach_cxt23(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22) \
    ww_metamacro_foreach_cxt22(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21) \
    SEP \
    MACRO(22, CONTEXT, _22)

#define ww_metamacro_foreach_cxt24(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23) \
    ww_metamacro_foreach_cxt23(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22) \
    SEP \
    MACRO(23, CONTEXT, _23)

#define ww_metamacro_foreach_cxt25(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24) \
    ww_metamacro_foreach_cxt24(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23) \
    SEP \
    MACRO(24, CONTEXT, _24)

#define ww_metamacro_foreach_cxt26(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25) \
    ww_metamacro_foreach_cxt25(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24) \
    SEP \
    MACRO(25, CONTEXT, _25)

#define ww_metamacro_foreach_cxt27(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26) \
    ww_metamacro_foreach_cxt26(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25) \
    SEP \
    MACRO(26, CONTEXT, _26)

#define ww_metamacro_foreach_cxt28(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27) \
    ww_metamacro_foreach_cxt27(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26) \
    SEP \
    MACRO(27, CONTEXT, _27)

#define ww_metamacro_foreach_cxt29(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28) \
    ww_metamacro_foreach_cxt28(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27) \
    SEP \
    MACRO(28, CONTEXT, _28)

#define ww_metamacro_foreach_cxt30(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29) \
    ww_metamacro_foreach_cxt29(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28) \
    SEP \
    MACRO(29, CONTEXT, _29)

#define ww_metamacro_foreach_cxt31(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30) \
    ww_metamacro_foreach_cxt30(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29) \
    SEP \
    MACRO(30, CONTEXT, _30)

#define ww_metamacro_foreach_cxt32(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31) \
    ww_metamacro_foreach_cxt31(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30) \
    SEP \
    MACRO(31, CONTEXT, _31)

#define ww_metamacro_foreach_cxt33(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32) \
    ww_metamacro_foreach_cxt32(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31) \
    SEP \
    MACRO(32, CONTEXT, _32)

#define ww_metamacro_foreach_cxt34(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33) \
    ww_metamacro_foreach_cxt33(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32) \
    SEP \
    MACRO(33, CONTEXT, _33)

#define ww_metamacro_foreach_cxt35(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34) \
    ww_metamacro_foreach_cxt34(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33) \
    SEP \
    MACRO(34, CONTEXT, _34)

#define ww_metamacro_foreach_cxt36(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35) \
    ww_metamacro_foreach_cxt35(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34) \
    SEP \
    MACRO(35, CONTEXT, _35)

#define ww_metamacro_foreach_cxt37(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36) \
    ww_metamacro_foreach_cxt36(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35) \
    SEP \
    MACRO(36, CONTEXT, _36)

#define ww_metamacro_foreach_cxt38(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37) \
    ww_metamacro_foreach_cxt37(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36) \
    SEP \
    MACRO(37, CONTEXT, _37)

#define ww_metamacro_foreach_cxt39(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38) \
    ww_metamacro_foreach_cxt38(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37) \
    SEP \
    MACRO(38, CONTEXT, _38)

#define ww_metamacro_foreach_cxt40(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39) \
    ww_metamacro_foreach_cxt39(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38) \
    SEP \
    MACRO(39, CONTEXT, _39)

#define ww_metamacro_foreach_cxt41(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40) \
    ww_metamacro_foreach_cxt40(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39) \
    SEP \
    MACRO(40, CONTEXT, _40)

#define ww_metamacro_foreach_cxt42(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41) \
    ww_metamacro_foreach_cxt41(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40) \
    SEP \
    MACRO(41, CONTEXT, _41)

#define ww_metamacro_foreach_cxt43(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42) \
    ww_metamacro_foreach_cxt42(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41) \
    SEP \
    MACRO(42, CONTEXT, _42)

#define ww_metamacro_foreach_cxt44(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43) \
    ww_metamacro_foreach_cxt43(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42) \
    SEP \
    MACRO(43, CONTEXT, _43)

#define ww_metamacro_foreach_cxt45(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44) \
    ww_metamacro_foreach_cxt44(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43) \
    SEP \
    MACRO(44, CONTEXT, _44)

#define ww_metamacro_foreach_cxt46(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45) \
    ww_metamacro_foreach_cxt45(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44) \
    SEP \
    MACRO(45, CONTEXT, _45)

#define ww_metamacro_foreach_cxt47(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46) \
    ww_metamacro_foreach_cxt46(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45) \
    SEP \
    MACRO(46, CONTEXT, _46)

#define ww_metamacro_foreach_cxt48(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47) \
    ww_metamacro_foreach_cxt47(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46) \
    SEP \
    MACRO(47, CONTEXT, _47)

#define ww_metamacro_foreach_cxt49(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48) \
    ww_metamacro_foreach_cxt48(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47) \
    SEP \
    MACRO(48, CONTEXT, _48)

#define ww_metamacro_foreach_cxt50(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49) \
    ww_metamacro_foreach_cxt49(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48) \
    SEP \
    MACRO(49, CONTEXT, _49)

#define ww_metamacro_foreach_cxt51(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50) \
    ww_metamacro_foreach_cxt50(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49) \
    SEP \
    MACRO(50, CONTEXT, _50)

#define ww_metamacro_foreach_cxt52(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51) \
    ww_metamacro_foreach_cxt51(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50) \
    SEP \
    MACRO(51, CONTEXT, _51)

#define ww_metamacro_foreach_cxt53(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52) \
    ww_metamacro_foreach_cxt52(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51) \
    SEP \
    MACRO(52, CONTEXT, _52)

#define ww_metamacro_foreach_cxt54(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53) \
    ww_metamacro_foreach_cxt53(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52) \
    SEP \
    MACRO(53, CONTEXT, _53)

#define ww_metamacro_foreach_cxt55(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54) \
    ww_metamacro_foreach_cxt54(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53) \
    SEP \
    MACRO(54, CONTEXT, _54)

#define ww_metamacro_foreach_cxt56(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55) \
    ww_metamacro_foreach_cxt55(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54) \
    SEP \
    MACRO(55, CONTEXT, _55)

#define ww_metamacro_foreach_cxt57(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56) \
    ww_metamacro_foreach_cxt56(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55) \
    SEP \
    MACRO(56, CONTEXT, _56)

#define ww_metamacro_foreach_cxt58(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57) \
    ww_metamacro_foreach_cxt57(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56) \
    SEP \
    MACRO(57, CONTEXT, _57)

#define ww_metamacro_foreach_cxt59(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58) \
    ww_metamacro_foreach_cxt58(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57) \
    SEP \
    MACRO(58, CONTEXT, _58)

#define ww_metamacro_foreach_cxt60(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59) \
    ww_metamacro_foreach_cxt59(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58) \
    SEP \
    MACRO(59, CONTEXT, _59)

#define ww_metamacro_foreach_cxt61(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60) \
    ww_metamacro_foreach_cxt60(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59) \
    SEP \
    MACRO(60, CONTEXT, _60)

#define ww_metamacro_foreach_cxt62(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61) \
    ww_metamacro_foreach_cxt61(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60) \
    SEP \
    MACRO(61, CONTEXT, _61)

#define ww_metamacro_foreach_cxt63(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62) \
    ww_metamacro_foreach_cxt62(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61) \
    SEP \
    MACRO(62, CONTEXT, _62)

#define ww_metamacro_foreach_cxt64(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63) \
    ww_metamacro_foreach_cxt63(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62) \
    SEP \
    MACRO(63, CONTEXT, _63)

#define ww_metamacro_foreach_cxt65(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64) \
    ww_metamacro_foreach_cxt64(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63) \
    SEP \
    MACRO(64, CONTEXT, _64)

#define ww_metamacro_foreach_cxt66(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65) \
    ww_metamacro_foreach_cxt65(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64) \
    SEP \
    MACRO(65, CONTEXT, _65)

#define ww_metamacro_foreach_cxt67(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66) \
    ww_metamacro_foreach_cxt66(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65) \
    SEP \
    MACRO(66, CONTEXT, _66)

#define ww_metamacro_foreach_cxt68(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67) \
    ww_metamacro_foreach_cxt67(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66) \
    SEP \
    MACRO(67, CONTEXT, _67)

#define ww_metamacro_foreach_cxt69(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68) \
    ww_metamacro_foreach_cxt68(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67) \
    SEP \
    MACRO(68, CONTEXT, _68)

#define ww_metamacro_foreach_cxt70(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69) \
    ww_metamacro_foreach_cxt69(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68) \
    SEP \
    MACRO(69, CONTEXT, _69)

#define ww_metamacro_foreach_cxt71(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70) \
    ww_metamacro_foreach_cxt70(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69) \
    SEP \
    MACRO(70, CONTEXT, _70)

#define ww_metamacro_foreach_cxt72(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71) \
    ww_metamacro_foreach_cxt71(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70) \
    SEP \
    MACRO(71, CONTEXT, _71)

#define ww_metamacro_foreach_cxt73(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72) \
    ww_metamacro_foreach_cxt72(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71) \
    SEP \
    MACRO(72, CONTEXT, _72)

#define ww_metamacro_foreach_cxt74(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73) \
    ww_metamacro_foreach_cxt73(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72) \
    SEP \
    MACRO(73, CONTEXT, _73)

#define ww_metamacro_foreach_cxt75(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74) \
    ww_metamacro_foreach_cxt74(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73) \
    SEP \
    MACRO(74, CONTEXT, _74)

#define ww_metamacro_foreach_cxt76(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75) \
    ww_metamacro_foreach_cxt75(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74) \
    SEP \
    MACRO(75, CONTEXT, _75)

#define ww_metamacro_foreach_cxt77(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76) \
    ww_metamacro_foreach_cxt76(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75) \
    SEP \
    MACRO(76, CONTEXT, _76)

#define ww_metamacro_foreach_cxt78(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77) \
    ww_metamacro_foreach_cxt77(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76) \
    SEP \
    MACRO(77, CONTEXT, _77)

#define ww_metamacro_foreach_cxt79(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78) \
    ww_metamacro_foreach_cxt78(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77) \
    SEP \
    MACRO(78, CONTEXT, _78)

#define ww_metamacro_foreach_cxt80(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79) \
    ww_metamacro_foreach_cxt79(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78) \
    SEP \
    MACRO(79, CONTEXT, _79)

#define ww_metamacro_foreach_cxt81(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80) \
    ww_metamacro_foreach_cxt80(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79) \
    SEP \
    MACRO(80, CONTEXT, _80)

#define ww_metamacro_foreach_cxt82(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81) \
    ww_metamacro_foreach_cxt81(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80) \
    SEP \
    MACRO(81, CONTEXT, _81)

#define ww_metamacro_foreach_cxt83(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82) \
    ww_metamacro_foreach_cxt82(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81) \
    SEP \
    MACRO(82, CONTEXT, _82)

#define ww_metamacro_foreach_cxt84(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83) \
    ww_metamacro_foreach_cxt83(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82) \
    SEP \
    MACRO(83, CONTEXT, _83)

#define ww_metamacro_foreach_cxt85(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84) \
    ww_metamacro_foreach_cxt84(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83) \
    SEP \
    MACRO(84, CONTEXT, _84)

#define ww_metamacro_foreach_cxt86(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85) \
    ww_metamacro_foreach_cxt85(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84) \
    SEP \
    MACRO(85, CONTEXT, _85)

#define ww_metamacro_foreach_cxt87(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86) \
    ww_metamacro_foreach_cxt86(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85) \
    SEP \
    MACRO(86, CONTEXT, _86)

#define ww_metamacro_foreach_cxt88(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87) \
    ww_metamacro_foreach_cxt87(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86) \
    SEP \
    MACRO(87, CONTEXT, _87)

#define ww_metamacro_foreach_cxt89(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88) \
    ww_metamacro_foreach_cxt88(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87) \
    SEP \
    MACRO(88, CONTEXT, _88)

#define ww_metamacro_foreach_cxt90(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89) \
    ww_metamacro_foreach_cxt89(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88) \
    SEP \
    MACRO(89, CONTEXT, _89)

#define ww_metamacro_foreach_cxt91(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90) \
    ww_metamacro_foreach_cxt90(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89) \
    SEP \
    MACRO(90, CONTEXT, _90)

#define ww_metamacro_foreach_cxt92(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91) \
    ww_metamacro_foreach_cxt91(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90) \
    SEP \
    MACRO(91, CONTEXT, _91)

#define ww_metamacro_foreach_cxt93(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92) \
    ww_metamacro_foreach_cxt92(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91) \
    SEP \
    MACRO(92, CONTEXT, _92)

#define ww_metamacro_foreach_cxt94(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93) \
    ww_metamacro_foreach_cxt93(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92) \
    SEP \
    MACRO(93, CONTEXT, _93)

#define ww_metamacro_foreach_cxt95(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94) \
    ww_metamacro_foreach_cxt94(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93) \
    SEP \
    MACRO(94, CONTEXT, _94)

#define ww_metamacro_foreach_cxt96(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95) \
    ww_metamacro_foreach_cxt95(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94) \
    SEP \
    MACRO(95, CONTEXT, _95)

#define ww_metamacro_foreach_cxt97(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95, _96) \
    ww_metamacro_foreach_cxt96(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95) \
    SEP \
    MACRO(96, CONTEXT, _96)

#define ww_metamacro_foreach_cxt98(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95, _96, _97) \
    ww_metamacro_foreach_cxt97(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95, _96) \
    SEP \
    MACRO(97, CONTEXT, _97)

#define ww_metamacro_foreach_cxt99(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95, _96, _97, _98) \
    ww_metamacro_foreach_cxt98(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95, _96, _97) \
    SEP \
    MACRO(98, CONTEXT, _98)

#define ww_metamacro_foreach_cxt100(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95, _96, _97, _98, _99) \
    ww_metamacro_foreach_cxt99(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95, _96, _97, _98) \
    SEP \
    MACRO(99, CONTEXT, _99)

///////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////
// ww_metamacro_foreach_cxt expansions
#define ww_metamacro_foreach_cxt_recursive0(MACRO, SEP, CONTEXT)
#define ww_metamacro_foreach_cxt_recursive1(MACRO, SEP, CONTEXT, _0) MACRO(0, CONTEXT, _0)

#define ww_metamacro_foreach_cxt_recursive2(MACRO, SEP, CONTEXT, _0, _1) \
    ww_metamacro_foreach_cxt_recursive1(MACRO, SEP, CONTEXT, _0) \
    SEP \
    MACRO(1, CONTEXT, _1)

#define ww_metamacro_foreach_cxt_recursive3(MACRO, SEP, CONTEXT, _0, _1, _2) \
    ww_metamacro_foreach_cxt_recursive2(MACRO, SEP, CONTEXT, _0, _1) \
    SEP \
    MACRO(2, CONTEXT, _2)

#define ww_metamacro_foreach_cxt_recursive4(MACRO, SEP, CONTEXT, _0, _1, _2, _3) \
    ww_metamacro_foreach_cxt_recursive3(MACRO, SEP, CONTEXT, _0, _1, _2) \
    SEP \
    MACRO(3, CONTEXT, _3)

#define ww_metamacro_foreach_cxt_recursive5(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4) \
    ww_metamacro_foreach_cxt_recursive4(MACRO, SEP, CONTEXT, _0, _1, _2, _3) \
    SEP \
    MACRO(4, CONTEXT, _4)

#define ww_metamacro_foreach_cxt_recursive6(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5) \
    ww_metamacro_foreach_cxt_recursive5(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4) \
    SEP \
    MACRO(5, CONTEXT, _5)

#define ww_metamacro_foreach_cxt_recursive7(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6) \
    ww_metamacro_foreach_cxt_recursive6(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5) \
    SEP \
    MACRO(6, CONTEXT, _6)

#define ww_metamacro_foreach_cxt_recursive8(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7) \
    ww_metamacro_foreach_cxt_recursive7(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6) \
    SEP \
    MACRO(7, CONTEXT, _7)

#define ww_metamacro_foreach_cxt_recursive9(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8) \
    ww_metamacro_foreach_cxt_recursive8(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7) \
    SEP \
    MACRO(8, CONTEXT, _8)

#define ww_metamacro_foreach_cxt_recursive10(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9) \
    ww_metamacro_foreach_cxt_recursive9(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8) \
    SEP \
    MACRO(9, CONTEXT, _9)

#define ww_metamacro_foreach_cxt_recursive11(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10) \
    ww_metamacro_foreach_cxt_recursive10(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9) \
    SEP \
    MACRO(10, CONTEXT, _10)

#define ww_metamacro_foreach_cxt_recursive12(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11) \
    ww_metamacro_foreach_cxt_recursive11(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10) \
    SEP \
    MACRO(11, CONTEXT, _11)

#define ww_metamacro_foreach_cxt_recursive13(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12) \
    ww_metamacro_foreach_cxt_recursive12(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11) \
    SEP \
    MACRO(12, CONTEXT, _12)

#define ww_metamacro_foreach_cxt_recursive14(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13) \
    ww_metamacro_foreach_cxt_recursive13(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12) \
    SEP \
    MACRO(13, CONTEXT, _13)

#define ww_metamacro_foreach_cxt_recursive15(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14) \
    ww_metamacro_foreach_cxt_recursive14(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13) \
    SEP \
    MACRO(14, CONTEXT, _14)

#define ww_metamacro_foreach_cxt_recursive16(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15) \
    ww_metamacro_foreach_cxt_recursive15(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14) \
    SEP \
    MACRO(15, CONTEXT, _15)

#define ww_metamacro_foreach_cxt_recursive17(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16) \
    ww_metamacro_foreach_cxt_recursive16(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15) \
    SEP \
    MACRO(16, CONTEXT, _16)

#define ww_metamacro_foreach_cxt_recursive18(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17) \
    ww_metamacro_foreach_cxt_recursive17(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16) \
    SEP \
    MACRO(17, CONTEXT, _17)

#define ww_metamacro_foreach_cxt_recursive19(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18) \
    ww_metamacro_foreach_cxt_recursive18(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17) \
    SEP \
    MACRO(18, CONTEXT, _18)

#define ww_metamacro_foreach_cxt_recursive20(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19) \
    ww_metamacro_foreach_cxt_recursive19(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18) \
    SEP \
    MACRO(19, CONTEXT, _19)

#define ww_metamacro_foreach_cxt_recursive21(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20) \
    ww_metamacro_foreach_cxt_recursive20(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19) \
    SEP \
    MACRO(20, CONTEXT, _20)

#define ww_metamacro_foreach_cxt_recursive22(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21) \
    ww_metamacro_foreach_cxt_recursive21(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20) \
    SEP \
    MACRO(21, CONTEXT, _21)

#define ww_metamacro_foreach_cxt_recursive23(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22) \
    ww_metamacro_foreach_cxt_recursive22(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21) \
    SEP \
    MACRO(22, CONTEXT, _22)

#define ww_metamacro_foreach_cxt_recursive24(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23) \
    ww_metamacro_foreach_cxt_recursive23(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22) \
    SEP \
    MACRO(23, CONTEXT, _23)

#define ww_metamacro_foreach_cxt_recursive25(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24) \
    ww_metamacro_foreach_cxt_recursive24(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23) \
    SEP \
    MACRO(24, CONTEXT, _24)

#define ww_metamacro_foreach_cxt_recursive26(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25) \
    ww_metamacro_foreach_cxt_recursive25(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24) \
    SEP \
    MACRO(25, CONTEXT, _25)

#define ww_metamacro_foreach_cxt_recursive27(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26) \
    ww_metamacro_foreach_cxt_recursive26(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25) \
    SEP \
    MACRO(26, CONTEXT, _26)

#define ww_metamacro_foreach_cxt_recursive28(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27) \
    ww_metamacro_foreach_cxt_recursive27(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26) \
    SEP \
    MACRO(27, CONTEXT, _27)

#define ww_metamacro_foreach_cxt_recursive29(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28) \
    ww_metamacro_foreach_cxt_recursive28(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27) \
    SEP \
    MACRO(28, CONTEXT, _28)

#define ww_metamacro_foreach_cxt_recursive30(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29) \
    ww_metamacro_foreach_cxt_recursive29(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28) \
    SEP \
    MACRO(29, CONTEXT, _29)

#define ww_metamacro_foreach_cxt_recursive31(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30) \
    ww_metamacro_foreach_cxt_recursive30(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29) \
    SEP \
    MACRO(30, CONTEXT, _30)

#define ww_metamacro_foreach_cxt_recursive32(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31) \
    ww_metamacro_foreach_cxt_recursive31(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30) \
    SEP \
    MACRO(31, CONTEXT, _31)

#define ww_metamacro_foreach_cxt_recursive33(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32) \
    ww_metamacro_foreach_cxt_recursive32(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31) \
    SEP \
    MACRO(32, CONTEXT, _32)

#define ww_metamacro_foreach_cxt_recursive34(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33) \
    ww_metamacro_foreach_cxt_recursive33(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32) \
    SEP \
    MACRO(33, CONTEXT, _33)

#define ww_metamacro_foreach_cxt_recursive35(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34) \
    ww_metamacro_foreach_cxt_recursive34(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33) \
    SEP \
    MACRO(34, CONTEXT, _34)

#define ww_metamacro_foreach_cxt_recursive36(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35) \
    ww_metamacro_foreach_cxt_recursive35(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34) \
    SEP \
    MACRO(35, CONTEXT, _35)

#define ww_metamacro_foreach_cxt_recursive37(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36) \
    ww_metamacro_foreach_cxt_recursive36(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35) \
    SEP \
    MACRO(36, CONTEXT, _36)

#define ww_metamacro_foreach_cxt_recursive38(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37) \
    ww_metamacro_foreach_cxt_recursive37(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36) \
    SEP \
    MACRO(37, CONTEXT, _37)

#define ww_metamacro_foreach_cxt_recursive39(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38) \
    ww_metamacro_foreach_cxt_recursive38(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37) \
    SEP \
    MACRO(38, CONTEXT, _38)

#define ww_metamacro_foreach_cxt_recursive40(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39) \
    ww_metamacro_foreach_cxt_recursive39(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38) \
    SEP \
    MACRO(39, CONTEXT, _39)

#define ww_metamacro_foreach_cxt_recursive41(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40) \
    ww_metamacro_foreach_cxt_recursive40(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39) \
    SEP \
    MACRO(40, CONTEXT, _40)

#define ww_metamacro_foreach_cxt_recursive42(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41) \
    ww_metamacro_foreach_cxt_recursive41(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40) \
    SEP \
    MACRO(41, CONTEXT, _41)

#define ww_metamacro_foreach_cxt_recursive43(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42) \
    ww_metamacro_foreach_cxt_recursive42(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41) \
    SEP \
    MACRO(42, CONTEXT, _42)

#define ww_metamacro_foreach_cxt_recursive44(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43) \
    ww_metamacro_foreach_cxt_recursive43(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42) \
    SEP \
    MACRO(43, CONTEXT, _43)

#define ww_metamacro_foreach_cxt_recursive45(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44) \
    ww_metamacro_foreach_cxt_recursive44(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43) \
    SEP \
    MACRO(44, CONTEXT, _44)

#define ww_metamacro_foreach_cxt_recursive46(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45) \
    ww_metamacro_foreach_cxt_recursive45(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44) \
    SEP \
    MACRO(45, CONTEXT, _45)

#define ww_metamacro_foreach_cxt_recursive47(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46) \
    ww_metamacro_foreach_cxt_recursive46(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45) \
    SEP \
    MACRO(46, CONTEXT, _46)

#define ww_metamacro_foreach_cxt_recursive48(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47) \
    ww_metamacro_foreach_cxt_recursive47(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46) \
    SEP \
    MACRO(47, CONTEXT, _47)

#define ww_metamacro_foreach_cxt_recursive49(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48) \
    ww_metamacro_foreach_cxt_recursive48(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47) \
    SEP \
    MACRO(48, CONTEXT, _48)

#define ww_metamacro_foreach_cxt_recursive50(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49) \
    ww_metamacro_foreach_cxt_recursive49(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48) \
    SEP \
    MACRO(49, CONTEXT, _49)

#define ww_metamacro_foreach_cxt_recursive51(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50) \
    ww_metamacro_foreach_cxt_recursive50(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49) \
    SEP \
    MACRO(50, CONTEXT, _50)

#define ww_metamacro_foreach_cxt_recursive52(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51) \
    ww_metamacro_foreach_cxt_recursive51(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50) \
    SEP \
    MACRO(51, CONTEXT, _51)

#define ww_metamacro_foreach_cxt_recursive53(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52) \
    ww_metamacro_foreach_cxt_recursive52(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51) \
    SEP \
    MACRO(52, CONTEXT, _52)

#define ww_metamacro_foreach_cxt_recursive54(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53) \
    ww_metamacro_foreach_cxt_recursive53(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52) \
    SEP \
    MACRO(53, CONTEXT, _53)

#define ww_metamacro_foreach_cxt_recursive55(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54) \
    ww_metamacro_foreach_cxt_recursive54(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53) \
    SEP \
    MACRO(54, CONTEXT, _54)

#define ww_metamacro_foreach_cxt_recursive56(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55) \
    ww_metamacro_foreach_cxt_recursive55(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54) \
    SEP \
    MACRO(55, CONTEXT, _55)

#define ww_metamacro_foreach_cxt_recursive57(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56) \
    ww_metamacro_foreach_cxt_recursive56(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55) \
    SEP \
    MACRO(56, CONTEXT, _56)

#define ww_metamacro_foreach_cxt_recursive58(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57) \
    ww_metamacro_foreach_cxt_recursive57(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56) \
    SEP \
    MACRO(57, CONTEXT, _57)

#define ww_metamacro_foreach_cxt_recursive59(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58) \
    ww_metamacro_foreach_cxt_recursive58(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57) \
    SEP \
    MACRO(58, CONTEXT, _58)

#define ww_metamacro_foreach_cxt_recursive60(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59) \
    ww_metamacro_foreach_cxt_recursive59(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58) \
    SEP \
    MACRO(59, CONTEXT, _59)

#define ww_metamacro_foreach_cxt_recursive61(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60) \
    ww_metamacro_foreach_cxt_recursive60(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59) \
    SEP \
    MACRO(60, CONTEXT, _60)

#define ww_metamacro_foreach_cxt_recursive62(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61) \
    ww_metamacro_foreach_cxt_recursive61(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60) \
    SEP \
    MACRO(61, CONTEXT, _61)

#define ww_metamacro_foreach_cxt_recursive63(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62) \
    ww_metamacro_foreach_cxt_recursive62(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61) \
    SEP \
    MACRO(62, CONTEXT, _62)

#define ww_metamacro_foreach_cxt_recursive64(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63) \
    ww_metamacro_foreach_cxt_recursive63(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62) \
    SEP \
    MACRO(63, CONTEXT, _63)

#define ww_metamacro_foreach_cxt_recursive65(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64) \
    ww_metamacro_foreach_cxt_recursive64(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63) \
    SEP \
    MACRO(64, CONTEXT, _64)

#define ww_metamacro_foreach_cxt_recursive66(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65) \
    ww_metamacro_foreach_cxt_recursive65(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64) \
    SEP \
    MACRO(65, CONTEXT, _65)

#define ww_metamacro_foreach_cxt_recursive67(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66) \
    ww_metamacro_foreach_cxt_recursive66(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65) \
    SEP \
    MACRO(66, CONTEXT, _66)

#define ww_metamacro_foreach_cxt_recursive68(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67) \
    ww_metamacro_foreach_cxt_recursive67(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66) \
    SEP \
    MACRO(67, CONTEXT, _67)

#define ww_metamacro_foreach_cxt_recursive69(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68) \
    ww_metamacro_foreach_cxt_recursive68(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67) \
    SEP \
    MACRO(68, CONTEXT, _68)

#define ww_metamacro_foreach_cxt_recursive70(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69) \
    ww_metamacro_foreach_cxt_recursive69(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68) \
    SEP \
    MACRO(69, CONTEXT, _69)

#define ww_metamacro_foreach_cxt_recursive71(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70) \
    ww_metamacro_foreach_cxt_recursive70(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69) \
    SEP \
    MACRO(70, CONTEXT, _70)

#define ww_metamacro_foreach_cxt_recursive72(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71) \
    ww_metamacro_foreach_cxt_recursive71(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70) \
    SEP \
    MACRO(71, CONTEXT, _71)

#define ww_metamacro_foreach_cxt_recursive73(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72) \
    ww_metamacro_foreach_cxt_recursive72(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71) \
    SEP \
    MACRO(72, CONTEXT, _72)

#define ww_metamacro_foreach_cxt_recursive74(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73) \
    ww_metamacro_foreach_cxt_recursive73(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72) \
    SEP \
    MACRO(73, CONTEXT, _73)

#define ww_metamacro_foreach_cxt_recursive75(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74) \
    ww_metamacro_foreach_cxt_recursive74(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73) \
    SEP \
    MACRO(74, CONTEXT, _74)

#define ww_metamacro_foreach_cxt_recursive76(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75) \
    ww_metamacro_foreach_cxt_recursive75(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74) \
    SEP \
    MACRO(75, CONTEXT, _75)

#define ww_metamacro_foreach_cxt_recursive77(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76) \
    ww_metamacro_foreach_cxt_recursive76(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75) \
    SEP \
    MACRO(76, CONTEXT, _76)

#define ww_metamacro_foreach_cxt_recursive78(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77) \
    ww_metamacro_foreach_cxt_recursive77(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76) \
    SEP \
    MACRO(77, CONTEXT, _77)

#define ww_metamacro_foreach_cxt_recursive79(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78) \
    ww_metamacro_foreach_cxt_recursive78(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77) \
    SEP \
    MACRO(78, CONTEXT, _78)

#define ww_metamacro_foreach_cxt_recursive80(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79) \
    ww_metamacro_foreach_cxt_recursive79(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78) \
    SEP \
    MACRO(79, CONTEXT, _79)

#define ww_metamacro_foreach_cxt_recursive81(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80) \
    ww_metamacro_foreach_cxt_recursive80(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79) \
    SEP \
    MACRO(80, CONTEXT, _80)

#define ww_metamacro_foreach_cxt_recursive82(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81) \
    ww_metamacro_foreach_cxt_recursive81(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80) \
    SEP \
    MACRO(81, CONTEXT, _81)

#define ww_metamacro_foreach_cxt_recursive83(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82) \
    ww_metamacro_foreach_cxt_recursive82(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81) \
    SEP \
    MACRO(82, CONTEXT, _82)

#define ww_metamacro_foreach_cxt_recursive84(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83) \
    ww_metamacro_foreach_cxt_recursive83(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82) \
    SEP \
    MACRO(83, CONTEXT, _83)

#define ww_metamacro_foreach_cxt_recursive85(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84) \
    ww_metamacro_foreach_cxt_recursive84(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83) \
    SEP \
    MACRO(84, CONTEXT, _84)

#define ww_metamacro_foreach_cxt_recursive86(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85) \
    ww_metamacro_foreach_cxt_recursive85(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84) \
    SEP \
    MACRO(85, CONTEXT, _85)

#define ww_metamacro_foreach_cxt_recursive87(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86) \
    ww_metamacro_foreach_cxt_recursive86(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85) \
    SEP \
    MACRO(86, CONTEXT, _86)

#define ww_metamacro_foreach_cxt_recursive88(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87) \
    ww_metamacro_foreach_cxt_recursive87(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86) \
    SEP \
    MACRO(87, CONTEXT, _87)

#define ww_metamacro_foreach_cxt_recursive89(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88) \
    ww_metamacro_foreach_cxt_recursive88(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87) \
    SEP \
    MACRO(88, CONTEXT, _88)

#define ww_metamacro_foreach_cxt_recursive90(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89) \
    ww_metamacro_foreach_cxt_recursive89(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88) \
    SEP \
    MACRO(89, CONTEXT, _89)

#define ww_metamacro_foreach_cxt_recursive91(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90) \
    ww_metamacro_foreach_cxt_recursive90(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89) \
    SEP \
    MACRO(90, CONTEXT, _90)

#define ww_metamacro_foreach_cxt_recursive92(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91) \
    ww_metamacro_foreach_cxt_recursive91(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90) \
    SEP \
    MACRO(91, CONTEXT, _91)

#define ww_metamacro_foreach_cxt_recursive93(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92) \
    ww_metamacro_foreach_cxt_recursive92(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91) \
    SEP \
    MACRO(92, CONTEXT, _92)

#define ww_metamacro_foreach_cxt_recursive94(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93) \
    ww_metamacro_foreach_cxt_recursive93(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92) \
    SEP \
    MACRO(93, CONTEXT, _93)

#define ww_metamacro_foreach_cxt_recursive95(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94) \
    ww_metamacro_foreach_cxt_recursive94(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93) \
    SEP \
    MACRO(94, CONTEXT, _94)

#define ww_metamacro_foreach_cxt_recursive96(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95) \
    ww_metamacro_foreach_cxt_recursive95(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94) \
    SEP \
    MACRO(95, CONTEXT, _95)

#define ww_metamacro_foreach_cxt_recursive97(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95, _96) \
    ww_metamacro_foreach_cxt_recursive96(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95) \
    SEP \
    MACRO(96, CONTEXT, _96)

#define ww_metamacro_foreach_cxt_recursive98(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95, _96, _97) \
    ww_metamacro_foreach_cxt_recursive97(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95, _96) \
    SEP \
    MACRO(97, CONTEXT, _97)

#define ww_metamacro_foreach_cxt_recursive99(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95, _96, _97, _98) \
    ww_metamacro_foreach_cxt_recursive98(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95, _96, _97) \
    SEP \
    MACRO(98, CONTEXT, _98)

#define ww_metamacro_foreach_cxt_recursive100(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95, _96, _97, _98, _99) \
    ww_metamacro_foreach_cxt_recursive99(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95, _96, _97, _98) \
    SEP \
    MACRO(99, CONTEXT, _99)

///////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////
#define ww_metamacro_foreach_iter(INDEX, MACRO, ARG) MACRO(INDEX, ARG)
///////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////
// implemented from scratch so that ww_metamacro_concat() doesn't end up nesting
#define ww_metamacro_foreach_concat_iter(INDEX, BASE, ARG) ww_metamacro_foreach_concat_iter_(BASE, ARG)
#define ww_metamacro_foreach_concat_iter_(BASE, ARG) BASE ## ARG
///////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////
// ww_metamacro_for_cxt expansions
#define ww_metamacro_for_cxt0(MACRO, SEP, CONTEXT)
#define ww_metamacro_for_cxt1(MACRO, SEP, CONTEXT) MACRO(0, CONTEXT)

#define ww_metamacro_for_cxt2(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt1(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(1, CONTEXT)

#define ww_metamacro_for_cxt3(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt2(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(2, CONTEXT)

#define ww_metamacro_for_cxt4(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt3(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(3, CONTEXT)

#define ww_metamacro_for_cxt5(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt4(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(4, CONTEXT)

#define ww_metamacro_for_cxt6(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt5(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(5, CONTEXT)

#define ww_metamacro_for_cxt7(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt6(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(6, CONTEXT)

#define ww_metamacro_for_cxt8(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt7(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(7, CONTEXT)

#define ww_metamacro_for_cxt9(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt8(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(8, CONTEXT)

#define ww_metamacro_for_cxt10(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt9(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(9, CONTEXT)

#define ww_metamacro_for_cxt11(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt10(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(10, CONTEXT)

#define ww_metamacro_for_cxt12(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt11(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(11, CONTEXT)

#define ww_metamacro_for_cxt13(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt12(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(12, CONTEXT)

#define ww_metamacro_for_cxt14(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt13(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(13, CONTEXT)

#define ww_metamacro_for_cxt15(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt14(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(14, CONTEXT)

#define ww_metamacro_for_cxt16(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt15(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(15, CONTEXT)

#define ww_metamacro_for_cxt17(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt16(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(16, CONTEXT)

#define ww_metamacro_for_cxt18(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt17(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(17, CONTEXT)

#define ww_metamacro_for_cxt19(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt18(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(18, CONTEXT)

#define ww_metamacro_for_cxt20(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt19(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(19, CONTEXT)

#define ww_metamacro_for_cxt21(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt20(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(20, CONTEXT)

#define ww_metamacro_for_cxt22(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt21(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(21, CONTEXT)

#define ww_metamacro_for_cxt23(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt22(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(22, CONTEXT)

#define ww_metamacro_for_cxt24(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt23(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(23, CONTEXT)

#define ww_metamacro_for_cxt25(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt24(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(24, CONTEXT)

#define ww_metamacro_for_cxt26(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt25(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(25, CONTEXT)

#define ww_metamacro_for_cxt27(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt26(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(26, CONTEXT)

#define ww_metamacro_for_cxt28(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt27(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(27, CONTEXT)

#define ww_metamacro_for_cxt29(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt28(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(28, CONTEXT)

#define ww_metamacro_for_cxt30(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt29(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(29, CONTEXT)

#define ww_metamacro_for_cxt31(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt30(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(30, CONTEXT)

#define ww_metamacro_for_cxt32(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt31(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(31, CONTEXT)

#define ww_metamacro_for_cxt33(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt32(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(32, CONTEXT)

#define ww_metamacro_for_cxt34(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt33(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(33, CONTEXT)

#define ww_metamacro_for_cxt35(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt34(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(34, CONTEXT)

#define ww_metamacro_for_cxt36(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt35(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(35, CONTEXT)

#define ww_metamacro_for_cxt37(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt36(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(36, CONTEXT)

#define ww_metamacro_for_cxt38(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt37(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(37, CONTEXT)

#define ww_metamacro_for_cxt39(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt38(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(38, CONTEXT)

#define ww_metamacro_for_cxt40(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt39(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(39, CONTEXT)

#define ww_metamacro_for_cxt41(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt40(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(40, CONTEXT)

#define ww_metamacro_for_cxt42(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt41(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(41, CONTEXT)

#define ww_metamacro_for_cxt43(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt42(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(42, CONTEXT)

#define ww_metamacro_for_cxt44(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt43(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(43, CONTEXT)

#define ww_metamacro_for_cxt45(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt44(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(44, CONTEXT)

#define ww_metamacro_for_cxt46(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt45(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(45, CONTEXT)

#define ww_metamacro_for_cxt47(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt46(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(46, CONTEXT)

#define ww_metamacro_for_cxt48(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt47(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(47, CONTEXT)

#define ww_metamacro_for_cxt49(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt48(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(48, CONTEXT)

#define ww_metamacro_for_cxt50(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt49(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(49, CONTEXT)

#define ww_metamacro_for_cxt51(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt50(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(50, CONTEXT)

#define ww_metamacro_for_cxt52(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt51(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(51, CONTEXT)

#define ww_metamacro_for_cxt53(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt52(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(52, CONTEXT)

#define ww_metamacro_for_cxt54(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt53(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(53, CONTEXT)

#define ww_metamacro_for_cxt55(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt54(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(54, CONTEXT)

#define ww_metamacro_for_cxt56(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt55(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(55, CONTEXT)

#define ww_metamacro_for_cxt57(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt56(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(56, CONTEXT)

#define ww_metamacro_for_cxt58(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt57(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(57, CONTEXT)

#define ww_metamacro_for_cxt59(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt58(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(58, CONTEXT)

#define ww_metamacro_for_cxt60(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt59(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(59, CONTEXT)

#define ww_metamacro_for_cxt61(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt60(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(60, CONTEXT)

#define ww_metamacro_for_cxt62(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt61(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(61, CONTEXT)

#define ww_metamacro_for_cxt63(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt62(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(62, CONTEXT)

#define ww_metamacro_for_cxt64(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt63(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(63, CONTEXT)

#define ww_metamacro_for_cxt65(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt64(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(64, CONTEXT)

#define ww_metamacro_for_cxt66(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt65(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(65, CONTEXT)

#define ww_metamacro_for_cxt67(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt66(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(66, CONTEXT)

#define ww_metamacro_for_cxt68(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt67(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(67, CONTEXT)

#define ww_metamacro_for_cxt69(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt68(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(68, CONTEXT)

#define ww_metamacro_for_cxt70(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt69(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(69, CONTEXT)

#define ww_metamacro_for_cxt71(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt70(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(70, CONTEXT)

#define ww_metamacro_for_cxt72(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt71(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(71, CONTEXT)

#define ww_metamacro_for_cxt73(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt72(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(72, CONTEXT)

#define ww_metamacro_for_cxt74(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt73(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(73, CONTEXT)

#define ww_metamacro_for_cxt75(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt74(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(74, CONTEXT)

#define ww_metamacro_for_cxt76(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt75(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(75, CONTEXT)

#define ww_metamacro_for_cxt77(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt76(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(76, CONTEXT)

#define ww_metamacro_for_cxt78(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt77(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(77, CONTEXT)

#define ww_metamacro_for_cxt79(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt78(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(78, CONTEXT)

#define ww_metamacro_for_cxt80(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt79(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(79, CONTEXT)

#define ww_metamacro_for_cxt81(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt80(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(80, CONTEXT)

#define ww_metamacro_for_cxt82(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt81(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(81, CONTEXT)

#define ww_metamacro_for_cxt83(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt82(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(82, CONTEXT)

#define ww_metamacro_for_cxt84(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt83(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(83, CONTEXT)

#define ww_metamacro_for_cxt85(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt84(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(84, CONTEXT)

#define ww_metamacro_for_cxt86(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt85(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(85, CONTEXT)

#define ww_metamacro_for_cxt87(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt86(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(86, CONTEXT)

#define ww_metamacro_for_cxt88(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt87(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(87, CONTEXT)

#define ww_metamacro_for_cxt89(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt88(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(88, CONTEXT)

#define ww_metamacro_for_cxt90(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt89(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(89, CONTEXT)

#define ww_metamacro_for_cxt91(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt90(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(90, CONTEXT)

#define ww_metamacro_for_cxt92(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt91(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(91, CONTEXT)

#define ww_metamacro_for_cxt93(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt92(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(92, CONTEXT)

#define ww_metamacro_for_cxt94(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt93(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(93, CONTEXT)

#define ww_metamacro_for_cxt95(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt94(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(94, CONTEXT)

#define ww_metamacro_for_cxt96(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt95(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(95, CONTEXT)

#define ww_metamacro_for_cxt97(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt96(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(96, CONTEXT)

#define ww_metamacro_for_cxt98(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt97(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(97, CONTEXT)

#define ww_metamacro_for_cxt99(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt98(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(98, CONTEXT)

#define ww_metamacro_for_cxt100(MACRO, SEP, CONTEXT) \
    ww_metamacro_for_cxt99(MACRO, SEP, CONTEXT) \
    SEP \
    MACRO(99, CONTEXT)

///////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////
// ww_metamacro_if_eq expansions
#define ww_metamacro_if_eq0(VALUE) \
    ww_metamacro_concat(ww_metamacro_if_eq0_, VALUE)

#define ww_metamacro_if_eq0_0(...) __VA_ARGS__ ww_metamacro_consume_
#define ww_metamacro_if_eq0_1(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_2(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_3(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_4(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_5(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_6(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_7(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_8(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_9(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_10(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_11(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_12(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_13(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_14(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_15(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_16(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_17(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_18(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_19(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_20(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_21(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_22(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_23(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_24(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_25(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_26(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_27(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_28(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_29(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_30(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_31(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_32(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_33(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_34(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_35(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_36(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_37(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_38(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_39(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_40(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_41(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_42(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_43(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_44(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_45(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_46(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_47(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_48(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_49(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_50(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_51(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_52(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_53(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_54(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_55(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_56(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_57(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_58(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_59(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_60(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_61(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_62(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_63(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_64(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_65(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_66(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_67(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_68(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_69(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_70(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_71(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_72(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_73(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_74(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_75(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_76(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_77(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_78(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_79(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_80(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_81(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_82(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_83(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_84(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_85(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_86(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_87(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_88(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_89(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_90(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_91(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_92(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_93(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_94(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_95(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_96(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_97(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_98(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_99(...) ww_metamacro_expand_
#define ww_metamacro_if_eq0_100(...) ww_metamacro_expand_

#define ww_metamacro_if_eq1(VALUE) ww_metamacro_if_eq0(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq2(VALUE) ww_metamacro_if_eq1(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq3(VALUE) ww_metamacro_if_eq2(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq4(VALUE) ww_metamacro_if_eq3(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq5(VALUE) ww_metamacro_if_eq4(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq6(VALUE) ww_metamacro_if_eq5(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq7(VALUE) ww_metamacro_if_eq6(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq8(VALUE) ww_metamacro_if_eq7(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq9(VALUE) ww_metamacro_if_eq8(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq10(VALUE) ww_metamacro_if_eq9(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq11(VALUE) ww_metamacro_if_eq10(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq12(VALUE) ww_metamacro_if_eq11(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq13(VALUE) ww_metamacro_if_eq12(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq14(VALUE) ww_metamacro_if_eq13(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq15(VALUE) ww_metamacro_if_eq14(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq16(VALUE) ww_metamacro_if_eq15(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq17(VALUE) ww_metamacro_if_eq16(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq18(VALUE) ww_metamacro_if_eq17(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq19(VALUE) ww_metamacro_if_eq18(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq20(VALUE) ww_metamacro_if_eq19(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq21(VALUE) ww_metamacro_if_eq20(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq22(VALUE) ww_metamacro_if_eq21(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq23(VALUE) ww_metamacro_if_eq22(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq24(VALUE) ww_metamacro_if_eq23(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq25(VALUE) ww_metamacro_if_eq24(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq26(VALUE) ww_metamacro_if_eq25(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq27(VALUE) ww_metamacro_if_eq26(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq28(VALUE) ww_metamacro_if_eq27(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq29(VALUE) ww_metamacro_if_eq28(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq30(VALUE) ww_metamacro_if_eq29(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq31(VALUE) ww_metamacro_if_eq30(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq32(VALUE) ww_metamacro_if_eq31(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq33(VALUE) ww_metamacro_if_eq32(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq34(VALUE) ww_metamacro_if_eq33(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq35(VALUE) ww_metamacro_if_eq34(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq36(VALUE) ww_metamacro_if_eq35(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq37(VALUE) ww_metamacro_if_eq36(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq38(VALUE) ww_metamacro_if_eq37(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq39(VALUE) ww_metamacro_if_eq38(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq40(VALUE) ww_metamacro_if_eq39(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq41(VALUE) ww_metamacro_if_eq40(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq42(VALUE) ww_metamacro_if_eq41(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq43(VALUE) ww_metamacro_if_eq42(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq44(VALUE) ww_metamacro_if_eq43(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq45(VALUE) ww_metamacro_if_eq44(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq46(VALUE) ww_metamacro_if_eq45(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq47(VALUE) ww_metamacro_if_eq46(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq48(VALUE) ww_metamacro_if_eq47(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq49(VALUE) ww_metamacro_if_eq48(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq50(VALUE) ww_metamacro_if_eq49(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq51(VALUE) ww_metamacro_if_eq50(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq52(VALUE) ww_metamacro_if_eq51(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq53(VALUE) ww_metamacro_if_eq52(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq54(VALUE) ww_metamacro_if_eq53(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq55(VALUE) ww_metamacro_if_eq54(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq56(VALUE) ww_metamacro_if_eq55(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq57(VALUE) ww_metamacro_if_eq56(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq58(VALUE) ww_metamacro_if_eq57(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq59(VALUE) ww_metamacro_if_eq58(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq60(VALUE) ww_metamacro_if_eq59(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq61(VALUE) ww_metamacro_if_eq60(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq62(VALUE) ww_metamacro_if_eq61(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq63(VALUE) ww_metamacro_if_eq62(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq64(VALUE) ww_metamacro_if_eq63(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq65(VALUE) ww_metamacro_if_eq64(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq66(VALUE) ww_metamacro_if_eq65(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq67(VALUE) ww_metamacro_if_eq66(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq68(VALUE) ww_metamacro_if_eq67(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq69(VALUE) ww_metamacro_if_eq68(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq70(VALUE) ww_metamacro_if_eq69(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq71(VALUE) ww_metamacro_if_eq70(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq72(VALUE) ww_metamacro_if_eq71(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq73(VALUE) ww_metamacro_if_eq72(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq74(VALUE) ww_metamacro_if_eq73(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq75(VALUE) ww_metamacro_if_eq74(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq76(VALUE) ww_metamacro_if_eq75(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq77(VALUE) ww_metamacro_if_eq76(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq78(VALUE) ww_metamacro_if_eq77(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq79(VALUE) ww_metamacro_if_eq78(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq80(VALUE) ww_metamacro_if_eq79(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq81(VALUE) ww_metamacro_if_eq80(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq82(VALUE) ww_metamacro_if_eq81(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq83(VALUE) ww_metamacro_if_eq82(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq84(VALUE) ww_metamacro_if_eq83(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq85(VALUE) ww_metamacro_if_eq84(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq86(VALUE) ww_metamacro_if_eq85(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq87(VALUE) ww_metamacro_if_eq86(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq88(VALUE) ww_metamacro_if_eq87(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq89(VALUE) ww_metamacro_if_eq88(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq90(VALUE) ww_metamacro_if_eq89(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq91(VALUE) ww_metamacro_if_eq90(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq92(VALUE) ww_metamacro_if_eq91(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq93(VALUE) ww_metamacro_if_eq92(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq94(VALUE) ww_metamacro_if_eq93(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq95(VALUE) ww_metamacro_if_eq94(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq96(VALUE) ww_metamacro_if_eq95(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq97(VALUE) ww_metamacro_if_eq96(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq98(VALUE) ww_metamacro_if_eq97(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq99(VALUE) ww_metamacro_if_eq98(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq100(VALUE) ww_metamacro_if_eq99(ww_metamacro_dec(VALUE))
///////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////
// ww_metamacro_if_eq_recursive expansions
#define ww_metamacro_if_eq_recursive0(VALUE) \
    ww_metamacro_concat(ww_metamacro_if_eq_recursive0_, VALUE)

#define ww_metamacro_if_eq_recursive0_0(...) __VA_ARGS__ ww_metamacro_consume_
#define ww_metamacro_if_eq_recursive0_1(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_2(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_3(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_4(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_5(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_6(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_7(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_8(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_9(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_10(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_11(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_12(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_13(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_14(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_15(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_16(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_17(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_18(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_19(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_20(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_21(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_22(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_23(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_24(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_25(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_26(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_27(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_28(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_29(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_30(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_31(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_32(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_33(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_34(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_35(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_36(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_37(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_38(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_39(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_40(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_41(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_42(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_43(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_44(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_45(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_46(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_47(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_48(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_49(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_50(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_51(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_52(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_53(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_54(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_55(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_56(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_57(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_58(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_59(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_60(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_61(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_62(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_63(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_64(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_65(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_66(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_67(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_68(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_69(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_70(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_71(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_72(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_73(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_74(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_75(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_76(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_77(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_78(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_79(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_80(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_81(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_82(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_83(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_84(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_85(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_86(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_87(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_88(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_89(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_90(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_91(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_92(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_93(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_94(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_95(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_96(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_97(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_98(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_99(...) ww_metamacro_expand_
#define ww_metamacro_if_eq_recursive0_100(...) ww_metamacro_expand_

#define ww_metamacro_if_eq_recursive1(VALUE) ww_metamacro_if_eq_recursive0(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive2(VALUE) ww_metamacro_if_eq_recursive1(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive3(VALUE) ww_metamacro_if_eq_recursive2(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive4(VALUE) ww_metamacro_if_eq_recursive3(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive5(VALUE) ww_metamacro_if_eq_recursive4(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive6(VALUE) ww_metamacro_if_eq_recursive5(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive7(VALUE) ww_metamacro_if_eq_recursive6(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive8(VALUE) ww_metamacro_if_eq_recursive7(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive9(VALUE) ww_metamacro_if_eq_recursive8(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive10(VALUE) ww_metamacro_if_eq_recursive9(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive11(VALUE) ww_metamacro_if_eq_recursive10(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive12(VALUE) ww_metamacro_if_eq_recursive11(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive13(VALUE) ww_metamacro_if_eq_recursive12(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive14(VALUE) ww_metamacro_if_eq_recursive13(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive15(VALUE) ww_metamacro_if_eq_recursive14(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive16(VALUE) ww_metamacro_if_eq_recursive15(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive17(VALUE) ww_metamacro_if_eq_recursive16(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive18(VALUE) ww_metamacro_if_eq_recursive17(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive19(VALUE) ww_metamacro_if_eq_recursive18(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive20(VALUE) ww_metamacro_if_eq_recursive19(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive21(VALUE) ww_metamacro_if_eq_recursive20(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive22(VALUE) ww_metamacro_if_eq_recursive21(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive23(VALUE) ww_metamacro_if_eq_recursive22(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive24(VALUE) ww_metamacro_if_eq_recursive23(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive25(VALUE) ww_metamacro_if_eq_recursive24(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive26(VALUE) ww_metamacro_if_eq_recursive25(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive27(VALUE) ww_metamacro_if_eq_recursive26(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive28(VALUE) ww_metamacro_if_eq_recursive27(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive29(VALUE) ww_metamacro_if_eq_recursive28(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive30(VALUE) ww_metamacro_if_eq_recursive29(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive31(VALUE) ww_metamacro_if_eq_recursive30(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive32(VALUE) ww_metamacro_if_eq_recursive31(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive33(VALUE) ww_metamacro_if_eq_recursive32(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive34(VALUE) ww_metamacro_if_eq_recursive33(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive35(VALUE) ww_metamacro_if_eq_recursive34(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive36(VALUE) ww_metamacro_if_eq_recursive35(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive37(VALUE) ww_metamacro_if_eq_recursive36(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive38(VALUE) ww_metamacro_if_eq_recursive37(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive39(VALUE) ww_metamacro_if_eq_recursive38(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive40(VALUE) ww_metamacro_if_eq_recursive39(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive41(VALUE) ww_metamacro_if_eq_recursive40(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive42(VALUE) ww_metamacro_if_eq_recursive41(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive43(VALUE) ww_metamacro_if_eq_recursive42(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive44(VALUE) ww_metamacro_if_eq_recursive43(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive45(VALUE) ww_metamacro_if_eq_recursive44(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive46(VALUE) ww_metamacro_if_eq_recursive45(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive47(VALUE) ww_metamacro_if_eq_recursive46(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive48(VALUE) ww_metamacro_if_eq_recursive47(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive49(VALUE) ww_metamacro_if_eq_recursive48(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive50(VALUE) ww_metamacro_if_eq_recursive49(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive51(VALUE) ww_metamacro_if_eq_recursive50(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive52(VALUE) ww_metamacro_if_eq_recursive51(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive53(VALUE) ww_metamacro_if_eq_recursive52(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive54(VALUE) ww_metamacro_if_eq_recursive53(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive55(VALUE) ww_metamacro_if_eq_recursive54(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive56(VALUE) ww_metamacro_if_eq_recursive55(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive57(VALUE) ww_metamacro_if_eq_recursive56(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive58(VALUE) ww_metamacro_if_eq_recursive57(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive59(VALUE) ww_metamacro_if_eq_recursive58(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive60(VALUE) ww_metamacro_if_eq_recursive59(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive61(VALUE) ww_metamacro_if_eq_recursive60(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive62(VALUE) ww_metamacro_if_eq_recursive61(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive63(VALUE) ww_metamacro_if_eq_recursive62(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive64(VALUE) ww_metamacro_if_eq_recursive63(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive65(VALUE) ww_metamacro_if_eq_recursive64(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive66(VALUE) ww_metamacro_if_eq_recursive65(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive67(VALUE) ww_metamacro_if_eq_recursive66(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive68(VALUE) ww_metamacro_if_eq_recursive67(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive69(VALUE) ww_metamacro_if_eq_recursive68(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive70(VALUE) ww_metamacro_if_eq_recursive69(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive71(VALUE) ww_metamacro_if_eq_recursive70(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive72(VALUE) ww_metamacro_if_eq_recursive71(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive73(VALUE) ww_metamacro_if_eq_recursive72(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive74(VALUE) ww_metamacro_if_eq_recursive73(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive75(VALUE) ww_metamacro_if_eq_recursive74(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive76(VALUE) ww_metamacro_if_eq_recursive75(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive77(VALUE) ww_metamacro_if_eq_recursive76(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive78(VALUE) ww_metamacro_if_eq_recursive77(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive79(VALUE) ww_metamacro_if_eq_recursive78(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive80(VALUE) ww_metamacro_if_eq_recursive79(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive81(VALUE) ww_metamacro_if_eq_recursive80(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive82(VALUE) ww_metamacro_if_eq_recursive81(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive83(VALUE) ww_metamacro_if_eq_recursive82(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive84(VALUE) ww_metamacro_if_eq_recursive83(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive85(VALUE) ww_metamacro_if_eq_recursive84(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive86(VALUE) ww_metamacro_if_eq_recursive85(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive87(VALUE) ww_metamacro_if_eq_recursive86(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive88(VALUE) ww_metamacro_if_eq_recursive87(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive89(VALUE) ww_metamacro_if_eq_recursive88(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive90(VALUE) ww_metamacro_if_eq_recursive89(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive91(VALUE) ww_metamacro_if_eq_recursive90(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive92(VALUE) ww_metamacro_if_eq_recursive91(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive93(VALUE) ww_metamacro_if_eq_recursive92(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive94(VALUE) ww_metamacro_if_eq_recursive93(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive95(VALUE) ww_metamacro_if_eq_recursive94(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive96(VALUE) ww_metamacro_if_eq_recursive95(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive97(VALUE) ww_metamacro_if_eq_recursive96(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive98(VALUE) ww_metamacro_if_eq_recursive97(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive99(VALUE) ww_metamacro_if_eq_recursive98(ww_metamacro_dec(VALUE))
#define ww_metamacro_if_eq_recursive100(VALUE) ww_metamacro_if_eq_recursive99(ww_metamacro_dec(VALUE))
///////////////////////////////////////////////////////////////////////////////////


#endif // #ifndef EXTC_METAMACROS_EXTENDED_H
