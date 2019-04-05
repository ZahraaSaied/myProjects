import math
class Vector(object):
    def __init__(self, coordinates):
        try:
            if not coordinates:
                raise ValueError
            self.coordinates = tuple(coordinates)
            self.dimension = len(coordinates)

        except ValueError:
            raise ValueError('The coordinates must be nonempty')

        except TypeError:
            raise TypeError('The coordinates must be an iterable')


    def __str__(self):
        return 'Vector: {}'.format(self.coordinates)


    def __eq__(self, v):
        return self.coordinates == v.coordinates

    def addation(self, v):
        new_coordinates = [ i+j for i,j in zip(self.coordinates, v.coordinates)]
        return Vector(new_coordinates)

    def subtraction(self, v):
        new_coordinates = []
        n = len(self.coordinates)
        for i in range(n):
            new_coordinates.append(self.coordinates[i] - v.coordinates[i])
        return Vector(new_coordinates)

    def scalarMultiply(self, c):
        new_coordinates = [ i*c for i in self.coordinates]
        return Vector(new_coordinates)

    def magnitude(self):
        sqr_coordinates = [i**2 for i in self.coordinates]
        mag = math.sqrt(sum(sqr_coordinates))
        return mag
        """ Another solution
        mag_sq = 0
        n = len(self.coordinates)
        for i in range(n):
            mag_sq += self.coordinates[i]**2
        mag = math.sqrt(mag_sq) 
        return mag """
    def normalization(self):
        try:
            mag = self.magnitude()
            return self.scalarMultiply(1.0 / mag)
        except ZeroDivisionError:
            raise Exception("Cann't normalize the zero vector")

    def dot_product(self,v):
        new_coordinates = [i*j for i,j in zip(self.coordinates, v.coordinates)]
        return sum(new_coordinates)

    def angle_betwee_vectors(self, v):
        dot = self.dot_product(v)
        mag1 = self.magnitude()
        mag2 = v.magnitude()
        cos_angle = (dot/(mag1*mag2))
        angle_rdn = math.acos(cos_angle)
        angle_dgr = math.degrees(angle_rdn)
        return angle_rdn, angle_dgr        

my_vec = Vector([3.183, -7.627])
my_vec2 = Vector([-2.668,5.319])
#print my_vec
#print my_vec2
#print "addation result" ,my_vec.addation(my_vec2)
#print "multiply by 3 result" ,my_vec.scalarMultiply(3)
#print my_vec.magnitude()
#print my_vec.normalization()
print "dot product",my_vec.dot_product(my_vec2)
print "angle in rdn, degrees", my_vec.angle_betwee_vectors(my_vec2)