/// <copyright file="literal.h" company="Visualisierungsinstitut der Universitat Stuttgart">
/// Copyright (c) 2017 Visualisierungsinstitut der Universitat Stuttgart. Alle Rechte vorbehalten.
/// </copyright>
/// <author>Christoph Muller</author>

#pragma once


namespace datraw {
namespace detail {

    template<class T> struct literal_selector {
        typedef T char_type;
    };

    template<> struct literal_selector<char> {
        typedef char char_type;
        static const char_type select(const char n, const wchar_t w) {
            return n;
        }
        static const char_type *select(const char *n, const wchar_t *w) {
            return n;
        }
    };

    template<> struct literal_selector<wchar_t> {
        typedef wchar_t char_type;
        static const char_type select(const char n, const wchar_t w) {
            return w;
        }
        static const char_type *select(const char *n, const wchar_t *w) {
            return w;
        }
    };
}
}

#define DATRAW_TPL_LITERAL(T, l) datraw::detail::literal_selector<T>::select(l, L##l)
