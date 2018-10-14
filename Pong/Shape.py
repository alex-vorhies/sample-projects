# author: T. Urness
# description: a Shape Class
# consists of an (x,y) position (upper left)
#             color, and canvas objects

class Shape:
    def __init__(self, x, y, color, canvas):
        self.__x = x
        self.__y = y
        self.__color = color
        self.__canvas = canvas

    def get_x(self):
        return self.__x

    def set_x(self,x):
        self.__x = x

    def get_y(self):
        return self.__y

    def set_y(self,y):
        self.__y = y

    def get_color(self):
        return self.__color

    def set_color(self, color):
        self.__color = color

    def get_canvas(self):
        return self.__canvas

    def set_canvas(self, canvas):
        self.__canvas = canvas