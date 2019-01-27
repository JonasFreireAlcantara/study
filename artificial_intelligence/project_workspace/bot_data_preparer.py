"""
    Author: Jonas Freire
    E-mail: jonasfreireperson@gmail.com
"""

# import matplotlib.pyplot as plt

from PIL import Image
import numpy as np
import os
import random
from element import Element


def data_preparation(number_of_images=1,
                     number_of_pixels=1,
                     number_of_categories=1,
                     database_name='',
                     dataset_source='',
                     store_into_file=''):
    # Setup variables
    max_number_of_images_per_category = number_of_images    # Total is 1873 per category
    max_number_of_categories = number_of_categories         # Total is 10
    database_name = database_name
    dataset_source = dataset_source
    total_attributes_amount = number_of_pixels

    # store actual directory
    base_directory = os.getcwd()

    # File to write data
    # dataset = open(store_into_file, 'a')
    dataset = open(store_into_file, 'w')

    dataset.write('%% To get more informations about this dataset visit: %s\n' % dataset_source)
    dataset.write('\n\n@RELATION %s\n\n\n' % database_name)

    os.chdir(database_name)     # Access database
    dirs = os.listdir()         # Get the category(directories) of letters

    for k in range(total_attributes_amount):
        dataset.write('@ATTRIBUTE pixel_%d NUMERIC\n' % k)
    dataset.write('@ATTRIBUTE class ')
    for k in range(len(dirs)):
        if k == 0:
            dataset.write('{%s,' % dirs[k]) # Open curly brackets
        elif k == len(dirs) - 1:
            dataset.write('%s}' % dirs[k])  # Close curly brackets
        else:
            dataset.write('%s,' % dirs[k])  # Continue with categories
    dataset.write('\n\n\n')
    dataset.flush()

    print('FIRST PHASE')
    dataset.write('@DATA\n')
    category_count = 0
    image_count = 0
    images = []                         # Store all images to this list
    for k in range(30):
        random.shuffle(dirs)
    for category in dirs:
        os.chdir(category)              # Access class directory
        imgs_filename = os.listdir()    # List all images filenames

        if category_count >= max_number_of_categories:  # Control categories number
            break
        category_count += 1

        image_count = 0
        for img_filename in imgs_filename:
            img = Image.open(img_filename)    # Load image to array
            image = np.asarray(img)

            if image_count >= max_number_of_images_per_category:    # Control images per categories
                break
            image_count += 1

            images.append(Element(pixel=image, category=category))  # Store image

            # for x in range(image.shape[0]):
            #     for y in range(image.shape[1]):
            #         dataset.write('[%s],' % str(image[x][y]/256))  # Write each pixel to file
            #         print('[%f],' % (image[x][y]/256))
            # dataset.write('%s\n' % category)        # Write the category of such image and line feed to file

        os.chdir('..')  # Back to previous directory
        print('COMPLETED = %.2f%%' % (category_count/max_number_of_categories*100))

    print('SECOND PHASE')
    random.shuffle(images)
    image_saved_number = 0
    for element in images:
        image = element.pixels
        category = element.category
        for x in range(image.shape[0]):
            for y in range(image.shape[1]):
                dataset.write('[%s],' % str(image[x][y]/256))   # Write each pixel to file
        dataset.write('[%s]\n' % category)                      # Write the category of such image and line feed to file

        dataset.flush()
        image_saved_number += 1
        print('COMPLETED = %.2f%%' % (image_saved_number/len(images)*100))

    dataset.close()
    os.chdir(base_directory)
