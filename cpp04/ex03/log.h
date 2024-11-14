/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 20:32:36 by bonsthie          #+#    #+#             */
/*   Updated: 2024/11/14 17:48:40 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifdef VERBOSE
#include <iostream>
# define LOG(msg) std::cout << msg << std::endl;
#else
# define LOG(msg)
#endif
