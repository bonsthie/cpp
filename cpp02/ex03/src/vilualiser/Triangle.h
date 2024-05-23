/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Triangle.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:19:49 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/23 20:28:37 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "version.h"

#if CPP11

#include "MlxClass.h"
#include "Point.h"

class Triangle : public MlxClass {
  public:
    Triangle(Point p1, Point p2, Point p3);

    void loop_hook(void);

  private:
    static int _loop_hook(void *content);
    int        _loopPrintTriangle(void);

    Point _p1;
    Point _p2;
    Point _p3;
};

#endif
