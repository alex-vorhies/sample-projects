# name: T. Urness
# description: A Ball Class, inherits from Shape
# The Ball class keeps track of position, diameter, speed, and going_down values for a Ball

import Shape

class Ball(Shape):

    # initializtion method
    # x -- x position of upper left corner of ball
    # y -- y poisitoin of upper left corner of ball
    # canvas -- window canvas, part of tkinter
    # color -- string; color of ball to be drawn
    # width -- width of paddle
    # height -- height of paddle
    def __init__(self, x, y, color, canvas, diameter):
        Shape.__init__(self, x, y, color, canvas)
        self.__diameter = diameter
        self.__going_down = True
        self.__going_left = True
        self.__speed = 3

    def set_diameter(self, diameter):
        self.__diameter = diameter

    def get_diameter(self):
        return self.__diameter

    def set_speed(self,speed):
        self.__speed = speed

    def get_speed(self):
        return self.__speed

    def bounce_vertical(self):
        self.__going_down = not self.__going_down

    def get_going_down(self):
        return self.__going_down

    def move(self):
        if self.__going_down == True:
            self.set_y(self.get_y() + self.__speed)
        else:
            self.set_y(self.get_y() - self.__speed)

        if self.get_y() + self.__diameter > self.get_canvas().winfo_height():
            self.__going_down = False

        if self.get_y() < 0:
            self.__going_down = True

        if self.__going_left == True:
            self.set_x(self.get_x() + self.__speed)
        else:
            self.set_x(self.get_x() - self.__speed)

        if self.get_x() + self.__diameter > self.get_canvas().winfo_height():
            self.__going_left = False

        if self.get_x() < 0:
            self.__going_left = True


    def draw(self):
        self.get_canvas().delete("ball")
        self.get_canvas().create_oval(self.get_x(), self.get_y(),
                                self.get_x() + self.__diameter, self.get_y() + self.__diameter,
                                fill = self.get_color(), tags = "ball")


