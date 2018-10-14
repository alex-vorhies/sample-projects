# name: T. Urness
# description: A Padle Class, inherits from Shape

from Shape import *

class Paddle(Shape):

    # initializtion method
    # x -- x position of upper left corner of paddle
    # y -- y poisitoin of upper left corner of paddle
    # canvas -- window canvas, part of tkinter
    # color -- string; color of paddle to be drawn
    # width -- width of paddle
    # height -- height of paddle
    def __init__(self, x, y, color, canvas, width, height):
        # first call super class initializtion method
        Shape.__init__(self, x, y, color, canvas)
        self.__width = width
        self.__height = height

    def set_height(self, height):
        self.__height = height

    def get_height(self):
        return self.__height

    def set_width(self, width):
        self.__width = width

    def get_width(self):
        return self.__width

    # draw rectangle on canvas
    def draw(self):
        self.get_canvas().delete("paddle")
        self.get_canvas().create_rectangle(self.get_x(), self.get_y(),
                                self.get_x() + self.__width, self.get_y() + self.__height,
                                fill = self.get_color(), tags = "paddle")


