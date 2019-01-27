# Class to represent image bytes and category class

class Element:
    def __init__(self, pixel, category, filename=''):
        self.pixels = pixel
        self.category = category
        self.filename = filename