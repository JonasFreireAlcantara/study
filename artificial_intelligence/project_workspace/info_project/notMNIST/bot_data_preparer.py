"""
    Author: Jonas Freire
    E-mail: jonasfreireperson@gmail.com
"""

# import matplotlib.pyplot as plt

from PIL import Image
import numpy as np
import os


# Setup variables
max_number_of_images_per_category = 500     # Total is 1873 per category
max_number_of_categories = 10               # Total is 10
relation_name = 'notMNIST_small'
dataset_source = 'http://yaroslavvb.blogspot.com/2011/09/notmnist-dataset.html'
total_attributes_amount = 28 * 28

# File to write data
dataset = open('dataset.arff', 'a')

dataset.write('%% To get more informations about this dataset visit: %s\n' % dataset_source)
dataset.write('\n\n@RELATION %s\n\n\n' % relation_name)

os.chdir('notMNIST_small')  # Acess database
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

dataset.write('@DATA\n')
category_count = 0
image_count = 0
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

        for x in range(image.shape[0]):
            for y in range(image.shape[1]):
                dataset.write('%d,' % image[x][y])  # Write each pixel to file
        dataset.write('%s\n' % category)        # Write the category of such image and line feed to file

    os.chdir('..')  # Back to previous directory
    print('COMPLETED = %.2f%%' % (category_count/max_number_of_categories*100))
