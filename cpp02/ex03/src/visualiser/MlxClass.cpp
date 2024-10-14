/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MlxClass.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:17:56 by babonnet          #+#    #+#             */
/*   Updated: 2024/08/28 13:02:55 by bonsthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "version.h"

#if CPP11

#include "MlxClass.h"
#include "mlx.h"
#include <string>

void *MlxClass::_connection = mlx_init();
int   MlxClass::_mouse_x = -1;
int   MlxClass::_mouse_y = -1;

MlxClass::MlxClass() {
    if (!_connection)
        return;
    _window = mlx_new_window(_connection, WIDTH, HEIGHT, "Over Engineer CPP02");
    if (!_window) {
        mlx_destroy_display(_connection);
        return;
    }
}

MlxClass::~MlxClass() {
    if (_window)
        mlx_destroy_window(_connection, _window);
    if (_connection)
        mlx_destroy_display(_connection);
}

int MlxClass::loop() {
    if (!_connection)
        return (1);
    mlx_loop(_connection);
    return (0);
}

int window_hook(int event, void *param) {
    if (event == 0)
        mlx_loop_end(param);
    return (0);
}

void MlxClass::hook() {
    if (_connection && _window)
        mlx_on_event(_connection, _window, MLX_WINDOW_EVENT, window_hook,
                     _connection);
}

void MlxClass::printTriangle(Point p1, Point p2, Point p3, int color) {
    printLine(p1, p2, color);
    printLine(p1, p3, color);
    printLine(p2, p3, color);
}

void MlxClass::printCoord(Point point, int color) {
    std::string str;

    str = "x = ";
    str.append(std::to_string(point.getXfloat() / (1 << 4)));
    mlx_string_put(_connection, _window, point.getXint() + OFFSET_X,
                   point.getYint() + OFFSET_Y, color, (char *)str.c_str());
    str = "y = ";
    str.append(std::to_string(point.getYfloat() / (1 << 4)));
    mlx_string_put(_connection, _window, point.getXint() + OFFSET_X,
                   point.getYint() + OFFSET_Y + LINE_SIZE, color,
                   (char *)str.c_str());
}
#endif
