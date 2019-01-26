'''
    This file reads an file of arff format with images of 28 x 28 pixels
    and returns a list of numpy arrays containing the image arrays in 2-D
'''
from element import element
import numpy as np


class LoadData:

    def __init__(self, number_of_images=1, number_of_pixels=1, number_of_categories=1, database_name=None):
        self.max_number_of_images_per_category = number_of_images    # Max is 1873 per category
        self.max_number_of_categories = number_of_categories         # Max is 10
        self.total_number_of_images = self.max_number_of_images_per_category * self.max_number_of_categories
        self.database_name = database_name
        self.total_attributes_amount = number_of_pixels
        self.dataset = open(database_name, 'r')
        # Dictionary to convert class letter to number and vice-versa
        self.converter = {'A': 1,   1: 'A',
                          'B': 2,   2: 'B',
                          'C': 3,   3: 'C',
                          'D': 4,   4: 'D',
                          'E': 5,   5: 'E',
                          'F': 6,   6: 'F',
                          'G': 7,   7: 'G',
                          'H': 8,   8: 'H',
                          'I': 9,   9: 'I',
                          'J': 10,  10: 'J'}

        self.load_data()

    def go_to_data_position(self):
        line = self.dataset.readline()
        while line[:-1] != '@DATA':
            line = self.dataset.readline()

    def load_single_image(self):
        image_str_line = self.dataset.readline()[:-1]   # Ignore the last \n character
        image = []
        pixel = 0.0
        test_element = None

        for k in range(self.total_attributes_amount):
            number = ''

            for character in image_str_line:

                if character == '[':
                    # Initialize number
                    number = ''

                elif character == ']':
                    # Finalize number converting it to float number and add it to image
                    pixel = float(number)
                    image.append([pixel])

                elif character == ',':
                    # ...
                    pass

                elif character == '\n':
                    # ...
                    pass

                elif character.isalpha():
                    # Create element and store your respective category
                    test_element = element(pixel=image, category=character)
                    return test_element

                else:
                    # Add this character of float pixel to number string
                    number = number + character
                    pass

    def load_data(self):
        self.go_to_data_position()

        self.all_images = []

        for k in range(self.total_number_of_images):
            new_image = self.load_single_image()
            self.all_images.append(new_image)

    def get_numpy_images_and_categories(self):
        images      = []
        categories  = []

        for elem in self.all_images:
            images.append(elem.pixels)
            categories.append([elem.category])

        return np.array(images), np.array(categories, ndmin=(3))

    def convert_categories_to_number(self):
        for elem in self.all_images:
            elem.category = np.array([self.converter[elem.category]])
        elem.category = np.array(elem.category)

    def convert_categories_to_letter(self):
        for elem in self.all_images:
            elem.category = self.converter(elem.category[0])

    def convert_categories(self, category):
        return self.converter[int(category[0][0])]



# LoadData(number_of_images=2, number_of_pixels=784, number_of_categories=2, database_name='dataset.arff')



