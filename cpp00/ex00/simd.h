/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simd.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:50:17 by babonnet          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/07/06 15:20:22 by babonnet         ###   ########.fr       */
=======
/*   Updated: 2024/07/08 17:40:33 by babonnet         ###   ########.fr       */
>>>>>>> refs/remotes/origin/main
/*                                                                            */
/* ************************************************************************** */

#ifndef __SIMD_H__
#define __SIMD_H__

// define simd level
#if defined(__AVX512BW__)
#	define SIMD_LVL 512
#elif defined(__AVX2__)
#	define SIMD_LVL 256
#elif defined(__SSE4_2__)
#	define SIMD_LVL 128
#else
#	define SIMD_LVL 0
#endif

#if SIMD_LVL >= 512
#	define TAG(x) _mm512_##x
#	define TAG_SI(x) _mm512_##x##_si512
#	define TYPE __m512i
#	define SIZE 64
#	include "megaphone.h"
#endif
 
#if SIMD_LVL >= 256
#	define TAG(x) _mm256_##x
#	define TAG_SI(x) _mm256_##x##_si256
#	define TYPE __m256i
#	define SIZE 32
#	include "megaphone.h"
#endif
 
#if SIMD_LVL >= 128
#	define TAG(x) _mm_##x
#	define TAG_SI(x) _mm_##x##_si128
#	define TYPE __m128i
#	define SIZE 16
#	include "megaphone.h"
#endif

#endif // __SIMD_H__
