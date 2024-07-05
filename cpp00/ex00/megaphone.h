/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:37:26 by babonnet          #+#    #+#             */
/*   Updated: 2024/07/06 01:29:30 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if defined(__AVX2__) || defined(__SSE__)
#include <immintrin.h>

inline TYPE TAG(islower_epi8)(TYPE data) {
  static const TYPE A_MASK = TAG(set1_epi8)('a' - 1);
  static const TYPE Z_MASK = TAG(set1_epi8)('z');
  return TAG_SI(and)(TAG(cmpgt_epi8)(data, A_MASK), TAG(cmpgt_epi8)(Z_MASK, data));
}

inline TYPE TAG(mask_toupper_epi8)(TYPE data) {
  static const TYPE SUB_MASK = TAG(set1_epi8)(32);
  TYPE mask = TAG(islower_epi8)(data);
  TYPE lower_to_upper = TAG(sub_epi8)(data, SUB_MASK);
  return TAG(blendv_epi8)(data, lower_to_upper, mask);
}

inline void TAG(toupper_epi8)(char *str, size_t *i, size_t len) {
  for (; *i + SIZE <= len; *i += SIZE) {
    TYPE data = TAG_SI(loadu)((TYPE *)(str + *i));
    data = TAG(mask_toupper_epi8)(data);
    TAG_SI(storeu)((TYPE *)(str + *i), data);
  }
}

#undef TAG
#undef TAG_SI
#undef TYPE
#undef SIZE

#endif
