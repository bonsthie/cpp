/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Log.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 20:32:36 by bonsthie          #+#    #+#             */
/*   Updated: 2024/08/13 09:36:04 by bonsthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#ifdef VERBOSE
# define LOG(msg) std::cout << msg << std::endl;
#else
# define LOG(msg)
#endif
