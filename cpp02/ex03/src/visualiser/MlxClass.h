/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MlxClass.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:36:33 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/23 20:28:20 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "version.h"
#include "Point.h"

#define WIDTH 1920
#define HEIGHT 1080

#define RED_COLOR 0xFFFF0000
#define GREEN_COLOR 0xFF00FF00
#define WHITE_COLOR 0xFFFFFFFF

// text settings 
#define OFFSET_X 15 
#define OFFSET_Y 15
#define LINE_SIZE 20

#if CPP11

#include <mlx.h>

class MlxClass {
  public:
    MlxClass();
    ~MlxClass();
    int  loop();
    void hook();
    void printTriangle(Point p1, Point p2, Point p3, int color);
    void printLine(Point p1, Point p2, int color);
    void printCoord(Point p1, int color);

  protected:
    static void *_connection;
    static int   _mouse_x;
    static int   _mouse_y;
    void        *_window;
};

#endif
