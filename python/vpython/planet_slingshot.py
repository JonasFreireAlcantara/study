# This script aim to simulates through vpython library the gravitational slingshot
# Only for study purposes
# @author: Jonas Freire - jonasfreireperson@gmail.com

"""
Este código pode ser utilizado livremente com a garantia
de que seja utilizado para fim pedagógicos, sem fins lucrativos ;)
"""

from vpython import *


class planet(sphere):
    C = 1

    def __init__(
                    self,
                    pos = vector(0, 0, 0),
                    speed = vector(0, 0, 0),
                    acceleration = vector(0, 0, 0),
                    axis = vector(0, 0, 0),
                    mass = 0.0,
                    radius = 1,
                    make_trail = False):
        sphere.__init__(self, pos=pos, radius=radius, make_trail=make_trail)
        self.speed = speed
        self.acceleration = acceleration
        self.arrow = arrow(pos=pos, axis=axis, color=color.red)
        self.mass = mass

    def update(self, delta_t):
        self.speed = self.speed + (self.acceleration * delta_t)
        self.pos = self.pos + (self.speed * delta_t)
        self.arrow.pos = self.pos

    def updateArrow(self, object=vector(0, 0, 0)):
        self.arrow.axis = (object - self.arrow.pos).norm()

    """
        Determine the new acceleration object based on universal gravitational law

        F = C * m1 * m2 / d*d
        <=>
        F = m1 * a
        <=>
        m1 * a = C * m1 * m2 / d*d
        <=>
        a = C * m2 / d*d 
    """
    def updateAcceleration(self, planet = None):
        if planet == None:
            return
        acceleration = self.C * planet.mass / ((planet.pos - self.pos).mag**2)
        self.acceleration = (planet.pos - self.pos).norm() * acceleration

mars = planet(pos=vector(-89, 0, 0), speed=vector(10, 0, 0), mass=50, radius=0.3, make_trail=True)
satellite = planet(pos=vector(0, 28, 0), speed=vector(0, -3, 0), mass=1, radius=0.1, make_trail=True)

delta_t = 0.01
t = 0

initial_distance = (mars.pos - satellite.pos).mag
initial_speed = satellite.speed.mag

while True:
    rate(1/delta_t)

    # Update gravitational force and acceleration
    mars.updateAcceleration(satellite)
    satellite.updateAcceleration(mars)
    # Update position based at the acceleration
    mars.update(delta_t)
    satellite.update(delta_t)
    # Update the arrow - Descomente isto para visualizar as setas que mostram o vetor força gravitacional
    # mars.updateArrow(satellite.pos)
    # satellite.updateArrow(mars.pos)

    # This is necessary to increase simulation precision
    if t >= 9.25:     # Deactivate slow motion
        delta_t = 0.0001
    elif t >= 8.5:    # Activate slow motion
        delta_t = 0.000001
    t = t + delta_t

    if (mars.pos - satellite.pos).mag >= initial_distance:
        break

final_speed = satellite.speed.mag
final_distance = (mars.pos - satellite.pos).mag

# print(40 * '=')
#
# print('initial distance = ', initial_distance)
# print('final distance = ', final_distance)
#
# print(40 * '=')
#
# print('initial speed = ', initial_speed)
# print('final speed = ', final_speed)

# Portuguese
print(40 * '=')

print('Distância Inicial = ', initial_distance)
print('Distância Final = ', final_distance)

print(40 * '=')

print('Velocidade Inicial = ', initial_speed)
print('Velocidade Final = ', final_speed)

print(40 * '=')