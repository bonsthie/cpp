/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:37:26 by babonnet          #+#    #+#             */
/*   Updated: 2024/07/06 15:04:35 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if defined(__AVX2__) || defined(__SSE2__)

#include <immintrin.h>

#if defined(__clang__) || defined(__GNUC__)
#	define TYPE_ALIGN __attribute__((aligned(SIZE))) TYPE
#	define INLINE __attribute__((always_inline)) inline
#elif defined(_MSC_VER)
#	define TYPE_ALIGN __declspec(align(SIZE)) TYPE
#	define INLINE __forceinline
#else
#	define TYPE_ALIGN TYPE
#	define INLINE inline
#endif

INLINE TYPE islower_epi8(TYPE data) {
    static const TYPE_ALIGN A_MASK = TAG(set1_epi8)('a' - 1);
    static const TYPE_ALIGN Z_MASK = TAG(set1_epi8)('z');
    return TAG_SI(and)(TAG(cmpgt_epi8)(data, A_MASK), TAG(cmpgt_epi8)(Z_MASK, data));
}

INLINE TYPE mask_toupper_epi8(TYPE data) {
    static const TYPE_ALIGN SUB_MASK = TAG(set1_epi8)(32);
    TYPE_ALIGN mask = islower_epi8(data);
    TYPE_ALIGN lower_to_upper = TAG(sub_epi8)(data, SUB_MASK);
    return TAG(blendv_epi8)(data, lower_to_upper, mask);
}

INLINE void TAG(toupper_epi8)(char *str, size_t *i, size_t len) {
    for (; *i + SIZE <= len; *i += SIZE) {
        TYPE_ALIGN data = TAG_SI(loadu)((TYPE *)(str + *i));
        data = mask_toupper_epi8(data);
        TAG_SI(storeu)((TYPE *)(str + *i), data);
    }
}

#undef TAG
#undef TAG_SI
#undef TYPE
#undef SIZE

#endif
