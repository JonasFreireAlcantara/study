# Class to represent image bytes and category class

class element:
    def __init__(self, pixel, category, filename=''):
        self.pixels = pixel
        self.category = category
        self.filename = filename